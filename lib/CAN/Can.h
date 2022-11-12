#pragma once
#include <stdint.h>

#ifndef STM32
#error CANBus is not supported on any platform besides the STM32!!!
#endif

class CANBus
{
public:
    static void begin();
    
    static uint32_t getAvailableForWrite();
    
    static void write(uint16_t message_id, const uint8_t data[], uint32_t size);
private:
};
