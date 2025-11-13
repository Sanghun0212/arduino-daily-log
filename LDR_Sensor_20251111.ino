int sensorPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);  // 0~1023
  float voltage = sensorValue * (5.0 / 1023.0); // 전압으로 변환
  Serial.print("LDR value: ");
  Serial.print(sensorValue);
  Serial.print("\tVoltage: ");
  Serial.println(voltage, 3);
  delay(500);
}