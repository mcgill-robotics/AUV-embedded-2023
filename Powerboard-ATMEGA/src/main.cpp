#include <Arduino.h>
#include "Current-Readings.cpp"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int systemCurrent = getSystemCurrent();
  int thruster1_current = getThrusterCurrent().thruster_1_current;

}