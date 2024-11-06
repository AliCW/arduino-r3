int buttonPin = 2;
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int alternate = 0;

byte LEDState = LOW;
byte lastButtonState = LOW;

unsigned long debounceDuration = 50; // millis
unsigned long lastTimeButtonStateChanged = 0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  if (millis() - lastTimeButtonStateChanged > debounceDuration) {
    byte buttonState = digitalRead(buttonPin);
    if(buttonState != lastButtonState){
      lastTimeButtonStateChanged = millis();
      lastButtonState = buttonState;
      if(buttonState == LOW){
        if(alternate == 0){
          setColour(255, 0, 0); //red
          alternate = 1;
        } else if (alternate == 1){
          setColour(0, 255, 0); //green  
          alternate = 2;
        } else if (alternate == 2){
          setColour(0, 0, 255); //blue
          alternate = 0;
        }
      }
    }
  }
}

void setColour(int red, int green, int blue){
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
