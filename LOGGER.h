#pragma once

#include <Arduino.h>

class Logger
{
private:

public:
    void begin();

    void logInfo(const String &message);

    void logWarning(const String &message);

    void logError(const String &message);
};
