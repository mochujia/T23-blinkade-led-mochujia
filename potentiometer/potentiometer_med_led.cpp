#include <Arduino.h>



#define PM 1
#define LED 2
int minDelay = 10;
int maxDelay = 1000;



void setup() {
// put your setup code here, to run once:
Serial.begin(115200);
Serial.println("Hello, ESP32-S2!");
pinMode(LED, OUTPUT);
pinMode(PM, INPUT);
analogReadResolution(12);
}

void loop() {
int sensorValue = analogRead(PM);
float blinkDelay = minDelay + ((maxDelay-minDelay) * sensorValue)/4095;
delay(blinkDelay);
digitalWrite(LED, HIGH);
Serial.println("Lampan tänds");
delay(blinkDelay);
digitalWrite(LED, LOW);


  
}
