#include <UIPEthernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    delay(10);
  }

  // Start Ethernet
  Ethernet.begin(mac);

  Serial.print("DHCP assigned IP: ");
  Serial.println(Ethernet.localIP());
}

void loop() {
//  // Check link status
//  EthernetLinkStatus linkStatus = Ethernet.linkStatus();
//  if (linkStatus == LinkON) {
//    Serial.println("Ethernet link is ON");
//  } else if (linkStatus == LinkOFF) {
//    Serial.println("Ethernet link is OFF");
//  }
//
//  // Check connection status by making an HTTP request to a known website
//  EthernetClient client;
//  if (client.connect("www.google.com", 80)) {
//    client.print("GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n");
//    delay(500); // Wait for server response
//
//    if (client.available()) {
//      // Read and print the first line of the response
//      String response = client.readStringUntil('\r');
//      Serial.println("Received response: " + response);
//    }
//
//    client.stop();
//  } else {
//    Serial.println("Failed to connect to the website");
//  }

  delay(1000);
}
