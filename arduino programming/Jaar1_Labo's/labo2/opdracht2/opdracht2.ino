int button = 2;
int externeled = 13;
bool stand = LOW;
void setup() {
  pinMode(button, INPUT);
  pinMode(externeled, OUTPUT);
}

void loop() {
  if (digitalRead(button) && stand == HIGH) {
    digitalWrite(externeled, LOW);
    stand = LOW;
    delay(500);
  }
  else if (digitalRead(button) && stand == LOW) {
    digitalWrite(externeled, HIGH);
    stand = HIGH;
    delay(500);
  }
}
