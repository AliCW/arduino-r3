int brightness = 0; //intensity metric of 0 - 255

void setup() {
  pinMode(9, OUTPUT); 
}

void loop() {
  //Turn up brightness
  for(brightness = 0; brightness <= 175; brightness += 1){
    analogWrite(9, brightness);
    delay(20);
    }
  
  //Turn down brightness
  for(brightness = 175; brightness >= 0; brightness -= 1){
    analogWrite(9, brightness);
    delay(20);
  }
}


//https://myenterprised.com/mods/model-remodel/arduino/dimming-leds/