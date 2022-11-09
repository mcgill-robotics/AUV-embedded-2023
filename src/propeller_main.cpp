#ifdef PROPELLER

#include <Arduino.h>
#include "propeller_main.h"
#include "Can.h"

void propeller_setup(){
    CANBus::begin();
}

void propeller_loop(){
    
}

#endif // PROPERLLER