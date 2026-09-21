// #include <Arduino.h>

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
// #include <Arduino.h> //arduino har program mein add krna hia 

// #define LED_BUILTIN 2 //constant ko define krna ka lia , jo repeatedly use hoga
// // led name or 2 value jahan led likha ho ga wahan 2 value ajai gi
// void setup()  // ya function lazmi declare honga hardware ka kam mein 
// // ya function sirf ek dafa run hoga
// {
//   pinMode(LED_BUILTIN, OUTPUT);
// // input ya output ko pin mode sa configure krna hoga
// }
// //ya end hona ka bad again run hoga jab tak electricity hoga

// void loop() {
//   digitalWrite(LED_BUILTIN, HIGH);
//   //print ki jagah digital write ka use hoga , ya function led ko on off kr dega
//   delay(1000);
//   //1000 mean 1 second delay 
//   digitalWrite(LED_BUILTIN, LOW);
//   //
//   delay(1000);

// }
#include <Arduino.h>

void setup() {
  pinMode(2, OUTPUT);
  
  // Initialize serial communication at 115200 baud
  Serial.begin(115200);
  Serial.println("ESP32 Simulation Started!");
}

void loop() {
  digitalWrite(2, HIGH);   
  Serial.println("LED State: ON");
  delay(1000);             
  
  digitalWrite(2, LOW);    
  Serial.println("LED State: OFF");
  delay(1000);             
}