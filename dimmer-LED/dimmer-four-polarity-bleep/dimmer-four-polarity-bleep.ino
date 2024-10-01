int nine_brightness = 0; //intensity metric of 0 - 255
int ten_brightness = 175;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  digitalWrite(3, HIGH);
  delay(50);
  digitalWrite(13, LOW);
  digitalWrite(3, LOW);

  //Turn up nine_brightness
  for(nine_brightness = 0; nine_brightness <= 175; nine_brightness += 1){
    ten_brightness -= 1;
    analogWrite(9, nine_brightness);
    analogWrite(10, ten_brightness);
    delay(20);
    }

  digitalWrite(8, HIGH);
  digitalWrite(3, HIGH);
  delay(50);
  ten_brightness = 0;
  digitalWrite(8, LOW);
  digitalWrite(3, LOW);


  //Turn down nine_brightness
  for(nine_brightness = 175; nine_brightness >= 0; nine_brightness -= 1){
    ten_brightness += 1;
    analogWrite(9, nine_brightness);
    analogWrite(10, ten_brightness);
    delay(20);
  }
}


