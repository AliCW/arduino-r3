int nine_brightness = 0; //intensity metric of 0 - 255
int ten_brightness = 175;

void setup() {
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT);
}

void loop() {

  //Turn up nine_brightness
  for(nine_brightness = 0; nine_brightness <= 175; nine_brightness += 1){
    ten_brightness -= 1;
    analogWrite(9, nine_brightness);
    analogWrite(10, ten_brightness);
    delay(20);
    }

  ten_brightness = 0;
  
  //Turn down nine_brightness
  for(nine_brightness = 175; nine_brightness >= 0; nine_brightness -= 1){
    ten_brightness += 1;
    analogWrite(9, nine_brightness);
    analogWrite(10, ten_brightness);
    delay(20);
  }
}