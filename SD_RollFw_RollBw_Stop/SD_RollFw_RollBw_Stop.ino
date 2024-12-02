float breakBeam = 0;
int state = 1;
int t = 0;
int dt = 0;
int duty, prevState;
const int beamTol = 5;

void setup() {
  // put your setup code here, to run once:
  pwm_init();
  DDRB = 255;

  // rollForward(255);
  // delay(5000);
  // rollBackward(255);
  // delay(5000);
  // stopRolling();

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  breakBeam = analogRead(A0);
  Serial.println(breakBeam);
  duty = 200;

  switch (state) {
    case 1:  // forward
      rollForward(duty);

      if (breakBeam <= beamTol) {
        state = 2;
        prevState = 1;
      }

      break;

    case 2:  // stop
      stopRolling();


      if (breakBeam > beamTol) {
        if (prevState == 3) {
          state = 1;
        }

        else if (prevState == 1) {
          state = 3;
        }
      }
      break;

    case 3:  // reverse
      rollBackward(duty);

      if (breakBeam <= beamTol) {
        state = 2;
        prevState = 3;
      }
      break;
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
  OCR5B = duty;
  PORTB = 0b10;
}

void rollBackward(int duty) {
  OCR5A = duty;
  PORTB = 1;
}

void stopRolling() {
  OCR5A = 0;
  OCR5B = 0;
  PORTB = 0;
}