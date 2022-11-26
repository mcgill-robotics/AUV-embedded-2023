# CANBus API

Sample program:

```
#include "Can.h"

void setup(){
    CANBus::init(CANBus::GPIOMode::A11A12, /* use_default_filter = */ false);

    // Filter which places all messages with ids { 0xde, 0xad, 0xbe, 0xef } into fifo 0.
    CANBus::init_filter(0, 0, { 
        .type = CANBus::FilterType::IDList, 
        .filters = { 0xde, 0xad, 0xbe, 0xef }});

    // Filter which places all messages with ids { 0xfa, 0xce, 0xfe, 0xed } into fifo 1.
    CANBus::init_filter(1, 1, { 
        .type = CANBus::FilterType::IDList, 
        .filters = { 0xfa, 0xce, 0xfe, 0xed }});

    CANBus::start();
}

void loop(){
    // checks if any messages from our first fifo (assigned to { 0xde, 0xad, 0xbe, 0xef } above) have arrived.
    if (CANBus::getAvailableForRead(0) > 0)
    {
        CANBus::Message m;
        CANBus::read(m, 0);
        // do something with the message...
        // ...
    }

    // checks if any messages from our second fifo (assigned to { 0xde, 0xad, 0xbe, 0xef } above) have arrived.
    if (CANBus::getAvailableForRead(1) > 0)
    {
        CANBus::Message m;
        CANBus::read(m, 1);
        // do something with the message...
        // ...
    }
   
   // checks if there are spaces available to transmit
   if (CANBus::getAvailableForWrite() > 0)
   {
       CANBus::write({.id  = 0xde, .size = 8, .data_32 = {1, 2}});
   }


    delay(100);
}
```