import processing.serial.*;

Serial myPort;  
int val = 0;      

void setup() {
  size(800 , 600);                    //de grote van je window
  background(200);                    //verandert de achtergrond kleur
  ellipseMode(CENTER);                //zet de 1ste 2 parameters van ellipse() in het center van de vorm
  fill(255);                          //verandert de kleur in de cirkel
  ellipse( 400, 300, 200, 200);       //verandert de positie en de vorm van je cirkel
  textSize(12);                       //verandert de grote van de tekst
  fill(0);                            //verandert de kleur van de tekst
  textAlign(CENTER);                  //zet de text in het midden
  text("push a button", 400, 300);    //verandert de positie van de tekst
  

  val = Serial.list().length;         //geeft een array van alle mogelijke COM-poorten
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
    print(i + ": ");                  //zorgt voor de nummering van de COM poorten
    println(Serial.list()[i]);        //Schrijft de COM poorten met hun nummer achter
  }
  myPort = new Serial(this, Serial.list()[1], 9600);            //hier wordt geselecteerd welke poort er gebruikt wordt
  println("Seriële poort geselecteerd: " + Serial.list()[1]); 

} 

void draw () { 
  if ( myPort.available() > 0) {        
    val = myPort.read();                 
  }
  
  if( val == '1' ){                    //als er op de knop wordt gedrukt die op pin 2 is aangesloten zullen er 3 random cirkels op het scherm komen
    float x = random(800);
    float y = random(600);
    float r = random(50)+10;
    fill( random(255), random(255), random(255));
    ellipse( x, y, r, r);
    val = 0;
  }
  
  if( val == '2' ){                    //als er op de knop wordt gedrukt die op pin 3 is aangesloten zal het scherm gecleared worden
    background(200);
    val = 0;
  }
}
