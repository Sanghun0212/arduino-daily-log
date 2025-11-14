
int res = 0;
const int SENSOR_PIN = A0;
const int LED_Pin    = 5;

void setup() {
  Serial.begin(9600);
  pinMode(LED_Pin, OUTPUT);
}

void loop() {
  res = analogRead(SENSOR_PIN);          // 0~1023
  int brightness = map(res, 0, 1023, 255, 0);
  analogWrite(LED_Pin, brightness);

  Serial.print("LDR: ");
  Serial.print(res);
  Serial.print("\tPWM: ");
  Serial.println(brightness);

  delay(100);
}
