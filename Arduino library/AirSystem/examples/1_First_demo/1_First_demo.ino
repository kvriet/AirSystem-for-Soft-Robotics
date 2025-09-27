/*
   AirSystem Demo Sketch
   ---------------------

   Author: C.M. van Riet
   Library: AirSystem
   Date:   September 2025

  Objects can be called in 2 ways:
     - pumpA, valveB, sensorC (named)
     - pumps[0], valves[1], sensors[2] (array-based)

   Functions available in this library:
     - Initialize the system with AirSystem_begin()
     - Control pumps with .set(percentage), on(), and .off()
     - Control valves with .open() and .close()
     - Read pressure from sensors with .read()

   Hardware:
   - Designed for a maximum of 4 pumps, 4 valves, and 4 sensors
   - Pin mappings are fixed in the library (see AirSystem.h)

   Notes:
   - Make sure to include the AirSystem.h library at the top of your sketch (#include <AirSystem.h>)
   - This example can be found under File > Examples > AirSystem > 1_First_demo.
*/

#include <AirSystem.h>

void setup() {
  Serial.begin(9600);
  AirSystem_begin();  // Initialise the pins
  pumpA.off();        // Pump off
  valveA.close();     // Close valve
}

void loop() {
  // This loop is empty
  // You can turn the pump and valve on by pressing
  // the buttons on the board of the unit
}
