#include <Arduino.h>
 


#define PM 1
#define LED 2
unsigned long minDelay = 10;
unsigned long maxDelay = 1000;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32-S2!");
  pinMode(LED, OUTPUT);
  pinMode(PM, INPUT);
  analogReadResolution(12);
}

void loop() {
  unsigned long sensorValue = analogRead(PM);
  unsigned long blinkDelay = minDelay + ((maxDelay-minDelay) * sensorValue)/4095;
  delay(blinkDelay);
  digitalWrite(LED, HIGH);
  Serial.println("Lampan tänds");
  delay(200);
  digitalWrite(LED, LOW);


  
}
