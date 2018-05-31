//Envoi de données

 /**********************************************  
 // Transfert de données d'une carte arduino à une autre  
 // Ce sketch envoie le message Hello à une carte connectée  
 // via le port série logiciel  
 // Branchements :  
 // * RX connecté sur pin 3 (connecté à TX sur l'autre carte)  
 // * TX connecté sur pin 2 (connect à RX sur l'autre carte)  
 // * Et ne pas oublier de relier les masses des 2 cartes (GND)  
 ****************************************/  
 #include <SoftwareSerial.h>   
 SoftwareSerial mySerial(10, 11); // RX, TX  
 void setup()   
 { //-- définition du port Série Logiciel
  Serial.begin(9600);
  mySerial.begin(9600);    
 }  
 void loop() { //-- Toutes les 2 secondes envoi d'un message 
 if (mySerial.available())  { 
  mySerial.write("Hello");  
  }  
  digitalWrite(led, LOW);  
  delay(2000); //-- Attente de 2 secondes avant de recommencer  
 }  
