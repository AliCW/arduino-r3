//#define led_pin 13

void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  delay(200);

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  delay(200);
}
