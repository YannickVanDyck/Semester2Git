int bediening;

void setup() {
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  bediening = Serial.read() - '0';   //de - '0' is voor ascii
  
  switch (bediening) {
    case 0:
      digitalWrite(13, HIGH);
      break;
    case 1:
      digitalWrite(13, LOW);
      break;
    case 2:
      digitalWrite(12, HIGH);
      break;
    case 3:
      digitalWrite(12, LOW);
      break;
    case 4:
      digitalWrite(11, HIGH);
      break;
    case 5:
      digitalWrite(11, LOW);
      break;
  }
}
