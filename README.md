# GuardianVault 🛡️

## TinyML-Powered Intelligent Asset Protection & Predictive Preservation System

GuardianVault is an **ESP32-based intelligent asset protection and predictive preservation system** designed to monitor the environmental and physical conditions surrounding valuable assets.

The system combines **multi-sensor monitoring, feature extraction, TinyML-based risk prediction, FreeRTOS multitasking, automated protection, system health monitoring, and watchdog supervision** into a single embedded platform.

---

## 🚀 Overview

Traditional asset protection systems often rely on fixed thresholds or simple motion detection.

GuardianVault takes a more intelligent approach by combining:

- 🌡️ Temperature monitoring
- 💧 Humidity monitoring
- 💡 Light-level monitoring
- 🚶 Motion detection
- 🧠 TinyML-based risk prediction
- ⚡ Automated protection
- 🖥️ Real-time OLED monitoring
- 🔄 FreeRTOS-based multitasking
- ❤️ System health monitoring
- 🐕 Watchdog supervision
- 📝 Data logging

The system processes sensor information locally on the ESP32, allowing the core decision-making process to operate without relying on cloud processing.

---

## 🎯 Objectives

The main objectives of GuardianVault are:

1. Monitor the environmental conditions surrounding an asset.
2. Detect physical activity or possible unauthorized access.
3. Extract useful features and trends from sensor data.
4. Perform local risk prediction using TinyML.
5. Automatically respond to detected risk.
6. Provide real-time system information through an OLED display.
7. Maintain system reliability using health monitoring and watchdog supervision.
8. Organize the complete system using a modular embedded-software architecture.

---

## 🏗️ System Architecture

```text
                 ┌───────────────┐
                 │     DHT11     │
                 │ Temp / Humidity│
                 └───────┬───────┘
                         │
                 ┌───────▼───────┐
                 │      LDR      │
                 │ Light Level   │
                 └───────┬───────┘
                         │
                 ┌───────▼───────┐
                 │      PIR      │
                 │ Motion Detect │
                 └───────┬───────┘
                         │
                         ▼
                ┌─────────────────┐
                │ Sensor Manager  │
                └────────┬────────┘
                         │
                         ▼
                ┌─────────────────┐
                │ Feature         │
                │ Extractor       │
                └────────┬────────┘
                         │
                         ▼
                ┌─────────────────┐
                │  TinyML Manager │
                │  Risk Prediction│
                └────────┬────────┘
                         │
                         ▼
                  ┌─────────────┐
                  │ Risk Level  │
                  └──────┬──────┘
                         │
              ┌──────────┴──────────┐
              ▼                     ▼
     ┌─────────────────┐    ┌─────────────────┐
     │ Protection      │    │ OLED Manager    │
     │ Manager         │    │                 │
     └────────┬────────┘    └─────────────────┘
              │
        ┌─────┴─────┐
        ▼           ▼
      Relay       Alarm


       Parallel System Services
       ─────────────────────────
       Health Manager
       Watchdog Manager
       Logger
       FreeRTOS
```
---
## ML pipeline:

```text
Sensor Data
     ↓
Feature Extraction
     ↓
Feature Vector
     ↓
TinyML Model
     ↓
Risk Prediction
     ↓
Protection Response
```
---
## 📊 Risk Assessment

GuardianVault uses risk classification to determine the appropriate system response.

```text

SAFE
  ↓
Normal monitoring

WARNING
  ↓
Increased attention / warning

HIGH RISK
  ↓
Protective response

UNAUTHORIZED ACCESS
  ↓
Security response / alarm
```
---
## 🖥️ OLED Monitoring

The OLED provides real-time information about the system, including sensor readings and system status.

Typical information includes:

- Temperature
- Humidity
- Light
- Motion
- Risk
- System Mode

---
## 🔬 Working Principle
```text
The complete operating sequence is:

 ESP32 initializes
        ↓
 Sensors are initialized
        ↓
 Sensor data is continuously collected
        ↓
 Features and trends are calculated
        ↓
 TinyML model evaluates the current condition
        ↓
 Risk level is determined
        ↓
 Protection Manager responds
        ↓
 OLED displays system status
        ↓
 Health and watchdog mechanisms monitor the system
        ↓
 Logger records system information

```
---
## 📈 Future Improvements

Possible future improvements include:

- Larger real-world datasets
- Improved ML model accuracy
- Additional environmental sensors
- Remote monitoring
- Wireless notifications
- Energy optimization
- Advanced anomaly detection
- Long-term asset-condition prediction
