#include <AirSystem.h>

void setup() {
  Serial.begin(9600);
  AirSystem_begin();  // Initialise the pins
  pumpA.off();        // Pump off
  valveA.close();     // Close valve
}

void loop() {
  pumpA.set(50);
  Serial.println("Pump set to 50% intensity");

  delay(2000);

  pumpA.off();
  Serial.println("Pump turned off");

  delay(2000);
}
