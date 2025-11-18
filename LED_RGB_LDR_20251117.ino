// My version
// const int LED_RED = 9;
// const int LED_GREEN = 10;
// const int LED_BLUE = 11;
// const int LDR_PIN = A0;



// void setup() {
//   Serial.begin(9600);
//   pinMode(LED_RED, OUTPUT);
//   pinMode(LED_GREEN, OUTPUT);
//   pinMode(LED_BLUE, OUTPUT);
//   pinMode(LDR_PIN, INPUT);
// }

// void loop() {
//   int ldrValue = analogRead(LDR_PIN);
//   Serial.print("LDR: ");
//   Serial.println(ldrValue);
//   int brightness = map(ldrValue, 0, 1023, 255, 0);
//   if (brightness >= 180) {
//     analogWrite(LED_RED, brightness);
//     analogWrite(LED_GREEN, 0);
//     analogWrite(LED_BLUE, 0);
//   }
//   else if (brightness >= 80) {
//     analogWrite(LED_RED, 0);
//     analogWrite(LED_GREEN, brightness);
//     analogWrite(LED_BLUE, 0);
//   }
//   else {
//     analogWrite(LED_RED, 0);
//     analogWrite(LED_GREEN, 0);
//     analogWrite(LED_BLUE, brightness);
//   }
//   delay(100);
// }


// Revised version
const int LED_RED   = 9;
const int LED_GREEN = 10;
const int LED_BLUE  = 11;
const int LDR_PIN   = A0;

// ----- Function: read LDR with simple averaging filter -----
int readLDRAverage() {
  const int samples = 10;   // number of samples for averaging
  long sum = 0;

  for (int i = 0; i < samples; i++) {
    sum += analogRead(LDR_PIN);
    delay(2);               // small delay between samples
  }

  return sum / samples;     // return averaged value
}

// ----- Function: set RGB color -----
void setColor(int r, int g, int b) {
  r = constrain(r, 0, 255);
  g = constrain(g, 0, 255);
  b = constrain(b, 0, 255);

  analogWrite(LED_RED,   r);
  analogWrite(LED_GREEN, g);
  analogWrite(LED_BLUE,  b);
}

void setup() {
  Serial.begin(9600);

  pinMode(LED_RED,   OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE,  OUTPUT);
  pinMode(LDR_PIN,   INPUT);
}

void loop() {
  int ldrValue = readLDRAverage();

  Serial.print("LDR(avg): ");
  Serial.println(ldrValue);

  int level = map(ldrValue, 0, 1023, 0, 510);

  int red, green, blue;

  if (level <= 255) {
    red   = 0;
    green = level;
    blue  = 255 - level;
  } else {
    int l2 = level - 255;

    red   = l2;
    green = 255 - l2;
    blue  = 0;
  }

  setColor(red, green, blue);

  delay(20);
}

