
int ledPin = 13;

int knobPin = A0;
int knobValue = 0;

int switchPin = 7;
int switchState = 0;

int buttonPin = 2;
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  buttonState = digitalRead(buttonPin);
  Serial.print("Button: ");
  Serial.println(buttonState);

  if (buttonState == 1) {
    // turn off LED
    digitalWrite(ledPin, LOW);
    
  } else {

    knobValue = analogRead(knobPin);
    Serial.print("Knob Value: ");
    Serial.println(knobValue);
  
    switchState = digitalRead(switchPin);
    Serial.print("Switch: ");
    Serial.println(switchState);
    
    if (switchState == 1) {
      // turn led on
      digitalWrite(ledPin, HIGH);
    } else {
      // do the regular thing
      if(knobValue > 250) {
        // turn on
        digitalWrite(ledPin, HIGH);
      } else if (knobValue < 50) {
         digitalWrite(ledPin, LOW);
      } else {
        // do the regular thing
        digitalWrite(ledPin, HIGH); // on
        delay(knobValue);
        
        digitalWrite(ledPin, LOW);  // off
        delay(knobValue);
      }
    }
  }

  
}
