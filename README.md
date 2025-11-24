##  Automatic Temperature-Controlled Cooling System (LPC2138 + LM35 + Motors + Relay Control

This project implements an automatic cooling control system using the LPC2138 ARM7 microcontroller.
The system continuously monitors temperature using an LM35 sensor, displays real-time temperature on a 16×2 LCD, and controls two cooling motors via relay drivers based on predefined temperature thresholds.

This embedded system demonstrates:

 - ADC reading using ARM7

 - LCD interfacing

 - Relay control using transistors

 - Real-time decision-making based on sensor input

## 🖼️ Circuit Diagram

The circuit below shows the complete hardware connections including:

 - LPC2138 microcontroller

 - LM35 temperature sensor

 - Relay driver transistors (BC547)

 - Dual motor control

 - 16×2 LCD Display

![Circuit Diagram](https://github.com/Aditya3323/Automatic-Temperature-Controlled-Cooling-System/blob/main/schematic/Screenshot%202024-10-23%20174120.png)

🔍 Circuit Description

 - LM35 outputs analog temperature data → read using ADC0 channel of LPC2138
 - LCD connected to Port 0 for displaying formatted temperature
 - BC547 transistors act as switching drivers for the relays
 - When temperature crosses a threshold, motors turn ON automatically
 - LEDs act as status indicators for each motor

## 🔄 System Flowchart

The flowchart represents the software flow of the cooling control algorithm, from initialization to motor control logic.

![Flowchart](https://github.com/Aditya3323/Automatic-Temperature-Controlled-Cooling-System/blob/main/schematic/Screenshot%202025-11-24%20151908.png)

## ⚙️ Hardware Components
Component	Purpose:
 - LPC2138 (ARM7)	Main microcontroller, handles ADC + logic
 - LM35 Sensor	Provides analog temperature (10 mV/°C)
 - BC547 Transistors	Drive relay coils
 - 12V Relays	Control high-power motors
 - Cooling Motors (12V)	Act as heat exhaust units
 - 16×2 LCD	Shows live temperature
 - Resistors
 -  Wires	Support components

## 📌 Applications
 - Smart cooling systems
 - Industrial temperature monitoring
 - IoT-based HVAC automation
 - Educational embedded system design
