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

class XantoKT0803 {
  private:
    XantoI2C i2c;

  public:

    /**
     * Create a new instance of the XantoKT0803
     * clock_pin - any digital pin for SCL line
     * data_pin - any digital pin for SDA line
     */
    XantoKT0803(uint8_t clock_pin, uint8_t data_pin);

};

#endif XANTO_KT0803
