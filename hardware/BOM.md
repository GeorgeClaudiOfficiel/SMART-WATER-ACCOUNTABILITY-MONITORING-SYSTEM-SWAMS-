# Bill of Materials (BOM)

This document lists all the hardware components required to build the **Smart Water Accountability Monitoring System(SWAMS)**. It includes information about the parts, quantities, and specifications necessary for the project.

---

## Components

| Item                | Quantity | Description                                                                 | Specification/Model               |
|---------------------|----------|-----------------------------------------------------------------------------|-----------------------------------|
| **Water Flow Sensor**| 1        | Measures the water flow rate and total volume                               | YF-S201 or similar (1-30 L/min)   |
| **Arduino Uno**      | 1        | Microcontroller responsible for reading sensor data                         | Arduino Uno R3 or compatible      |
| **NodeMCU (ESP8266)**| 1        | Wi-Fi-enabled microcontroller for transmitting data wirelessly              | NodeMCU ESP8266 (ESP-12E Module)  |
| **OLED Display**     | 1        | Displays real-time water flow and total volume                              | 0.96" I2C OLED (SSD1306)          |
| **SD Card Module**   | 1        | For local data storage (optional)                                           | Standard MicroSD card module      |
| **Jumper Wires**     | 20       | For connecting components                                                   | Male-to-Male, Female-to-Male      |
| **Power Supply**     | 1        | Powers the microcontrollers and components                                  | 5V DC power supply or USB cable   |

---

## Additional Tools

| Item                | Quantity | Description                                     | Specification/Model               |
|---------------------|----------|-------------------------------------------------|-----------------------------------|
| **Glue Gun**         | 1        | For soldering components on the shell           | Standard 30W Soldering Iron       |
| **Multimeter**       | 1        | For testing connections and measuring voltages  | Digital Multimeter                |
| **Wire Cutters**     | 1        | For cutting wires to the appropriate lengths    | Standard Wire Cutters             |

---

## Notes

1. The **flow sensor** (YF-S201) can be replaced with any sensor with similar specifications, depending on availability and accuracy.
2. The **OLED display** should be an I2C-compatible SSD1306 model for easy integration with Arduino.
3. Depending on the application, the **SD Card Module** is optional if you want to store data locally.
4. For a more permanent setup, consider using a **soldering iron** and soldering the components instead of gluing them on the shell.

---

## Estimated Cost

| Component            | Estimated Price (USD) | Quantity | Total Price (USD) |
|----------------------|-----------------------|----------|-------------------|
| Water Flow Sensor     | kshs 1000             | 1        | kshs 1000         |
| Arduino Uno           | kshs 1700             | 1        | kshs 1700         |
| NodeMCU ESP8266       | kshs 1200             | 1        | kshs 1200         |
| OLED Display          | kshs 2000             | 1        | kshs 2000         |
| SD Card Module        | kshs 500              | 1        | kshs 500          |
| Jumper Wires          | kshs 250              | 60       | kshs 250          |
| **Total**             |                       |          | **kshs 6650**     |

---

## Assembly Notes

- Ensure proper orientation of flow sensor for accurate readings.
- Double-check jumper wire connections to avoid short circuits.
- Verify that all components are powered correctly before running the firmware.

---

This **Bill of Materials (BOM)** provides the essential components needed to build the Smart Water Monitoring System. It serves as a guide for sourcing parts, estimating costs, and assembling the hardware.
