byte var1 = 1;
int var2 = 2;
char var3 = 'a';
float var4 = 4;

byte *p1;
int *p2;
char *p3;
float *p4;

void setup() {
  Serial.begin(9600);
  p1 = &var1;    // 'p' bevat nu het adres van 'var1'
  p2 = &var2;
  p3 = &var3;
  p4 = &var4;

  Serial.println("byte:");
  Serial.println(int(p1));    //weergeeft het adres van p1
  Serial.println(*p1);        //weergeeft de inhoud van p1
  Serial.println("");

  Serial.println("int:");
  Serial.println(int(p2));
  Serial.println(*p2);
  Serial.println("");

  Serial.println("char:");
  Serial.println(int(p3));
  Serial.println(*p3);
  Serial.println("");

  Serial.println("float:");
  Serial.println(int(p4));
  Serial.println(*p4);
}

void loop() {
  // put your main code here, to run repeatedly:

}
