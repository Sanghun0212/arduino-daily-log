const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int LED_PIN  = 6;

const int MIN_DIST = 5;    // minimum distance (cm)
const int MAX_DIST = 50;   // maximum distance (cm)

void setup() {
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

long getDistance() {
  // Send trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo pulse
  long duration = pulseIn(ECHO_PIN, HIGH, 30000); // timeout 30ms

  // Convert time to distance (cm)
  long distance = duration * 0.034 / 2;
  return distance;
}

void loop() {
  long distance = getDistance();

  // Optional: ignore weird values
  if (distance <= 0 || distance > 200) {
    distance = MAX_DIST;
  }

  // Constrain distance between MIN_DIST and MAX_DIST
  distance = constrain(distance, MIN_DIST, MAX_DIST);

  // Map distance to brightness (farther → darker)
  int brightness = map(distance, MIN_DIST, MAX_DIST, 255, 0);

  analogWrite(LED_PIN, brightness);

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm, Brightness: ");
  Serial.println(brightness);

  delay(100);
}