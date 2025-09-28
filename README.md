# AirSystem for Soft Robotics
Modular Air System for Soft Robotics

## The system
![Example application](https://github.com/kvriet/AirSystem-for-Soft-Robotics/blob/main/Media/modular%20Air%20System.jpg)

**AirSystem** was designed as a low-cost way to rapidly prototype with air. The system consists of 1 controller and 4 pneumatic units. Each pneumatic units contains one pump, one solenoid valve, and one pressure sensor. The board provides 12V power and as such, any pump or solenoid that requires 12V power can be attached to the unit board. 

![System overview](https://github.com/kvriet/AirSystem-for-Soft-Robotics/blob/main/Media/system%20overview.png)

### Pneumatic Components
For the pneumatic board, easy-to-find components are used:
1. Pump 370A, 12V, 3.2LMP
2. Solenoid valve Skoocom SC0829GW, 12V
3. MCP-H10 pressure sensor, 0-200kPa, 3.3V

### Manual
A manual for AirSystem describes in detail how the system works and how the Arduino library can be installed: ![AirSystem](https://github.com/kvriet/AirSystem-for-Soft-Robotics/blob/main/Air%20System%20manual.pdf)

## Arduino Library
The system is controlled by a Waveshare RP2040 Zero and can be programmed through the Arduino IDE with a custom library: ![AirSystem](https://github.com/kvriet/AirSystem-for-Soft-Robotics/tree/main/Arduino%20library/AirSystem) This folder should be placed in the libraries folder of the Arduino folder. 

The library comes with 7 examples that showcase the abilities of **AirSystem**:
  1. Manual control
  2. Pressure reading
  3. Pump control
  4. Valve control
  5. Pump control without delay
  6. Haptic effects
  7. Object arrays

The video below shows such a haptic effect:

![Example application](https://raw.githubusercontent.com/kvriet/AirSystem-for-Soft-Robotics/refs/heads/main/Media/pneumatic%20button.gif)
