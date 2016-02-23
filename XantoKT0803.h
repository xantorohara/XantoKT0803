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

const uint8_t KT0803_CHIP = 1;
const uint8_t KT0803K_CHIP = 2;
const uint8_t KT0803L_CHIP = 3;
const uint8_t KT0803M_CHIP = 4;

const uint8_t KT0803_CMD_WRITE = 0x7C;
const uint8_t KT0803_CMD_READ = 0x7D;

/**
 * KT0803L declares 18 registers
 */
const uint8_t KT0803_REG_COUNT = 18;

/**
 * Registers addresses
 */

const uint8_t KT0803_REGA_00 = 0x00;
const uint8_t KT0803_REGA_01 = 0x01;
const uint8_t KT0803_REGA_02 = 0x02;
const uint8_t KT0803_REGA_04 = 0x04;
const uint8_t KT0803_REGA_0B = 0x0B;
const uint8_t KT0803_REGA_0C = 0x0C;
const uint8_t KT0803_REGA_0E = 0x0E;
const uint8_t KT0803_REGA_0F = 0x0F;
const uint8_t KT0803_REGA_10 = 0x10;
const uint8_t KT0803_REGA_12 = 0x12;
const uint8_t KT0803_REGA_13 = 0x13;
const uint8_t KT0803_REGA_14 = 0x14;
const uint8_t KT0803_REGA_15 = 0x15;
const uint8_t KT0803_REGA_16 = 0x16;
const uint8_t KT0803_REGA_17 = 0x17;
const uint8_t KT0803_REGA_1E = 0x1E;
const uint8_t KT0803_REGA_26 = 0x26;
const uint8_t KT0803_REGA_27 = 0x27;

const uint8_t KT0803_REGA[KT0803_REG_COUNT] = {
  KT0803_REGA_00,
  KT0803_REGA_01,
  KT0803_REGA_02,
  KT0803_REGA_04,
  KT0803_REGA_0B,
  KT0803_REGA_0C,
  KT0803_REGA_0E,
  KT0803_REGA_0F,
  KT0803_REGA_10,
  KT0803_REGA_12,
  KT0803_REGA_12,
  KT0803_REGA_14,
  KT0803_REGA_15,
  KT0803_REGA_16,
  KT0803_REGA_17,
  KT0803_REGA_1E,
  KT0803_REGA_26,
  KT0803_REGA_27
};


class XantoKT0803 {
  private:
    XantoI2C i2c;
    uint8_t chip_type;
    
  public:
    uint8_t data[KT0803_REG_COUNT] = {};
    uint8_t error = 0;

    /**
     * Create a new instance of the XantoKT0803
     * clock_pin - any digital pin for SCL line
     * data_pin - any digital pin for SDA line
     * chip_type - type of the chip (KT0803L, KT0803K or KT0803M)
     */
    XantoKT0803(uint8_t clock_pin, uint8_t data_pin, uint8_t chip_type = KT0803L_CHIP);

    /**
     * Read all registers (all from the KT0803_REGA list) from the chip.
     * Put results to the data[] holder
     */
    void readAll();

    /**
     * Read single register (one of the specified in KT0803_REGA list)
     * Put the result to the data[] holder
     */
    uint8_t read(uint8_t register_address);

    uint8_t get(uint8_t register_address);
    
    /**
     * Read value from the register.
     * This method accepts any address and doesn't touch data[] holder
     */
    uint8_t readRaw(uint8_t register_address);

    /**
     * Write value to the register (one of the specified in KT0803_REGA list)
     * Put the value to the data[] holder
     */
    uint8_t write(uint8_t register_address, uint8_t value);

    /**
     * Write value to the register.
     * This method accepts any address and doesn't touch data[] holder
     */
    uint8_t writeRaw(uint8_t register_address, uint8_t value);

    void setFrequency(float frequency);
};

#endif XANTO_KT0803
