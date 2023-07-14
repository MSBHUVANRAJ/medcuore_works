#include <SPI.h>
#include <UIPEthernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
char server[] = "www.google.com";
int port = 80;

EthernetClient client;

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Ethernet.init(5); // Initialize ENC28J60 module with CS pin 5

  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
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
  // Check if there is an internet connection
  if (Ethernet.linkStatus() == LinkON && client.connect(server, port)) {
    Serial.println("Internet connection available");
    // Perform additional internet-related tasks here
    client.stop();
  } else {
    Serial.println("No internet connection");
  }

  delay(5000); // Wait for a few seconds before checking again
}
