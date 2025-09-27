#include <AirSystem.h>

void setup() {
  Serial.begin(9600);
  AirSystem_begin();  // Initialise the pins
  pumpA.off();        // Pump off
  valveA.close();     // Close valve
}

void loop() {
  float pressure = sensorA.read();
  Serial.print(0);     // Lower limit in Serial Plotter
  Serial.print("\t");  // Print a tab
  Serial.print(200);   // Upper limit in Serial Plotter
  Serial.print("\t");  // Print a tab
  Serial.println(pressure);

  delay(10);
}
