int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int delay1 = 0;
int podpin = A3;
void setup() {
  pinMode(podpin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
}

void loop() {
  delay1 = analogRead(podpin);
  digitalWrite(led1, HIGH);
  delay(delay1);
  
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(delay1);
  
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(delay1);
  
  digitalWrite(led3, LOW);
  digitalWrite(led4, HIGH);
  delay(delay1);
  
  digitalWrite(led4, LOW);
  digitalWrite(led5, HIGH);
  delay(delay1);
  
  digitalWrite(led5, LOW);
  digitalWrite(led4, HIGH);
  delay(delay1);
  
  digitalWrite(led4, LOW);
  digitalWrite(led3, HIGH);
  delay(delay1);
  
  digitalWrite(led3, LOW);
  digitalWrite(led2, HIGH);
  delay(delay1);
  
  digitalWrite(led2, LOW);
  delay(delay1);
}
