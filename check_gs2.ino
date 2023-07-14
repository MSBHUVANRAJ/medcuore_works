//#include <SPI.h>
//#include <EthernetENC.h> // Include the EthernetENC library
//#include <HTTPClient.h>
//
////Things to change
//String GOOGLE_SCRIPT_ID = "1gpY94sQt-8tM1YwPXa2yGy9hACUb-H5etbPpeKxDiKARVnOJN307vwBF";
//// Rest of the code...
//
//EthernetClient client;
//EthernetUDP udpClient;
//
//  byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; 
//  IPAddress server(192, 168, 1, 10);
//void setup() {
//  Serial.begin(115200);
//  delay(10);
//  Ethernet.init(5); // Use pin 5 for EthernetENC CS
//  Ethernet.begin(mac);
//  delay(1000); // Allow the Ethernet module to initialize
//
//  Serial.println("Started");
//  Serial.print("Connecting");
//
//  if (Ethernet.linkStatus() == LinkOFF) {
//    Serial.println("Ethernet cable is not connected.");
//  }
//
//  while (Ethernet.linkStatus() != LinkON) {
//    delay(500);
//    Serial.print(".");
//  }
//
//  Serial.println("Ready to go");
//}
//
//void loop() {
//  float lightpercentage = 20;
//  float temp = 30;
//  String temp_s(temp);
//  String lightPer_s(lightpercentage);
//
//  sendData("tag=adc_A0&value=" + lightPer_s);
//  delay(5000);
//}
//
//void sendData(String params) {
//  if (client.connect(server, 80)) {
//    Serial.println("Connected to server");
//
//    // Make an HTTP request
//    client.print("GET /your_path?" + params + " HTTP/1.1");
//    client.println("Host: your_host");
//    client.println("Connection: close");
//    client.println();
//
//    Serial.println("Request sent");
//
//    // Wait for the server's response
//    while (client.connected()) {
//      if (client.available()) {
//        String response = client.readStringUntil('\n');
//        Serial.println(response);
//      }
//    }
//
//    // Disconnect from the server
//    client.stop();
//    Serial.println("Connection closed");
//  } else {
//    Serial.println("Connection failed");
//  }
//}
//#include <UIPEthernet.h>
//#include <HTTPClient.h>
//String GOOGLE_SCRIPT_ID = "AKfycbzvn-m6tYi2oiHbc_CzzAUQbDKZgUz4oTVu_YAGVVGR";
////https://script.google.com/macros/s/AKfycbwhcnmC6cSE_P5MKice-T6GX8pfe4rFFNiKUnY9-vuwE9hwzCA/exec?tag=adc_A0&value=123
////AKfycbwiAbnL8CuywQBqZFowzAp146bNRtpFI7l8jiPM1sTuDsYvqF4zttZKIcPz-cOb0W5aPg
////https://script.google.com/macros/library/d/1gpY94sQt-8tM1YwPXa2yGy9hACUb-H5etbPpeKxDiKARVnOJN307vwBF/1
////https://script.google.com/macros/s/AKfycbwiAbnL8CuywQBqZFowzAp146bNRtpFI7l8jiPM1sTuDsYvqF4zttZKIcPz-cOb0W5aPg/exec
//
//// Ethernet configuration
//byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
//IPAddress server(192, 168, 1, 10); // IP address of your server
//const int serverPort = 80;
//const String serverPath = "/your_path";
//
//const int sendInterval = 5000;
//
//void setup() {
//  Serial.begin(115200);
//  delay(10);
//
//  // Start Ethernet
//  if (!Ethernet.begin(mac)) {
//    Serial.println("Failed to initialize Ethernet");
//    while (1) {
//      delay(1);
//    }
//  }
//
//  Serial.println("Ethernet initialized");
//  Serial.print("IP address: ");
//  Serial.println(Ethernet.localIP());
//}
//
//void loop() {
//  float lightpercentage = 20;
//  float temp = 30;
//  String temp_s(temp);
//  String lightPer_s(lightpercentage);
//
//  sendData("tag=adc_A0&value=" + lightPer_s);
//  delay(sendInterval);
//}
//
//void sendData(String params) {
//  HTTPClient http;
//
//  // Construct the URL
// // String url = "http://" + server.toString() + ":" + String(serverPort) + serverPath + "?" + params;
//   String url="https://script.google.com/macros/s/"+GOOGLE_SCRIPT_ID+"/exec?"+params;
//
//  Serial.print("Sending request to: ");
//  Serial.println(url);
//
//  // Send the HTTP request
//  int httpResponseCode = http.begin(url);
//  if (httpResponseCode > 0) {
//    Serial.print("HTTP Response code: ");
//    Serial.println(httpResponseCode);
//
//    // Read the response
//    String response = http.getString();
//    Serial.println(response);
//  } else {
//    Serial.print("Error sending request. HTTP Response code: ");
//    Serial.println(httpResponseCode);
//  }
//
//  // Close the connection
//  http.end();
//}




//AKfycbyzH8Zz00MJi4NmY1kPTNwDt9YAt1d-QgbMixXGnP9zb1A2mttMVYO8e2d1nzvThz51-Q

//https://script.google.com/macros/s/AKfycbyzH8Zz00MJi4NmY1kPTNwDt9YAt1d-QgbMixXGnP9zb1A2mttMVYO8e2d1nzvThz51-Q/exec

//
//
//#include <SPI.h>
//#include <Ethernet.h>
//#include <HTTPClient.h>
//
//// Ethernet configuration
//byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
//IPAddress ip(192, 168, 1, 177);
//IPAddress server(192, 168, 1, 10); // IP address of your server
//const int serverPort = 80;
//const String serverPath = "/macros/s/AKfycbyLwIrgbWd2rmOkcMP2wAUCPhfKQ_CtpxbTBYtQz99r/dev";
//
//EthernetClient client;
//HTTPClient http;
//
//void setup() {
//  Serial.begin(115200);
//  delay(10);
//
//  // Start Ethernet
//  Ethernet.begin(mac, ip);
//  delay(1000); // Allow the Ethernet module to initialize
//
//  Serial.println("Ethernet initialized");
//  Serial.print("IP address: ");
//  Serial.println(Ethernet.localIP());
//}
//
//void loop() {
//  // Read your sensor data here
//  float sensorValue = 25.5; // Replace with your sensor value
//
//  // Construct the URL
//  String url = "http://" + server + serverPath + "?data=" + String(sensorValue);
//
//  Serial.print("Sending request to: ");
//  Serial.println(url);
//
//  // Send the HTTP request
//  int httpResponseCode = http.begin(url);
//  if (httpResponseCode > 0) {
//    Serial.print("HTTP Response code: ");
//    Serial.println(httpResponseCode);
//
//    // Read the response
//    String response = http.getString();
//    Serial.println(response);
//  } else {
//    Serial.print("Error sending request. HTTP Response code: ");
//    Serial.println(httpResponseCode);
//  }
//
//  // Close the connection
//  http.end();
//
//  delay(5000); // Wait for some time before sending the next request
//}


#include <SPI.h>
#include <EthernetENC.h>
#include <HTTPClient.h>

// Ethernet settings
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 10);
EthernetServer server(80);

// HTTP client settings
EthernetClient client;
HTTPClient http;

void setup() {
  // Initialize Ethernet connection
  Ethernet.begin(mac, ip);
  server.begin();

  // Initialize serial communication
  Serial.begin(9600);
  while (!Serial) {
    ; // Wait for serial port to connect
  }
  
  Serial.println("Ethernet initialized");
}

void loop() {
  // Make sure Ethernet connection is established
  if (Ethernet.linkStatus() == LinkON) {
    // Make an HTTP GET request
    String url = "https://script.google.com/macros/s/AKfycbyLwIrgbWd2rmOkcMP2wAUCPhfKQ_CtpxbTBYtQz99r/dev?data=25.50";
    int httpResponseCode = http.begin(url);
    
    // Check the response code
    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      
      // Read the response body
      String response = http.getString();
      Serial.println("Response:");
      Serial.println(response);
    } else {
      Serial.print("Error sending request. HTTP Response code: ");
      Serial.println(httpResponseCode);
    }
  } else {
    Serial.println("Ethernet connection lost");
  }

  delay(5000); // Wait for 5 seconds before making the next request
}
