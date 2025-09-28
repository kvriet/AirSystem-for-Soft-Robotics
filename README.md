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
A manual for AirSystem describes in detail how the system works and how the Arduino library can be installed: ![AirSystem Manual](https://github.com/kvriet/AirSystem-for-Soft-Robotics/blob/main/Air%20System%20manual.pdf)

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

## Schematics and KiCAD Files
The schematics for this project and the KiCAD files can be found here: ![KiCAD folder](https://github.com/kvriet/AirSystem-for-Soft-Robotics/tree/main/KiCAD).

## 3D Printing Files
The STLs for this project can be found here: ![Design Files](https://github.com/kvriet/AirSystem-for-Soft-Robotics/tree/main/Design%20Files).
The prints will fit most regular printers and can be printed out of PLA, 0.3 layer height, 4 perimeters (walls), 20% infill. The cushions for the pumps and solenoids are printed in TPU. These cushions can be replaced with some sponge (simple kitchen sponges work well) if TPU printing is not an option. 
To minimise vibrations and prevent the cases from slipping, 6mm silicone feet are added to the control and follower cases.
Any 4mm holes in the prints will require M3x4mm heated inserts to create screw holes. These can be inserted with a soldering iron at roughly 300 degrees Celsius. 

The screws needed for these cases are:
**Controller**
- 4x M3x10 or M3x20 (any length in between), flathead

**Follower**
- 4x M3x6 for the coloured cover
- 4x M3 spacer: 6mm height, 6mm thread
- 8x M3x10 for the clamps


