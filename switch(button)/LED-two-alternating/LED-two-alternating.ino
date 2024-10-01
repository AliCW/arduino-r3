int BUTTON_PIN = 2;
int BLUE_LED_PIN = 10;
int RED_LED_PIN = 11;

byte redLEDState = LOW;
byte blueLEDState = HIGH;
byte lastButtonState = LOW;

unsigned long debounceDuration = 50; // millis
unsigned long lastTimeButtonStateChanged = 0;


void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
  pinMode(RED_LED_PIN, OUTPUT);
}

void loop() {
  if (millis() - lastTimeButtonStateChanged > debounceDuration) {
  byte buttonState = digitalRead(BUTTON_PIN);

    if(buttonState != lastButtonState){
      lastTimeButtonStateChanged = millis();
      lastButtonState = buttonState;
      if(buttonState == LOW){
        redLEDState = (redLEDState == HIGH) ? LOW: HIGH;
        blueLEDState = (blueLEDState == HIGH) ? LOW: HIGH;
        digitalWrite(RED_LED_PIN, redLEDState);
        digitalWrite(BLUE_LED_PIN, blueLEDState);
      }
    }
  }
}