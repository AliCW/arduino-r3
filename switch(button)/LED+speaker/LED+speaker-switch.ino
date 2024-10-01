#include <toneAC.h>
int forLoop = 0;
int freq = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP); 
  pinMode(11, OUTPUT);
}

void loop() {

  int sensor = digitalRead(2);
  Serial.println(sensor);

  if (digitalRead(2) == HIGH) {
    digitalWrite(11, LOW);
    freq = 0;
    toneAC(freq);
  } else {
    digitalWrite(11, HIGH);
    for(forLoop = 0; forLoop <= 140; forLoop += 1){
      toneAC(freq);
      freq += 10;
      delay(20);
    }
    for(forLoop = 140; forLoop >= 0; forLoop -= 1){
      toneAC(freq);
      freq -= 10;
      delay(20);
    }
  }
}
