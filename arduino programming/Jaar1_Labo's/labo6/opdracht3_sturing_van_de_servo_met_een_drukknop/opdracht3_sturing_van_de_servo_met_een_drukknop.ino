#include <Servo.h>
Servo mijnServo;        // de servo noemt nu mijnservo
int potpin = 0;         // de potentiometer is verbonden met analoge pin 0
int val;                // val is de waarde van pin 0


void setup() {
  mijnServo.attach(9);  // de servo is verbonden met pin 9
}

void loop() {
  val = analogRead(potpin);           // lees de waarde van pin 0 ( dit is tussen 0 en 1023)
  val = map(val, 0, 1023, 0, 179);    // schaal de waarde van pin 0 om naar een waarde tussen 0 en 180
  mijnServo.write(val);               // servo gaat naar positie val
  delay(15);                          // geeft de servo tijd om te reageren
}
