int trig = 2;
int echo = 3;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig, LOW);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long tijd = pulseIn(echo, HIGH);
  int s = tijd * (0.034/2);
  if (s > 2 && s < 400)
  {
    Serial.print(s);
    Serial.println("cm");
    delay(100);
  }
  else
  {
    Serial.println("ERROR!!!");
  }
  
}
