#include <EEPROM.h>
                          
void setup() {
  Serial.begin(9600);
  for (int i = 2; i < 13; i++)
  {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 4; i++)
  {
    switch (i)
    {
      case 0:
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(12, HIGH);
        break;

      case 1:
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        digitalWrite(12, HIGH);
        break;

      case 2:
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(11, LOW);
        digitalWrite(12, HIGH);
        break;

      case 3:
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(12, LOW);
        break;
    }
    
    for (int j = 2; j < 9; j++)
    {
    digitalWrite(j, HIGH);
    delay(500);
    }
  }

  for (int i = 0; i < 4; i++)
  {
    switch (i)
    {
      case 0:
        digitalWrite(9, LOW);
        digitalWrite(10, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(12, HIGH);
        break;

      case 1:
        digitalWrite(9, HIGH);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        digitalWrite(12, HIGH);
        break;

      case 2:
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, HIGH);
        digitalWrite(12, LOW);
        break;

      case 3:
        digitalWrite(9, HIGH);
        digitalWrite(10, HIGH);
        digitalWrite(11, HIGH);
        digitalWrite(12, LOW);
        break;
      }
    
    for (int j = 2; j < 9; j++)
    {
    digitalWrite(j, LOW);
    delay(500);
    }
  }

}
