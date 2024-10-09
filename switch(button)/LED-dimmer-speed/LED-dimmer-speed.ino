int BUTTON_PIN = 2;
int RED_LED_PIN = 11;
int brightness = 0; //intensity metric of 0 - 255

bool LEDSpeed = true;
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
        LEDSpeed = !LEDSpeed;
        
      }
    }
  }
    if(LEDSpeed == true){
      bool exit = false;
    for(brightness = 0; brightness <= 175; brightness += 1){
      byte buttonState = digitalRead(BUTTON_PIN);
      Serial.println(buttonState);
      if (buttonState == LOW || exit == true) {
        exit = true;
        break;
      }
        
      analogWrite(RED_LED_PIN, brightness);
      delay(30);
    }
    for(brightness = 175; brightness >= 0; brightness -= 1) {
      byte buttonState = digitalRead(BUTTON_PIN);
      Serial.println(buttonState);
      if (buttonState == LOW || exit == true) {
        exit = true;
        break;
      }
      analogWrite(RED_LED_PIN, brightness);
      delay(30);
    } 
  } 
  if(LEDSpeed == false) {
      bool exit = false;
      for(brightness = 0; brightness <= 175; brightness += 1){
        byte buttonState = digitalRead(BUTTON_PIN);
        Serial.println(buttonState);
      if (buttonState == LOW || exit == true) {
        exit = true;
        break;
      }         
        analogWrite(RED_LED_PIN, brightness);
        delay(5);
      }
      for(brightness = 175; brightness >= 0; brightness -= 1){
        byte buttonState = digitalRead(BUTTON_PIN);
        if (buttonState == LOW || exit == true) {
          exit = true;
          break;
        }
        analogWrite(RED_LED_PIN, brightness);
        delay(5);
      } 
    }
  }
