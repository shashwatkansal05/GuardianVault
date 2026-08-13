#include "PROTECTIONMANAGER.h"

void ProtectionManager::begin()
{
    relay.begin();
    alarm.begin();
    led.begin();
}

void ProtectionManager::update()
{
    switch (currentRisk)
    {
    case RiskLevel::SAFE:

        relay.turnOff();
        alarm.turnOff();
        led.greenOn();
        currentMode = SystemMode::ARMED;
        break;

    case RiskLevel::WARNING:

        relay.turnOn();
        alarm.turnOff();
         led.yellowOn();
        currentMode = SystemMode::ARMED;
        break;

    case RiskLevel::HIGH_RISK:

        relay.turnOn();
        alarm.turnOn();
        led.redOn();
        currentMode = SystemMode::ALARM;
        break;

    case RiskLevel::UNAUTHORIZED_ACCESS:

        relay.turnOn();
        alarm.turnOn();
        led.redOn();
        currentMode = SystemMode::ALARM;
        break;
    }
}
