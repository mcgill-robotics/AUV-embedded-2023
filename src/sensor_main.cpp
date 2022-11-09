#include <Arduino.h>
#include "sensor_main.h"
#include "Current-Readings.h"
#include "MS5803.h"

MS5803 pressure_sensor(0x76);
int32_t pressure_array[5];
int WINDOW_SIZE = 5;
int index = 0;
int32_t avg = 0;
int32_t sum = 0;
int count = 0;
float P_ATM = 101325;
float G = 9.81;
float RHO = 1000;

void sensor_setup(){
      // put your setup code here, to run once:
      pressure_sensor.sensorInit();
      Serial.begin(9600);
}

void sensor_loop(){
      // put your main code here, to run repeatedly:
      int32_t pressure = pressure_sensor.getPressure();
      // int systemCurrent = getSystemCurrent();                           //Read System Current
      // int thruster1_current = getThrusterCurrent().thruster_1_current;  //Read Current From Thruster #1 Example
      
      
      count += 1;

      if(index==5) { // Loop index around to avoid array out of bounds error
            index = 0;
      }

      if(count<5) {
            sum += pressure;
            avg = sum/count;
      } else {
            avg = sum/WINDOW_SIZE;
            sum -= pressure_array[index];
            sum += pressure;
      }

      pressure_array[index] = pressure;
      index += 1;

      float depth = (float(avg)-P_ATM)/(G*RHO);

      Serial.print("Average:");
      Serial.println(avg);
      Serial.print("Pressure:");
      Serial.println(pressure);
      Serial.print("Depth:");
      Serial.println(depth);
      
      delay(100);
}