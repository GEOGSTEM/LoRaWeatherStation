// Lesson 1: Print team name on the OLED display

#include <Arduino.h>
#include <Adafruit_SSD1306.h>

static uint8_t const OLED_WIDTH = 128;
static uint8_t const OLED_HEIGHT = 64;
static uint8_t const OLED_I2C_ADDR = 0x3C;

static Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT);

void setup() {
        display.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDR);
        display.invertDisplay(false);
        display.setRotation(3);
        display.setTextSize(1);
        display.setTextColor(SSD1306_WHITE, SSD1306_BLACK);
        display.clearDisplay();
        display.display();
}

static int16_t position = 0;

void loop() {
        display.clearDisplay();
        display.setCursor(0, position);
        display.print("My Team is XXX");
        display.display();
        position = (position + 1) % OLED_WIDTH;
        delay(100); // milliseconds
}
