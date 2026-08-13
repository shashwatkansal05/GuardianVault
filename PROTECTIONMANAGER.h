#pragma once

#include "GLOBALS.h"
#include "RELAYDRIVER.h"
#include "ALARMDRIVER.h"
#include "LEDDRIVER.h"

class ProtectionManager
{

private:
  RelayDriver relay;
  AlarmDriver alarm;
  LEDDriver led;

public:
  void begin();
  void update();


};
