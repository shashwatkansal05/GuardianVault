#include "DHTDriver.h"

DHTDriver::DHTDriver()
    : dht(DHT_PIN, DHT11)
{
}

void DHTDriver::begin()
{
    dht.begin();
}

float DHTDriver::readTemperature()
{
    return dht.readTemperature();
}

float DHTDriver::readHumidity()
{
    return dht.readHumidity();
}
