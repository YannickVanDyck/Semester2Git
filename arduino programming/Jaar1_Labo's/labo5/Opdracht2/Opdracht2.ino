#include <EEPROM.h>

// strart het lezen vanaf de eerste byte (address 0) van de EEPROM
int adres = 0;
byte value;
void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
      // zodat de void loop niet van te voren al begint
  }

  // lees een byte uit van het huidige adres van de EEPROM
  value = EEPROM.read(adres);

  // standaard value is altijd 0, nu gaan we deze +1 doen
  value++;

  // schrijven van de value naar het adres 0
  EEPROM.write(adres, value);

  // weergeven van de value in de seriële monitor
  Serial.println(value);
}

void loop() {
  
}
