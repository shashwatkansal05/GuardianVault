#pragma once

#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "SENSORMANAGER_H.h"
#include "OLEDMANAGER.h"
#include "FeatureExtractor.h"
#include "TINYMLMANAGER.h"
#include "PROTECTIONMANAGER.h"
#include "LOGGER.h"
#include "HEALTHMANAGER.h"
#include "WATCHDOGMANAGER.h"

class FreeRTOSTasks
{

private: 

SensorManager sensorManager;

FeatureExtractor featureExtractor;

TinyMLManager tinyMLManager;

ProtectionManager protectionManager;

OLEDManager oledManager;

HealthManager healthManager;

Logger logger;

WatchdogManager watchdogManager;

TaskHandle_t sensorTaskHandle;

TaskHandle_t featureTaskHandle;

TaskHandle_t tinyMLTaskHandle;

TaskHandle_t protectionTaskHandle;

TaskHandle_t oledTaskHandle;

TaskHandle_t healthTaskHandle;

TaskHandle_t loggerTaskHandle;

public:

void begin();

void createTasks();

static void sensorTask(void *parameter);

static void featureTask(void *parameter);

static void tinyMLTask(void *parameter);

static void protectionTask(void *parameter);

static void oledTask(void *parameter);

static void healthTask(void *parameter);

static void loggerTask(void *parameter);
};


