const int ENA = 12;
const int ENB = 33;
const int IN1 = 14;
const int IN2 = 27;
const int IN3 = 26;
const int IN4 = 25;
int speedMode;
int motorSpeed;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  
   motorSpeed = Serial.parseInt();
   if(motorSpeed > 0){
    speedMode = motorSpeed;
   }
    if(speedMode == 1){
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, 200);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENB, 200);
    }
    else if(speedMode == 2){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      analogWrite(ENA, 200);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENB, 200);
    }
     else {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, 0);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(ENB, 0);
     }
  Serial.println(speedMode);
}


/*
#include "BluetoothSerial.h"
BluetoothSerial serialBT;
char cmd;
void setup() {
serialBT.begin("Esp32-Cubesat");
pinMode(2,OUTPUT);
}

void loop() {
  if(serialBT.available()){
    cmd = serialBT.read();
  }
  if(cmd == '1'){
    digitalWrite(2, HIGH);
  }
  if(cmd == '0'){
    digitalWrite(2, LOW);
  }
  delay(20);
}

*/