#include "HEALTHMANAGER.h"


void HealthManager::begin()
{
    systemHealth = 100;

    temperatureSensorStatus = SensorStatus::OK;
    humiditySensorStatus = SensorStatus::OK;
    lightSensorStatus = SensorStatus::OK;
    motionSensorStatus = SensorStatus::OK;
}

void HealthManager::update()
{
    systemHealth = 100;

    // Temperature Check
    if (sensorData.temperature < -40 || sensorData.temperature > 80)
    {
        temperatureSensorStatus = SensorStatus::FAILED;
        systemHealth -= 10;
    }
    else
    {
        temperatureSensorStatus = SensorStatus::OK;
    }

    // Humidity Check
    if (sensorData.humidity < 0 || sensorData.humidity > 100)
    {
        humiditySensorStatus = SensorStatus::FAILED;
        systemHealth -= 10;
    }
    else
    {
        humiditySensorStatus = SensorStatus::OK;
    }

    // Light Check
    if (sensorData.lightLevel < 0 || sensorData.lightLevel > 4095)
    {
        lightSensorStatus = SensorStatus::FAILED;
        systemHealth -= 10;
    }
    else
    {
        lightSensorStatus = SensorStatus::OK;
    }

    // Motion Check
    motionSensorStatus = SensorStatus::OK;

    if (systemHealth < 0)
    {
        systemHealth = 0;
    }
}

int HealthManager::getHealthScore()
{
    return systemHealth;
}
