#include "XantoKT0803.h"

XantoKT0803::XantoKT0803(uint8_t clock_pin, uint8_t data_pin, uint8_t chip_type):
  chip_type(chip_type), i2c(clock_pin, data_pin, 400) {
}

void XantoKT0803::readAll() {
  for (uint8_t i = 0; i < KT0803_REG_COUNT; i++) {
    data[i] = readRaw(KT0803_REGA[i]);
  }
}

uint8_t XantoKT0803::read(uint8_t register_address) {
  for (uint8_t i = 0; i < KT0803_REG_COUNT; i++) {
    if (register_address == KT0803_REGA[i]) {
      data[i] = readRaw(KT0803_REGA[i]);
      return data[i];
    }
  }
}

uint8_t XantoKT0803::readRaw(uint8_t register_address) {
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
  for (uint8_t i = 0; i < KT0803_REG_COUNT; i++) {
    if (register_address == KT0803_REGA[i]) {
      data[i] = writeRaw(KT0803_REGA[i], value);
      return data[i];
    }
  }
}

uint8_t XantoKT0803::writeRaw(uint8_t register_address, uint8_t value) {
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

void  XantoKT0803::setFrequency(float frequency) {
  uint16_t freq = frequency * 20;
  uint8_t temp;
  switch (chip_type) {
    case KT0803K_CHIP:
      //todo
      break;

    case KT0803L_CHIP:
      //in order to set a new frequency we need to write to 3 registers

//      temp = read(KT0803_REGA_02);
//      bitWrite(KT0803_REGA_02, 7, 1)
//      write(KT0803_REGA_02, temp);


      //      bitWrite(KT0803_REGA_00, 7, 1)
      //      bitWrite(KT0803_REGA_02, 7, 1)
      //      write(KT0803_REGA_01, );

      break;
  }
}


