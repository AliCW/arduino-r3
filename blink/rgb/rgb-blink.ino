int redPin = 11;
int greenPin = 10;
int bluePin = 9;


void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  setColour(255, 0, 0); //red
  delay(1000);
  setColour(0, 255, 0); //green
  delay(1000);
  setColour(0, 0, 255); //blue
  delay(1000);
}

void setColour(int red, int green, int blue){
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
