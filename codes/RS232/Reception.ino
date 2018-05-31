//Réception

 /**************  
 // Réception de données via le port Série Logiciel   
 ***************/  
 //-- Déclaration du port Série Logiciel  
 #include <SoftwareSerial.h>  
 SoftwareSerial mySerial(2, 3); // RX, TX  
 
 //-- Setup  
 void setup() {          
  //-- Ouverture du port Série de la carte pour le moniteur  
  Serial.begin(9600);  
  while (!Serial) {;} 
  Serial.println("Attente réception !");  
  //-- Définition et ouverture du port logiciel  
  mySerial.begin(9600);   
 }  
 //-- Affichage de la communication  
 void loop() {  
  //-- Si des données sont présentes  
  if (mySerial.available())  
   {//-- Affichage sur la console des données  
    Serial.write(mySerial.read());}  
 }  
