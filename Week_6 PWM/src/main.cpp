#include <Arduino.h>

constexpr uint8_t LED_PIN = 18;
constexpr uint32_t PWM_FREQUENCY = 5000;
constexpr uint8_t PWM_RESOLUTION = 8;
constexpr uint16_t PWM_MAX_DUTY = 255;

void setup()
{
    Serial.begin(115200);

    // Configure PWM
    ledcSetup(0, PWM_FREQUENCY, PWM_RESOLUTION);

    // Attach PWM channel to GPIO 18
    ledcAttachPin(LED_PIN, 0);

    // Start with LED OFF
    ledcWrite(0, 0);

    Serial.println("ESP32 PWM LED Fade Started");
}

void loop()
{
    // Increase brightness
    for (int duty = 0; duty <= PWM_MAX_DUTY; duty++)
    {
        ledcWrite(0, duty);
        delay(10);
    }

    // Decrease brightness
    for (int duty = PWM_MAX_DUTY; duty >= 0; duty--)
    {
        ledcWrite(0, duty);
        delay(10);
    }
}