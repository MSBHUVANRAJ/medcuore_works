#include <WiFiManager.h>
#include <PubSubClient.h>
#include <ArduinoOTA.h>

const char* mqtt_server = "mqtt-dashboard.com";
const int mqtt_port = 8884; // Use port 8884 for secure MQTT
const char* mqtt_topic = "ota_update_topic";
const char* mqtt_username = "mazeriikkaa";
const char* mqtt_password = "1234567890";

WiFiManager wm;
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);

  // Connect to WiFi using WiFiManager
  wm.autoConnect("AutoConnectAP", "password");

  Serial.println("Connected to WiFi");

 // espClient.setCACert(root_ca); // Set the root CA certificate

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

  if (client.connect("ESP32_Device", mqtt_username, mqtt_password)) {
    Serial.println("Connected to MQTT broker");
    client.subscribe(mqtt_topic);
  }

  // Initialize OTA updates
  ArduinoOTA.setHostname("ESP32_Device");
  ArduinoOTA.begin();
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  ArduinoOTA.handle();
}

void callback(char* topic, byte* payload, unsigned int length) {
  // Handle MQTT messages
  // Check if the topic is the OTA update topic
  if (strcmp(topic, mqtt_topic) == 0) {
    // Convert payload to a string and check for a specific command
    String command = String((char*)payload);
    if (command == "start_ota_update") {
      // Perform OTA update
      startOTAUpdate();
    }
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Connecting to MQTT broker...");
    if (client.connect("ESP32_Device", mqtt_username, mqtt_password)) {
      Serial.println("Connected to MQTT broker");
      client.subscribe(mqtt_topic);
    } else {
      delay(5000);
    }
  }
}

void startOTAUpdate() {
  Serial.println("Starting OTA update...");
  // Replace the firmware_url with the actual URL where your firmware binary is hosted
  ArduinoOTA.begin("http://your_firmware_url/firmware.bin");
}
