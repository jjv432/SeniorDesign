// Stepper variables
int stepper_dt = 6;
int curPos = 0;
int desPos = 0;
int max_step = 800; // 90 degrees

// Breakbeam variables
float breakBeamVal = 0;
bool breakBeam = 0;
const int beamTol = 500; // tolerance to switch between broken and not broken

// Button variables
int button_delay = 100;
int switch1Value, switch1OldValue;
bool button = 1;

// Logic variables
int state = 1;
int t = 0;
int duty, prevState;
int t_not;


void setup() {

  pwm_init();
  DDRB = 255;
  DDRA = 255;
  PORTB = 0b1;
  Serial.begin(9600);

  DDRD = 0;
  PORTD = 0xFF;
  switch1OldValue = PIND & 0b1;

  duty = 255; // motor speed
}

void loop() {

  // Tracking Changing Button Values
  switch1Value = PIND & 0b1;

  if ((switch1OldValue == 1) && (switch1Value == 0)) {
    button = !button;
    delay(button_delay);
  } else if ((switch1OldValue == 0) && (switch1Value == 1)) {
    delay(button_delay);
  }

  switch1OldValue = switch1Value;

  // Reading value from the break beam
  breakBeamVal = analogRead(A0);

  if (breakBeamVal >= beamTol) {
    breakBeam = 1;
  } else if (breakBeam < beamTol) {
    breakBeam = 0;
  }

  // Main switch to determine system behavior
  switch (state) {

    case 1:  // Rolling forward, arm at 0
      desPos = 0;
      rollForward(duty);
      if (button == 0)
        state = 3;
      else if (breakBeam == 1) {
        state = 2;
        t_not = millis(); // this is a guard for state 2
      }

      break;

    case 2:  // Rolling forward, arm at 45;
      rollForward(duty);
      desPos = max_step;
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

  // Code to make the stepper motor move to the desired positions
  if (curPos < desPos) {
    PORTB &= 0b0;
    PORTB &= 0b01;
    delayMicroseconds(stepper_dt);
    PORTB |= 0b10;
    delayMicroseconds(stepper_dt);
    curPos++;

  } else if (curPos > desPos) {
    PORTB |= 0b1;
    PORTB &= 0b01;
    delayMicroseconds(stepper_dt);
    PORTB |= 0b10;
    delayMicroseconds(stepper_dt);
    curPos--;
  }
}

// This function enables PWM
void pwm_init(void) {
  DDRL = 255;
  TCCR5A = _BV(COM5A1) | _BV(COM5B1) | _BV(WGM52) | _BV(WGM50);
  TCCR5B = _BV(CS51) | _BV(CS50);
  OCR5A = 0;
  OCR5B = 0;
}

// This moves the conveyor belt forward
void rollForward(int duty) {
  OCR5A = duty;
  PORTA = 0b10;
}

// This moves the conveyor belt backward
void rollBackward(int duty) {
  OCR5A = duty;
  PORTA = 0b1;
}

// This stops the conveyor belt
void stopRolling() {
  OCR5A = 0;
  PORTA = 0;
}