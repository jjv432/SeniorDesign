% Connect P+ to pin 22
int stepper_dt = 1000;

void setup() {

  DDRA = 255;
}

void loop() {
  // put your main code here, to run repeatedly:

driveStepper();

}

void driveStepper(void){
  PORTA = 1;
    delayMicroseconds(stepper_dt);
    PORTA = 0;
    delayMicroseconds(stepper_dt);
}
