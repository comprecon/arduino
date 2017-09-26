/*  
 *  Combines Class work with
 *  StateChangeDetection example 
 */
 
int ledPin = 13;

int knobPin = A0;
int knobValue = 0;

int switchPin = 7;
int switchState = 0;

int buttonPin = 2;
int buttonState = 0;
int lastButtonState = 0;

bool toggleState = false;

void setup() {
  // put your setup code here, to run once:

  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly

  // ---- TURN BUTTON INTO TOGGLE ----------------------------------  
  
  // read the buttonpin
  buttonState = digitalRead(buttonPin);

  // if it has changed, increment the counter
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      toggleState = !toggleState;
    }
    lastButtonState = buttonState;
  }

  // ---- DO THINGS BASED ON TOGGLESTATE ----------------------------
  
  if (toggleState) {
    // turn off LED
    digitalWrite(ledPin, LOW);
    //Serial.println("Off");
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
