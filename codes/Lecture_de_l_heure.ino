// Example sketch for interfacing with the DS1302 timekeeping chip.
//
// Copyright (c) 2009, Matt Sparks
// All rights reserved.
//
// http://quadpoint.org/projects/arduino-ds1302
lectureHeure(){
#include <stdio.h>
#include <DS1302.h>

namespace {

// Set the appropriate digital I/O pin connections. These are the pin
// assignments for the Arduino as well for as the DS1302 chip. See the DS1302
// datasheet:
//
//   http://datasheets.maximintegrated.com/en/ds/DS1302.pdf
const int kCePin   = 5;  // Chip Enable
const int kIoPin   = 6;  // Input/Output
const int kSclkPin = 7;  // Serial Clock

int heure = 0;
int minutes = 0;
int secondes = 0;

// Create a DS1302 object.
DS1302 rtc(kCePin, kIoPin, kSclkPin);
}  // namespace

void setup() {
  Serial.begin(9600);
}

// Loop and print the time every second.
void loop() {
Time X = rtc.time();
heure = X.hr;
minutes = X.min;
secondes = X.sec;
  
Serial.print("heure : ");
Serial.println(heure);

Serial.print("minutes : ");
Serial.println(minutes);

Serial.print("secondes : ");
Serial.println(secondes);

Serial.println(" ");

}
}
