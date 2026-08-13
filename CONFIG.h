#include <Arduino.h>
#pragma once

#define DHT_PIN             4
#define PIR_PIN             27
#define LDR_PIN             34


#define OLED_SDA            21
#define OLED_SCL            22


#define RELAY_PIN           26
#define BUZZER_PIN          25


#define GREEN_LED_PIN       18
#define YELLOW_LED_PIN      19
#define RED_LED_PIN         23


#define ARM_BUTTON_PIN      32
#define DISARM_BUTTON_PIN   33




#define SCREEN_WIDTH        128
#define SCREEN_HEIGHT       64

#define OLED_RESET          -1
#define OLED_ADDRESS        0x3C




#define SENSOR_INTERVAL_MS      100


#define OLED_INTERVAL_MS        500


#define ML_INTERVAL_MS          500


#define HEALTH_INTERVAL_MS      2000

#define LOGGER_INTERVAL_MS      1000



#define EVENT_QUEUE_SIZE        10
#define LOG_BUFFER_SIZE         100


// Maximum retries before declaring sensor failure
#define MAX_SENSOR_RETRY        3

// Watchdog timeout (seconds)
#define WATCHDOG_TIMEOUT        5

// Default armed state
#define DEFAULT_ARMED           false
