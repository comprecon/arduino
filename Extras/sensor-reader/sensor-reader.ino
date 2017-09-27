/**************************************
 Read a Sensor

 Make sure you know how much power the
 sensor needs in order to function.

 Sensor should be connected to ground
 and appropriate power, and its signal
 should be connected to an analog input
 
**************************************/

int ledPin = LED_BUILTIN; // same as pin 13

int sensorPin = A0;     // analog pin because reading a range of numbers
int sensorValue = 0;    // variable for reading the sensor

void setup() {
  
  // set digital pin as output
  pinMode(ledPin, OUTPUT);

  // start serial communications at 9600 baud
  Serial.begin(9600);
  
}

void loop() {
  // main program goes here
  
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);      // print out the value
  delay(50);
  // visual indicator
//  digitalWrite(ledPin, HIGH);       // turn the ledPin on
//  delay(sensorValue);                 // stop the program for <knobValue> ms
//  sensorValue = analogRead(sensorPin);
//  digitalWrite(ledPin, LOW);        // turn the ledPin off
//  delay(sensorValue);                 // stop the program for <knobValue> ms

}
