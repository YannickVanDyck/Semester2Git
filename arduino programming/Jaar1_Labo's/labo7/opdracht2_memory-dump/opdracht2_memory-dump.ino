char *pointer = 0x0100;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
}

void loop() {
  for (; pointer < 0x08FF; pointer++)
  //pointer zal steeds met 1 geheugenplaats ophogen zolang hij kleiner is als 0x08FF
  {
    if (int(pointer) % 16 == 0)    //% zorgt ervoor dat ja weet wnr het 0 is
    {
      Serial.println("");
      Serial.print(int(pointer));
      Serial.print(" ");
    }
    else
    {
      Serial.print(*pointer);
      Serial.print(" ");
    }
  }
}
