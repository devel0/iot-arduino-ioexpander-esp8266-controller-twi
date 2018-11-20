#include "TWIUtil.h"
#include <Wire.h>

#include "arduinoNanoUtil.h"

void WireInit()
{
    Wire.begin(D2, D1);

    // allow esp8266 communicate to arduino nano ( https://github.com/devel0/knowledge/blob/dd35f1e1c931b0aa68d6262c24c6bb2135d70915/electronics/esp8266-twi-arduino-nano.md )
    auto ms = 7;
    // default is 230us
    Wire.setClockStretchLimit(ms * 1000);
}

SearchAThing::Arduino::SList<byte> TWIScan()
{
    SearchAThing::Arduino::SList<byte> slist;

    byte addr = 1;
    while (addr < 127)
    {
        Wire.beginTransmission(addr);
        if (!Wire.endTransmission())
            slist.Add(addr);

        ++addr;
    }

    return slist;
}

SearchAThing::Arduino::SList<PortMode> getPortModes(int addr)
{
    SearchAThing::Arduino::SList<PortMode> lst;

    const char **port = arduinoNanoDigitalPorts;

    while (*port)
    {
        String q = "getportmode ";
        q.concat(*port);
        int txres = -1;
        int dl = 0;

        while (txres != 0)
        {
            Wire.beginTransmission(addr);
            Wire.write((const uint8_t *)q.c_str(), q.length());
            txres = Wire.endTransmission();
        }

        Wire.requestFrom(addr, 1);
        auto x = 0;
        while (Wire.available())
        {
            x = Wire.read();
        }
        PortMode pm;
        pm.mode = x;
        pm.port = String(*port);
        lst.Add(pm);

        ++port;
    }

    return lst;
}

void setPortMode(int addr, const char *portstr, int mode)
{
    char buf[80];
    sprintf(buf, "setportmode %s %d", portstr, mode);
        
    int txres = -1;
    int dl = 0;

    while (txres != 0)
    {
        Wire.beginTransmission(addr);
        Wire.write(buf, strlen(buf));
        txres = Wire.endTransmission();
    }
}

SearchAThing::Arduino::SList<PortValue> getPortValues(int addr)
{
    SearchAThing::Arduino::SList<PortValue> lst;

    const char **port = arduinoNanoDigitalPorts;

    while (*port)
    {
        String q = "getportvalue ";
        q.concat(*port);
        int txres = -1;
        int dl = 0;

        while (txres != 0)
        {
            Wire.beginTransmission(addr);
            Wire.write((const uint8_t *)q.c_str(), q.length());
            txres = Wire.endTransmission();
        }

        Wire.requestFrom(addr, 1);
        auto x = 0;
        while (Wire.available())
        {
            x = Wire.read();
        }
        PortValue pv;
        pv.value = x;
        pv.port = String(*port);
        lst.Add(pv);

        ++port;
    }

    return lst;
}

void setPortValue(int addr, const char *portstr, int value)
{
    char buf[80];
    sprintf(buf, "setportvalue %s %d", portstr, value);
        
    int txres = -1;
    int dl = 0;

    while (txres != 0)
    {
        Wire.beginTransmission(addr);
        Wire.write(buf, strlen(buf));
        txres = Wire.endTransmission();
    }
}