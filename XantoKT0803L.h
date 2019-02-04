/**
 * Library implementation for KT0803L chip
 */

#ifndef XANTO_KT0803L
#define XANTO_KT0803L

#include "XantoKT0803.h"

/**
 * KT0803L declares 18 registers
 */
const uint8_t KT0803L_REG_COUNT = 18;

/**
 * KT0803L new registers
 */
const uint8_t KT0803L_REGA_0C = 0x0C;
const uint8_t KT0803L_REGA_15 = 0x15;
const uint8_t KT0803L_REGA_17 = 0x17;
const uint8_t KT0803L_REGA_1E = 0x1E;
const uint8_t KT0803L_REGA_26 = 0x26;
const uint8_t KT0803L_REGA_27 = 0x27;

const uint8_t KT0803L_REGS[KT0803L_REG_COUNT] = {
  KT0803_REGA_00,
  KT0803_REGA_01,
  KT0803_REGA_02,
  KT0803_REGA_04,
  KT0803_REGA_0B,
  KT0803L_REGA_0C,
  KT0803_REGA_0E,
  KT0803_REGA_0F,
  KT0803_REGA_10,
  KT0803_REGA_12,
  KT0803_REGA_12,
  KT0803_REGA_14,
  KT0803L_REGA_15,
  KT0803_REGA_16,
  KT0803L_REGA_17,
  KT0803L_REGA_1E,
  KT0803L_REGA_26,
  KT0803L_REGA_27
};


class XantoKT0803L : public XantoKT0803 {
  public:
    XantoKT0803L(uint8_t clock_pin, uint8_t data_pin);

    const uint8_t* getRegisters();
    
    uint8_t getRegistersCount();
    void setFrequency(uint16_t frequency);
};

#endif XANTO_KT0803L

