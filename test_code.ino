
#include <MPU9250_WE.h>
#include <Wire.h>
#define MPU9250_ADDR 0x68
#include <Adafruit_BMP085.h>
#include <ESP32Servo.h> 
#define BLDC_SIGNAL_1 12 //ESC_1 control
#define BLDC_SIGNAL_2 14 //ESC_2 control
#define BLDC_SIGNAL_3 27 //ESC_3 control
#define BLDC_FWD_1 4  //to dfr0535  ENABLE 1
#define BLDC_RVS_1 17 //to dfr0535 ENABLE 3
#define BLDC_FWD_2 26 //to logic converter
#define BLDC_RVS_2 25 //to logic converter
#define BLDC_FWD_3 33 //to logic converter
#define BLDC_RVS_3 32 //to logic converter

int val;
Servo myservo1;
Servo myservo2;
Servo myservo3; 
ESP32PWM pwm;

MPU9250_WE myMPU9250 = MPU9250_WE(MPU9250_ADDR);
Adafruit_BMP085 bmp;

void setup() {
  Wire.begin();
  ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
  Serial.begin(115200);
  pinMode(12, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(32, OUTPUT);
  myservo1.setPeriodHertz(50);
  myservo1.attach(BLDC_PIN_1, 1000, 2000);
  myservo2.setPeriodHertz(50);
  myservo2.attach(BLDC_PIN_2, 1000, 2000);
  myservo3.setPeriodHertz(50);
  myservo3.attach(BLDC_PIN_3, 1000, 2000);
  if(!myMPU9250.init()){
    Serial.println("MPU9250 does not respond");
  }
  else{
    Serial.println("MPU9250 is connected");
  }
  if(!myMPU9250.initMagnetometer()){
    Serial.println("Magnetometer does not respond");
  }
  else{
    Serial.println("Magnetometer is connected");
  }

  
  Serial.println("Position you MPU9250 flat and don't move it - calibrating...");
  delay(1000);
  myMPU9250.autoOffsets();
  Serial.println("Done!");
  
 
  myMPU9250.enableGyrDLPF();
 
  myMPU9250.setGyrDLPF(MPU9250_DLPF_6);

  myMPU9250.setSampleRateDivider(5);

  myMPU9250.setGyrRange(MPU9250_GYRO_RANGE_250);

  myMPU9250.setAccRange(MPU9250_ACC_RANGE_2G);

  myMPU9250.enableAccDLPF(true);

  myMPU9250.setAccDLPF(MPU9250_DLPF_6);

  
  myMPU9250.enableAccAxes(MPU9250_ENABLE_XYZ);//not needed
  myMPU9250.enableGyrAxes(MPU9250_ENABLE_XYZ);//not needed
  
  myMPU9250.setMagOpMode(AK8963_CONT_MODE_100HZ);
  delay(200);
  if (!bmp.begin()) {
	Serial.println("Could not find a valid BMP085 sensor, check wiring!");
	while (1) {}
  }
}

void loop() {
  xyzFloat gValue = myMPU9250.getGValues();
  xyzFloat gyr = myMPU9250.getGyrValues();
  xyzFloat magValue = myMPU9250.getMagValues();
  float resultantG = myMPU9250.getResultantG(gValue);

  (gValue.x);//Acceleration in g (x,y,z)
  (gValue.y);//Acceleration in g (x,y,z)
  (gValue.z);//Acceleration in g (x,y,z)
  (resultantG);//Resultant g

  Serial.println("Gyroscope data in degrees/s: ");
  (gyr.x);//Gyroscope data in degrees/s
  (gyr.y);//Gyroscope data in degrees/s
  (gyr.z);//Gyroscope data in degrees/s
    
    (bmp.readAltitude());//Altitude
    (bmp.readSealevelPressure());//Pressure at sealevel (calculated)
    Serial.println(" Pa");
    (bmp.readAltitude(101500));//Real altitude

  delay(1000);
}