import processing.serial.*;

Serial myPort;  
int val = 0;  
boolean overButtonR = false;
boolean overButtonG = false;
boolean overButtonB = false;
boolean overButtonRoff = false;
boolean overButtonGoff = false;
boolean overButtonBoff = false;

void setup() {
  size(190 , 150);
  textAlign(CENTER);
  background(200);
  
  fill(255,0,0);
  rect(10,10,50,50); 
  fill(0,255,0);
  rect(70,10,50,50); 
  fill(0,0,255);
  rect(130,10,50,50); 
  
  fill(0);
  stroke(255, 0, 0);
  rect(10,70,50,50); 
  stroke(0,255,0);    //kleurcode stond fout
  rect(70,70,50,50); 
  stroke(0,0,255);    //kleurcode stond fout
  rect(130,70,50,50); 
  
val = Serial.list().length;
  if(val == 0){
    println("Geen seriële poorten gevonden");
    exit();
    return;
  }else if(val > 1){
    println("Meer dan 1 seriële poort gevonden.");
  }
  println("Seriële poorten gedetecteerd: ");
  for(int i=0; i<val; i++)
  {
    print(i + ": ");
    println(Serial.list()[i]);
  }
  myPort = new Serial(this, Serial.list()[0], 9600);
  println("Seriële poort geselecteerd: " + Serial.list()[0]);  

} 

void mousePressed() {
  if (overButtonR) { 
    myPort.write("r=1\n");
  }
  if (overButtonG) { 
    myPort.write("g=1\n");
  }
  if (overButtonB) { 
    myPort.write("b=1\n");    
  }
  if (overButtonRoff) { 
    myPort.write("r=0\n");
  }
  if (overButtonGoff) { 
    myPort.write("g=0\n");
  }
  if (overButtonBoff) { 
    myPort.write("b=0\n");    
  }
  
}

void draw() {

}

void mouseMoved() { 
  checkButtons(); 
}
  
void mouseDragged() {
  checkButtons(); 
}

void checkButtons() {
  print(mouseX);
  print(" ");
  println(mouseY);

  if (mouseX > 10 && mouseX < 60 && mouseY > 10 && mouseY < 60) {
    overButtonR = true;   
    text("  Rood aan  ",95,140);
  } else {
    overButtonR = false;
  }
  if (mouseX > 70 && mouseX < 120 && mouseY > 10 && mouseY < 60) {
    overButtonG = true;   
    text("  Groen aan  ",95,140);
  } else {
    overButtonG = false;
  }
  if (mouseX > 130 && mouseX < 180 && mouseY > 10 && mouseY < 60) {
    overButtonB = true;   
    text("  Blauw aan  ",95,140);
  } else {
    overButtonB = false;
  }
  
  if (mouseX > 10 && mouseX < 60 && mouseY > 70 && mouseY < 120) {
    overButtonRoff = true;   
    text("  Rood uit  ",95,140);
  } else {
    overButtonRoff = false;
  }
  if (mouseX > 70 && mouseX < 120 && mouseY > 70 && mouseY < 120) {
    overButtonGoff = true;   
    text("  Groen uit  ",95,140);
  } else {
    overButtonGoff = false;
  }
  if (mouseX > 130 && mouseX < 180 && mouseY > 70 && mouseY < 120) {
    overButtonBoff = true;   
    text("  Blauw uit  ",95,140);
  } else {
    overButtonBoff = false;
  }
  
  if(!(overButtonR || overButtonG || overButtonB || overButtonRoff || overButtonGoff || overButtonBoff)){  //zorgt ervoor dat als je niet meer over 1 v/d buttons hovert dat het tekstje weg gaat
    fill(200);
    noStroke();
    rect(60,130,70,20);
    stroke(0);
    fill(0);
  }
}
