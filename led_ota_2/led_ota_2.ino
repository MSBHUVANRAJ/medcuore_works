#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

const char* ssid = "Mazeriikkaa";
const char* password = "";

void setupOTA() {
  ArduinoOTA.setPort(3000); // Specify the OTA port (default: 8266)
  ArduinoOTA.setHostname("esp32"); // Replace with your desired hostname
  ArduinoOTA.setPassword("esp32"); // Set OTA password (optional)

  // Define OTA update handlers
  ArduinoOTA.onStart([]() {
    // Perform actions before OTA update starts
  });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    // Progress update during OTA update
  });

  ArduinoOTA.onEnd([]() {
    // Actions to perform after OTA update completes
  });

  ArduinoOTA.onError([](ota_error_t error) {
    // Error handling during OTA update
  });

  ArduinoOTA.begin(); // Start OTA update process
}

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Set up OTA
  setupOTA();
}

void loop() {
  ArduinoOTA.handle(); // Handle OTA update process

  // Your main code logic here
}
