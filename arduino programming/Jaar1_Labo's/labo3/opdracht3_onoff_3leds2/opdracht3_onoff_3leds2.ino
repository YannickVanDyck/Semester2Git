int aan = 2;
int uit = 3;
int led1 = 4;
int led2 = 5;
int led3 = 6;
int counter = 0;
void setup() {
  pinMode(aan, INPUT);
  pinMode(uit, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(aan), ledaan, FALLING);
  attachInterrupt(digitalPinToInterrupt(uit), leduit, FALLING);
}

void ledaan(){
  switch (counter)
  {
    case 0:
      digitalWrite(led1, HIGH);
      counter += 1;
      break;
    case 1:
      digitalWrite(led2, HIGH);
      counter += 1;
      break;
    case 2:
      digitalWrite(led3, HIGH);
      counter += 1;
      break;
  }
}

void leduit(){
  switch (counter)
  {
    case 1:
      digitalWrite(led1, LOW);
      counter -= 1;
      break;
    case 2:
      digitalWrite(led2, LOW);
      counter -= 1;
      break;
    case 3:
      digitalWrite(led3, LOW);
      counter -= 1;
      break;
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
