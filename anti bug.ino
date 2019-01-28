const byte TRIGGER_PIN = 2; // Broche TRIGGER
const byte ECHO_PIN = 3;    // Broche ECHO
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s
const float SOUND_SPEED = 340.0 / 1000;
int verif;

void setup() {

  Serial.begin(9600);
   
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(ECHO_PIN, INPUT);
}
 
void loop() {

  if(verif > 3) { verif=0;  }
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
  float distance_mm = measure / 2.0 * SOUND_SPEED;

  
  ///////////////////////////////////////////////////////////// MESURE DISTANCE ////////////////////////////
  Serial.print(F("Distance Capteur 1 : "));
  Serial.print(distance_mm);
  Serial.println ("mm (");


  
//Serial.println("DEBUT DES VALIDATIONS");
// delay(2000);

if(distance_mm < 100) {
 // Serial.print("Une validation !! Mesure actuelle : ");
  Serial.println(distance_mm);
// delay(5000);

  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
  float distance_mm = measure / 2.0 * SOUND_SPEED;
  

 // Serial.print("Deuxieme validation en verification.. ! Mesure actuelle : ");
  Serial.println(distance_mm);
 // delay(3000);

  
if(distance_mm < 100) { 
  verif++;  
//Serial.print("On augmente Verif:");
// Serial.println(verif);
}


if(verif>3) {Serial.println("The mesure is good and valable !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");}

Serial.println(verif);
// delay(2000);

  delay(10);
}



}
