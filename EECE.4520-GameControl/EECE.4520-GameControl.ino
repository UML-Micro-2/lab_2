/*
  Ronan Dunn
  Patrick Hoey
  Peter Lynch
  Description: Game Control with Joy Stick, Gyro, and Accelerometer.
  
*/

// determines directions of joystick
#include <AxisJoystick.h>

// Buzzer pin
const int buzzer = 5;
int incomingByte = 0;

// Joystick pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

// joystick control
Joystick* joystick_CC;

// the setup routine runs once when you press reset:
void setup() {
  
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // set up buzzer for output
  pinMode(buzzer, OUTPUT); // buzzer

  joystick_CC = new AxisJoystick(SW_pin, X_pin, Y_pin);
  
}

// returns the direction of the joy stick in terms of n, s, e, and w
char joyStickDirection() {

  // north
  if(joystick_CC->isUp())
    return 'n';
  // south
  else if (joystick_CC->isDown())
    return 's';
  // east
  else if (joystick_CC->isLeft())
    return 'e';
  // west
  else if (joystick_CC->isRight())
    return 'w';
  // no move
  else
    return 'z';
       
}

// the loop routine runs over and over again forever:
void loop() {
  
  // read from the Serial port:
  if (Serial.available() > 0) {
    
    // read the incoming byte:
    incomingByte = Serial.read();
    Serial.println(incomingByte);
    
    if(incomingByte == 'b') {
      // sound buzzer
      digitalWrite(buzzer, HIGH);
    }
  }

  // determine the position of the snake given the input of the joystick and print it to the serial stream
  Serial.println(joyStickDirection());
  
  delay(100);

  // buzzer off
  digitalWrite(buzzer, LOW);

}
