#include <ESP32Servo.h>

Servo myServo;
int servoPin = 18;

void setup() {
  myServo.attach(servoPin);
  //myServo.write(0);
  Serial.begin(115200);
  delay(5000);

}

void loop() {
 
 
 
 
 
 
 /*
  if(Serial.available(){
    int angle= Serial.parseInt();
    myServo.write(angle);
  }
  delay(20);
  */

}
