#pragma once

#include "CONFIG.h"

class RelayDriver
{
private:

public:
    RelayDriver();

    void begin();

    void turnOn();

    void turnOff();

    bool isOn();
};
