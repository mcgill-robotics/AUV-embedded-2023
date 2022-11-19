#pragma once
#include <stdint.h>
#include <stdbool.h>

#ifndef STM32
#error CANBus is not supported on any platform besides the STM32!!!
#endif

enum class Status
{
    Error,
    Okay,
};

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
    static Status init(GPIOMode gpio_mode = GPIOMode::A11A12, bool use_default_filter = true);

    enum class FilterType
    {
        IDMask = 0,
        IDList = 1,
    };

    enum class FilterScale
    {
        FS16,
        FS32,
    };


    struct FilterInitParams
    {
    public:
        FilterType type;
        FilterScale scale;

        union
        {
            uint16_t filters_16[4];
            uint32_t filters_32[2];
        };
    };

    /**
     * @param bank_number, specifies the filter bank to initialize [0, 13].
     * @param fifo_number, specifies to which fifo the filter will be assigned [0, 1].
    */
    static Status init_filter(uint16_t bank_number, uint16_t fifo_number, const FilterInitParams& params);

    /**
     * Call start after calling begin and setting up any required filters.
     */
    static Status start();
    
    /**
     * @returns the number of available output mailboxes.
     */
    static uint32_t getAvailableForWrite();

    struct Message
    {
    public:
        uint32_t id = 0;
        uint32_t size = 0;
        uint8_t data[8] = {0};
    };

    /**
     * Writes a message to the CAN bus.
     * @param buffer data to be output on the bus. Must be at least `size` bytes long.
     * @param size number of bytes to write.
     * @returns Okay if the message was successfully posted to a mailbox. If Error, must retry when `getAvailableForWrite()` returns > 0
     */
    static Status write(uint16_t message_id, const uint8_t data[], uint32_t size);
    static Status write(const Message& message);
    
    /**
     * @returns the number of messages available for reading.
     */
    static uint32_t getAvailableForRead(uint32_t rx_fifo = 0);
    
    /** 
     * Reads the next available message from the CAN bus.
     * @param buffer output buffer. Must be at least `size` bytes long.
     * @returns Okay if a message was read out
     */
    static Status read(Message& message_out, uint32_t rx_fifo = 0);
private:
    enum State
    {
        None,
        Initialized,
        Ready,
        Error,
    };

    static State state;
};
