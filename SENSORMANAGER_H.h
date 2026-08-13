#pragma once

#include "DHTDRIVER.h"
#include "LDRDRIVER.h"
#include "PIRDRIVER.h"
#include "GLOBALS.h"

class SensorManager
{
private:
    DHTDriver dhtDriver;
    LDRDriver ldrDriver;
    PIRDriver pirDriver;

public:
    void begin();
    void update();
};
