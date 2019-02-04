#include "XantoKT0803.h"

XantoKT0803::XantoKT0803(uint8_t clock_pin, uint8_t data_pin):
  i2c(clock_pin, data_pin, 1) {
}

uint8_t XantoKT0803::read(uint8_t register_address) {
  i2c.start();

  i2c.writeByte(KT0803_CMD_WRITE);
  if (i2c.readAck()) {
    error = 1;
    return 0;
  }

  i2c.writeByte(register_address);
  if (i2c.readAck()) {
    error = 2;
    return 0;
  }

  i2c.start();

  i2c.writeByte(KT0803_CMD_READ);
  if (i2c.readAck()) {
    error = 3;
    return 0;
  }

  uint8_t register_value = i2c.readByte();
  if (i2c.readNack()) {
    error = 4;
    return 0;
  }

  i2c.stop();

  return register_value;
}

uint8_t XantoKT0803::write(uint8_t register_address, uint8_t value) {
  i2c.start();

  i2c.writeByte(KT0803_CMD_WRITE);
  if (i2c.readAck()) {
    error = 11;
    return 0;
  }

  i2c.writeByte(register_address);
  if (i2c.readAck()) {
    error = 12;
    return 0;
  }

  i2c.writeByte(value);
  if (i2c.readAck()) {
    error = 13;
    return 0;
  }

  i2c.stop();

  return value;
}

/**
 * See KT0803 datasheets for "Register 0x02"
 */
void XantoKT0803::mute(uint8_t mute_enable) {
  uint8_t r02 = read(KT0803_REGA_02);

  bitWrite(r02, 3, mute_enable == 1);

  write(KT0803_REGA_02, r02);
}


