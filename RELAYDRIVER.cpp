#include "RELAYDRIVER.h"

static bool relayState = false;

RelayDriver::RelayDriver()
{
}

void RelayDriver::begin()
{
    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, LOW);
}

void RelayDriver::turnOn()
{
    digitalWrite(RELAY_PIN, HIGH);
    relayState = true;
}

void RelayDriver::turnOff()
{
    digitalWrite(RELAY_PIN, LOW);
    relayState = false;
}

bool RelayDriver::isOn()
{
    return relayState;
}
