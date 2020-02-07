int aan = 2;
int uit = 3;
int led = 4;
void setup() {
  pinMode(aan, INPUT);
  pinMode(uit, INPUT);
  pinMode(led, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(aan), ledaan, FALLING);
  attachInterrupt(digitalPinToInterrupt(uit), leduit, FALLING);
}

void ledaan(){
  digitalWrite(led, HIGH);
}

void leduit(){
  digitalWrite(led, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

}
