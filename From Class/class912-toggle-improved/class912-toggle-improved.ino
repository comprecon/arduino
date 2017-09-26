/*  Combines Class work with
 *  StateChangeDetection example and with
 *  BlinkWithoutDelay example
 */

int ledPin = 13;
int ledState = 0;

int knobPin = A0;
int knobValue = 0;

int switchPin = 7;
int switchState = 0;

int buttonPin = 2;
int buttonState = 0;
int lastButtonState = 0;

bool toggleState = false; // start at false because button hasn't been pressed yet

// absolute time variables
unsigned long currentMillis;       // will read the current time
unsigned long previousMillis = 0;  // will store last time LED was updated

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly

  // read the current time
  currentMillis = millis();
  
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
      // do the regular knob thing
      if(knobValue > 250) {
        // turn on
        digitalWrite(ledPin, HIGH);
      } else if (knobValue < 50) {
         digitalWrite(ledPin, LOW);
      } else {
        // if knob is between 50 and 250, do the regular blinking thing

        // check to see if it's time to blink the LED; that is, if the
        // difference between the current time and last time you blinked
        // the LED is bigger than the interval at which you want to
        // blink the LED.
        if (currentMillis - previousMillis >= knobValue) {
          // save the last time you blinked the LED
          previousMillis = currentMillis;
      
          // if the LED is off turn it on and vice-versa:
          if (ledState == LOW) {
            ledState = HIGH;
          } else {
            ledState = LOW;
          }
 
          // set the LED with the ledState of the variable:
          digitalWrite(ledPin, ledState);
        } // end time check
      } // end knob value conditional
    } // end switch conditional
  } // end toggle conditional
  
} // end of loop
