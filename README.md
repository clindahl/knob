# knob - A project for turning virtual knobs with a Usb-connected physical knob
This project is based on a Arduino Pro Micro that emulates a Usb HID-device.
The Arduino is conneced to PC through Usb and can control mouse movements with the knob.

Good for controlling knobs in Digital Audio Workstations and plugins.
Those knobs are often controlled with the left mousebutton pressed/hold and moving the mouse up and down. 
Please feel free to add functionality or ideas.

## Description of Usage

### Controlling Mouse
- Press knob to toggle left mousebutton press/hold and release
- LED turns on when left mousebutton is pressed
- LED turns off when left mousebutton is released
- When turning knob right mouse moves Up
- When turning knob left mouse moves Down

### Adjusting Sensitivity
- Turn pot right to set a lower sensitivity of the mouse
- Turn pot left to set a higher sensitivity of the mouse

## Hardware
- 1 Arduino Pro Micro (5v) (Other Arudinos could be used but must be capable of emulating Usb HID-device)
- 1 Rotary Encoder
- 1 Potentiometer (50k)
- 2 LED´s
- 2 220 Ohms Resistors
- 2 10K Ohms Resistors
- Enclosure
- 3d printed knob to attach to Rotary Encoder
- some wires and soldering equipment

<ATTACH PICTURE OF WIREDIAGRAM HERE> 
  
## Software
knob.ino is uploaded to Arduino via Arduino IDE (https://www.arduino.cc/en/Guide/HomePage)
