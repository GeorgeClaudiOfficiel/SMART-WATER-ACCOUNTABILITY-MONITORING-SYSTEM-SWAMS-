# Firmware for Smart Water Accountability Monitoring System (SWAMS)

This folder contains the firmware required to run the **Smart Water Accountability Monitoring System (SWAMS)**, including code for both the **Arduino** and **NodeMCU** microcontrollers. The Arduino handles water flow measurement, and the NodeMCU manages data transmission via Wi-Fi to a backend or cloud service.

---

## Table of Contents

- [Folder Structure](#folder-structure)
- [Arduino Firmware](#arduino-firmware)
- [NodeMCU Firmware](#nodemcu-firmware)
- [Libraries](#libraries)
- [How to Upload](#how-to-upload)

---

## Folder Structure

---

## Arduino Firmware

### **Overview:**

The Arduino firmware is responsible for:

- Interfacing with the water flow meter to measure the water flow rate and total volume.
- Displaying real-time water usage data on the OLED screen.

### **File:**

- **`/src/arduino_main.ino`**: The main Arduino program that handles water flow measurement and OLED display logic.

### **How to Use:**

1. Connect the Arduino to the hardware components as per the [hardware schematic](../hardware/schematics).
2. Open `arduino_main.ino` in the Arduino IDE.
3. Install the necessary libraries.
4. Upload the firmware to the Arduino board.

---

## NodeMCU Firmware

### **Overview**

The NodeMCU firmware manages:

- Wi-Fi connectivity, allowing the system to send water consumption data to a remote server or cloud service.
- Communication between the Arduino and a backend (via HTTP or MQTT).

### **Files:**

- **`/src/main.ino`**: The main NodeMCU program that handles Wi-Fi connection and data transmission.

### **How to Use;**

1. Open `nodemcu_main.ino` in the Arduino IDE (set the board to **NodeMCU 1.0**).
2. Modify the Wi-Fi credentials in `nodemcu_main.ino` as per your network.
3. Upload the code to your NodeMCU board.
4. Ensure your backend API or MQTT broker is ready to receive data.

---

## Libraries

For the external libraries used in the project, you can install them via the Arduino Library Manager.

---

## How to Upload

### **For Arduino:**

1. Open **Arduino IDE**.
2. Connect the Arduino to your PC using a USB cable.
3. Open `/firmware/arduino/src/arduino_main.ino`.
4. Select the correct Arduino board (e.g., **Arduino Uno**) from the Tools > Board menu.
5. Click **Upload** to upload the firmware.

### **For NodeMCU:**

1. Open **Arduino IDE**.
2. Connect the NodeMCU to your PC.
3. Open `/firmware/nodemcu/src/nodemcu_main.ino`.
4. Set the board to **NodeMCU 1.0 (ESP-12E Module)** from the Tools > Board menu.
5. Update Wi-Fi credentials in the code (if necessary).
6. Click **Upload** to upload the firmware to the NodeMCU.

---
