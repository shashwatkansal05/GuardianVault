#pragma once

#include <Arduino.h>
#include "CONFIG.h"

class WatchdogManager
{
public:

    void begin();

    void kick();

    void forceReset();
};

extern WatchdogManager watchdogManager;
