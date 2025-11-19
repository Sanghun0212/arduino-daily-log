#include <Servo.h>

const int button1 = 2;    
const int button2 = 3;    
const int ServoPin = 10;

Servo myServo;


unsigned long debounceDelay = 30;  
unsigned long lastPressTime1 = 0;  
unsigned long lastPressTime2 = 0; 

int pos = 90;          

void setup() {
  myServo.attach(ServoPin);
  pinMode(button1, INPUT_PULLUP);   
  pinMode(button2, INPUT_PULLUP);

  Serial.begin(9600);
  myServo.write(pos);
}

void loop() {

  unsigned long currentTime = millis();


  if (digitalRead(button1) == LOW) {               
    if (currentTime - lastPressTime1 > debounceDelay) {  
      if (pos < 180) pos++;                     
      myServo.write(pos);

      Serial.print("Angle: ");
      Serial.println(pos);

    }
  }


  if (digitalRead(button2) == LOW) {
    if (currentTime - lastPressTime2 > debounceDelay) {  
      if (pos > 0) pos--;                          
      myServo.write(pos);

      Serial.print("Angle: ");
      Serial.println(pos);

      lastPressTime2 = currentTime;                
    }
  }
}