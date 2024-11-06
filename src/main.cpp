
#include <Arduino.h>


#define A0 1


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32-S2!");
  analogReadResolution(12);
}

void loop() {

  float sensorValue = analogRead(A0);
  float voltage = sensorValue * (3.3/4095);
  Serial.println(voltage);
  // put your main code here, to run repeatedly:
  delay(10); // this speeds up the simulation
}