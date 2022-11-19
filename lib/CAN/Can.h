#pragma once
#include <stdint.h>

#ifndef STM32
#error CANBus is not supported on any platform besides the STM32!!!
#endif

class CANBus
{
public:
    enum class GPIOMode
    {
        A11A12,
        B8B9,
    };

    /**
     * Initializes the CAN bus peripheral.
     */
    static void begin(GPIOMode gpio_mode = GPIOMode::A11A12);
    
    /**
     * @returns the number of available output mailboxes.
     */
    static uint32_t getAvailableForWrite();

    /**
     * Writes a message to the CAN bus.
     * @param buffer data to be output on the bus. Must be at least `size` bytes long.
     * @param size number of bytes to write.
     */
    static void write(uint16_t message_id, const uint8_t data[], uint32_t size);
    
    /**
     * @returns the number of messages available for reading.
     */
    static uint32_t getAvailableForRead(uint32_t rx_fifo = 0);
    
    /** 
     * Reads the next available message from the CAN bus.
     * @param buffer output buffer. Must be at least `size` bytes long.
     * @returns the standard id of the message
     */
    static uint32_t read(uint8_t data_out[], uint32_t size, uint32_t rx_fifo = 0);
private:
    static void init_filter(); // #todo: expose
};
