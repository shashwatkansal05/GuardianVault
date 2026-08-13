#include "TINYMLMANAGER.h"


void TinyMLManager::begin()
{
    Serial.println("Loading TinyML Model...");

    tf.setNumInputs(8);
    tf.setNumOutputs(4);


    if (!tf.begin(model_data).isOk())
    {
        Serial.println("Model loading failed");
        Serial.println(tf.exception.toCString());
        return;
    }


    Serial.println("TinyML Model Loaded Successfully");
}



void TinyMLManager::predict()
{
    // Prepare input features
    input[0] = sensorData.temperature;
    input[1] = sensorData.humidity;
    input[2] = sensorData.lightLevel;
    input[3] = sensorData.motionDetected;

    input[4] = featureData.temperatureTrend;
    input[5] = featureData.humidityTrend;
    input[6] = featureData.lightChangeRate;
    input[7] = featureData.recentMotion;


    // Run inference
    if (!tf.predict(input).isOk())
    {
        Serial.println("Prediction failed");
        Serial.println(tf.exception.toCString());
        return;
    }


    // Get classification result
    switch(tf.classification)
    {
        case 0:
            currentRisk = RiskLevel::HIGH_RISK;
            break;


        case 1:
            currentRisk = RiskLevel::SAFE;
            break;


        case 2:
            currentRisk = RiskLevel::UNAUTHORIZED_ACCESS;
            break;


        case 3:
            currentRisk = RiskLevel::WARNING;
            break;


        default:
            currentRisk = RiskLevel::SAFE;
            break;
    }


    Serial.print("Prediction: ");


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


    Serial.print("Inference Time (us): ");
    Serial.println(tf.benchmark.microseconds());
}
