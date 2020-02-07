int A = 2;
int B = 3;
int count = 0;                // preset de count op 0
int c = LOW;                  // preset de status van pin A op LOW
int cLast = LOW;              // maak de laaste waar van A hetzelfde
int d = LOW;                  // preset de status van pin B op LOW

void setup() {
  pinMode(A, INPUT);
  pinMode(B, INPUT);
  Serial.begin(9600);         // serial debugging
  attachInterrupt(digitalPinToInterrupt(2), richting, CHANGE);
}

void richting() {
  d = c^d;                    // bepalen van de draairichting met een XOR poort
}

void loop() {
  c = digitalRead(A);         // lees pin A als int A
  d = digitalRead(B);         // lees pin B als int B

  if (c != cLast) {           // als int A van waarde veranderd doen we hetvolgende
    if (d) {
      count --;               // als pin B geen 0 is, is het tegen de klok in
    }
    else {
      count++;                // als pin B 0 is, is het klokgewijs
    }
    Serial.println(count);
    cLast = c;                // opslaan van de huidige status van A voor de volgende passage
  }
}
