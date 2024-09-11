#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);

#define LED2 2 // Definierar att pin 2 ska kallas LED
#define LED3 3
#define LED4 4
#define LED5 5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // Fixar med uppladdningshastighet
  pinMode(LED2, OUTPUT); // Sätter pin 2 till output
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LED5, LOW); // Stänger av den sista lampan och sätter på den första
  digitalWrite(LED2, HIGH); // digital = hög eller låg, hög = lLED:en lyser
  Serial.println("LED2 is on"); // syns i terminalen, kan användas som felsökning
  delay(1000);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, HIGH);
  Serial.println("LED3 is on");
  delay(1000);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, HIGH);
  Serial.println("LED4 is on");
  delay(1000);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, HIGH);
  Serial.println("LED5 is on");
  delay(1000);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}