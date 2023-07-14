#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include <ArduinoOTA.h>  // Library for OTA updates

void setup() {
    WiFi.mode(WIFI_STA);
    Serial.begin(115200);

    // WiFiManager setup
    WiFiManager wm;
    bool res;
    res = wm.autoConnect("AutoConnectAP", "password");

    if (!res) {
        Serial.println("Failed to connect");
        ESP.restart();
    } else {
        Serial.println("Connected to WiFi");
        Serial.print("IP address: ");
        Serial.println(WiFi.localIP());
    }

    // OTA update setup
    ArduinoOTA.setHostname("ESP32_Device"); // Set the hostname for OTA
    ArduinoOTA.begin();                     // Start OTA

    // Additional setup code
}

void loop() {
    ArduinoOTA.handle(); // Handle OTA update requests

    // Your main code logic
}
