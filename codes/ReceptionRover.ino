//Réception ok avec la class Valeur
/**************

  // Réception de données via le port Série Logiciel :
  // Attention les câbles RX et TX doivent être croisés
***************/

//-- Déclaration du port Série Logiciel

#include <SoftwareSerial.h>
#include <SD.h>


SoftwareSerial mySerial(2, 3); // RX, TX
class Valeur {
  private:
    String nombre;
    bool loading; // permet de savoir si le nombre peut s'afficher

  public:
    void Ecrire(); // Ecrit le caractére
    void Afiche(); // Affiche le nombre temporaire
    void Refresh(); // Réinisialise le nombre temporaire
    int Test();     // Test si le nombre est lisible ou non
    String Retour();// Retourne le nombre
};



void Valeur::Ecrire() {
  char charactere;
  charactere = mySerial.read(); // enregistre le caractère arrivant
  if (charactere == '$') { // caractére de fin du nombre
    loading = 0;
  }
  else {             //j'enregistre la valeur arrivante du nombre
      nombre = String(nombre + charactere);
  }
};

void Valeur::Afiche() {
  Serial.println(nombre);
};

int Valeur::Test() {
  return loading;
};



void Valeur::Refresh() {
  nombre = "";
  loading = 1;
}

String Valeur::Retour() {
  return nombre;
}
Valeur bon;

//-- Setup
int chipSelect = 4; //chip select pin for the microSD Card Adapter
char code[5];
byte i;// variable pour les données
int test = 0; // variable pour la demande d'info
int led = 10;
File fich; // file object that is used to read and write data


void setup() {
  pinMode(chipSelect, OUTPUT);

  //-- Ouverture du port Série de la carte pour le moniteur
  Serial.begin(9600);

  //Serial.println("Attente réception !");

  //-- Définition et ouverture du port logiciel
  mySerial.begin(9600);
  delay(2000);

  while (!SD.begin(chipSelect)) { // initialize SD card

    Serial.println("Could not initialize SD card."); // if return value is false, something went wrong.
    delay(1000);

  }
}

//-- Affichage de la communication

void loop() {

  //-- Affichage sur la console des données
  //digitalWrite(led, HIGH);
  fich = SD.open("FICH6.txt", FILE_WRITE);
  if (fich) {
    Serial.println("fich open");
    //Serial.setTimeout(2000);
    //delay(2);
    char charactere = mySerial.read();
    delay(2);
    if (mySerial.available() > 0) {

     while (mySerial.available()  and bon.Test() == 1) {

      bon.Ecrire();
      }
    }
    String code=bon.Retour();
    fich.print(code);
    Serial.print(code);
    fich.close();
    bon.Refresh();
  }
  else {
    Serial.print("Could not open fich (writing).");
  }
  delay(300);
}
