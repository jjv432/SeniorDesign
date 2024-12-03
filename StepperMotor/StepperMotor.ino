int dt = 60;
void setup() {

  DDRA = 255;
  PORTA = 0b1;
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTA &= 0b01;  
  delayMicroseconds(dt);
  PORTA |= 0b10;
  delayMicroseconds(dt);
  


}
