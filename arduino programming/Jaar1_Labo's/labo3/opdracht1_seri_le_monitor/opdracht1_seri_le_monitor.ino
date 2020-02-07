int analog = A3;
int voltage = 0;
int aantal = 0;
void setup() {
  pinMode(analog, INPUT);
  Serial.begin(9600);
}

void loop() {
  voltage = analogRead(analog);
  aantal = ceil(voltage/20.5); //ceil zorgt ervoor dat de uitkomst naar boven wordt afgerond.
  //20.5 want 5V komt in analogRead overeen met 1023. 5/0.1 = 50 dus 1023/50 = 20.5
  Serial.print("0");
  for ( byte t=0; t < aantal; t++ )
  {
    Serial.print("+");
  }
  Serial.println("");
}
