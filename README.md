# Arduino Sonar avec Servo et Capteur Ultrason

## Présentation
Ce projet consiste à simuler un système de type sonar à l’aide d’un Arduino, d’un servomoteur et d’un capteur ultrason HC-SR04.

Le système effectue un balayage et détecte les objets dans son champ. Selon la distance mesurée, des LEDs indiquent la présence ou non d’un obstacle.

---

## Matériel utilisé
- Arduino Uno
- Capteur ultrason HC-SR04
- Servomoteur SG90
- LED rouge
- LED verte
- Résistances
- Breadboard + câbles

---

## Fonctionnement
- Le servomoteur effectue un balayage de 0° à 90° en continu
- Le capteur mesure la distance en temps réel
- Si un objet est détecté à moins de 15 cm :
  - 🔴 LED rouge ON
- Sinon :
  - 🟢 LED verte ON

---

##  Schéma de câblage


![Schéma](images/schema.png)

---

## Démonstration


![Demo](videos/demo.mp4)

---

## Code
Le code se trouve dans le dossier `/sonar`.

