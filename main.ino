#include <Arduino.h>

#include "CONFIG.h"
#include "GLOBALS.h"

#include "SENSORMANAGER_H.h"
#include "FeatureExtractor.h"
#include "TINYMLMANAGER.h"
#include "OLEDMANAGER.h"
#include "PROTECTIONMANAGER.h"




SensorManager sensorManager;
FeatureExtractor featureExtractor;
TinyMLManager tinyMLManager;
OLEDManager oledManager;
ProtectionManager protectionManager;


void setup()
{
    Serial.begin(115200);

    Serial.println();
    Serial.println("======================================");
    Serial.println(" GuardianVault TinyML Mode");
    Serial.println("======================================");


    // Initialize OLED
    oledManager.begin();


    // Initialize sensors
    sensorManager.begin();

    delay(3000);      // Allow sensors to stabilize


    sensorManager.update();


    // Initialize feature extraction
    featureExtractor.begin();


    // Load TinyML model
    tinyMLManager.begin();
    protectionManager.begin();

    Serial.println("TinyML Model Loaded.");
    Serial.println();

}



void loop()
{
    // Read sensors
    sensorManager.update();


    // Extract features
    featureExtractor.update();


    // Run ML inference
    tinyMLManager.predict();

   
    // Update OLED
    oledManager.update();
    protectionManager.update();


    // Serial monitoring

    Serial.print("Temp: ");
    Serial.print(sensorData.temperature);


    Serial.print("  Hum: ");
    Serial.print(sensorData.humidity);


    Serial.print("  Light: ");
    Serial.print(sensorData.lightLevel);


    Serial.print("  Motion: ");
    Serial.print(sensorData.motionDetected);


    Serial.print("  --> Prediction: ");


    switch(currentRisk)
    {
        case RiskLevel::SAFE:
            Serial.println("SAFE");
            break;


        case RiskLevel::WARNING:
            Serial.println("WARNING");
            break;


        case RiskLevel::HIGH_RISK:
            Serial.println("HIGH_RISK");
            break;


        case RiskLevel::UNAUTHORIZED_ACCESS:
            Serial.println("UNAUTHORIZED_ACCESS");
            break;
    }


    delay(2000);

}
