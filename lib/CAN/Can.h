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

    struct FilterInitConfig
    {
    public:
        /** 
         * Type of filter, either a list of 4 specific message identifiers or a set of bit masks. 
         * When in mask mode, a mask of 0 will allow all messages through and a mask of 0xFFFF will block everything.
         */
        FilterType type;

        uint16_t filters[4];
    };

    /**
     * @param bank_number, specifies the filter bank to initialize [0, 13].
     * @param fifo_number, specifies to which fifo the filter will be assigned [0, 1].
     * @param params, filter config. see `FilterInitConfig`
    */
    static Status init_filter(uint16_t bank_number, uint16_t fifo_number, const FilterInitConfig& config);

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
        
        union
        {
            uint64_t data_64;
            uint32_t data_32[2];
            uint16_t data_16[4];
            uint8_t data_8[8];
        };
    };

    /**
     * Writes a message to the CAN bus.
     * @param buffer data to be output on the bus. Must be at least `size` bytes long.
     * @param size number of bytes to write.
     * @returns Okay if the message was successfully posted to a mailbox. If Error, must retry when `getAvailableForWrite()` returns > 0
     */
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

    typedef void (*MessageReceivedCallbackType)(uint32_t fifo);

    static void register_msg_received_callback(MessageReceivedCallbackType callback);
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
