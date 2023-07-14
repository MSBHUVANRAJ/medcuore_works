#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <Arduino.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h> 
#include<WiFiManager.h>
WiFiManager wifiManager;
String url;
String receivedData;  // String to store received data
int ADC_value;
int float_value;
String payload = "";
String httpRequestData = "";
String device_Id = "ESPTEST_1";
void setup() {
  Serial.begin(115200);
  wifiManager.setTimeout(150);  // hotspot visibility for 5 minutes
  wifiManager.autoConnect("Pixel's Wifi","karthikhamaran2311");  //set the hotspot name and password
  Serial.println("Connected via WifiManager....."); 

  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}

void loop() {
   if (Serial.available()) {
    char receivedChar = Serial.read();  // Read a character from the serial buffer
    
    if (receivedChar == '\n') {  // Check if the received character is a newline character (Enter key)
      // Process the received data
      processData(receivedData);
      
      // Clear the received data for the next input
      receivedData = "";
    } else {
      receivedData += receivedChar;  // Append the received character to the data string
    }
  }
  upload_data();
  delay(10000);
}
void processData(const String& data) {
  // Split the received data into two values
  int value1 = data.toInt();  // Assuming the first value is an integer
  
  // Find the position of the separator character (e.g., comma)
  int separatorPos = data.indexOf(',');
  
  // Extract the second value from the data string
  float value2 = data.substring(separatorPos + 1).toFloat();  // Assuming the second value is a float
  
  // Print the received values for verification
  Serial.print("Received values: ");
  Serial.print(value1);
  Serial.print(", ");
  Serial.println(value2);  // Print with one decimal place
}
void upload_data()
{
    WiFiClient client;
    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    // configure traged server and url
    http.begin(client,"http://43.205.74.94:8082/topics/+String(device_Id)"); //HTTP
    http.addHeader("Content-Type", "application/vnd.kafka.json.v2+json");
    Serial.println("[HTTP] POST...\n");
    
    // start connection and send HTTP header and body
    httpRequestData = "{\r\n    \"records\": [\r\n      {\r\n            \"key\": \"device_id\",\r\n            \"value\": \"" + String(device_Id) + "\"\r\n        },\r\n  {\r\n            \"key\": \"humidity\",\r\n            \"value\": \"" + String(ADC_value) + "\"\r\n        },\r\n  {\r\n            \"key\": \"temperature\",\r\n            \"value\": \"" + String(float_value) + "\"\r\n        }\r\n    ]\r\n}";
    Serial.println("payload format : "+httpRequestData); 
    int httpCode = http.POST(httpRequestData);
          
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] POST... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        payload = http.getString();
        Serial.println("received payload:\n<<");
        Serial.println(payload);
        Serial.println(">>");
      }
    } else {
      Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }
    http.end();
}
