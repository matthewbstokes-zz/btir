# Description

Currently the project is set-up exclusively to act as a TV remote. However this project is going to pivot to simply relay IR commands sent over bluetooth.

# Hardware
  - ATTINY85
  - IR LED
  - IR Receiver
  - BTLE 4.0
  
# Software
Using the software serial library for bluetooth communication as the ATTINY85 does not have hardware serial communication.
  - Pin 4 - RX
  - Pin 3 - TX
  
Using Ken Sheriffs IR library outfitted for the ATTINY85 to send IR commands
  - Pin 1 - IR LED
  
# TODO
  - ATTINY85 low energy sleep mode
  - Interrupt pin wakes up ATTINY85
  - IR Receiver
  - Case
  - Modify code to relay commands
  - Flash storage for adding additional "favorite" commands
  - App to send/add
