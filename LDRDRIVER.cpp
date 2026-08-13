#include "LDRDriver.h"

LDRDriver::LDRDriver()
{
}

void LDRDriver::begin()
{
    pinMode(LDR_PIN, INPUT);
}

int LDRDriver::readLight()
{
    return analogRead(LDR_PIN);
}
