#include <AirSystem.h>

int setpoint = 30;            // The target pressure (kPa) for the button
int offset = 2;               // Optional: how much higher the target pressure can be before pump turns off (to prevent pump jitter)
int threshold = 45;           // The pressure at which the buttons 'snaps' down
int counter_number = 3;       // For how many loops the button empties
int counter = 0;              // We start our haptic effect counter at 0
bool doHapticEffect = false;  // Currently don't do the haptic effect yet

void setup() {
  Serial.begin(9600);
  AirSystem_begin();  // Initialise the pins
  pumpA.off();        // Pump off
  valveA.close();     // Close valve
}

void loop() {
  float pressure = sensorA.read();

  // Pump control
  if (doHapticEffect == false) {
    // If we're not doing the haptic effect:
    if (pressure < setpoint) {
      // If the pressure is not at the target level, keep pumping
      pumpA.set(100);  // Set pump to 100%
      valveA.close();  // Keep valve closed
    } else if (pressure >= setpoint + offset) {
      // If target pressure has been reached (+ offset value), turn pump off
      pumpA.off();
    }
  }

  if (pressure > threshold) {
    // If the pressure meets haptic effect threshold, set doHapticEffect to true
    doHapticEffect = true;
  }

  if (doHapticEffect == true) {
    // If we have to do the haptic effect, turn off pump and open valve
    pumpA.off();
    valveA.open();
    counter++;  // Increment counter
    if (counter > counter_number) {
      // After 3 cycles, the haptic effect resets and pressure will need to meet threshold again
      doHapticEffect = false;
      counter = 0;
    }
  }
  delay(10);
}
