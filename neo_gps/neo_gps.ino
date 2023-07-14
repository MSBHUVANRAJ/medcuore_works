void setup() {
  // Initialize the serial communication
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, 18, 19);  // ESP32's serial2 port connected to GPS module

  // Wait for the GPS module to initialize
  delay(1000);

  // Send an AT command to the GPS module
  Serial2.println("AT");
}

void loop() {
  // Check for any incoming data from the GPS module
  Serial2.println("AT");
  delay(1000);
  while (Serial2.available()) {
    char c = Serial2.read();
    // Process the incoming data from the GPS module
    // ...
  }
}
