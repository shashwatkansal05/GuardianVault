#pragma once

#include <Arduino.h>
#include "CONFIG.h"

class LEDDriver
{
public:

    void begin();

    void allOff();

    void greenOn();

    void yellowOn();

    void redOn();
};
