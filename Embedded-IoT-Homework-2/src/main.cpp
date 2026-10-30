/*
 * Name: Khudaira Babar
 * Reg No: 24-NTU-CS-FL-1041
 * Task 2: OLED Monitoring
 */
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

using namespace std;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int led1Pin = 16;
const int led2Pin = 17;

// PWM Properties
const int freq1 = 5000; 
const int freq2 = 1000; 
const int pwmChannel1 = 0;
const int pwmChannel2 = 1;
const int resolution = 8;
const int maxDuty = 255;

void setup() {
  Serial.begin(115200);
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  
  // Configure and attach PWM
  ledcSetup(pwmChannel1, freq1, resolution);
  ledcSetup(pwmChannel2, freq2, resolution);
  ledcAttachPin(led1Pin, pwmChannel1);
  ledcAttachPin(led2Pin, pwmChannel2);
}

void loop() {
  // Fade in loop
  for (int duty = 0; duty <= maxDuty; duty += 5) {
    ledcWrite(pwmChannel1, duty);
    ledcWrite(pwmChannel2, duty);
    
    int dutyPercentage = (duty * 100) / maxDuty;
    
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Khudaira Babar");
    display.println("24-NTU-CS-FL-1041");
    display.println("-----------------");
    
    display.print("L1 Freq: "); display.print(freq1); display.println("Hz");
    display.print("L1 Duty: "); display.print(dutyPercentage); display.println("%");
    
    display.print("L2 Freq: "); display.print(freq2); display.println("Hz");
    display.print("L2 Duty: "); display.print(dutyPercentage); display.println("%");
    
    display.display();
    delay(50);
  }
  
  // Fade out loop
  for (int duty = maxDuty; duty >= 0; duty -= 5) {
    ledcWrite(pwmChannel1, duty);
    ledcWrite(pwmChannel2, duty);
    
    int dutyPercentage = (duty * 100) / maxDuty;
    
    display.clearDisplay();
    display.setCursor(0, 0);
    display.println("Khudaira Babar");
    display.println("24-NTU-CS-FL-1041");
    display.println("-----------------");
    
    display.print("L1 Freq: "); display.print(freq1); display.println("Hz");
    display.print("L1 Duty: "); display.print(dutyPercentage); display.println("%");
    
    display.print("L2 Freq: "); display.print(freq2); display.println("Hz");
    display.print("L2 Duty: "); display.print(dutyPercentage); display.println("%");
    
    display.display();
    delay(50);
  }
}