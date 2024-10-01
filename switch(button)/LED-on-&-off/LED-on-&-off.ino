int BUTTON_PIN = 2;
int RED_LED_PIN = 11;

byte LEDState = LOW;
byte lastButtonState = LOW;

unsigned long debounceDuration = 50; // millis
unsigned long lastTimeButtonStateChanged = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(RED_LED_PIN, OUTPUT);
}

void loop() {
  if (millis() - lastTimeButtonStateChanged > debounceDuration) {
  byte buttonState = digitalRead(BUTTON_PIN);

    if(buttonState != lastButtonState){
      lastTimeButtonStateChanged = millis();
      lastButtonState = buttonState;
      if(buttonState == LOW){
        LEDState = (LEDState == HIGH) ? LOW: HIGH;
        digitalWrite(RED_LED_PIN, LEDState);
      }
    }
  }
}