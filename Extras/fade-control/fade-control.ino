int ledPin = 10; // use a PWM pin

int knobPin = A0;
int knobValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  knobValue = analogRead(knobPin); // read the knob


// constrain range of knob
  knobValue = constrain(knobValue, 0, 331);
  Serial.print("Knob: ");
  Serial.print(knobValue); // see what values you get from knobPin
  
//  Map the values
  knobValue = map(knobValue, 0, 331, 0, 255); // match the range of the PWM pin
  Serial.print("       Knob Mapped: ");
  Serial.println(knobValue); // see what values you get from knobPin
  
  analogWrite(ledPin, knobValue); // use analogWrite with PWM pins
  

}
