#include "arduinoNanoUtil.h"

// arduino nano ports suitable to be used as digital ports
const char *arduinoNanoDigitalPorts[] = {
    "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13",
    "A0", "A1", "A2", "A3", NULL };

uint8_t arduinoPortStrToNr(const char *portstr)
{
    if (strcmp(portstr, "D2") == 0)
        return 2;
    else if (strcmp(portstr, "D3") == 0)
        return 3;
    else if (strcmp(portstr, "D4") == 0)
        return 4;
    else if (strcmp(portstr, "D5") == 0)
        return 5;
    else if (strcmp(portstr, "D6") == 0)
        return 6;
    else if (strcmp(portstr, "D7") == 0)
        return 7;
    else if (strcmp(portstr, "D8") == 0)
        return 8;
    else if (strcmp(portstr, "D9") == 0)
        return 9;
    else if (strcmp(portstr, "D10") == 0)
        return 10;
    else if (strcmp(portstr, "D11") == 0)
        return 11;
    else if (strcmp(portstr, "D12") == 0)
        return 12;
    else if (strcmp(portstr, "D13") == 0)
        return 13;
    else if (strcmp(portstr, "A0") == 0)
        return 14;
    else if (strcmp(portstr, "A1") == 0)
        return 15;
    else if (strcmp(portstr, "A2") == 0)
        return 16;
    else if (strcmp(portstr, "A3") == 0)
        return 17;

    return -1;
}