#pragma once

struct SensorData{
    float temperature;
    float humidity;

    int lightLevel;

    bool motionDetected;

    unsigned long timestamp;


};

struct FeatureData{

  float temperatureTrend;

    float humidityTrend;

    float lightChangeRate;

    bool recentMotion;


};

enum class RiskLevel{

  SAFE,

    WARNING,

    HIGH_RISK,

    UNAUTHORIZED_ACCESS


};

enum class SystemMode{

  DISARMED,

    ARMED,

    ALARM



};

enum class SensorStatus{

  OK,

    FAILED,

    OFFLINE


};

