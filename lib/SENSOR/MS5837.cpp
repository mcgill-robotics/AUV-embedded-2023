#include "MS5837.h"
#include <Wire.h>

const uint8_t MS5837_ADDR = 0x76;
const uint8_t MS5837_RESET = 0x1E;
const uint8_t MS5837_ADC_READ = 0x00;
const uint8_t MS5837_PROM_READ = 0xA0;
const uint8_t MS5837_CONVERT_D1_8192 = 0x4A;
const uint8_t MS5837_CONVERT_D2_8192 = 0x5A;

MS5837::MS5837() {
	fluidDensity = 1029;
}

bool MS5837::begin(TwoWire &wirePort) {
  // Calls the init() function
	return (init(wirePort));
}

bool MS5837::init(TwoWire &wirePort) {
  // Resets the sensor, extracts the coefficient values, and verifies their authenticity

	_i2cPort = &wirePort;

	_i2cPort->beginTransmission(MS5837_ADDR);
	_i2cPort->write(MS5837_RESET);
	_i2cPort->endTransmission();
  
	delay(10);
  
	for ( uint8_t i = 0 ; i < 7 ; i++ ) {
		_i2cPort->beginTransmission(MS5837_ADDR);
		_i2cPort->write(MS5837_PROM_READ+i*2);
		_i2cPort->endTransmission();

		_i2cPort->requestFrom(0x76,2);
		C[i] = (_i2cPort->read() << 8) | _i2cPort->read();
	}
  
	uint8_t crcRead = C[0] >> 12;
	uint8_t crcCalculated = crc4(C);

	if ( crcCalculated != crcRead ) {
		return false;
	}
	return true;
}

void MS5837::setFluidDensity(float density) {
  // enforces fluid density
	fluidDensity = density;
}

void MS5837::read() {
  // Reads digital values, and requests calculations

	if (_i2cPort == NULL)
	{
		return;
	}

	_i2cPort->beginTransmission(MS5837_ADDR);
	_i2cPort->write(MS5837_CONVERT_D1_8192);
	_i2cPort->endTransmission();

	delay(20);

	_i2cPort->beginTransmission(MS5837_ADDR);
	_i2cPort->write(MS5837_ADC_READ);
	_i2cPort->endTransmission();

	_i2cPort->requestFrom(0x76,3);
	D1_pres = 0;
	D1_pres = _i2cPort->read();
	D1_pres = (D1_pres << 8) | _i2cPort->read();
	D1_pres = (D1_pres << 8) | _i2cPort->read();
  
	_i2cPort->beginTransmission(MS5837_ADDR);
	_i2cPort->write(MS5837_CONVERT_D2_8192);
	_i2cPort->endTransmission();

	delay(20);

	_i2cPort->beginTransmission(MS5837_ADDR);
	_i2cPort->write(MS5837_ADC_READ);
	_i2cPort->endTransmission();

	_i2cPort->requestFrom(0x76,3);
	D2_temp = 0;
	D2_temp = _i2cPort->read();
	D2_temp = (D2_temp << 8) | _i2cPort->read();
	D2_temp = (D2_temp << 8) | _i2cPort->read();

	calculate();
}

void MS5837::calculate() {
  // Uses coefficients and digital values to calculate temp and P in first and second order

  int32_t dT = 0;
	int64_t SENS = 0;
	int64_t OFF = 0;
	int32_t SENSi = 0;
	int32_t OFFi = 0;
	int32_t Ti = 0;
	int64_t OFF2 = 0;
	int64_t SENS2 = 0;

	dT = D2_temp-uint32_t(C[5])*256l;
  
  SENS = int64_t(C[1])*32768l+(int64_t(C[3])*dT)/256l;
	OFF = int64_t(C[2])*65536l+(int64_t(C[4])*dT)/128l;
	P = (D1_pres*SENS/(2097152l)-OFF)/(8192l);

	TEMP = 2000l+int64_t(dT)*C[6]/8388608LL;


	if((TEMP/100)<20){
		Ti = (3*int64_t(dT)*int64_t(dT))/(8589934592LL);
		OFFi = (3*(TEMP-2000)*(TEMP-2000))/2;
		SENSi = (5*(TEMP-2000)*(TEMP-2000))/8;
		if((TEMP/100)<-15){
			OFFi = OFFi+7*(TEMP+1500l)*(TEMP+1500l);
			SENSi = SENSi+4*(TEMP+1500l)*(TEMP+1500l);
		}
	}
	else if((TEMP/100)>=20){
		Ti = 2*(dT*dT)/(137438953472LL);
		OFFi = (1*(TEMP-2000)*(TEMP-2000))/16;
		SENSi = 0;
	}
	

	OFF2 = OFF-OFFi;
	SENS2 = SENS-SENSi;

	TEMP = (TEMP-Ti);

  P = (((D1_pres*SENS2)/2097152l-OFF2)/8192l);
}

float MS5837::pressure() {
  // returns pressure in mbar
  return P/10.0f;
}

float MS5837::temperature() {
  // returns temp in deg C
	return TEMP/100.0f;
}

float MS5837::depth() {
  // returns depth
	return (pressure()-101300)/(fluidDensity*9.80665);
}

float MS5837::altitude() {
  // returns altitude
	return (1-pow((pressure()/1013.25),.190284))*145366.45*.3048;
}


uint8_t MS5837::crc4(uint16_t n_prom[]) {
  // verifies authenticity of coefficient values

	uint16_t n_rem = 0;

	n_prom[0] = ((n_prom[0]) & 0x0FFF);
	n_prom[7] = 0;

	for ( uint8_t i = 0 ; i < 16; i++ ) {
		if ( i%2 == 1 ) {
			n_rem ^= (uint16_t)((n_prom[i>>1]) & 0x00FF);
		} else {
			n_rem ^= (uint16_t)(n_prom[i>>1] >> 8);
		}
		for ( uint8_t n_bit = 8 ; n_bit > 0 ; n_bit-- ) {
			if ( n_rem & 0x8000 ) {
				n_rem = (n_rem << 1) ^ 0x3000;
			} else {
				n_rem = (n_rem << 1);
			}
		}
	}

	n_rem = ((n_rem >> 12) & 0x000F);

	return n_rem ^ 0x00;
}