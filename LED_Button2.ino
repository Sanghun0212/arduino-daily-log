#define LED_PIN 8
#define Button_PIN 7

byte lastButtonState = LOW;
byte ledState = LOW;


void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(Button_PIN, INPUT);

}

void loop() {
  byte buttonstate = digitalRead(BUTTON_PIN);
  
  if (buttonstate ! = lastButtonState) {
    lastButtonState = buttonstate;

    if (buttonstate == LOW) {
      ledState = (ledState == HIGH) ? LOW : HIGH;
      digitalWrite(LED_PIN, ledstate);
    }
  }

}
