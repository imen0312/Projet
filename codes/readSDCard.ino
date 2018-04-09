#include <SD.h>

int chipSelect = 4; //chip select pin for the microSD Card Adapter
File file; // file object that is used to read and write data

void setup() {
  Serial.begin(9600); // start serial connection to print our debug messages and data
  pinMode(chipSelect, OUTPUT); // chip select pin must be set to OUTPUT mode
  if(!SD.begin(chipSelect)) { // initialize SD card
    Serial.println("Could not initialize SD card."); // if return value is false, something went wrong.
  }

  file = SD.open("file.txt", FILE_READ); // open "file.txt" to read data

  if(file) {
    Serial.println("--- Reading start ---");
    char character;
    while((character=file.read()) != -1) { // this while loop reads data stored in 'file.txt" and prints it to serial monitor
      Serial.print(character);
    }
    file.close();
    Serial.println("--- Reading end ---");
  } else {
    Serial.println("Could not open file (reading).");
  }


//  file = SD.open("file.txt", FILE_WRITE); 
//  file = SD.open("file.txt", FILE_READ);
//  Serial.println(file.read());
//  file.close();
}

void loop() {

}
