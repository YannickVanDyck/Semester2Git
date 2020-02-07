#include <NewPing.h>
#include <Servo.h>
#include <LiquidCrystal.h>


int rotaryA = 2;
int sensorTrig = 3;
int rotaryB = 4;
int sensorEcho = 5;
int servo = 6;
int lcdPin14 = 7;
int lcdPin13 = 8;
int lcdPin12 = 9;
int lcdPin11 = 10;
int lcdPin6 = 11;
int lcdPin4 = 12;
int button = 13;
int ledDistance1 = A0;
int ledDistance2 = A1;
int ledDistance3 = A2;
int ledDistance4 = A3;
int ledDistance5 = A4;
int led6 = A5;
int count = 0;          //Preset count op 0
volatile int c = LOW;            //Preset de status van pin A op LOW
int cLastMin = 0;
int cLastMax = 0;
volatile int d = LOW;            //Preset de status van pin B op LOW
int menu = 8;
bool B = LOW;
int valueLed1;
int valueLed2;
int valueLed3;
int valueLed4;
int valueLed5;
volatile bool rotaryChange = LOW;
bool meting = LOW;
int hoek = 90;
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
NewPing sonar(sensorTrig, sensorEcho);      //Creëert een object genaamt sonar met "sensorTrig" als trigger output met "sensorEcho" als echo input
Servo myServo;                              //De servo noemt nu "myServo"

void setup() {
  //pinMode
  pinMode(rotaryA, INPUT);
  pinMode(sensorEcho, INPUT);
  pinMode(rotaryB , INPUT);
  pinMode(sensorTrig , OUTPUT);
  pinMode(servo , OUTPUT);
  pinMode(button , INPUT);
  pinMode(ledDistance1 , OUTPUT);
  pinMode(ledDistance2 , OUTPUT);
  pinMode(ledDistance3 , OUTPUT);
  pinMode(ledDistance4 , OUTPUT);
  pinMode(ledDistance5 , OUTPUT);
  pinMode(led6 , OUTPUT);

  myServo.attach(6);      //De servo is verbonden met pin 6

  lcd.begin(16, 2);               // set up the LCD's number of columns and rows:

  attachInterrupt(digitalPinToInterrupt(rotaryA), richting, RISING);
}

void richting() {
  B = digitalRead(rotaryB);
  rotaryChange = HIGH;
}

void loop() {
  //Menu structuur:
  lcd.clear();                  //maakt het lcd-scherm leeg
  lcd.setCursor(0, 0);          //set de cursor

  c = digitalRead(rotaryA);
  d = digitalRead(rotaryB);

  if (rotaryChange == HIGH) {       //als er aan de rotary gedraaid wordt zal deze code uitgevoerd worden
    if (B == HIGH) {                //als pin B 1 is, is het tegen de klok in
      if (meting == HIGH) {         //door de waarde meting kan er een verschil worden gemaakt tussen het scrollen in het menu en tussen het aanpassen van een waarde
        count --;                   //hiermee zal een waarde worden aangepast
      }
      else {
        menu --;                    //hiermee zal het menu veranderen
      }
    }
    else if (B == LOW) {            //als pin B 0 is, is het klokgewijs
      if (meting == HIGH) {
        count++;
      }
      else {
        menu ++;
      }
    }
    rotaryChange = LOW;             //rotaryChange wordt 'LOW' gezet omdat deze code anders constant wordt uitgevoerd
  }



  switch (menu) {
    case 0:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(">Afstand meten");      // print a message to the LCD.
      lcd.setCursor(0, 1);              // set the cursor to column 0, line 1
      lcd.print(" Hoeken meten");
      if (digitalRead(button)) {
        menu = 2;
        digitalWrite(led6, HIGH);
      }
      break;

    case 1:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" Afstand meten");     // print a message to the LCD.
      lcd.setCursor(0, 1);            // set the cursor to column 0, line 1
      lcd.print(">Hoeken meten");
      if (digitalRead(button)) {
        menu = 7;
        digitalWrite(led6, LOW);
      }
      break;

    case 2:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(">Minimum meetwaarde instellen");
      lcd.setCursor(0, 1);
      lcd.print(" Maximum meetwaarde instellen");
      if (digitalRead(button)) {
        menu = 10;
        meting = HIGH;
      }
      break;

    case 3:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(">Maximum meetwaarde instellen");
      lcd.setCursor(0, 1);
      lcd.print(" Verdeling led's");
      if (digitalRead(button)) {
        menu = 11;
        meting = HIGH;
      }
      break;

    case 4:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(">Verdeling led's");
      lcd.setCursor(0, 1);
      lcd.print(" Meten activeren");
      if (digitalRead(button)) {
        menu = 12;
      }
      break;

    case 5:
      lcd.print(">Meten activeren");
      lcd.setCursor(0, 1);
      lcd.print(" Terug naar het hoofdmenu");
      if (digitalRead(button)) {
        menu = 13;
      }
      break;

    case 6:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" Meten activeren");
      lcd.setCursor(0, 1);
      lcd.print(">Terug naar het hoofdmenu");
      if (digitalRead(button)) {
        menu = 0;
        digitalWrite(led6, LOW);
      }
      break;

    case 7:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(">Instellen hoek");
      lcd.setCursor(0, 1);
      lcd.print(" Hoek activeren");
      if (digitalRead(button)) {
        menu = 14;
        meting = HIGH;
      }
      break;

    case 8:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(">Hoek activeren");
      lcd.setCursor(0, 1);
      lcd.print(" Terug naar hoofdmenu");
      if (digitalRead(button)) {
        menu = 15;
      }
      break;

    case 9:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(" Hoek activeren");
      lcd.setCursor(0, 1);
      lcd.print(">Terug naar hoofdmenu");
      if (digitalRead(button)) {
        menu = 0;
      }
      break;

    case 10:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Minwaarde:");
      cLastMin = cLastMin + count;
      lcd.print(cLastMin);
      if (digitalRead(button)) {
        meting = LOW;
        menu = 2;
      }
      break;

    case 11:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Maxwaarde:");
      cLastMax = cLastMax + count;
      lcd.print(cLastMax);

      int verschilMinMax = cLastMax - cLastMin;
      int valuePerLed = verschilMinMax / 5;
      valueLed1 = cLastMin;
      valueLed2 = valueLed1 + valuePerLed;
      valueLed3 = valueLed2 + valuePerLed;
      valueLed4 = valueLed3 + valuePerLed;
      valueLed5 = valueLed4 + valuePerLed;

      if (digitalRead(button)) {
        if (cLastMax < cLastMin) {
          meting = LOW;
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("ERROR! Min is");
          lcd.setCursor(0, 1);
          lcd.print("groter dan Max");
          delay(5000);
          menu = 3;
        }
        else {
        meting = LOW;
        menu = 3;
        }
      }
      break;

    case 12:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("L1:");
      lcd.print(valueLed1);

      lcd.print(" L2:");
      lcd.print(valueLed2);

      lcd.print(" L3:");
      lcd.print(valueLed3);

      lcd.setCursor(0, 1);
      lcd.print("L4:");
      lcd.print(valueLed4);

      lcd.print(" L5:");
      lcd.print(valueLed5);

      if (digitalRead(button)) {
        menu = 4;
      }
      break;

    case 13:
      int cm = sonar.ping_cm();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Afstand:");
      lcd.print(cm);
      delayMicroseconds(5);

      if (cm > valueLed1 && cm < valueLed2) {
        digitalWrite(ledDistance1, HIGH);
        digitalWrite(ledDistance2, LOW);
        digitalWrite(ledDistance3, LOW);
        digitalWrite(ledDistance4, LOW);
        digitalWrite(ledDistance5, LOW);
      }
      else if (cm > valueLed2 && cm < valueLed3) {
        digitalWrite(ledDistance1, HIGH);
        digitalWrite(ledDistance2, HIGH);
        digitalWrite(ledDistance3, LOW);
        digitalWrite(ledDistance4, LOW);
        digitalWrite(ledDistance5, LOW);
      }
      else if (cm > valueLed3 && cm < valueLed4) {
        digitalWrite(ledDistance1, HIGH);
        digitalWrite(ledDistance2, HIGH);
        digitalWrite(ledDistance3, HIGH);
        digitalWrite(ledDistance4, LOW);
        digitalWrite(ledDistance5, LOW);
      }
      else if (cm > valueLed4 && cm < valueLed5) {
        digitalWrite(ledDistance1, HIGH);
        digitalWrite(ledDistance2, HIGH);
        digitalWrite(ledDistance3, HIGH);
        digitalWrite(ledDistance4, HIGH);
        digitalWrite(ledDistance5, LOW);;
      }
      else if (cm > valueLed5) {
        digitalWrite(ledDistance1, HIGH);
        digitalWrite(ledDistance2, HIGH);
        digitalWrite(ledDistance3, HIGH);
        digitalWrite(ledDistance4, HIGH);
        digitalWrite(ledDistance5, HIGH);
      }

      if (digitalRead(button)) {
        menu = 5;
      }
      break;

    case 14:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Hoek:");
      hoek = hoek + count;
      lcd.print(hoek);
      if (digitalRead(button)) {
        meting = LOW;
        menu = 7;
      }
      break;

    case 15:
      myServo.write(hoek);                  //Servo gaat naar de ingestelde hoek
      delay(15);                          //Geeft de servo tijd om te reageren
      if (digitalRead(button)) {
        menu = 8;
      }
  }
}
