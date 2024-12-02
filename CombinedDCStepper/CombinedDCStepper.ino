int dt = 60;
float breakBeam = 0;
int state = 1;
int t = 0;
int duty, prevState;
const int beamTol = 5;

void setup() {

pwm_init();
  DDRB = 255;
  DDRA = 255;
  PORTA = 0b1;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTA &= 0b01;  
  delayMicroseconds(dt);
  PORTA |= 0b10;
  delayMicroseconds(dt);

  breakBeam = analogRead(A0);
  Serial.println(breakBeam);
  duty = 255;

  switch (state) {
    case 1: // stepper idle
    desPos = 0;
    break;
    
    case 2: // CCW 90
    desPos = 90;
    direction = 1;
    break;

    case 3: 
    desPos = 90;
    direction = -1;
    break;

    rollForward();

  }

}

void pwm_init(void) {
  DDRL = 255;
  TCCR5A = _BV(COM5A1) | _BV(COM5B1) | _BV(WGM52) | _BV(WGM50);
  TCCR5B = _BV(CS51) | _BV(CS50);
  OCR5A = 0;
  OCR5B = 0;
}

void rollForward(int duty) {
  OCR5A = duty;
  PORTB = 0b10;
}

void rollBackward(int duty) {
  OCR5A = duty;
  PORTB = 0b1;
}

void stopRolling() {
  OCR5A = 0;
  PORTB = 0;
}