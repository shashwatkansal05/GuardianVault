#include "FreeRTOSTasks.h"

void FreeRTOSTasks::begin()
{
    logger.begin();

    sensorManager.begin();

    featureExtractor.begin();

    tinyMLManager.begin();

    protectionManager.begin();

    oledManager.begin();

    healthManager.begin();

    watchdogManager.begin();
}

void FreeRTOSTasks::createTasks()
{
    xTaskCreatePinnedToCore(
        sensorTask,
        "Sensor Task",
        4096,
        this,
        2,
        &sensorTaskHandle,
        1
    );

    xTaskCreatePinnedToCore(
        featureTask,
        "Feature Task",
        4096,
        this,
        2,
        &featureTaskHandle,
        1
    );

    xTaskCreatePinnedToCore(
        tinyMLTask,
        "TinyML Task",
        4096,
        this,
        2,
        &tinyMLTaskHandle,
        1
    );

    xTaskCreatePinnedToCore(
        protectionTask,
        "Protection Task",
        4096,
        this,
        2,
        &protectionTaskHandle,
        1
    );

    xTaskCreatePinnedToCore(
        oledTask,
        "OLED Task",
        4096,
        this,
        1,
        &oledTaskHandle,
        1
    );

    xTaskCreatePinnedToCore(
        healthTask,
        "Health Task",
        4096,
        this,
        1,
        &healthTaskHandle,
        1
    );

    xTaskCreatePinnedToCore(
        loggerTask,
        "Logger Task",
        4096,
        this,
        1,
        &loggerTaskHandle,
        1
    );
}

void FreeRTOSTasks::sensorTask(void *parameter)
{
    FreeRTOSTasks *tasks = static_cast<FreeRTOSTasks *>(parameter);

    while (true)
    {
        tasks->sensorManager.update();

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void FreeRTOSTasks::featureTask(void *parameter)
{
    FreeRTOSTasks *tasks = static_cast<FreeRTOSTasks *>(parameter);

    while (true)
    {
        tasks->featureExtractor.update();

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void FreeRTOSTasks::tinyMLTask(void *parameter)
{
    FreeRTOSTasks *tasks = static_cast<FreeRTOSTasks *>(parameter);

    while (true)
    {
        tasks->tinyMLManager.predict();

        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void FreeRTOSTasks::protectionTask(void *parameter)
{
    FreeRTOSTasks *tasks = static_cast<FreeRTOSTasks *>(parameter);

    while (true)
    {
        tasks->protectionManager.update();

        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void FreeRTOSTasks::oledTask(void *parameter)
{
    FreeRTOSTasks *tasks = static_cast<FreeRTOSTasks *>(parameter);

    while (true)
    {
        tasks->oledManager.update();

        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

void FreeRTOSTasks::healthTask(void *parameter)
{
    FreeRTOSTasks *tasks = static_cast<FreeRTOSTasks *>(parameter);

    while (true)
    {
        tasks->healthManager.update();

        tasks->watchdogManager.kick();

        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

void FreeRTOSTasks::loggerTask(void *parameter)
{
    FreeRTOSTasks *tasks = static_cast<FreeRTOSTasks *>(parameter);

    while (true)
    {
        tasks->logger.logInfo("GuardianVault Running");

        vTaskDelay(pdMS_TO_TICKS(3000));
    }
}
