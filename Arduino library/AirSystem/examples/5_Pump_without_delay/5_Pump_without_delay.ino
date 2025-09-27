// Pump without delay based on the code by David A. Mellis

#include <AirSystem.h>

// Variables will change:
int pumpState = LOW;  // pumpState used to set the pump on/off

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;  // will store last time LED was updated

// Constants won't change:
const long interval = 1000;  // interval at which to blink (milliseconds)
// Blink here means turn the pump on and off

void setup() {
  Serial.begin(9600);
  AirSystem_begin();  // Initialise the pins
  pumpA.off();        // Pump off
  valveA.close();     // Close valve
}

void loop() {
  // Here is where you'd put code that needs to be running all the time.

  // Get the current elapsed milliseconds from the start of the sketch
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // This if-statement checks if the current time is bigger than the previous time - interval
    // So check if the interval time (1 second) has elapsed

    previousMillis = currentMillis;  // Save the last time you blinked the pump

    // If the pump is off, turn it on and vice-versa:
    if (pumpState == LOW) {
      pumpState = HIGH;
      pumpA.set(50);   // Set pump to 50%
      valveA.close();  // Close valve
    } else {
      pumpState = LOW;
      pumpA.off();    // Turn pump off
      valveA.open();  // Open valve
    }
  }
  Serial.print(currentMillis);
  Serial.print("\t");
  Serial.print(previousMillis);
  Serial.print("\t");
  Serial.println(interval);
}
