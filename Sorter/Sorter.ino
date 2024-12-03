int stepper_dt = 6;
float breakBeamVal = 0;
float tallBreakBeam = 0;
int state = 1;
int t = 0;
int debounceDT = 0;
int duty, prevState;
const int beamTol = 500;
int curPos = 0;
int desPos = 0;
int t_not;
int button_delay = 100;

int switch1Value, switch1OldValue;
bool button = 1;
bool breakBeam = 0;

void setup() {

  pwm_init();
  DDRB = 255;
  DDRA = 255;
  PORTA = 0b1;
  Serial.begin(9600);

  DDRC = 0;
  PORTC = 0xFF;
  switch1OldValue = PINC & 0b1;
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(state);

  switch1Value = PINC & 0b1;

  if ((switch1OldValue == 1) && (switch1Value == 0)) {
    button = !button;
    delay(button_delay);
  } else if ((switch1OldValue == 0) && (switch1Value == 1)) {
    delay(button_delay);
  }

  switch1OldValue = switch1Value;

  breakBeamVal = analogRead(A0);

  duty = 255;

  if (breakBeamVal >= beamTol) {
    breakBeam = 1;
  } else if (breakBeam < beamTol) {
    breakBeam = 0;
  }

  switch (state) {

    case 1:  // Rolling forward, arm at 0
      desPos = 0;
      rollForward(duty);
      if (button == 0)
        state = 3;
      else if (breakBeam == 1) {
        state = 2;
        t_not = millis();
      }

      break;

    case 2:  // Rolling forward, arm at 45;
      rollForward(duty);
      desPos = 400;
      if ((breakBeam == 0) && (millis() - t_not > 2000)) {
        state = 1;
      }
      break;

    case 3:  // Rolling backward, arm at 0
      desPos = 0;
      rollBackward(duty);
      if (button == 1) {
        state = 1;
      }
      break;
  }

  if (curPos < desPos) {
    PORTA &= 0b0;
    PORTA &= 0b01;
    delayMicroseconds(stepper_dt);
    PORTA |= 0b10;
    delayMicroseconds(stepper_dt);
    curPos++;

  } else if (curPos > desPos) {
    PORTA |= 0b1;
    PORTA &= 0b01;
    delayMicroseconds(stepper_dt);
    PORTA |= 0b10;
    delayMicroseconds(stepper_dt);
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