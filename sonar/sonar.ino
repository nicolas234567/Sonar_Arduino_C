#include <Servo.h>

#define PIN_LED_ROUGE 5
#define PIN_LED_VERTE 3

//Ultrasonic sensor
#define PIN_TRIG 6
#define PIN_ECHO 7
#define LIMITE_DETECTION 15

Servo servo;

//definition globale
int angle = 0;
int direction = 1;
long distance;
unsigned long previousMillis = 0;
const int interval = 50;

void setup() {
  // put your setup code here, to run once:
  servo.attach(9); // on définit le Pin utilisé par le servomoteur
  pinMode(PIN_LED_ROUGE, OUTPUT);
  pinMode(PIN_LED_VERTE, OUTPUT);
  Serial.begin(115200);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentMillis = millis();

  // Mouvement du servo
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    servo.write(angle);
    angle += direction;

    // changement de sens
    if (angle >= 90 || angle <= 0) {
      direction *= -1; 
    }
  }

  //mesure et gestion des led
  long distance = mesurerDistance();
  actionDistance(distance);
}

long mesurerDistance() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  long duree = pulseIn(PIN_ECHO, HIGH);
  if (duree == 0) return -1; 

  return duree / 58; //conversion en centimetre
}

void actionDistance(long distance) {
  //erreur si distance invalide
  if(distance == -1){
    Serial.println("Erreur mesure");
    return;
  }

  //gestion des led
  if(distance < LIMITE_DETECTION){
    digitalWrite(PIN_LED_VERTE, LOW);
    digitalWrite(PIN_LED_ROUGE, HIGH);
  }
  else{
    digitalWrite(PIN_LED_VERTE, HIGH);
    digitalWrite(PIN_LED_ROUGE, LOW);
  }

}

