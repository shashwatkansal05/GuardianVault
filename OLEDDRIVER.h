#pragma once

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "CONFIG.h"

class OLEDDriver
{
private:
    Adafruit_SSD1306 display;

public:
    OLEDDriver();

    void begin();

    void clear();

    void printText(int x, int y, const String &text);

    void drawLine(int x1, int y1, int x2, int y2);

    void drawRectangle(int x, int y, int width, int height);

    void displayScreen();
};
