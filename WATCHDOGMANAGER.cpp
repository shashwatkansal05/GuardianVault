#include "WatchdogManager.h"
#include "CONFIG.h"

#include <esp_task_wdt.h>
#include <esp_system.h>

WatchdogManager watchdogManager;

void WatchdogManager::begin()
{
#if WATCHDOG_ENABLED

    esp_task_wdt_init(WATCHDOG_TIMEOUT, true);

    // Register the current task (setup task)
    esp_task_wdt_add(NULL);

    Serial.println("[Watchdog] Initialized");

#endif
}

void WatchdogManager::kick()
{
#if WATCHDOG_ENABLED

    esp_task_wdt_reset();

#endif
}

void WatchdogManager::forceReset()
{
    Serial.println("[Watchdog] Force Restart");

    esp_restart();
}
