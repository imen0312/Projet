// test envoi d'un fichier d'une carte SD vers un autre arduino
// update : OK ça marche!
// Envoi de données
// VERSION FINALE NE PAS MODIFIER ICI

 /**********************************************  
 // Transfert de données d'une carte arduino à une autre  
 // Ce sketch envoie le message Hello à une carte connectée  
 // via le port série logiciel  
 // Branchements :  
 // * RX connecté sur pin 10 (connecté à TX sur l'autre carte)  
 // * TX connecté sur pin 11 (connect à RX sur l'autre carte)  
 // * Et ne pas oublier de relier les masses des 2 cartes (GND)  
 // Remarque :  
 // Sur la MEGA utilisez uniquement pour RX:   
 // 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69  
 // Sur la Leonardo utilisez uniquement pour RX:  
 // 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).  
 ****************************************/  
 #include <SoftwareSerial.h>
 #include <SD.h>
 
 //int led = 13;  
 SoftwareSerial mySerial(2, 3); // RX, TX (inversé)
 int test=0;
 int chipSelect = 4; //chip select pin for the microSD Card Adapter
 File file; // file object that is used to read and write data

 void setup() { //-- définition du port Série Logiciel
  Serial.begin(9600);
  mySerial.begin(9600); 
  pinMode(chipSelect, OUTPUT); // chip select pin must be set to OUTPUT mode
  if(!SD.begin(chipSelect)) { // initialize SD card
    Serial.println("Could not initialize SD card."); // if return value is false, something went wrong.
  }
  
  file = SD.open("FICH3.txt", FILE_READ); // open "fic1.txt" to read data
  delay(10000);
 }  
 void loop() { //-- Toutes les secondes envoi d'un message  
  if (mySerial.available() and test==0){
    Serial.println("OK"); // vérifie que la comunnication est établie
    //digitalWrite(led, HIGH); //-- Pendant l'envoi allume la LED
    
    mySerial.write("--- Reading start2 ---\r\n");
    char character;
    while((character=file.read()) != -1) { // this while loop reads data stored in 'file.txt" and prints it to serial monitor
    delay(200);
    mySerial.write(character);
    //Serial.setTimeout(1000);
    }
    file.close();
    mySerial.write("--- Reading end ---\r\n");
    test = 1;
  }
  else if(test==0){
    mySerial.write("Could not open file (reading).\r\n");
   }
  
  //digitalWrite(led, LOW);  
 //-- Attente de 2 secondes avant de recommencer
 delay(2000);  
 }  

