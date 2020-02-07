#include <NewPing.h>

int trig = 2;
int echo = 3;
NewPing sonar(trig, echo, 400);

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);
}

void loop() {
  int cm = sonar.ping_cm(400);
  if (cm > 2 && cm < 400)
  {
    Serial.print(cm);
    Serial.println("cm");
    delay(100);
  }
  else
  {
    Serial.println("ERROR!!!");
  }
  
}
