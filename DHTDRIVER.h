#pragma once

#include <DHT.h>
#include "CONFIG.h"

class DHTDriver
{
private:
    DHT dht;

public:
    DHTDriver();

    void begin();

    float readTemperature();

    float readHumidity();
};
