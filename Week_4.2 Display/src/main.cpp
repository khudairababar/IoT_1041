
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_SDA 21
#define OLED_SCL 22
#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    -1
);

void setup() {
    Serial.begin(115200);
    
//this is where we initailize our I2C
    Wire.begin(OLED_SDA, OLED_SCL);
//this checks the successful initailization
    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
        Serial.println("OLED initialization failed!");
        while (true) {
            delay(100);
        }
    }
//clears the ram buffer
    display.clearDisplay();
//display size specofication
    display.setTextSize(1);
//the text color it values is either white, or invert
    display.setTextColor(SSD1306_WHITE);
//where the cursor should be placed where to write the data max values of both can be max height and width give
    display.setCursor(0, 0);
    //gives values to buffer
    display.println("ESP32 + OLED");

    display.println("PlatformIO Ready!");
    display.println("I2C Address: 0x3C");
//this actually displays the content, unless or until its written this nothing will be shown in the output
    display.display();

    Serial.println("OLED initialized successfully.");
}

void loop() {
    // Add your application code here.
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_INVERSE);
    display.setCursor(62, 32);
    display.println("Hello IoT");
    display.display();
}
