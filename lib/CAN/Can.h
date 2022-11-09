#pragma once
#include <Arduino.h>

#ifndef STM32
#error CANBus is not supported on any platform besides the STM32!!!
#endif

class CANBus
{
public:
    enum class GPIOMode : uint8_t
    {
        PORTA_11_12_XCVR,
        PORTA_11_12_WIRE_PULLUP,
    };

    enum class BitRate : uint8_t
    {
        BR125K = 15,
        BR250K = 7,
        BR500K = 3,
        BR1M = 1,
    };
    
    enum class IDType : uint8_t
    {
        ID_STD,
        ID_EXT,
    };

    static void begin(IDType id_type = IDType::ID_STD, BitRate bit_rate = BitRate::BR500K, GPIOMode gpio_mode = GPIOMode::PORTA_11_12_WIRE_PULLUP);
private:
};
