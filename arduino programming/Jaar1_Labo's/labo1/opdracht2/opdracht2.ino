int aan = 2;
int uit = 3;
int led = 4;
void setup() {
  // put your setup code here, to run once:
  pinMode ( aan, INPUT );
  pinMode ( uit, INPUT );
  pinMode ( led, OUTPUT );
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(aan)) {
    digitalWrite( led, HIGH );
  }
  else if (digitalRead(uit)) {
    digitalWrite( led, LOW );
  }
}
