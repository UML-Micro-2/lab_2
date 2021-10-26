// Modified from basic demo for accelerometer readings from Adafruit MPU6050

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

#define BUZZER 5

Adafruit_MPU6050 mpu;

void setup(void) {
  Serial.begin(115200);
//wait for a serial connection to initialize
  while (!Serial)
    delay(10);

  // Try to initialize!
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  //Initialize Accelerometer and Filter for the IMU
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  //Give a bit of boot up time
  delay(100);
}

void loop() {

  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  //Basic Directional Check
  if (a.acceleration.x > 2){
    Serial.println('n');    
  } else if (a.acceleration.x < -2){
    Serial.println('s');
  } else if (a.acceleration.y > 2){
    Serial.println('w');
  }else if (a.acceleration.y < -2){
    Serial.println('e');
  }

  if (Serial.available() > 0){
    if(Serial.read() == 'b'){
      digitalWrite(BUZZER, HIGH);
    }
  }  

  delay(100);
  digitalWrite(BUZZER, LOW);
}