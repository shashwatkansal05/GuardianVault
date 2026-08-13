#include "SENSORMANAGER_H.h"

void SensorManager::begin()
{
    dhtDriver.begin();
    ldrDriver.begin();
    pirDriver.begin();
}

void SensorManager::update()
{
    sensorData.temperature = dhtDriver.readTemperature();

    sensorData.humidity = dhtDriver.readHumidity();

    sensorData.lightLevel = ldrDriver.readLight();

    sensorData.motionDetected = pirDriver.readMotion();

    sensorData.timestamp = millis();
}
