const int LED_Pin = 6;
const int Trig_Pin = 9;
const int Echo_Pin = 10;
const int Buzzer_Pin = 11;

const int Min_Dist = 5;
const int Max_Dist = 50;


void setup() {
  Serial.begin(9600);

  pinMode(Trig_Pin, OUTPUT);
  pinMode(Echo_Pin, INPUT);
  pinMode(LED_Pin, OUTPUT);
  pinMode(Buzzer_Pin, OUTPUT);

}

long getDistance() {
  
  digitalWrite(Trig_Pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_Pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_Pin, LOW);

  long duration = pulseIn(Echo_Pin, HIGH, 30000);
  long distance = duration * 0.034/2;
  return distance;

}


void loop() {

  long distance = getDistance();

  if (distance <= 0 || distance > 200) {
    distance = Max_Dist;
  }

  distance = constrain(distance, Min_Dist, Max_Dist);

  int brightness = map(distance, Min_Dist, Max_Dist, 255, 0);
  analogWrite(LED_Pin, brightness);

  Serial.print("Raw distance: ");
  Serial.print(distance);
  Serial.print(" cm -> ");

  if (distance >= 15) {
    Serial.println("NO SOUND");
    noTone(Buzzer_Pin);

  } else if (distance >= 10) {
    Serial.println("BEEP 400Hz");
    tone(Buzzer_Pin, 400);

  } else {
    Serial.println("BEEP 1000Hz");
    tone(Buzzer_Pin, 1000);
  }

  delay(200);
}
