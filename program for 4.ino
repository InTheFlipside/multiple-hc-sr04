// Capteur 1
const byte TRIGGER_PIN = 2; // Broche TRIGGER
const byte ECHO_PIN = 3;    // Broche ECHO
// Capteur 2
const byte TRIGGER_PIN2 = 4; // Broche TRIGGER
const byte ECHO_PIN2 = 5;    // Broche ECHO
// Capteur 3
const byte TRIGGER_PIN3 = 6; // Broche TRIGGER
const byte ECHO_PIN3 = 7;    // Broche ECHO
// Capteur 4
const byte TRIGGER_PIN4 = 8; // Broche TRIGGER
const byte ECHO_PIN4 = 9;    // Broche ECHO

const byte timetostart = 10;

/// définition des constantes. Pas besoin de définir ça pour chacun (le timeout / vitesse du son ne change pas) 
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s
const float SOUND_SPEED = 340.0 / 1000;

void setup() {

  Serial.begin(115200);

   // on indique quelle pin sert à quoi pour chaque capteur
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); 
  pinMode(ECHO_PIN, INPUT);

  pinMode(TRIGGER_PIN2, OUTPUT);
  digitalWrite(TRIGGER_PIN2, LOW); 
  pinMode(ECHO_PIN2, INPUT);

    pinMode(TRIGGER_PIN3, OUTPUT);
  digitalWrite(TRIGGER_PIN3, LOW); 
  pinMode(ECHO_PIN3, INPUT);

    pinMode(TRIGGER_PIN4, OUTPUT);
  digitalWrite(TRIGGER_PIN4, LOW);
  pinMode(ECHO_PIN4, INPUT);
  
}
 
void loop() {



  ////////////// MESURE CAPTEUR 1 //////////
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);


  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
  float distance_mm = measure / 2.0 * SOUND_SPEED;
  
  Serial.print(F("Distance Capteur 1 : "));
  Serial.print(distance_mm);
  Serial.print (F("mm (")); // pas de "println" comme ça on met tout les capteurs sur la même ligne



  /////////////MESURE CAPTEUR 2 /////// 

 
  digitalWrite(TRIGGER_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN2, LOW);
  
  long measure2 = pulseIn(ECHO_PIN2, HIGH, MEASURE_TIMEOUT); //// Normalement, une fois que la mesure du capteur 1 est bonne, on devrait pouvoir réutiliser la variable "measure" et "distance_mm". mais c'est plus facile d'en faire une autre. puis ça aidera au debuggage
  float distance_mm2 = measure2 / 2.0 * SOUND_SPEED; 

  Serial.print(F("                Distance Capteur 2 : "));
  Serial.print(distance_mm2);
  Serial.print(F("mm (")); // Toujours pas de println. 


/////////////////MESURE CAPTEUR 3 /////////


  digitalWrite(TRIGGER_PIN3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN3, LOW);
  
  long measure3 = pulseIn(ECHO_PIN3, HIGH, MEASURE_TIMEOUT);
  float distance_mm3 = measure3 / 2.0 * SOUND_SPEED; 

  Serial.print(F("                Distance Capteur 3 : "));
  Serial.print(distance_mm3);
  Serial.print(F("mm (")); 


/////////////////MESURE CAPTEUR 4 /////////


  digitalWrite(TRIGGER_PIN4, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN4, LOW);
  
  long measure4 = pulseIn(ECHO_PIN4, HIGH, MEASURE_TIMEOUT);
  float distance_mm4 = measure4 / 2.0 * SOUND_SPEED; 

  Serial.print(F("                Distance Capteur 4 : "));
  Serial.print(distance_mm4);
  Serial.println(F("mm ("));  /// et là on met enfin le println





  delay(timetostart); // voir "timetostart" au début. permet de définir le nb de milliseconde avant que le programme se relance
  

  
}
