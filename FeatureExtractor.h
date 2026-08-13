#pragma once

#include "GLOBALS.h"

class FeatureExtractor
{
private:
    float previousTemperature;

    float previousHumidity;

    int previousLight;

public:
    void begin();

    void update();
};
