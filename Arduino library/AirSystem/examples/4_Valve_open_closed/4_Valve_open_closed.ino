#include <AirSystem.h>

void setup() {
  Serial.begin(9600);
  AirSystem_begin();  // Initialise the pins
  pumpA.off();        // Pump off
  valveA.close();     // Close valve
}

void loop() {
  valveA.close();
  pumpA.set(25);
  Serial.println("Valve closed and pump set to 25%");

  delay(1000);

  valveA.open();
  pumpA.off();
  Serial.println("Valve opened and pump off");

  delay(2000);
}
