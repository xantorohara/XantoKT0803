/**
 * XantoKT0803
 * Arduino library for KT0803-based FM radio transmitter
 *
 * Version: 1.0.1
 * Author: Xantorohara <xantorohara@gmail.com>
 *
 * Requires: XantoI2C library
 *
 * References:
 * - KT0803 datasheet http://xantorohara.github.io/datasheets/KT0803L.pdf
 *
 */

#ifndef XANTO_KT0803
#define XANTO_KT0803

#include <Arduino.h>
#include <XantoI2C.h>

const uint8_t KT0803_CMD_WRITE = 0x7C;
const uint8_t KT0803_CMD_READ = 0x7D;

/**
 * KT0803 base registers
 */
const uint8_t KT0803_REGA_00 = 0x00;
const uint8_t KT0803_REGA_01 = 0x01;
const uint8_t KT0803_REGA_02 = 0x02;
const uint8_t KT0803_REGA_04 = 0x04;
const uint8_t KT0803_REGA_0B = 0x0B;
const uint8_t KT0803_REGA_0E = 0x0E;
const uint8_t KT0803_REGA_0F = 0x0F;
const uint8_t KT0803_REGA_10 = 0x10;
const uint8_t KT0803_REGA_12 = 0x12;
const uint8_t KT0803_REGA_13 = 0x13;
const uint8_t KT0803_REGA_14 = 0x14;
const uint8_t KT0803_REGA_16 = 0x16;

class XantoKT0803 {
  private:
    XantoI2C i2c;

  public:
    uint8_t error = 0;

    /**
     * Create a new instance of the XantoKT0803
     * clock_pin - any digital pin for SCL line
     * data_pin - any digital pin for SDA line
     */
    XantoKT0803(uint8_t clock_pin, uint8_t data_pin);

    /**
     * Read value from the register
     */
    uint8_t read(uint8_t register_address);

    /**
     * Write value to the register
     */
    uint8_t write(uint8_t register_address, uint8_t value);

    /**
     * Set FM radio frequency
     * frequency  - target  frequency in MHz*10
     */
    virtual void setFrequency(uint16_t frequency) = 0;

    /**
     * Returns array of registers addresses for the chip
     */
    virtual const uint8_t* getRegisters() = 0;

    /**
     * Returns amount of registers for the chip
     */
    virtual uint8_t getRegistersCount() = 0;

    /**
     * Mute or unmute transmitter
     */
    void mute(uint8_t mute_enable);
};

#endif XANTO_KT0803

