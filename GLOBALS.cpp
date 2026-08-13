#include "GLOBALS.h"

SensorData sensorData;
FeatureData featureData;

RiskLevel currentRisk = RiskLevel::SAFE;
SystemMode currentMode = SystemMode::DISARMED;
int systemHealth = 100;
