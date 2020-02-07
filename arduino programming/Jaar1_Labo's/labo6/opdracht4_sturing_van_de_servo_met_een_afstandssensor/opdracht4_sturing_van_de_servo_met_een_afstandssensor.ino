#include <NewPing.h>
#include <Servo.h>

NewPing sonar(sensorTrig, sensorEcho);      //Creëert een object genaamt sonar met "sensorTrig" als trigger output met "sensorEcho" als echo input
Servo myServo;                              //De servo noemt nu "myServo"

void setup() {
  Serial.begin(9600);
  myServo.attach(6);                        //De servo is verbonden met pin 6
}

void loop() {
  int cm = sonar.ping_cm();
  val = map(cm, 0, 1023, 0, 179);           //Schaalt de waarde cm naar een waarde tussen 0 en 180 voor de servo
  mijnServo.write(val);                     //Servo gaat naar positie val
  delay(15);                                //Geeft de servo tijd om te reageren
}
