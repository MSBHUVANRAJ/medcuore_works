#include <SPI.h>
#include <Ethernet.h>
#include <HTTPClient.h>
//Things to change
String GOOGLE_SCRIPT_ID = "1gpY94sQt-8tM1YwPXa2yGy9hACUb-H5etbPpeKxDiKARVnOJN307vwBF";
//https://script.google.com/macros/s/AKfycbwhcnmC6cSE_P5MKice-T6GX8pfe4rFFNiKUnY9-vuwE9hwzCA/exec?tag=adc_A0&value=123
//AKfycbwiAbnL8CuywQBqZFowzAp146bNRtpFI7l8jiPM1sTuDsYvqF4zttZKIcPz-cOb0W5aPg
//https://script.google.com/macros/library/d/1gpY94sQt-8tM1YwPXa2yGy9hACUb-H5etbPpeKxDiKARVnOJN307vwBF/1
//https://script.google.com/macros/s/AKfycbwiAbnL8CuywQBqZFowzAp146bNRtpFI7l8jiPM1sTuDsYvqF4zttZKIcPz-cOb0W5aPg/exec

const int sendInterval = 5000;
//updated 04.12.2019
const char *root_ca = \
"-----BEGIN CERTIFICATE-----\n" \
"MIIDujCCAqKgAwIBAgILBAAAAAABD4Ym5g0wDQYJKoZIhvcNAQEFBQAwTDEgMB4G\n" \
"A1UECxMXR2xvYmFsU2lnbiBSb290IENBIC0gUjIxEzARBgNVBAoTCkdsb2JhbFNp\n" \
"Z24xEzARBgNVBAMTCkdsb2JhbFNpZ24wHhcNMDYxMjE1MDgwMDAwWhcNMjExMjE1\n" \
"MDgwMDAwWjBMMSAwHgYDVQQLExdHbG9iYWxTaWduIFJvb3QgQ0EgLSBSMjETMBEG\n" \
"A1UEChMKR2xvYmFsU2lnbjETMBEGA1UEAxMKR2xvYmFsU2lnbjCCASIwDQYJKoZI\n" \
"hvcNAQEBBQADggEPADCCAQoCggEBAKbPJA6+Lm8omUVCxKs+IVSbC9N/hHD6ErPL\n" \
"v4dfxn+G07IwXNb9rfF73OX4YJYJkhD10FPe+3t+c4isUoh7SqbKSaZeqKeMWhG8\n" \
"eoLrvozps6yWJQeXSpkqBy+0Hne/ig+1AnwblrjFuTosvNYSuetZfeLQBoZfXklq\n" \
"tTleiDTsvHgMCJiEbKjNS7SgfQx5TfC4LcshytVsW33hoCmEofnTlEnLJGKRILzd\n" \
"C9XZzPnqJworc5HGnRusyMvo4KD0L5CLTfuwNhv2GXqF4G3yYROIXJ/gkwpRl4pa\n" \
"zq+r1feqCapgvdzZX99yqWATXgAByUr6P6TqBwMhAo6CygPCm48CAwEAAaOBnDCB\n" \
"mTAOBgNVHQ8BAf8EBAMCAQYwDwYDVR0TAQH/BAUwAwEB/zAdBgNVHQ4EFgQUm+IH\n" \
"V2ccHsBqBt5ZtJot39wZhi4wNgYDVR0fBC8wLTAroCmgJ4YlaHR0cDovL2NybC5n\n" \
"bG9iYWxzaWduLm5ldC9yb290LXIyLmNybDAfBgNVHSMEGDAWgBSb4gdXZxwewGoG\n" \
"3lm0mi3f3BmGLjANBgkqhkiG9w0BAQUFAAOCAQEAmYFThxxol4aR7OBKuEQLq4Gs\n" \
"J0/WwbgcQ3izDJr86iw8bmEbTUsp9Z8FHSbBuOmDAGJFtqkIk7mpM0sYmsL4h4hO\n" \
"291xNBrBVNpGP+DTKqttVCL1OmLNIG+6KYnX3ZHu01yiPqFbQfXf5WRDLenVOavS\n" \
"ot+3i9DAgBkcRcAtjOj4LaR0VknFBbVPFd5uRHg5h6h+u/N5GJG79G+dwfCMNYxd\n" \
"AfvDbbnvRG15RjF+Cv6pgsH/76tuIMRQyV+dTZsXjAzlAcmgQWpzU/qlULRuJQ/7\n" \
"TBj0/VLZjmmx6BEP3ojY+x1J96relc8geMJgEtslQIxq/H5COEBkEveegeGTLg==\n" \
"-----END CERTIFICATE-----\n";

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED }; // Change the MAC address

IPAddress server(192, 168, 1, 10); // Change the server IP address

EthernetClient client;

void setup() {
  Serial.begin(115200);
  delay(10);

  Ethernet.begin(mac);
  delay(1000); // Allow the Ethernet module to initialize

  Serial.println("Started");
  Serial.print("Connecting");

  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }

  while (Ethernet.linkStatus() != LinkON) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("Ready to go");
}
void loop() {
  float lightpercentage = 20;
  float temp = 30;
  String temp_s(temp);
  String lightPer_s(lightpercentage);

  sendData("tag=adc_A0&value=" + lightPer_s);
  delay(sendInterval);
}

void sendData(String params) {
  if (client.connect(server, 80)) {
    Serial.println("Connected to server");

    // Make an HTTP request
    client.print("GET /your_path?" + params + " HTTP/1.1");
    client.println("Host: your_host");
    client.println("Connection: close");
    client.println();

    Serial.println("Request sent");

    // Wait for the server's response
    while (client.connected()) {
      if (client.available()) {
        String response = client.readStringUntil('\n');
        Serial.println(response);
      }
    }

    // Disconnect from the server
    client.stop();
    Serial.println("Connection closed");
  } else {
    Serial.println("Connection failed");
  }
}
