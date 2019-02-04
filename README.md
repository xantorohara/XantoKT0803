# XantoKT0803
Arduino library for KT0803-based FM radio transmitter

## Elechouse V2.0 FM radio transmitter module

The only one module I've bought in AliExpress is Elechouse V2.0 FM radio transmitter module:

[![Elechouse V2.0 FM radio transmitter module](https://github.com/xantorohara/XantoKT0803/raw/master/extras/elechouse_v2_fm_transmitter.jpg?raw=true)](http://s.click.aliexpress.com/e/MNVjMVbaQ)


But unfortunately my module is a bit defective.

It works as I2C device; all registers are available for reading and writing.

Also I can hear the transmitted sound, but this module generates such a terrible noise...

:construction:

Currently this library has low-level operations with registers and just two high-level functions (setFrequency and mute).

Maybe I'll resume work on it when I have time and proper KT0803-based devices. 

:construction:

## Quick start
1. Download XantoI2C library: [XantoI2C-master.zip](https://github.com/xantorohara/XantoI2C/archive/master.zip)
2. Download XantoKT0803 library: [XantoKT0803-master.zip](https://github.com/xantorohara/XantoKT0803/archive/master.zip)
3. Install these libraries (for example, via Arduino IDE: Sketch -> Include Library -> Add .ZIP Library...)
4. Use it 


## Examples
* [XantoKT0803_Demo](https://github.com/xantorohara/XantoKT0803/tree/master/examples/XantoKT0803_Demo) -
set of Serial commands to interact with with a KT0803 chip 

## Related projects
* [XantoI2C](https://github.com/xantorohara/XantoI2C) - 
XantoKT0803 uses XantoI2C library for I2C communications with a KT0803 chip.

## Author
Xantorohara <xantorohara@gmail.com>
