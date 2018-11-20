#ifndef _TWI_UTIL_H_
#define _TWI_UTIL_H_

#include <Arduino.h>

#include "SList.h"

#define TWI_DELAY_MS 20
#define TWI_DELAY_MS_MAX 500

typedef struct
{
    String port;
    int mode;
} PortMode;

typedef struct
{
    String port;
    int value;
} PortValue;

void WireInit();

SearchAThing::Arduino::SList<byte> TWIScan();
SearchAThing::Arduino::SList<PortMode> getPortModes(int addr);
void setPortMode(int addr, const char *portstr, int mode);
SearchAThing::Arduino::SList<PortValue> getPortValues(int addr);
void setPortValue(int addr, const char *portstr, int value);

#endif