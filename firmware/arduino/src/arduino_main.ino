#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <SD.h>

// OLED display settings
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// SD card pin (adjust based on your wiring)
#define SD_CS_PIN 53

// Water flow meter settings
volatile int pulseCount = 0;
float flowRate = 0.0;
float totalLiters = 0.0;  // Total water used in liters
float dailyLiters = 0.0;  // Water used today in liters
float monthlyLiters = 0.0;  // Water used this month in liters
float unitUsed = 0.0;  // Water used in units (e.g., 1 unit = 1000 liters)
unsigned long oldTime = 0;
unsigned long lastMidnight = 0; // To track the time for resetting daily usage

// Pin connected to the flow meter
const int flowMeterPin = 2;  // Interrupt pin

// Unit conversion (1 unit = 1000 liters)
const float LITERS_PER_UNIT = 1000.0;

void pulseCounter() {
  pulseCount++;
}

void setup() {
  Serial.begin(9600);           // Main serial for debugging
  Serial1.begin(9600);          // Serial for communication with NodeMCU (TX1/RX1)
  
  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();

  // Initialize SD card
  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("SD card initialization failed!");
    return;
  }

  // Initialize flow meter pin and interrupt
  pinMode(flowMeterPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(flowMeterPin), pulseCounter, FALLING);

  oldTime = millis();
  lastMidnight = millis();
}

void loop() {
  if (millis() - oldTime > 1000) {  // Every second
    detachInterrupt(digitalPinToInterrupt(flowMeterPin));

    // Calculate flow rate in liters/min
    flowRate = (pulseCount / 7.5);  // Adjust based on flow meter spec
    float flowLiters = flowRate / 60;  // Convert to liters per second

    // Update totals
    totalLiters += flowLiters;
    dailyLiters += flowLiters;
    unitUsed = totalLiters / LITERS_PER_UNIT;

    // Display on OLED
    displayData();

    // Log data to SD card
    logToSD();

    // Send data to NodeMCU
    sendToNodeMCU(flowRate, totalLiters, dailyLiters, unitUsed);

    pulseCount = 0;
    oldTime = millis();

    if (millis() - lastMidnight > 86400000) {  // Reset at midnight
      resetDailyUsage();
    }

    attachInterrupt(digitalPinToInterrupt(flowMeterPin), pulseCounter, FALLING);
  }
}

void displayData() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);

  // Flow rate
  display.setCursor(0, 0);
  display.print("Flow rate: ");
  display.print(flowRate);
  display.println(" L/min");

  // Total liters
  display.setCursor(0, 10);
  display.print("Total used: ");
  display.print(totalLiters);
  display.println(" L");

  // Daily liters
  display.setCursor(0, 20);
  display.print("Today: ");
  display.print(dailyLiters);
  display.println(" L");

  // Units
  display.setCursor(0, 30);
  display.print("Units: ");
  display.print(unitUsed);

  // Monthly liters
  display.setCursor(0, 40);
  display.print("This month: ");
  display.print(monthlyLiters);
  display.println(" L");

  display.display();
}

void logToSD() {
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (dataFile) {
    dataFile.print("Flow rate: ");
    dataFile.print(flowRate);
    dataFile.print(" L/min, ");
    dataFile.print("Total: ");
    dataFile.print(totalLiters);
    dataFile.print(" L, ");
    dataFile.print("Today: ");
    dataFile.print(dailyLiters);
    dataFile.print(" L, ");
    dataFile.print("Units: ");
    dataFile.print(unitUsed);
    dataFile.print(", This month: ");
    dataFile.print(monthlyLiters);
    dataFile.println(" L");
    dataFile.close();
  } else {
    Serial.println("Error opening datalog.txt");
  }
}

void sendToNodeMCU(float flowRate, float totalLiters, float dailyLiters, float unitUsed) {
  // Send data to NodeMCU via Serial1
Serial1.print("Flowrate: ");
  Serial1.print(flowRate);
  Serial1.print(", Total: ");
  Serial1.print(totalLiters);
  Serial1.print(", Today: ");
  Serial1.print(dailyLiters);
  Serial1.print(", Unit: ");
  Serial1.println(unitUsed);
}

void resetDailyUsage() {
  monthlyLiters += dailyLiters;
  dailyLiters = 0;
  lastMidnight = millis();
}
