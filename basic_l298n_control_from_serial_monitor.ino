const int ENA = 12;
const int ENB = 33;
const int IN1 = 14;
const int IN2 = 27;
const int IN3 = 26;
const int IN4 = 25;

int motorSpeed = 0;

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.begin(115200);
  Serial.println("Write speed value:(0-255)");
}

void loop() {
  if(Serial.available() > 0){
    motorSpeed = Serial.parseInt();
    motorSpeed = constrain(motorSpeed, 0, 255);
    if(motorSpeed > 0){
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, motorSpeed);
    }
    else{
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      analogWrite(ENA, 0);
    }
    while(Serial.available() > 0){
      Serial.read();
    }
  }
  Serial.println(motorSpeed);
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