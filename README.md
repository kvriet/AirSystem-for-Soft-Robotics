# AirSystem for Soft Robotics
Modular Air System for Soft Robotics\
Designed and created by [C.M. van Riet](https://research.tue.nl/en/persons/cm-katrien-van-riet) - Summer 2025\
With thanks to d.search at Eindhoven University of Technology for their guidance.\
Special thanks to Geert van den Boomen for checking the schematics and debugging the circuits.

## The system
![Example application](https://github.com/kvriet/AirSystem-for-Soft-Robotics/blob/main/Media/modular%20Air%20System.jpg)

**AirSystem** was designed as a low-cost way to rapidly prototype with air, costing roughly €125 for the entire system. AirSystem consists of 1 controller and 4 pneumatic units. Each pneumatic unit contains one pump, one solenoid valve, and one pressure sensor. The board provides 12V power and as such, any pump or solenoid that requires 12V power can be attached to the unit board. 

![System overview](https://github.com/kvriet/AirSystem-for-Soft-Robotics/blob/main/Media/system%20overview.png)

### Pneumatic Components
For the pneumatic board, easy-to-find components are used:
1. Pump 370A, 12V, 3.2LPM
2. Solenoid valve Skoocom SC0829GW, 12V
3. MCP-H10 pressure sensor, 0-200kPa, 3.3V

### Manual
A manual for AirSystem describes in detail how the system works and how the Arduino library can be installed: [AirSystem Manual](https://github.com/kvriet/AirSystem-for-Soft-Robotics/blob/main/Air%20System%20manual.pdf)
Users are free to connect the sensor, pump, and valve to their inflatables as desired. However, a sample pneumatic circuit is outlined in the manual, along with example Arduino sketches that work well with such a circuit.

## Arduino Library
The system is controlled by a Waveshare RP2040 Zero and can be programmed through the Arduino IDE with a custom library: [AirSystem](https://github.com/kvriet/AirSystem-for-Soft-Robotics/tree/main/Arduino%20library/AirSystem) This folder should be placed in the libraries folder of the Arduino folder. 

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
The schematics for this project and the KiCAD files can be found here: [KiCAD folder](https://github.com/kvriet/AirSystem-for-Soft-Robotics/tree/main/KiCAD).

## 3D Printing Files
The STLs for this project can be found here: [Design Files](https://github.com/kvriet/AirSystem-for-Soft-Robotics/tree/main/Design%20Files).
- The prints will fit most regular printers and can be printed out of PLA, 0.3 layer height, 4 perimeters (walls), 20% infill. The cushions for the pumps and solenoids are printed in TPU. These cushions can be replaced with some sponge (simple kitchen sponges work well) if TPU printing is not an option.
- To minimise vibrations and prevent the cases from sliding around on a hard surface, 6mm silicone feet are added to the bottom of control and follower cases.
- Any 4mm holes in the prints will require M3x4mm heated inserts to create screw holes. These can be inserted with a soldering iron at roughly 300 degrees Celsius. The other 3mm holes are self-tapping.

The screws needed for these cases are:

**Controller**
- 4x M3x10 or M3x20 (any length in between), flathead

**Follower**
- 4x M3x6 for the coloured cover
- 4x M3 spacer: 6mm height, 6mm thread
- 8x M3x10 for the clamps

## Limitations
- Although protection is implemented on the signal lines, the Waveshare RP2040 Zero sometimes dies when the IDC connector cable is plugged into the controller or follower when the RP2040 is still connected by USB C. For this reason, it is important to unplug the RP2040 before plugging in/out ribbon cables.
- Due to the above issue, I am looking into switching to the ESP32 C3 Zero (Pro). This board is equally cheap, but seems to be more robust. This board is currently not yet a drop-in replacement for the RP2040, although it can already be made to work if some soldering on the controller is reworked and the pin numbers in the library are updated. I will probably release KiCAD files for an ESP32 controller in the future. The follower boards will not be affected, although the resistor value in series with the mosfet might be updated (from 1k to 500R).
- The Skoocom solenoid valve is able to remain closed up to pressures of 100kPa, whereas the pump is able to deliver 150kPa. This means the valve will start leaking at pressures over 100kPa. In practice, this is not a major issue, as our projects rarely need pressures of over 100kPa (usually maxing out at 50kPa for haptic purposes). However, this overpressure might reduce valve longevity in the long run. In the future, a higher-pressure solenoid valve could be found, or a pump could be found that delivers max 100kPa. This would also allow for a lower-range pressure sensor to be used, the MCP-H10 0-100kPa, 3.3V. Switching to the 0-100kPa sensor would also double pressure measuring resolution.
- Currently no PID has been implemented in the library. As many inflatables or the tubing used are somewhat elastic, I have found that setting a target pressure (feedback loop sensor reading to pump power) is enough to achieve that pressure with a minimal offset. However, for more high-end applications, PID should be implemented.
- The Skoocom solenoid valve is not proportional. It is just open/closed. This means that controller deflation is a challenge. This can be worked around by turning on the pump simultaneously to opening the valve to reduce the air flowing out. Additionally, a resistor (very thin tube) could be connected to the valve outlet to reduce airflow out of the system. However, such a resistor also slows down response times when air does need to evacuate the system quickly. This is a trade-off for how cheap this entire system is.
