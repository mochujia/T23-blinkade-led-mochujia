


#include <Arduino.h>


const int BUTTON = 1;
const int LED = 2;
const int DEBOUNCE_DELAY = 50;

enum BUTTON_STATE {
  UP,
  PRESSED,
  DOWN,
  RELEASED
};

enum LED_STATE {
  LED_ON,
  LED_OFF,
  LED_BLINK
};


int lastBUTTON_STATE = HIGH;

BUTTON_STATE buttonRead() {

  int reading = digitalRead(BUTTON);


  if (reading != lastBUTTON_STATE) {
    delay(DEBOUNCE_DELAY);
    reading = digitalRead(BUTTON);

    if (reading != lastBUTTON_STATE) {
      lastBUTTON_STATE = digitalRead(BUTTON);

      if (reading == LOW) {
        return PRESSED;
      }

      else {
        return RELEASED;
      }

    }
  }


  if (lastBUTTON_STATE == LOW) {
    return DOWN;
  }

  if (reading == HIGH) {
    return UP;
  }






}










void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32-S2!");
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
}

LED_STATE state = LED_OFF;

unsigned long LED_DEBOUNCE = 200;
unsigned LAST_LED_DEBOUNCE = millis();
int LED_STATE2 = HIGH;

void loop() {
  BUTTON_STATE button_state = buttonRead();

  switch (state) {

    case LED_OFF: 
    if (button_state == PRESSED) {
      digitalWrite(LED, HIGH);
      state = LED_ON;
      break;
    }

    case LED_ON:
    if (button_state == PRESSED) {
      state = LED_BLINK;
      break;
    }

    case LED_BLINK:
    if (button_state == PRESSED) {
      digitalWrite(LED, LOW);
      state = LED_OFF;
      break;
    }
  }

  if (state == LED_BLINK && button_state != PRESSED) {
    if (millis() - LAST_LED_DEBOUNCE >= LED_DEBOUNCE) {
      LED_STATE2 = !LED_STATE2;
      LAST_LED_DEBOUNCE = millis();
      digitalWrite(LED, LED_STATE2);
    }
  }









  // put your main code here, to run repeatedly:
  delay(10); // this speeds up the simulation
}
  













  


