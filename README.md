# AVR Drivers Based On [ATmega32]
## Pin  Diagram 
![image](https://github.com/MahmoudSamy511/AVR-Drivers/assets/95527475/a727be48-296e-4e76-bd9e-3883125ee2c5)


## Table of Contents
1. Introduction
2. Prerequisites
3. Included Drivers
4. How to Use Drivers
5. Additional Resources

## 1. Introduction

The AVR drivers for ATmega32 are a collection of C libraries that simplify the process of utilizing the microcontroller's hardware peripherals such as GPIO, UART, ADC, Timer/Counter, etc. These drivers abstract the low-level register manipulations and provide easy-to-use functions for interacting with the peripherals.

## 2. Prerequisites

Before using the AVR drivers for ATmega32, make sure you have the following:

- ATmega32 microcontroller board
- Eclipse software or any IDE to run C code
- AVR-GCC compiler and toolchain
- AVRDUDE or any other AVR programmer software
- AVR drivers library (provided in this repository)
- Basic knowledge of C programming
- Basic knowledge of microcontroller peripherals

## 3. Included Drivers

  The drivers library for ATmega32 contains the following modules:
  ## MCAL Layer
   **`1. DIO Driver:`** For configuring and manipulating General Purpose Input/Output pins.
   
   **`2. UART Driver:`** For UART serial communication with other devices.
   
   **`3. ADC Driver:`** For Analog to Digital Conversion using the onboard ADC.
   
   **`4. Timer Driver:`** For utilizing the Timer/Counter modules for various timing and PWM applications.
  ## HAL Layer
   **`1. LCD:`** For interfacing with Liquad Crystal Display 2X16 (lm016l).
      
   **`2. KEYPAD:`** For interfacing with 4X4 keypad.
      
   **`3. Seven Segment:`** For interfacing with seven segment display common [Anode/Cathode] .
      
   **`4. DC Motor:`** For interfacing with  DC Motors Connected to L298N H-bridge.
      
   **`5. Stepper Motor:`** For interfacing with Stepper Motors
## 4. How to Use Drivers
  To get started with the AVR drivers, clone this repository to your local machine using the following command:

  `git clone https://github.com/your_username/avr-drivers-for-atmega32.git`
  
  Replace `your_username` with your GitHub username.
  ## 5. Additional Resources
  - [ATmega32 Datasheet](https://www.microchip.com/en-us/product/ATmega32) - Refer to the official datasheet for detailed information about the ATmega32 microcontroller.
