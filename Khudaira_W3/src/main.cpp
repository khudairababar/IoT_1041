#include <Arduino.h>

// // put function declarations here:
// int myFunction(int, int);

// void setup() {
//   // put your setup code here, to run once:
//   int result = myFunction(2, 3);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
// }

// // put function definitions here:
// int myFunction(int x, int y) {
//   return x + y;
// }
// Week3-Lecture1
// Interrupt (External -Button)
// Embedded IoT System Fall-2025

// Name: Khudaira                  Reg#: 1041


const int buttonPin = 32;
const int ledPin = 4;
volatile bool ledState = LOW;

void IRAM_ATTR handleButton() {
  ledState = !ledState;
  digitalWrite(ledPin, ledState);
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), handleButton, FALLING);
}

void loop() {
  // main loop free for other tasks
}