#include <EEPROM.h>

const uint8_t ldrsen[] = {A0,A1,A2,A3,A4,A5,A6};

const int buzzerPin = 7;

int value[7];
const int tono[] = {261, 293, 329, 349, 392, 440, 493};

void setup() {
  Serial.begin(9600);
  
  for(int i = 0; i < 7; i++){
      pinMode(ldrsen[i], INPUT);
  }
  
  pinMode(buzzerPin, OUTPUT);
}


 
void loop() {
  
  for(int i = 0; i < 7; i++){
      value[i] = analogRead(ldrsen[i])/4;
  }
  
  for(int i = 0; i < 7; i++){
    if(value[i] < 150){
      tone(buzzerPin, tono[i], 100);
    }
  }  
}

