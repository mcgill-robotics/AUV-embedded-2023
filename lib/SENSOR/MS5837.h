#ifndef MS5837_H_BLUEROBOTICS
#define MS5837_H_BLUEROBOTICS

#include "Arduino.h"
#include <Wire.h>

class MS5837 {
public:
  MS5837();

	bool init(TwoWire &wirePort = Wire);
	bool begin(TwoWire &wirePort = Wire);
  
	void setFluidDensity(float density);

	void read();
  
	float pressure();
	float temperature();
	float depth();
	float altitude();

private:
	TwoWire * _i2cPort;

	uint16_t C[8];
	uint32_t D1_pres, D2_temp;
	int32_t TEMP;
	int32_t P;
	uint8_t _model;

	float fluidDensity;
  
	void calculate();

	uint8_t crc4(uint16_t n_prom[]);
};

#endif