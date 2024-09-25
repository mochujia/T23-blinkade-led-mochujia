#include <Arduino.h>

// put function declarations here:
int myFunction(int, int);
void blinkande_led_lamp_funktion(int antal_ganger_loop_har_korts);

#define LED2 2 // Definierar att pin 2 ska kallas LED
#define LED3 3
#define LED4 4
#define LED5 5

void setup() {
  delay(1000);
  // put your setup code here, to run once:
  Serial.begin(115200); // Fixar med uppladdningshastighet
  pinMode(LED2, OUTPUT); // Sätter pin 2 till output
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  
}
int antal_ganger_loop_har_korts = 0;
const int lista_med_led[4] = {LED2, LED3, LED4, LED5}; //Sätter alla led lampor i en constant array




void blinkande_led_lamp_funktion() {

  if (antal_ganger_loop_har_korts == 0){
    digitalWrite(LED5, LOW);

  }
  else{
    digitalWrite(lista_med_led[antal_ganger_loop_har_korts - 1], LOW); //stänger av den förra lampan

  }
  
  

  digitalWrite(lista_med_led[antal_ganger_loop_har_korts], HIGH); //sätter på lampan

  delay(1000);
  

 
}











void loop() {
  blinkande_led_lamp_funktion(antal_ganger_loop_har_korts);

  if (antal_ganger_loop_har_korts == 3){
    antal_ganger_loop_har_korts = 0;
  }

  else{
    antal_ganger_loop_har_korts += 1;

  }

  
  
  
  

}
  



// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}


