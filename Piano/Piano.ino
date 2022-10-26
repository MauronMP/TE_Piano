#include <EEPROM.h>
const int ldrsen = A0;
const int ldrsen_1 = A1;
const int buzzerPin = 7;
int value = 0;
int value_1 = 0; 

void setup() {
  delay(2000);
  Serial.begin(9600);
  pinMode(ldrsen, INPUT);
  pinMode(ldrsen_1, INPUT);
  pinMode(7, OUTPUT);
  Serial.println("Now testing the Photoresistor, Make sure it is connected to the Pin A0");
  delay(2000);
  Serial.println("Starting the test now!");   
   
   rerun:
  value = analogRead(ldrsen) /4;
  value_1 = analogRead(ldrsen_1) /4;
  
  if(value >1){
    Serial.print("The Photoresistor is connected and here are some value: ");
    delay(200);
    Serial.println(value); 
    delay(200);
    Serial.println(value); 
    delay(200); 
    Serial.println(value);    
  }
    else{
      value = analogRead(ldrsen)/4 ;
        if(value<0)
          Serial.println("Hmm the Photoresistor is not connected");
          Serial.println("Retrying in 5s");
          delay(5000);
          goto rerun;
        }
          Serial.println("======END======");
}


 //*************************LOOP*******************


 
void loop() {
  value = analogRead(ldrsen)/4;
  value_1 = analogRead(ldrsen_1)/4;
  delay(50);
  if(value>150){
      Serial.println("Muxa lu");
  } else {
    Serial.println("Poca lu");
    tone(7, 523, 100); //C
  }

  if(value_1 > 150){
      Serial.println("Muxa lu");
  } else {
    Serial.println("Poca lu");
    tone(7, 587, 100); //D
  }  
}

