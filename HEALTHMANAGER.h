#pragma once

#include "GLOBALS.h"
#include "LOGGER.h"

class HealthManager
{

private:

  SensorStatus temperatureSensorStatus;
    SensorStatus humiditySensorStatus;
    SensorStatus lightSensorStatus;
    SensorStatus motionSensorStatus;

public:

  void begin();

  void update();

  int getHealthScore();
};
