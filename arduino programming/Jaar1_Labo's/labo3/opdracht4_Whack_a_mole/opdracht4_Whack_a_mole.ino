int shot = 2;
int start = 3;
int led1 = A0;
int led2 = A1;
int led3 = A2;
int led4 = A3;
int led5 = A4;
int led6 = A5;
int getal = 0;
int led = 0;

void setup() {
  Serial.begin(9600);
  pinMode(shot, INPUT);
  pinMode(start, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
}

void raakled() {
  if (digitalRead(shot)) {
    getal = random(1,6);
    Serial.println(getal);
  }
}

void loop() {
      led = random(1,6);
      digitalWrite(led, HIGH);
      delay(2000);
      digitalWrite(led, LOW);
      led = 0;
    }
  }
}
