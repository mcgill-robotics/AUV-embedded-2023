#include <Arduino.h>
#include "grabber_main.h"
#include "hydrophone_main.h"
#include "power_main.h"
#include "propeller_main.h"
#include "sensor_main.h"
#include "torpedo_main.h"

void setup() {
#if defined(POWER)
    power_setup(); // Call POWER setup function
#elif defined(PROPELLER)
    propeller_setup(); // Call PROPELLER setup function
#elif defined(GRABBER)
    grabber_setup(); // Call GRABBER setup function
#elif defined(SENSOR)
    sensor_setup(); // Call SENSOR setup function
#elif defined(TORPEDO)
    torpedo_setup(); // Call TORPEDO setup function
#elif defined(HYDROPHONE)
    hydrophone_setup(); // Call HYDROPHONE setup function
#endif
}

void loop() {
#if defined(POWER)
    power_loop(); // Call POWER loop function
#elif defined(PROPELLER)
    propeller_loop(); // Call PROPELLER loop function
#elif defined(GRABBER)
    grabber_loop(); // Call GRABBER loop function
#elif defined(SENSOR)
    sensor_loop(); // Call SENSOR loop function
#elif defined(TORPEDO)
    torpedo_loop(); // Call TORPEDO loop function
#elif defined(HYDROPHONE)
    hydrophone_loop(); // Call HYDROPHONE loop function
#elif
#error System has no loop function defined!
#endif
}