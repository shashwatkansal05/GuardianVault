#include "PIRDriver.h"

PIRDriver::PIRDriver()
{
}

void PIRDriver::begin()
{
    pinMode(PIR_PIN, INPUT);
}

bool PIRDriver::readMotion()
{
    return digitalRead(PIR_PIN) == HIGH;
}
