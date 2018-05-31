// Test envoi d'un fichier d'une carte SD vers un autre arduino
// Envoi de données
// VERSION FINALE NE PAS MODIFIER ICI (2)

 /**********************************************  
 // Transfert de données d'une carte arduino à une autre  
 ****************************************/  
 #include <SoftwareSerial.h>
 #include <SD.h>
 
 SoftwareSerial mySerial(2, 3); // RX, TX
 int test=0;
 int chipSelect = 4; //chip select pin for the microSD Card Adapter
 File file; // file object that is used to read and write data

 void setup() { //-- définition du port Série Logiciel
  Serial.begin(9600);
  mySerial.begin(9600); 
  if(!SD.begin(chipSelect)) { // initialize SD card
    Serial.println("Could not initialize SD card."); // if return value is false, something went wrong.
  }
  
  file = SD.open("file.txt", FILE_READ); // open "file.txt" to read data
  delay(10000);
 }  
 void loop() { //-- envoi d'un message une seule fois
  if (mySerial.available() and test==0){
    Serial.println("OK"); // vérifie que la comunnication est établie
    
    mySerial.write("--- Reading start2 ---\r\n");
    char character;
    while((character=file.read()) != -1) { // this while loop reads data stored in 'file.txt" and prints it to serial monitor
    delay(50);
    mySerial.write(character);
    }
    file.close();
    mySerial.write("--- Reading end ---\r\n");
    test = 1;
  }
  else if(test==0){
    mySerial.write("Could not open file (reading).\r\n");
   }
  
 //-- Attente de 2 secondes avant de recommencer
 delay(2000);  
 }  

