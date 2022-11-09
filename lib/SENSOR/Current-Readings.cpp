#include <Arduino.h>
#include "Current-Readings.h"

float V_REF = 0;
float R_SHUNT = 0.001;
float GAIN = 100;

#define CURRENT_SYSTEM_PIN A0
#define CURRENT_THRUSTER_PIN_1 A1
#define CURRENT_THRUSTER_PIN_2 A2
#define CURRENT_THRUSTER_PIN_3 A3
#define CURRENT_THRUSTER_PIN_4 A4
#define CURRENT_THRUSTER_PIN_5 A5
#define CURRENT_THRUSTER_PIN_6 A6


int current_calculation(int voltage){
  return (voltage-V_REF)/(GAIN*R_SHUNT);
}

int getSystemCurrent(){
    return current_calculation(analogRead(CURRENT_SYSTEM_PIN));
}

/**
 * Call this to refresh all the thrusters current.
 * 
 * return: thrusters current structure
*/
ThrusterCurrent_t getThrusterCurrent()
{
    static ThrusterCurrent_t currents;
    currents.thruster_1_current = current_calculation(analogRead(CURRENT_THRUSTER_PIN_1));
    currents.thruster_2_current = current_calculation(analogRead(CURRENT_THRUSTER_PIN_2));
    currents.thruster_3_current = current_calculation(analogRead(CURRENT_THRUSTER_PIN_3));
    currents.thruster_4_current = current_calculation(analogRead(CURRENT_THRUSTER_PIN_4));
    currents.thruster_5_current = current_calculation(analogRead(CURRENT_THRUSTER_PIN_5));
    currents.thruster_6_current = current_calculation(analogRead(CURRENT_THRUSTER_PIN_6));

    return currents;
}