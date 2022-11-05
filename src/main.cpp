#include <Arduino.h>
#include "Current-Readings.h" // always include headers files, not cpp code 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  #ifdef POWER
    // Call POWER setup function
  #endif
}

void loop() {
  // put your main code here, to run repeatedly:

  #ifdef POWER
    // Call POWER setup function
  #endif

  int systemCurrent = getSystemCurrent();                           //Read System Current
  int thruster1_current = getThrusterCurrent().thruster_1_current;  //Read Current From Thruster #1 Example
}