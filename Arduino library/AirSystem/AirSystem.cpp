#include "AirSystem.h"

// ------------------- Pump -------------------
void Pump::begin(int pumpPin) {
  pin = pumpPin;
  pinMode(pin, OUTPUT);
  off();
}

void Pump::set(float percentage) {
  if (percentage < 0) percentage = 0;
  if (percentage > 100) percentage = 100;
  int pwmValue = map((int)percentage, 0, 100, 0, 255);
  analogWrite(pin, pwmValue);
}

void Pump::on() {
  analogWrite(pin, 255);
}

void Pump::off() {
  analogWrite(pin, 0);
}

// ------------------- Valve -------------------
void Valve::begin(int valvePin) {
  pin = valvePin;
  pinMode(pin, OUTPUT);
  close();
}

void Valve::open() {
  digitalWrite(pin, HIGH);
}

void Valve::close() {
  digitalWrite(pin, LOW);
}

// ------------------- Sensor -------------------
void Sensor::begin(int sensorPin) {
  pin = sensorPin;
  pinMode(pin, INPUT);
}

float Sensor::read() {
  float pressure = 0.219 * analogRead(pin) - 7.664;     // Pressure in kPa
  return pressure;
}

// ------------------- Global objects -------------------

// Arrays of real objects
Pump pumps[CHANNEL_COUNT];
Valve valves[CHANNEL_COUNT];
Sensor sensors[CHANNEL_COUNT];

// Named references bound to array elements
Pump& pumpA = pumps[0];
Pump& pumpB = pumps[1];
Pump& pumpC = pumps[2];
Pump& pumpD = pumps[3];

Valve& valveA = valves[0];
Valve& valveB = valves[1];
Valve& valveC = valves[2];
Valve& valveD = valves[3];

Sensor& sensorA = sensors[0];
Sensor& sensorB = sensors[1];
Sensor& sensorC = sensors[2];
Sensor& sensorD = sensors[3];

// ------------------- Init function -------------------
void AirSystem_begin() {
  int pumpPins[CHANNEL_COUNT]   = PUMP_PINS;
  int valvePins[CHANNEL_COUNT]  = VALVE_PINS;
  int sensorPins[CHANNEL_COUNT] = SENSOR_PINS;

  for (int i = 0; i < CHANNEL_COUNT; i++) {
    pumps[i].begin(pumpPins[i]);
    valves[i].begin(valvePins[i]);
    sensors[i].begin(sensorPins[i]);
  }
}
