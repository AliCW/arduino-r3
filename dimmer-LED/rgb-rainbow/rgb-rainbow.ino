int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  setColour(0, 0, 0);
}

void loop() {
  int rgbColour[3];
  rgbColour[0] = 255;
  rgbColour[1] = 0;
  rgbColour[2] = 0;  

  for (int decColour = 0; decColour < 3; decColour += 1) {
    //int incColour = decColour == 2 ? 0 : decColour + 1;
    int incColour;
    if (decColour == 2){
        incColour = 0;
    } else {
        incColour = decColour +1;
    }

    for(int i = 0; i < 255; i += 1) { //fade
      rgbColour[decColour] -= 1;
      rgbColour[incColour] += 1;
      setColour(rgbColour[0], rgbColour[1], rgbColour[2]);
      delay(5);
    }
  }
}

void setColour(int red, int green, int blue){
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
