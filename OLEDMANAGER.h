#pragma once

#include "OLEDDRIVER.h"
#include "GLOBALS.h"

class OLEDManager
{
private:
    OLEDDriver oled;

public:
    void begin();

    void update();
};
