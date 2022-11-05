#include <Arduino.h>
#include "sensor_main.h"
#include "Current-Readings.h"

void sensor_setup(){
      // put your setup code here, to run once:
}

void sensor_loop(){
      // put your main code here, to run repeatedly:
      int systemCurrent = getSystemCurrent();                           //Read System Current
      int thruster1_current = getThrusterCurrent().thruster_1_current;  //Read Current From Thruster #1 Example
}