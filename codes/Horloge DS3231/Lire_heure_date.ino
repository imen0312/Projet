#include <RTClib.h>
#include <Wire.h>

RTC_DS1307 rtc; // La bibliothèque de la DS1307 fonctionne aussi avec la DS3231, pas de problème

char buf1[20];

void setup() {

  Serial.begin(9600);

  rtc.begin();

}

void loop() {
  DateTime now = rtc.now();

  sprintf(buf1, "%02d:%02d:%02d %02d/%02d/%02d", now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year());

  Serial.print(F("Date/Time: "));
  Serial.println(buf1);

  delay(1000);

}
