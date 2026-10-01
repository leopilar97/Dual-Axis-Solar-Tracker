#include <Servo.h>

Servo servo1; // First servo object
Servo servo2; // Second servo object

void setup() {
  // Attach servos to digital pins (e.g., 9 and 10)
  servo1.attach(9);
  servo2.attach(10);
  // Move both servos to the center position (90 degrees)
  servo1.write(90);
  delay(300);
  servo2.write(90);
  
  // Small delay to allow servos to reach position
  delay(1000);
}

void loop() {
  // Code to execute repeatedly goes here
  // The servos will remain at 90 degrees until new commands are sent
}   