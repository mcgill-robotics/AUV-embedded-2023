#include <Arduino.h>

float V_REF = 0;
float R_SHUNT = 0.001;
float GAIN = 100;

#define CURRENT_SYSTEM_PIN PIN_A0
#define CURRENT_THRUSTER_PIN_1 PIN_A1
#define CURRENT_THRUSTER_PIN_2 PIN_A2
#define CURRENT_THRUSTER_PIN_3 PIN_A3
#define CURRENT_THRUSTER_PIN_4 PIN_A4
#define CURRENT_THRUSTER_PIN_5 PIN_A5
#define CURRENT_THRUSTER_PIN_6 PIN_A6


int current_calculation(int voltage){
  return (voltage-V_REF)/(GAIN*R_SHUNT);
}

struct ThrusterCurrent{
    int thruster_1_current;
    int thruster_2_current;
    int thruster_3_current;
    int thruster_4_current;
    int thruster_5_current;
    int thruster_6_current;
}

int getSystemCurrent(){
    return current_calculation(analogRead(CURRENT_SYSTEM_PIN));
}

ThrusterCurrent getThrusterCurrent(){
    ThrusterCurrent currents;
    currents.thruster_1_current = current_calculation(analogRead(CURRENT_THRUSTER_PIN_1));
    currents.thruster_2_current = current_calculation(analogRead(CURRENT_THRUSTER_PIN_2));
    currents.thruster_3_current = current_calculation(analogRead(CURRENT_THRUSTER_PIN_3));
    currents.thruster_4_current = current_calculation(analogRead(CURRENT_THRUSTER_PIN_4));
    currents.thruster_5_current = current_calculation(analogRead(CURRENT_THRUSTER_PIN_5));
    currents.thruster_6_current = current_calculation(analogRead(CURRENT_THRUSTER_PIN_6));
    return ThrusterCurrent;
}