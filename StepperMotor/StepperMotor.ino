int dt = 60;
int state = 1;
int desPos = 0;

int stepper_dt = 30;
int curPos = 0;
int max_step = 1600; // 90 degrees
void setup() {

  DDRB = 255;
  PORTB = 0b10;
}

void loop() {
  // put your main code here, to run repeatedly:

  switch(state){
    case 1: 
    desPos = max_step;
    if (curPos == max_step){
      state = 2;
      delay(1000);
    }
    break;
    case 2: 
    desPos = 0;
    if (curPos == 0){
      state = 1;
      delay(1000);
    }
    break;

  }


  if (curPos < desPos) {
    PORTB = 0b1;
    driveStepper();
    curPos++;

  } else if (curPos > desPos) {
    PORTB = 0b10;
    driveStepper();
    curPos--;
  }

}

void driveStepper(void){
  PORTB &= 0b01;
    delayMicroseconds(stepper_dt);
    PORTB |= 0b10;
    delayMicroseconds(stepper_dt);
}
