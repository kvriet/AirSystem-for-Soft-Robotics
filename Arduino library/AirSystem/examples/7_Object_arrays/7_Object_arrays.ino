#include <AirSystem.h>

void setup() {
  Serial.begin(9600);
  AirSystem_begin();  // Initialise the pins
  pumps[0].off();     // Pump A off
  valves[0].close();  // Close valve A
}

void loop() {
  // Close valve A and set pump A to 25%
  valves[0].close();
  pumps[0].set(25);
  delay(1000);

  // Get pressure sensor A value and print
  float pressure = sensors[0].read();
  Serial.println(pressure);

  // Open valve A and turn pump A off
  valves[0].open();
  pumps[0].off();
  delay(2000);
}
