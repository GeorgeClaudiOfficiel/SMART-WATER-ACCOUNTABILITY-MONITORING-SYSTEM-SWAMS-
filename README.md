# Smart Water Acccountability Monitoring System (SWAMS)

**A real-time smart water monitoring solution** designed to track water usage, and provide actionable insights for efficient water management.

---

## Table of Contents

- [Project Overview](#project-overview)
- [Features](#features)
- [Technologies Used](#technologies-used)
- [Setup Guide](#setup-guide)

---

## Project Overview

The **SWAMS** is designed to help users monitor and manage their water consumption in real-time. It uses a flow meter, OLED display, and NodeMCU ESP8266 microcontroller to measure water flow and total volume and sends this data wirelessly to a web/mobile interface for remote tracking and analysis.

This system promotes water conservation by giving users insights into their daily and monthly consumption patterns remotely, allowing for efficient water usage.

---

## Features

- **Real-Time Water Monitoring**: Tracks real-time water flow rate and total volume.
- **Historical Data**: Provides daily, monthly, and total water usage statistics.
- **Mobile & Web Access**: Monitor water usage remotely through a web or mobile app.

---

## Technologies Used

### Hardware Components

- **Flow Meter**: Measures the water flow rate.
- **OLED Display (1306)**: Displays real-time flow rate and total volume.
- **NodeMCU ESP8266**: Handles data processing and wireless communication.
- **SD Card Module** (for local storage)
- **Miscellaneous**: Jumper wires, breadboard, power supply.

### **Software:**

- **Backend**:
- **Frontend**:
- **Database**:
- **Communication Protocol**: MQTT or HTTP for data transmission

---

## Setup Guide

### **1. Hardware Setup:**

- Assemble the components following the provided [schematics](./hardware/schematics).
- Connect the flow meter to NodeMCU ESP8266, and integrate the OLED display.

### **2. Firmware Installation:**

- Upload the Arduino/NodeMCU firmware from the `firmware/` directory.
- Use the `config.h` file to set your Wi-Fi credentials.
