#ifndef _ARDUINO_NANO_UTIL_H_
#define _ARDUINO_NANO_UTIL_H_

#include <Arduino.h>

extern const char *arduinoNanoDigitalPorts[];
uint8_t arduinoPortStrToNr(const char *portstr);

#endif
