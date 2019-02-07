const byte TRIGGER_PIN1 = 2; // Broche TRIGGER
const byte ECHO_PIN1 = 3;    // Broche ECHO

const byte TRIGGER_PIN2 = 2; // Broche TRIGGER
const byte ECHO_PIN2 = 3;    // Broche ECHO

const byte TRIGGER_PIN3 = 2; // Broche TRIGGER
const byte ECHO_PIN3 = 3;    // Broche ECHO

const byte TRIGGER_PIN4 = 2; // Broche TRIGGER
const byte ECHO_PIN4 = 3;    // Broche ECHO

const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s

const float SOUND_SPEED = 340.0 / 1000;

int verif1;
int verif2;
int verif3;
int verif4;

void setup() {

  Serial.begin(9600);
   
  pinMode(TRIGGER_PIN1, OUTPUT);
  digitalWrite(TRIGGER_PIN1, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(ECHO_PIN1, INPUT);
}
 
void loop() {

  if(verif > 3) { verif=0;  }


  
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
  float distance_mm = measure / 2.0 * SOUND_SPEED;
  Serial.print(F("Distance Capteur 1 : "));
  Serial.print(distance_mm);
  Serial.print ("mm (");

if(distance_mm < 100) {
  Serial.println(distance_mm);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
  float distance_mm1 = measure / 2.0 * SOUND_SPEED;
   Serial.println(distance_mm);
if(distance_mm < 100) {verif++;}


if(verif>3) {Serial.println("MESURE OK !");}

Serial.println(verif);
// delay(2000);

  delay(10);
}



}
