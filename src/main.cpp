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

const int lista_med_led[4] = {LED2, LED3, LED4, LED5}; //Sätter alla led lampor i en constant array

void loop() {
  for (int i = 0; i < 4; i++){ //for loop

  if (i == 0){ 
    digitalWrite(LED5, LOW); //man kan inte ta -1 så den stänger av den sista lampan
  }
  else{
    digitalWrite(lista_med_led[i - 1], LOW); //stänger av den förra lampan
  }

  digitalWrite(lista_med_led[i], HIGH); //sätter på lampan

  delay(1000);
  

}
  

}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}


