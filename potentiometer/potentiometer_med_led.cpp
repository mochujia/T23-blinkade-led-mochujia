#include <Arduino.h>
 
#define A0 1
#define LED 2



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32-S2!");
  pinMode(LED, OUTPUT);
}

void loop() {
  unsigned long sensorValue = analogRead(A0) / 2;
  
  delay(sensorValue);
  digitalWrite(LED, HIGH);
  Serial.println("Lampan tänds");
  delay(200);
  digitalWrite(LED, LOW);


  
}
