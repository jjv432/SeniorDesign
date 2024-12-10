// Stepper variables
int stepper_dt = 30;
int curPos = 0;
int desPos = 0;
int max_step = 1200;  // 90 degrees

// Breakbeam variables
float breakBeamVal = 0;
bool breakBeam = 0;
const int beamTol = 900;  // tolerance to switch between broken and not broken

// Button variables
int button_delay = 100;
int switch1Value, switch1OldValue;
bool button = 1;

// Logic variables
int state = 1;
int t = 0;
int duty, prevState;
int t_not = 0;
int t_not2 = 0;


void setup() {

  pwm_init();
  DDRB = 255;
  DDRA = 255;
  Serial.begin(9600);

  DDRD = 0;
  PORTD = 0xFF;
  switch1OldValue = PIND & 0b1;

  duty = 127;  // motor speed
  delay(1500);
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
  // Serial.println(breakBeamVal);


  if (breakBeamVal >= beamTol) {
    breakBeam = 1;
  } else if (breakBeam < beamTol) {
    breakBeam = 0;
  }

  // Main switch to determine system behavior
  switch (state) {

    case 1:  // Rolling forward, arm at 0
      rollForward(duty);
      if (breakBeam == 0 && (millis() - t_not > 500))
        state = 3;
      else if (breakBeam == 1) {
        t_not2 = millis();
        state = 5;
      } else if (button == 0){
        state = 4;
        desPos = 0;
      }

      break;

    case 2:  // Rolling forward, arm at 45;'
      desPos = max_step;
      stopRolling();
      if (curPos == desPos) {
        state = 1;
        t_not = millis();
      } else if (button == 0){
        state = 4;
        desPos = 0;
      }
      break;

    case 3:  // Rolling backward, arm at 0
      desPos = 0;
      stopRolling();
      if (curPos == desPos) {
        state = 1;
        t_not = millis();
      } else if (button == 0){
        state = 4;
        desPos = 0;
      }
      break;

    case 4:
      rollBackward(duty);
      if (button == 1)
        state = 1;
      break;

    case 5:
      rollForward(duty);
      if (millis() - t_not2 > 700)
        state = 2;
      else if (button == 0){
        state = 4;
        desPos = 0;
      }

      break;
  }
  // Serial.println(state);
  // Code to make the stepper motor move to the desired positions
  if (curPos < desPos) {
    PORTB = 0b10;
    driveStepper();
    curPos++;

  } else if (curPos > desPos) {
    PORTB = 0b1;
    driveStepper();
    curPos--;
  }
}

void driveStepper(void) {
  PORTB &= 0b01;
  delayMicroseconds(stepper_dt);
  PORTB |= 0b10;
  delayMicroseconds(stepper_dt);
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
  PORTA = 0b1;
}

// This moves the conveyor belt backward
void rollBackward(int duty) {
  OCR5A = duty;
  PORTA = 0b10;
}

// This stops the conveyor belt
void stopRolling() {
  OCR5A = 0;
  PORTA = 0;
}