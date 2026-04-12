#include <Servo.h>

#define PIN_LED_ROUGE 5
#define PIN_LED_VERTE 3

//Ultrasonic sensor
#define PIN_TRIG 6
#define PIN_ECHO 7
#define LIMITE_DETECTION 15

Servo servo;

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
  long distance;

  servo.write(0);
  distance = mesurerDistance();
  actionDistance(distance);
  delay(500);

  servo.write(45);
  distance = mesurerDistance();
  actionDistance(distance);
  delay(500);

  servo.write(90);
  distance = mesurerDistance();
  actionDistance(distance);
  delay(500);

  servo.write(45);
  distance = mesurerDistance();
  actionDistance(distance);
  delay(500);
}

long mesurerDistance() {
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  long duree = pulseIn(PIN_ECHO, HIGH);
  if (duree == 0) return; 

  return duree / 58; //conversion en centimetre
}

void actionDistance(long distance) {
  if(distance < LIMITE_DETECTION){
    digitalWrite(PIN_LED_VERTE, LOW);
    digitalWrite(PIN_LED_ROUGE, HIGH);
    delay(500);
    digitalWrite(PIN_LED_ROUGE, LOW);
  }
  else{
    digitalWrite(PIN_LED_VERTE, HIGH);
  }

}

