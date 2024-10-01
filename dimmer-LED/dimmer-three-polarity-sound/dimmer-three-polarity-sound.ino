#include <toneAC.h>

int brightness = 0; //intensity metric of 0 - 255
int freq = 0;

void setup() {
  pinMode(9, OUTPUT); //speaker out
  pinMode(10, OUTPUT); //speaker in
  pinMode(11, OUTPUT); //white
  pinMode(12, OUTPUT); //red
  pinMode(13, OUTPUT); //green
}

void loop() {

  digitalWrite(12, HIGH);
  delay(50);
  digitalWrite(12, LOW);

  for(brightness = 0; brightness <= 175; brightness += 1){
    toneAC(freq);
    freq += 10;
    analogWrite(11, brightness);
    delay(20);
  }

  digitalWrite(13, HIGH);
  delay(50);
  digitalWrite(13, LOW);


  for(brightness = 175; brightness >= 0; brightness -= 1){
    analogWrite(11, brightness);
    toneAC(freq);
    freq -= 10;
    delay(20);
  }
}

//toneAC library: https://bitbucket.org/teckel12/arduino-toneac/wiki/Home#!syntax