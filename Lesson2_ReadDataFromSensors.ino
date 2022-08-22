// Lesson 2: get data from the sensor

#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BME280.h>

static uint8_t const OLED_WIDTH = 128;
static uint8_t const OLED_HEIGHT = 64;
static uint8_t const OLED_I2C_ADDR = 0x3C;

static Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT);
static class Adafruit_BME280 sensor;

static bool ok = false;

void setup() {
        display.begin(SSD1306_SWITCHCAPVCC, OLED_I2C_ADDR);
        display.invertDisplay(false);
        display.setRotation(2);
        display.setTextSize(1);
        display.setTextColor(SSD1306_WHITE, SSD1306_BLACK);
        display.clearDisplay();

        ok = sensor.begin();
        if (!ok) {
                display.println("sensor not found");
        }

        display.display();
}

void loop() {
        if (ok) {
                display.clearDisplay();
                display.setCursor(0, 0);
                display.println("HKU Geog");
                display.println();
                display.print("Temperature: ");
                display.println(sensor.readTemperature());
                display.print("Pressure: ");
                display.println(sensor.readPressure());
                display.print("Humidity: ");
                display.println(sensor.readHumidity());
                display.display();
        }
        delay(1000); // milliseconds
}
