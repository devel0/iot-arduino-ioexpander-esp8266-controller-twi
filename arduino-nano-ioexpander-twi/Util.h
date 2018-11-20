#ifndef _UTIL_H_
#define _UTIL_H_

#include <Arduino.h>

unsigned long TimeDiff(unsigned long start, unsigned long now);
uint8_t getPinMode(uint8_t pin);
uint8_t arduinoPortStrToNr(const char *str);

#endif