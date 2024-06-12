#include "HCSR04.h"
#include "Buzzer.h"

Buzzer buzzer(12);

byte triggerPin = 11;
byte echoPin = 10;

const byte R = 5;
const byte G = 4;
const byte B = 3;

void setup() {
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  HCSR04.begin(triggerPin, echoPin);
  buzzer.begin(0);
}

void loop() {
  double* cm = HCSR04.measureDistanceCm();
  int time = 300;

  if (cm[0] > 0 && cm[0] <= 100) {
	  green();
    digitalWrite(9, HIGH);
    digitalWrite(8, HIGH);
    distanteApaga();
  }

  else if (cm[0] > 100 && cm[0] <= 200) {
	  blue();
    distante();
    proximo();
  }

  else if (cm[0] > 200 && cm[0] <= 300) {
	  red();
    proximoApaga();
    distante();
    buzzer.sound(NOTE_C5, time / 2);
    buzzer.end(100);
    buzzer.sound(NOTE_C5, time / 2);
    buzzer.end(100);
    buzzer.sound(NOTE_C5, time / 2);
    buzzer.end(100);
  }

  else {
    apagar();
    proximoApaga();
    digitalWrite(7, HIGH);
    digitalWrite(6, HIGH);
  }
}

void green() {
  analogWrite(R, 0);
  analogWrite(G, 255);
  analogWrite(B, 0);
}

void blue() {
  analogWrite(R, 0);
  analogWrite(G, 0);
  analogWrite(B, 255);
}  

void red() {
  analogWrite(R, 255);
  analogWrite(G, 0);
  analogWrite(B, 0);
}

void apagar() {
  analogWrite(R, 0);
  analogWrite(G, 0);
  analogWrite(B, 0);
}

void proximo() {
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  delay(300);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  delay(300);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  delay(300);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  delay(300);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
  delay(300);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  delay(300);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);
}

void proximoApaga() {
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
}

void distante() {
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  delay(300);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  delay(300);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  delay(300);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  delay(300);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
  delay(300);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  delay(300);
  digitalWrite(7, HIGH);
  digitalWrite(6, HIGH);
}

void distanteApaga() {
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
}