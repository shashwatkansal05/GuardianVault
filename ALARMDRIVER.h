#pragma once

#include "CONFIG.h"

class AlarmDriver
{
private:

public:
    AlarmDriver();

    void begin();

    void turnOn();

    void turnOff();

    bool isOn();
};
