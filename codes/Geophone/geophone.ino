float sensorPin = A0; // select the input pin for the potentiometer
float sensorValue = 0; // variable to store the value coming from the sensor
 
void setup () 
{
  Serial.begin (9600);
}
 
void loop () 
{
  sensorValue = analogRead (A0);
   Serial.print("$");
  Serial.print(sensorValue*5/1023);//sending data in Volts
  Serial.print(";");
  Serial.println (" ");
}
