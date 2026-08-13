#include "OLEDMANAGER.h"

void OLEDManager::begin()
{
    oled.begin();
}

void OLEDManager::update()
{
    oled.clear();

    oled.printText(0, 0, "GuardianVault");

    oled.printText(0, 12, "Temp : " + String(sensorData.temperature) + " C");

    oled.printText(0, 24, "Hum  : " + String(sensorData.humidity) + " %");

    oled.printText(0, 36, "Motion: " + String(sensorData.motionDetected ? "YES" : "NO"));

    String mode;

    switch (currentMode)
    {
        case SystemMode::DISARMED:
            mode = "DISARMED";
            break;

        case SystemMode::ARMED:
            mode = "ARMED";
            break;

        case SystemMode::ALARM:
            mode = "ALARM";
            break;

        default:
            mode = "UNKNOWN";
            break;
    }

    oled.printText(0, 48, "Mode: " + mode);

    oled.displayScreen();
}
