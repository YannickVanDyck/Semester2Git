#include <EEPROM.h>

int num_array[10][7] = {  { 1,1,1,1,1,1,0 },    // 0
                          { 0,1,1,0,0,0,0 },    // 1
                          { 1,1,0,1,1,0,1 },    // 2
                          { 1,1,1,1,0,0,1 },    // 3
                          { 0,1,1,0,0,1,1 },    // 4
                          { 1,0,1,1,0,1,1 },    // 5
                          { 1,0,1,1,1,1,1 },    // 6
                          { 1,1,1,0,0,0,0 },    // 7
                          { 1,1,1,1,1,1,1 },    // 8
                          { 1,1,1,0,0,1,1 }};   // 9

void setup() {
  Serial.begin(9600);
  for (int i = 2; i < 9; i++)
  {
    pinMode(i, OUTPUT);
  }

}

void loop() {
  if (Serial.available() > 0)
  {
    byte data = Serial.read();
    data -= '0';
    
    if (data <= 9 && data >=0)
    {
      for (int i = 0; i < 7; i++) //zorgt ervoor dat er over elke pin van de display gegaan wordt
      {
        digitalWrite(i+2 ,num_array[data][i]); //data zorgt ervoor dat je de juiste rij selecteert (0 of 1 of 2 enzovoort)
        // i+2 zorgt ervoor dat de i overeen komt met je pinnen op het breadbord
      }
    }
  }

}
