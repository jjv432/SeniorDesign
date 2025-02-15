int dt = 900;
void setup() {

  DDRA = 255;
  PORTA = 0b1;
}

void loop() {
  // put your main code here, to run repeatedly:
PORTA = 1;
    delayMicroseconds(dt);
 PORTA = 0;
    delayMicroseconds(dt);

}
