void setup() {
  Serial.begin(9600);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available() > 0)
  {
    char buff[3];
    Serial.readBytesUntil('\n', buff, 3);     //3 zorgt ervoor dat alleen de 1ste 3 tekens in buff komen te staan

    if (buff[0] == 'r' && buff[1] == '=')     //het 1ste karakter in de array moet r zijn en de 2de moet = zijn
    {
      int waarde = buff[2]-'0';               //waarde krijgt de waarde van het 3de karakter van de array buff, 0 zorgt ervoor dat de char naar een int wordt omgezet
      digitalWrite(11, waarde);               //led op pin 11 krijgt de waarde van waarde
    }

    else if (buff[0] == 'g' && buff[1] == '=')
    {
      int waarde = buff[2]-'0';
      digitalWrite(12, waarde);
    }

    else if (buff[0] == 'b' && buff[1] == '=')
    {
      int waarde = buff[2]-'0';
      digitalWrite(13, waarde);
    }
  }
}
