#define BLYNK_TEMPLATE_ID "TMPL2qEJNg17Y"
#define BLYNK_TEMPLATE_NAME "SWAMS"

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <SoftwareSerial.h>
#include <BlynkSimpleEsp8266.h>

const char* ssid = "MACRAY";
const char* password = "401477B7";
char auth[] = "MUgGmRsgc-ZQggjcu83q8yjCRjnGV_Sx"; // Replace with your actual token

const char* host = "script.google.com";
const char* googleScriptID = "AKfycby_p5UTPdH2JHwHMKW9aEZdPP_zpmFCZ--RKAqE0kkx21VU5qDWWjTe3YEB5MOG6oQwMQ";  // Google Apps Script ID

#define RX_PIN 4   // GPIO4 (D2)
#define TX_PIN 5   // GPIO5 (D1)

SoftwareSerial mySerial(RX_PIN, TX_PIN); // RX, TX

// Helper function to extract numeric values
String getNumericValue(String data) {
  data.trim();  // Remove any leading/trailing whitespace
  // Remove any text labels like "Flowrate:"
  int colonIndex = data.indexOf(':');
  if (colonIndex != -1) {
    data = data.substring(colonIndex + 1);
  }
  data.trim();  // Trim again to remove extra whitespace after the substring operation
  return data;  // Return the clean numeric value
}

void setup() {
  Serial.begin(115200);
  mySerial.begin(9600);

  WiFi.begin(ssid, password);
  int retries = 0;
  while (WiFi.status() != WL_CONNECTED && retries < 30) {
    delay(500);
    Serial.print(".");
    retries++;
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected to WiFi");
  } else {
    Serial.println("Failed to connect to WiFi");
  }

  Blynk.begin(auth, ssid, password);
  if (Blynk.connected()) {
    Serial.println("Connected to Blynk server");
  } else {
    Serial.println("Failed to connect to Blynk server");
  }
}

void loop() {
  Blynk.run(); // Ensure Blynk is running

  // Reconnect WiFi if disconnected
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.reconnect();
    Serial.println("Reconnecting to WiFi...");
  }

  // Reconnect Blynk if disconnected
  if (!Blynk.connected()) {
    Blynk.connect();
    Serial.println("Reconnecting to Blynk...");
  }

  if (mySerial.available()) {
    String data = mySerial.readStringUntil('\n');
    Serial.println("Received data: " + data); // Debugging

    String flowRate, totalLiters, dailyLiters, unitUsed;
    int firstComma = data.indexOf(',');
    int secondComma = data.indexOf(',', firstComma + 1);
    int thirdComma = data.indexOf(',', secondComma + 1);

    if (firstComma > 0 && secondComma > firstComma && thirdComma > secondComma) {
      flowRate = getNumericValue(data.substring(0, firstComma));
      totalLiters = getNumericValue(data.substring(firstComma + 1, secondComma));
      dailyLiters = getNumericValue(data.substring(secondComma + 1, thirdComma));
      unitUsed = getNumericValue(data.substring(thirdComma + 1));

      Serial.println("Flow rate: " + flowRate);  // Debugging
      Serial.println("Total liters: " + totalLiters);  // Debugging
      Serial.println("Daily liters: " + dailyLiters);  // Debugging
      Serial.println("Unit used: " + unitUsed);  // Debugging

      // Send data to Google Sheets
      sendToGoogleSheets(flowRate, totalLiters, dailyLiters, unitUsed);

      // Send data to Blynk
      Blynk.virtualWrite(V0, flowRate.toFloat());
      Blynk.virtualWrite(V1, totalLiters.toFloat());
      Blynk.virtualWrite(V2, dailyLiters.toFloat());
      Blynk.virtualWrite(V3, unitUsed.toFloat());
    } else {
      Serial.println("Error: Invalid data format.");
    }
  }

  delay(1000); // Adjust the delay as needed
}

void sendToGoogleSheets(String flowRate, String totalLiters, String dailyLiters, String unitUsed) {
  WiFiClientSecure client;
  client.setInsecure(); // Bypass SSL certificate verification for simplicity

  if (!client.connect(host, 443)) {
    Serial.println("Connection to Google failed!");
    return;
  }

  // Build URL for GET request
  String url = String("/macros/s/") + googleScriptID + "/exec?flowRate=" + urlencode(flowRate) +
               "&totalLiters=" + urlencode(totalLiters) + "&dailyLiters=" + urlencode(dailyLiters) +
               "&unitUsed=" + urlencode(unitUsed);

  Serial.println("Requesting URL: " + url); // Debugging output

  // Send HTTP request
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");

  delay(500); // Wait for response

  // Read the response
  while (client.available()) {
    String line = client.readStringUntil('\n');
    Serial.println("Response: " + line); // Print the response
  }

  int httpResponseCode = client.read();
  if (httpResponseCode > 0) {
    Serial.println("Data sent successfully.");
  } else {
    Serial.println("Failed to send data. HTTP Response code: " + String(httpResponseCode));
  }

  client.stop(); // Close the connection
}

// Function to encode URL parameters
String urlencode(String str) {
  String encodedStr = "";
  char c;
  for (int i = 0; i < str.length(); i++) {
    c = str.charAt(i);
    if (c == ' ') {
      encodedStr += '+';
    } else if (isalnum(c)) {
      encodedStr += c;
    } else {
      encodedStr += '%';
      if (c < 16) encodedStr += '0';
      encodedStr += String(c, HEX);
    }
  }
  return encodedStr;
}