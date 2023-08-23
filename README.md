<div align="center">
  <h1>AVR Drivers Based on [ATmega32] </h1>
  <p>This README file provides an overview and instructions for using drivers of ATmega32 microcontroller.</p>
  <h1>Pin  Diagram </h1>
  <!img src="https://github.com/MahmoudSamy511/AVR-Drivers/assets/95527475/f93e2eb8-090f-4724-825d-20b565e27bb4" alt="Image 1" width="400" height ="331"/>
  <!img src="https://github.com/MahmoudSamy511/AVR-Drivers/assets/95527475/fa65fee4-86d0-46da-8960-d2b1a950ad7d" alt="Image 2" width="400"/>
  <img src="https://github.com/MahmoudSamy511/AVR-Drivers/assets/95527475/10be0c9b-8484-46fd-99d2-c7a7b6c42024">
</div>

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
   
   **`4. EXTI Driver:`** For handling External Interrupts.
   
   **`5. GI Driver:`** For Controlling Global Interrupt.
   
   **`6. Timer Driver:`** For utilizing the Timer/Counter modules for various timing and PWM applications.
   
   **`7. WDT Driver:`** For dealing with Watch Dog timer.
  ## HAL Layer
   **`1. LCD:`** For interfacing with Liquad Crystal Display 2X16 (lm016l).
      
   **`2. KEYPAD:`** For interfacing with 4X4 keypad.
      
   **`3. Seven Segment:`** For interfacing with seven segment display common [Anode/Cathode] .
      
   **`4. DC Motor:`** For interfacing with  DC Motors Connected to L298N H-bridge.
      
   **`5. Stepper Motor:`** For interfacing with Stepper Motors.

   **`6. Servo Motor:`** For interfacing with Servo Motor.
  ## LIB Layer
   **`1-TYPEDEF.h`** a file has redefined types like (Unsigned char --> u8 ,..).
   
   **`2-ErrorState.h`** a file has Enum contain two States [OK,NOT_OK].
   
   **`3-BitMath.h`** a file has functions like macro like [GITBIT,SETBIT,..].
   
   **`4-ISR_Functions.h`** a file has vector macros for ISR Functions.
   
 ## 4. How to Use Drivers

  To get started with the AVR drivers, clone this repository to your local machine using the following command:

- `git clone https://github.com/your_username/avr-drivers-for-atmega32.git`
  
     Replace `your_username` with your GitHub username.
  
- Copy the necessary AVR driver files (DIO, UART,LCD,etc..) from the cloned repository to your project directory.

- Include the driver `interface_file.h` in your C source files to use the functions provided by the driver and
 include any file from LIB layer if you needed. 

- Call the driver initialization functions and use the driver functions in your application code to interact with the microcontroller's peripherals.

- Compile your code using the AVR-GCC compiler and program the ATmega32 microcontroller with the generated HEX file using AVRDUDE or any other AVR programmer software
  
 ## 5. Additional Resources
  - [ATmega32 Datasheet](https://www.microchip.com/en-us/product/ATmega32) - Refer to the official datasheet for detailed information about the ATmega32 microcontroller.
