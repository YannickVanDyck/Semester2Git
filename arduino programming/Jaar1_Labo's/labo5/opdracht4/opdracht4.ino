#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.println("Geef een getal tussen 0 en 1023");
}

void loop() {
  int trimmer = analogRead(A0);
  Serial.println(trimmer);

  if (Serial.available() > 0)
  {
    int input = Serial.parseInt();
    Serial.println(input);
    
    if ( input < trimmer )
    {
      digitalWrite(5, LOW);
      digitalWrite(4, HIGH);
    }
  
    if ( input > trimmer )
    {
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
    }
  }
  delay(2000);
}
