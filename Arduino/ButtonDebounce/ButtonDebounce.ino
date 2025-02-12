int switch1Value, switch1OldValue;
int count = 0;

void setup() {
  // put your setup code here, to run once:
  DDRC = 0;
  PORTC = 0xFF;
  switch1OldValue = PINC & 0b1;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  switch1Value = PINC & 0b1;

  if ((switch1OldValue == 1) && (switch1Value == 0)) {
    count++;
  }

  switch1OldValue = switch1Value;
  Serial.println(count);
}
