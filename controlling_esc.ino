#include <Servo.h>

Servo ESC; 

int Speed; 

void setup(){
ESC.attach(23,1000,2000);
Serial.begin(115200);
}

void loop(){
  /*Speed = analogRead(A0);
  Speed = map(Speed, 0, 1023, 0, 180);*/
  for(speed=0;speed<=170;speed++){
    ESC.write(Speed);
    Serial.print(speed);
    delay(200);
  }
  
}