#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <ArduinoJson.h>

const char* ssid = "Mazeriikkaa";
const char* password = "YOUR_WIFI_PASSWORD";
const char* apiKey = "YOUR_GOOGLE_API_KEY";

const char* host = "www.googleapis.com";
const int httpsPort = 443;

WiFiClientSecure client;
DynamicJsonDocument jsonDocument(1024);

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi!");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    if (!client.connect(host, httpsPort)) {
      Serial.println("Connection failed!");
      return;
    }

    Serial.println("Connected to API server!");

    // Build the JSON payload
    String jsonPayload = "{\"considerIp\": \"true\"}";

    // Send the POST request
    client.print("POST /geolocation/v1/geolocate?key=");
    client.print(apiKey);
    client.println(" HTTP/1.1");
    client.println("Host: www.googleapis.com");
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(jsonPayload.length());
    client.println();
    client.println(jsonPayload);

    // Wait for the response
    while (client.connected()) {
      String line = client.readStringUntil('\n');
      if (line == "\r") {
        Serial.println("Headers received!");
        break;
      }
    }

    // Parse the JSON response
    while (client.available()) {
      String line = client.readStringUntil('\n');
      Serial.println(line);

      DeserializationError error = deserializeJson(jsonDocument, line);
      if (error) {
        Serial.print("Deserialization failed: ");
        Serial.println(error.c_str());
        return;
      }

      double latitude = jsonDocument["location"]["lat"];
      double longitude = jsonDocument["location"]["lng"];
      double accuracy = jsonDocument["accuracy"];

      Serial.print("Latitude: ");
      Serial.println(latitude, 6);
      Serial.print("Longitude: ");
      Serial.println(longitude, 6);
      Serial.print("Accuracy: ");
      Serial.println(accuracy);
    }

    Serial.println("Closing connection");
    client.stop();
  }

  delay(5000); // Wait for 5 seconds before fetching location again
}
