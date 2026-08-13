#include "FeatureExtractor.h"

void FeatureExtractor::begin()
{
    previousTemperature = sensorData.temperature;
    previousHumidity = sensorData.humidity;
    previousLight = sensorData.lightLevel;
}

void FeatureExtractor::update()
{
    featureData.temperatureTrend =
        sensorData.temperature - previousTemperature;

    featureData.humidityTrend =
        sensorData.humidity - previousHumidity;

    featureData.lightChangeRate =
        sensorData.lightLevel - previousLight;

    featureData.recentMotion =
        sensorData.motionDetected;

    previousTemperature = sensorData.temperature;
    previousHumidity = sensorData.humidity;
    previousLight = sensorData.lightLevel;
}
