#include "sensor_main.h"
#include "Current-Readings.h"
#include "MS5803.h"
#include <Arduino.h>

MS5803 pressure_sensor(0x76);

void sensor_setup() {
    // put your setup code here, to run once:
    pressure_sensor.sensorInit();
}

void sensor_loop() {
    // put your main code here, to run repeatedly:
    int pressure = pressure_sensor.getPressure();
    int systemCurrent = getSystemCurrent(); // Read System Current
    int thruster1_current = getThrusterCurrent().thruster_1_current; // Read Current From Thruster #1 Example
}