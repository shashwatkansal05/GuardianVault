#include "OLEDDRIVER.h"

OLEDDriver::OLEDDriver()
    : display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET)
{
}

void OLEDDriver::begin()
{
    display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.display();
}

void OLEDDriver::clear()
{
    display.clearDisplay();
}

void OLEDDriver::printText(int x, int y, const String &text)
{
    display.setCursor(x, y);
    display.print(text);
}

void OLEDDriver::drawLine(int x1, int y1, int x2, int y2)
{
    display.drawLine(x1, y1, x2, y2, SSD1306_WHITE);
}

void OLEDDriver::drawRectangle(int x, int y, int width, int height)
{
    display.drawRect(x, y, width, height, SSD1306_WHITE);
}

void OLEDDriver::displayScreen()
{
    display.display();
}
