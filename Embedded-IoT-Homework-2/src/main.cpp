/*
 * Name: Khudaira Babar
 * Reg No: 24-NTU-CS-FL-1041
 * Task 1: Dual LED PWM
 */
#include <Arduino.h>

using namespace std;

const int led1Pin = 16;
const int led2Pin = 17;

// PWM Properties
const int freq1 = 5000; // 5 kHz
const int freq2 = 1000; // 1 kHz
const int pwmChannel1 = 0;
const int pwmChannel2 = 1;
const int resolution = 8;
const int maxDuty = 255;

void setup() {
  // Configure PWM functionalities
  ledcSetup(pwmChannel1, freq1, resolution);
  ledcSetup(pwmChannel2, freq2, resolution);
  
  // Attach the channel to the GPIO to be routed
  ledcAttachPin(led1Pin, pwmChannel1);
  ledcAttachPin(led2Pin, pwmChannel2);
}

void loop() {
  // Fade in
  for (int duty = 0; duty <= maxDuty; duty++) {
    ledcWrite(pwmChannel1, duty);
    ledcWrite(pwmChannel2, duty);
    delay(10);
  }
  
  // Fade out
  for (int duty = maxDuty; duty >= 0; duty--) {
    ledcWrite(pwmChannel1, duty);
    ledcWrite(pwmChannel2, duty);
    delay(10);
  }
}