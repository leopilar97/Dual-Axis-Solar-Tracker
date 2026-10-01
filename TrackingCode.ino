#include <Servo.h>

Servo HorizontalServo ;
Servo VerticalServo ;
int servoh = 90 ;
int servov = 90 ;
const int Hmin = 0 ;
const int Hmax = 180 ;
const int Vmin = 0 ;
const int Vmax = 180 ;
// pin constants
const int pinldrtl = A0 ;
const int pinldrtr = A1 ;
const int pinldrbr = A2 ;
const int pinldrbl = A3 ;
const int pinservoh = 9 ;
const int pinservov = 10 ;
//tuning
const int tolerance = 20 ;
const int speedDelay = 25 ;

void setup() {
Serial.begin(9600);
HorizontalServo.attach(pinservoh);
VerticalServo.attach(pinservov);

HorizontalServo.write(servoh);
delay(200);
VerticalServo.write(servov);
delay(1000);
}

void loop() {
int tl = analogRead(pinldrtl) ;
int tr = analogRead(pinldrtr) ;
int bl = analogRead(pinldrbr) ;
int br = analogRead(pinldrbr) ;
//integers for averages:
int avgtop = (tl + tr) / 2 ;
int avgbottom = (bl + br) / 2 ;
int avgleft = (tl + bl) / 2 ;
int avgright = (tr + br) / 2 ;
//integers for average differences
int vertdiff = avgtop - avgbottom ;
int horidiff = avgleft - avgright ;
//vertical tracking based on values
if (abs(vertdiff) > tolerance) {
  if (avgtop > avgbottom) {
    servov++ ;
  } else {  
    servov-- ;
  } 
  servov = constrain(servov, Vmin, Vmax) ;
  VerticalServo.write(servov) ;
}
delay(100);
//horizontal tracking based on values
if (abs(horidiff) > tolerance) {
  if (avgleft > avgright) {
    servoh++ ;
  } else {
    servoh-- ;
  }
  servoh = constrain(servoh, Hmin, Hmax) ;
  HorizontalServo.write(servoh) ;
  }
delay(speedDelay) ;
}
