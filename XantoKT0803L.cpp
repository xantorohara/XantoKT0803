#include "XantoKT0803L.h"

XantoKT0803L::XantoKT0803L(uint8_t clock_pin, uint8_t data_pin):
  XantoKT0803(clock_pin, data_pin) {
}

const uint8_t* XantoKT0803L::getRegisters() {
  return KT0803L_REGS;
}

uint8_t XantoKT0803L::getRegistersCount() {
  return KT0803L_REG_COUNT;
}

/**
 * See KT0803L datasheet, section 4.1 "Register 0x00"
 */
void  XantoKT0803L::setFrequency(uint16_t frequency) {
  frequency *= 2;

  uint8_t r00 = read(KT0803_REGA_00);
  uint8_t r01 = read(KT0803_REGA_01);
  uint8_t r02 = read(KT0803_REGA_02);

  bitWrite(r02, 7, bitRead(frequency, 0));

  bitWrite(r00, 0, bitRead(frequency, 1));
  bitWrite(r00, 1, bitRead(frequency, 2));
  bitWrite(r00, 2, bitRead(frequency, 3));
  bitWrite(r00, 3, bitRead(frequency, 4));
  bitWrite(r00, 4, bitRead(frequency, 5));
  bitWrite(r00, 5, bitRead(frequency, 6));
  bitWrite(r00, 6, bitRead(frequency, 7));
  bitWrite(r00, 7, bitRead(frequency, 8));

  bitWrite(r01, 0, bitRead(frequency, 9));
  bitWrite(r01, 1, bitRead(frequency, 10));
  bitWrite(r01, 2, bitRead(frequency, 11));

  write(KT0803_REGA_00, r00);
  write(KT0803_REGA_01, r01);
  write(KT0803_REGA_02, r02);
}

