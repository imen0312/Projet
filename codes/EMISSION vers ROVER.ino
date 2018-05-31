#include <SD.h>
#include <SPI.h>
#include <RTClib.h>
#include <Wire.h>

 #include <SoftwareSerial.h>

//pour l'horloge
RTC_DS1307 rtc;
char buf1[20];//affichage
SoftwareSerial mySerial(3, 2); // RX, TX 
const int geophone = A0;

int chipSelect = 4; //chip select pin for the microSD Card Adapter
float sensorValue;
float value;
File fich; // fich object that is used to read and write data
float valueMin=2.90;
long time=0;


void setup() {

  Serial.begin(9600); // start serial connection to print our debug messages and data
  mySerial.begin(9600); 
  rtc.begin();
  pinMode(chipSelect, OUTPUT); // chip select pin must be set to OUTPUT mode
  while (!SD.begin(chipSelect)) { // initialize SD card

    Serial.println("Could not initialize SD card."); // if return value is false, something went wrong.
    delay(1000);
  }
  //fich =SD.open("fich10.txt", FILE_WRITE); // open "fich.txt" to write data
}
void loop(){
  value=analogRead(geophone);
  sensorValue=value*5/1023;
  fich =SD.open("test11.txt", FILE_WRITE); // open "fich.txt" to write data
  if (fich){
    Serial.println("fich open");
    if(sensorValue <=valueMin){
      Serial.println("Valeur minimale atteinte");
      time=millis();
      //DateTime now = rtc.now();
      //sprintf(buf1, "%02d:%02d:%02d %02d/%02d/%02d", now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year());
      //fich.print(F("Date/Time:  "));
      //fich.println(buf1); //enregistre l'heure actuelle
       
      while((millis()-time)<10000.00){
        fich.print(analogRead(geophone)*(5.0/1023.0)); // write geophone's values to fich
        delay(10);
        fich.println("$");
        sensorValue=(analogRead(geophone)*(5.0/1023.0));
        Serial.print("Wrote value:"); // debug output: show written number in serial monitor
        Serial.println(sensorValue);
      }
      Serial.println("End");
    }
    fich.close(); // close fich
    delay(50);
    envoyer(); //envoit du fichier
    
   
  }    
  else {
    Serial.print("Could not open fich (writing).");

  }
}
void envoyer() {
  
  fich =SD.open("test11.txt", FILE_WRITE); // open "fich.txt" to write data
  delay(1000);
  if (mySerial.available() ){

    Serial.println("OK"); // vérifie que la comunnication est établie
   

    mySerial.write("--- Reading start ---\r\n");

   char character;

    while((character=fich.read()) != -1) { // this while loop reads data stored in 'fich.txt" and prints it to serial monitor

    delay(500);

    mySerial.write(character);

    }

    fich.close();

    mySerial.write("--- Reading end ---\r\n");


  }

  else {//if(test==0){

    Serial.write("Could not open fich (reading).\r\n");

   }
  delay(2000);
}
