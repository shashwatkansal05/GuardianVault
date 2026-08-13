#include "LEDDRIVER.h"

void LEDDriver::begin()
{
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(RED_LED_PIN, OUTPUT);

    allOff();
}

void LEDDriver::allOff()
{
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
    digitalWrite(RED_LED_PIN, LOW);
}

void LEDDriver::greenOn()
{
    allOff();
    digitalWrite(GREEN_LED_PIN, HIGH);
}

void LEDDriver::yellowOn()
{
    allOff();
    digitalWrite(YELLOW_LED_PIN, HIGH);
}

void LEDDriver::redOn()
{
    allOff();
    digitalWrite(RED_LED_PIN, HIGH);
}
