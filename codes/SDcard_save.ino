#include <SD.h>

const int geophone = 9;
int chipSelect = 4; //chip select pin for the microSD Card Adapter
File fich; // file object that is used to read and write data

void setup() {
  Serial.begin(9600); // start serial connection to print our debug messages and data
  pinMode(chipSelect, OUTPUT); // chip select pin must be set to OUTPUT mode
  if(!SD.begin(chipSelect)) { // initialize SD card
    Serial.println("Could not initialize SD card."); // if return value is false, something went wrong.
  }

}

void loop() {
  fich = SD.open("fich.txt", FILE_WRITE); // open "fich.txt" to write data

  if(fich) {
    fich.println(analogRead(geophone)/204.8); // write geophone's values to file
    fich.close(); // close file
    Serial.print("Wrote value:"); // debug output: show written number in serial monitor
    Serial.println(analogRead(geophone)/204.8);
  } else {
    Serial.println("Could not open fich (writing).");
  }
//
//  fich = SD.open("fich.txt", FILE_READ); // open "fich.txt" to read data
//
//  if(fich) {
//    Serial.println("--- Reading start ---");
//    char character;
//    while((character=file.read()) != -1) { // this while loop reads data stored in 'file.txt" and prints it to serial monitor
//      Serial.print(character);
//    }
//    file.close();
//    Serial.println("--- Reading end ---");
//  } else {
//    Serial.println("Could not open file (reading).");
//  }
//  delay(5000); // wait for 5000ms

}
