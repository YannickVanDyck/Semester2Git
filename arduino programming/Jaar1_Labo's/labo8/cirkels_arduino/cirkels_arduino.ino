void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

void loop() {
  if (digitalRead(2) == HIGH)
  {
    Serial.write('1');
    delay(50);
  }
  else if (digitalRead(3) == HIGH)
  {
    Serial.write('2');
    while(digitalRead(3) == HIGH);
    delay(100);
  }
}
