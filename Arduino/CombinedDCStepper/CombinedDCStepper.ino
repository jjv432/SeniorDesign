int dt = 6;
float breakBeam = 0;
float tallBreakBeam = 0;
int state = 1;
int t = 0;
int debounceDT = 0;
int duty, prevState;
const int beamTol = 500;
int curPos = 0;
int desPos = 0;

void setup() {

  pwm_init();
  DDRB = 255;
  DDRA = 255;
  PORTA = 0b1;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  breakBeam = analogRead(A0);
  tallBreakBeam = analogRead(A1);
  // Serial.println(tallBreakBeam);

  duty = 255;

  switch (state) {
    case 1:  // forward
      rollForward(duty);

      if (breakBeam >= beamTol) {
        state = 2;
        prevState = 1;
      }

      break;

    case 2:  // stop
      stopRolling();
      desPos = 1600;



      if (breakBeam < .9 * beamTol) {
        if (prevState == 3) {
          state = 1;

        }

        else if (prevState == 1) {
          state = 3;
        }
        delay(debounceDT);
        desPos = 0;
      }
      break;

    case 3:  // reverse
      rollBackward(duty);

      if (breakBeam >= beamTol) {
        state = 2;
        prevState = 3;
      }
      break;
  }

  if (curPos < desPos) {
    PORTA &= 0b0;
    PORTA &= 0b01;
    delayMicroseconds(dt);
    PORTA |= 0b10;
    delayMicroseconds(dt);
    curPos++;

  } else if (curPos > desPos) {
    PORTA |= 0b1;
    PORTA &= 0b01;
    delayMicroseconds(dt);
    PORTA |= 0b10;
    delayMicroseconds(dt);
    curPos--;
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