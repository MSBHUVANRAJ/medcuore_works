#include <SPI.h>
#include <EthernetWebServer_SSL.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress serverIP(192, 168, 1, 10); // IP address of the server
EthernetSSLClient client;

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Ethernet.init(5); // Initialize ENC28J60 module with CS pin 5

  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // Check for Ethernet hardware present
    if (Ethernet.hardwareStatus() == EthernetNoHardware) {
      Serial.println("Ethernet shield was not found. Cannot run without hardware.");
      while (true);
    }
    if (Ethernet.linkStatus() == LinkOFF) {
      Serial.println("Ethernet cable is not connected.");
      while (true);
    }
  }

  delay(5000); // Wait for the connection to stabilize

  Serial.println("Ethernet Successfully Initialized");
}

void loop() {
  if (Ethernet.linkStatus() == LinkON) {
    Serial.println("Internet connection available");
    if (client.connect(serverIP, 443)) {
      client.print("GET /macros/s/AKfycbyLwIrgbWd2rmOkcMP2wAUCPhfKQ_CtpxbTBYtQz99r/dev?data=25.50 HTTP/1.1\r\n");
      client.print("Host: script.google.com\r\n");
      client.print("Connection: close\r\n\r\n");

      Serial.println("Sending request...");

      while (client.connected()) {
        if (client.available()) {
          char c = client.read();
          Serial.print(c);
        }
      }

      client.stop();

      Serial.println("\nRequest complete");
    } else {
      Serial.println("Failed to connect to the server");
    }
  } else {
    Serial.println("No internet connection");
  }

  delay(5000);
}
