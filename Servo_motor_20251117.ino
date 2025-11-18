#include <Servo.h> //recall Servo motor library

#define SERVO_PIN  9

Servo myServo;

void setup() {

  myServo.attach(SERVO_PIN); // use 9 pin to control servo

}

void loop() {

  for (int angle = 0;  angle <= 180; angle +=5) {
    myServo.write(angle);
    delay(20);
  }

  for (int angle = 180; angle >= 0; angle -= 5) {
    myServo.write(angle);
    delay(20);
  }

}


