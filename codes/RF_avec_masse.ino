//Envoi de données

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
 int led = 13;  
 SoftwareSerial mySerial(10, 11); // RX, TX  
 void setup()   
 { //-- définition du port Série Logiciel
  Serial.begin(9600);
  mySerial.begin(9600);   
  pinMode(led, OUTPUT);  
 }  
 void loop() //-- Toutes les 2 secondes envoi d'un message  
 {if (mySerial.available())  
  {digitalWrite(led, HIGH); //-- Pendant l'envoi allume la LED  
  mySerial.write("Hello");  
  }  
  digitalWrite(led, LOW);  
  delay(2000); //-- Attente de 2 secondes avant de recommencer  
 }  

//Réception

 /**************  
 // Réception de données via le port Série Logiciel :  
 // Testé avec une NANO 328   
 // Attention les câbles RX et TX doivent être croisés   
 // Ne pas oublier de relier les masses des 2 cartes (GND)  
 // entre la carte émitrice et la carte réceptrice !  
 ***************/  
 //-- Déclaration du port Série Logiciel  
 #include <SoftwareSerial.h>  
 SoftwareSerial mySerial(10, 11); // RX, TX  
 //-- Mise en fonction de la LED lorsqu'un message est reçu  
 int led = 13;  
 //-- Setup  
 void setup() {          
  //-- Initialisation de la LED  
  pinMode(led, OUTPUT);  
  //-- Ouverture du port Série de la carte pour le moniteur  
  Serial.begin(9600);  
  while (!Serial) {;} //-- Pour Leonaro nécessaire  
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
// Remarque : Avant 1.0.x Serial.flush() vidait le buffer entrant, depuis 1.0.x Serial.flush() vide le buffer sortant. Application : pour envoyer via le port Série des données et écouter en même temps si il y a des données en réception :
