/**
 * This example demonstrates abilities of the XantoKT0803 library.
 *
 */
#include <XantoI2C.h>

#include "XantoKT0803L.h"

const uint8_t PIN_SCL = 8;
const uint8_t PIN_SDA = 9;

XantoKT0803L fm(PIN_SCL, PIN_SDA);

char snprintf_buffer[19] = "0x00 76543210 0x00";

void setup() {
  Serial.begin(9600);
  printUsage();
}

void printUsage() {
  Serial.println("Usage:");
  Serial.println(" -Write register: W register_address_hex value_hex");
  Serial.println(" -Read register: R register_address_hex");
  Serial.println(" -Set Frequency: F frequency*10");
  Serial.println(" -Print all registers: P");
  Serial.println(" -Mute: M");
  Serial.println(" -Unmute: U");
  Serial.println("E.g.: \"W 0x02 0x40\" - write value=0x40 to the register with address=0x02");
  Serial.println("E.g.: \"R 0x02\" - read the register with address=0x02");
  Serial.println("E.g.: \"F 997\" - set radio frequency=99.7MHz");
}

void printErrorIfExists() {
  if (fm.error > 0) {
    Serial.print("Error: ");
    Serial.println(fm.error);
    fm.error = 0;
  }
}

void printRegister(uint8_t register_address, uint8_t value) {
  snprintf(snprintf_buffer, 19, "0x%02X %d%d%d%d%d%d%d%d 0x%02X",
           register_address,
           bitRead(value, 7),
           bitRead(value, 6),
           bitRead(value, 5),
           bitRead(value, 4),
           bitRead(value, 3),
           bitRead(value, 2),
           bitRead(value, 1),
           bitRead(value, 0),
           value
          );
  Serial.println(snprintf_buffer);
}

void readAndPrintRegister(uint8_t register_address) {
  Serial.print("Read: ");
  Serial.println(register_address, HEX);

  uint8_t value = fm.read(register_address);
  printErrorIfExists();

  Serial.println("Register address, BIN value, HEX value:");
  printRegister(register_address, value);
}

void readAndPrintAllRegisters() {
  Serial.println("Read all: ");

  Serial.println("Register address, BIN value, HEX value:");
  for (uint8_t i = 0; i < fm.getRegistersCount(); i++) {
    uint8_t value = fm.read(fm.getRegisters()[i]);
    printErrorIfExists();
    printRegister(fm.getRegisters()[i], value);
  }
  Serial.println("Done");
}

void writeAndPrintRegister(uint8_t register_address, uint8_t value) {
  Serial.print("Write: ");
  Serial.print(register_address, HEX);
  Serial.print(" ");
  Serial.println(value, HEX);

  value = fm.write(register_address, value);
  printErrorIfExists();

  Serial.println("Register address, BIN value, HEX value:");
  printRegister(register_address, value);

  value = fm.read(register_address);
  printErrorIfExists();

  Serial.println("Register address, BIN value, HEX value:");
  printRegister(register_address, value);
}

void setFrequency(uint16_t frequency) {
  Serial.print("Set frequency: ");
  Serial.print(frequency / 10.0);
  Serial.println("MHz");
  fm.setFrequency(frequency);
}

void loop() {
  if (Serial.available()) {
    byte cmd = Serial.read();

    if (cmd == 'W') {
      String str = Serial.readString();

      int register_address, value;
      sscanf(str.c_str(), "%i %i", &register_address, &value);

      writeAndPrintRegister(register_address, value);

    } else if (cmd == 'R') {
      String str = Serial.readString();

      int register_address;
      sscanf(str.c_str(), "%i %i", &register_address);

      readAndPrintRegister(register_address);

    } else if (cmd == 'F') {
    
      setFrequency(Serial.parseInt());
    
    } else if (cmd == 'P') {
      
      readAndPrintAllRegisters();
      
    } else if (cmd == 'M') {
      
      Serial.println("Mute");
      fm.mute(1);
      printErrorIfExists();
      
    } else if (cmd == 'U') {
      
      Serial.println("Unmute");
      fm.mute(0);
      printErrorIfExists();
      
    } else {
      Serial.println("Unknown command");
      printUsage();
    }
  }
}

