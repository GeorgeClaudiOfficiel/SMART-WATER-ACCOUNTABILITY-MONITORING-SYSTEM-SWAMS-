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
- **Miscellaneous**: Jumper wires, breadboard, power supply.

### **Software(Tech Stack):**

- **Frontend**: HTML5 and CSS3 for structuring and styling the web content.
                JavaScript with JQuery for enhancing interactivity, smooth scrolling and event handling.
- **Communication Protocol**: MQTT or HTTP for data transmission

---

## Setup Guide

### **1. Hardware Setup:**

- Assemble the components following the provided [schematics](./hardware/schematics).
- Connect the flow meter to NodeMCU ESP8266, and integrate the OLED display.

### **2. Firmware Installation:**

- Upload the Arduino/NodeMCU firmware from the `firmware/` directory.

### **3. Software Setup:**

- To get started simply follow the following [link](https://georgeclaudiofficiel.github.io/SMART-WATER-ACCOUNTABILITY-MONITORING-SYSTEM-SWAMS-/).
- To run the web app on your browser through localhost:5500, simply download the extensions 'Liveserver' and 'Prettier' then:

1. Clone this repository:

   ```bash
   git clone https://github.com/yourusername/Smart-Water-Accountability-Monitoring-System-SWAMS-.git

2. Click on the Go Live button on your VS Code.

Done! Now the web app will appear on your localhost through the browser.
