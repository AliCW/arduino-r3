int RED_LED_PIN = 11;

void setup() {
  Serial.begin(9600);
  pinMode(RED_LED_PIN, OUTPUT);
}

void loop() {
  int blink;
  blink = blinkFunction();
  return blink;
}

int blinkFunction(){
  digitalWrite(RED_LED_PIN, HIGH);
  delay(200);
  digitalWrite(RED_LED_PIN, LOW);
  delay(200);
  return;
}
