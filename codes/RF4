Carte Arduino 1

void setup()  {
  Serial.begin(9600);
}

void loop() {
  Serial.print('A');
  delay(250);
  Serial.print('B');
  delay(250);
}

Carte Arduino 2
#define LED 13

void setup()  {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()>0){
    if(Serial.read() == 'A')
      digitalWrite(LED, 1);
    else
      digitalWrite(LED, 0);
  }
}
