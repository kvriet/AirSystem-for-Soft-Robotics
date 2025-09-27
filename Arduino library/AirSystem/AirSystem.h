#ifndef AIRSYSTEM_H
#define AIRSYSTEM_H

#include <Arduino.h>

#define CHANNEL_COUNT 4

#define PUMP_PINS   {15, 13, 11, 9}
#define VALVE_PINS  {14, 12, 10, 8}
#define SENSOR_PINS {29, 28, 27, 26}
#define LED_BUILTIN 16

// ---- Pump ---- //
class Pump {
  int pin;
public:
  Pump() {}
  Pump(int pumpPin) { begin(pumpPin); }
  void begin(int pumpPin);
  void set(float percentage);
  void on();
  void off();
};

// ---- Valve ---- //
class Valve {
  int pin;
public:
  Valve() {}
  Valve(int valvePin) { begin(valvePin); }
  void begin(int valvePin);
  void open();
  void close();
};

// ---- Sensor ---- //
class Sensor {
  int pin;
public:
  Sensor() {}
  Sensor(int sensorPin) { begin(sensorPin); }
  void begin(int sensorPin);
  float read();
};

// ---- Global arrays ---- //
extern Pump pumps[CHANNEL_COUNT];
extern Valve valves[CHANNEL_COUNT];
extern Sensor sensors[CHANNEL_COUNT];

// ---- Named references ---- //
extern Pump& pumpA;
extern Pump& pumpB;
extern Pump& pumpC;
extern Pump& pumpD;

extern Valve& valveA;
extern Valve& valveB;
extern Valve& valveC;
extern Valve& valveD;

extern Sensor& sensorA;
extern Sensor& sensorB;
extern Sensor& sensorC;
extern Sensor& sensorD;

// ---- Init function ---- //
void AirSystem_begin();

#endif
