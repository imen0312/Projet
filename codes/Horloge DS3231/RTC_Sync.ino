// code à exécuter qu'UNE seule fois pour synchroniser les horloges avec l'heure du PC

#include <RTClib.h>
#include <Wire.h>

RTC_DS1307 rtc; // fonctionne avec la bibliothèque de la DS1307 car la DS3231 et la DS1307 utilisent toutes les deux une communication I2C

char buf1[20];

void setup() {
  Serial.begin(9600);
  Wire.begin();

  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
  
}

void loop() {
  DateTime now = rtc.now();

  sprintf(buf1, "%02d:%02d:%02d %02d/%02d/%02d", now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year());

  Serial.print(F("Date/Time: "));
  Serial.println(buf1);

  delay(1000);
}
