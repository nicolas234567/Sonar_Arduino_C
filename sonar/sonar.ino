#include <Servo.h>

#define PIN_LED_ROUGE 5
#define PIN_LED_VERTE 3
Servo servo;

void setup() {
  // put your setup code here, to run once:
  servo.attach(9); // on définit le Pin utilisé par le servomoteur
  pinMode(PIN_LED_ROUGE, OUTPUT);
  pinMode(PIN_LED_VERTE, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  servo.write(0);
  delay(500);
  servo.write(45);
  delay(500);
  servo.write(90);
  delay(500);
  servo.write(45);
  delay(500);
}
