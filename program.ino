
const byte TRIGGER_PIN = 2; // Broche TRIGGER
const byte ECHO_PIN = 3;    // Broche ECHO
const byte TRIGGER_PIN2 = 4; // Broche TRIGGER
const byte ECHO_PIN2 = 5;    // Broche ECHO
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s
const float SOUND_SPEED = 340.0 / 1000;

void setup() {

  Serial.begin(115200);
   
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(ECHO_PIN, INPUT);



    pinMode(TRIGGER_PIN2, OUTPUT);
  digitalWrite(TRIGGER_PIN2, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(ECHO_PIN2, INPUT);
}
 
void loop() {
  
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);


  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
  float distance_mm = measure / 2.0 * SOUND_SPEED;
  
  Serial.print(F("Distance Capteur 1 : "));
  Serial.print(distance_mm);
  Serial.print (F("mm ("));



///////////////////////////////////////////////////////////////////////////////////// 


 
  digitalWrite(TRIGGER_PIN2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN2, LOW);
  
  long measure2 = pulseIn(ECHO_PIN2, HIGH, MEASURE_TIMEOUT);
  float distance_mm2 = measure2 / 2.0 * SOUND_SPEED;

  Serial.print(F("Distance Capteur 2 : "));
  Serial.print(distance_mm2);
  Serial.println(F("mm ("));

  delay(10);
}
