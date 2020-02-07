int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 7;
int led5 = 6;
int waarde = 0;
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
  //5V = 1023(11 1111 1111 binair)
  
  waarde = analogRead(podpin);

  if (waarde < 10){
    digitalWrite(led1,LOW);
  }
  else if(waarde < 205){        // 1024 delen door 5 krijg je 205
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  else if(waarde < 410){
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  }
  else if(waarde < 615){
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  }
  else if(waarde < 820){
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
  }
  else if(waarde > 820){
    digitalWrite(led5, HIGH);
  }
}
