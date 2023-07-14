#include <ETH.h>

void setup() {
  Serial.begin(115200);

  // Start Ethernet
  if (!ETH.begin()) {
    Serial.println("Failed to initialize Ethernet");
    while (true) {
      delay(1);
    }
  }
}

void loop() {
  // Check link status
  bool linkUp = ETH.phyLinkState();
  if (linkUp) {
    Serial.println("Ethernet link is up");
  } else {
    Serial.println("Ethernet link is down");
  }

  // Check connection status
  if (linkUp && ETH.isConnected()) {
    Serial.println("Ethernet is connected");
  } else {
    Serial.println("Ethernet is not connected");
  }

  delay(1000);
}
