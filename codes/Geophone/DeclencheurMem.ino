#include <SD.h>
#include <SPI.h>




const int geophone = A0;

int chipSelect = 4; //chip select pin for the microSD Card Adapter
float sensorValue;
float value;
File fich; // file object that is used to read and write data
float valueMin=2.90;
long time=0;


void setup() {

  Serial.begin(9600); // start serial connection to print our debug messages and data

  pinMode(chipSelect, OUTPUT); // chip select pin must be set to OUTPUT mode


  while (!SD.begin(chipSelect)) { // initialize SD card

    Serial.println("Could not initialize SD card."); // if return value is false, something went wrong.
    delay(1000);

  }



}



void loop(){
  value=analogRead(geophone);
  sensorValue=value*5/1023;
  Serial.print(sensorValue);
  fich =SD.open("fich.txt", FILE_WRITE); // open "fich.txt" to write data
  if (fich){
    Serial.println("fich open");
    if(sensorValue <=valueMin){
      Serial.println("Valeur minimale atteinte");
      time=millis();
      while((millis()-time)<60000.00){
        fich.println(analogRead(geophone)*(5.0/1023.0)); // write geophone's values to file
        sensorValue=(analogRead(geophone)*(5.0/1023.0));
        Serial.print("Wrote value:"); // debug output: show written number in serial monitor
        Serial.println(sensorValue);
      }
      Serial.println("End");
    }
    fich.close(); // close file
  }
    
  else {

    Serial.print("Could not open fich (writing).");

  }


}
