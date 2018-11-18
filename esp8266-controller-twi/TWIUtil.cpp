#include "TWIUtil.h"
#include <Wire.h>

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