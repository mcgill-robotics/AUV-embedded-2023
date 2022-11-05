#include <Arduino.h>
#include "power_main.h"
#include "propeller_main.h"
#include "grabber_main.h"
#include "sensor_main.h"
#include "torpedo_main.h"
#include "hydrophone_main.h"

void setup() {

  #ifdef POWER
    power_setup();              // Call POWER setup function
  #endif


 #ifdef PROPELLER
    propeller_setup();          // Call PROPELLER setup function
  #endif


  #ifdef GRABBER
    grabber_setup();            // Call GRABBER setup function
  #endif


  #ifdef SENSOR
    sensor_setup();             // Call SENSOR setup function
  #endif


  #ifdef TORPEDO
    torpedo_setup();            // Call TORPEDO setup function
  #endif


  #ifdef HYDROPHONE
    hydrophone_setup();         // Call HYDROPHONE setup function
  #endif
}

void loop() {
  // put your main code here, to run repeatedly:

  #ifdef POWER
    power_loop();              // Call POWER loop function
  #endif


 #ifdef PROPELLER
    propeller_loop();          // Call PROPELLER loop function
  #endif


  #ifdef GRABBER
    grabber_loop();            // Call GRABBER loop function
  #endif


  #ifdef SENSOR
    sensor_loop();             // Call SENSOR loop function
  #endif


  #ifdef TORPEDO
    torpedo_loop();            // Call TORPEDO loop function
  #endif


  #ifdef HYDROPHONE
    hydrophone_loop();         // Call HYDROPHONE loop function
  #endif
}