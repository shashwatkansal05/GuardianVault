#include "ALARMDRIVER.h"

static bool alarmState = false;

AlarmDriver::AlarmDriver()
{
}

void AlarmDriver::begin()
{
    pinMode(BUZZER_PIN, OUTPUT);
    digitalWrite(BUZZER_PIN, LOW);
}

void AlarmDriver::turnOn()
{
    digitalWrite(BUZZER_PIN, HIGH);
    alarmState = true;
}

void AlarmDriver::turnOff()
{
    digitalWrite(BUZZER_PIN, LOW);
    alarmState = false;
}

bool AlarmDriver::isOn()
{
    return alarmState;
}
