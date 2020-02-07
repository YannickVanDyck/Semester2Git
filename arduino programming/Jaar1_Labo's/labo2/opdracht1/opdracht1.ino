int pin = 2;
int interneled = 13;
void setup() {
  pinMode(pin, INPUT);
  pinMode(interneled, OUTPUT);
}

void loop() {
  if (digitalRead(pin)) {
    digitalWrite(interneled, HIGH);
  }
  else {
    digitalWrite(interneled, LOW);
  }
}
