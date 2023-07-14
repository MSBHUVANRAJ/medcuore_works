//#include <SPI.h>
//#include <EthernetENC.h>
//
//byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
//char server[] = "43.205.74.94";  // IP address of the server
//int port = 8082;  // Port number of the server
//String url = "/topics/";  // URL path for the HTTP POST request
//
//EthernetClient client;
//
//float temp = 27;
//float humidity = 57;
//int pm1_0 = 7;
//int pm2_5 = 18;
//int pm10 = 13;
//int co2 = 1472;
//float co = 10;
//float ch2o = 1250;
//double AQI = 140;
//String payload = "";
//String httpRequestData = "";
//String device_Id = "ESPTEST_1";
//
//void setup()
//{
//  Serial.begin(115200);
//  Ethernet.init(5);         // Set the SPI CS pin for ENC28J60 module
//  Ethernet.begin(mac);
//  delay(1000);
//  Serial.println("Connecting...");
//}
//
//void loop()
//{
//  if (client.connect(server, port))
//  {
//    Serial.println("Connected");
//
//    // Construct the HTTP request
//    String httpRequest = "POST " + url + device_Id + " HTTP/1.1\r\n" +
//                         "Host: " + server + "\r\n" +
//                         "Content-Type: application/vnd.kafka.json.v2+json\r\n" +
//                         "Content-Length: " + String(httpRequestData.length()) + "\r\n" +
//                         "Connection: close\r\n\r\n" +
//                         httpRequestData;
//
//    // Send the HTTP request
//    client.print(httpRequest);
//
//    // Wait for the server's response
//    delay(100);  // Adjust the delay if needed
//
//    // Read and print the server's response
//    while (client.available())
//    {
//      char c = client.read();
//      Serial.write(c);
//    }
//
//    // Disconnect from the server
//    client.stop();
//    Serial.println("HTTP POST request completed");
//
//    delay(10000);  // Delay for 10 seconds before sending the next request
//  }
//  else
//  {
//    Serial.println("Connection failed");
//  }
//}

#include <SPI.h>
#include <EthernetENC.h>

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
char server[] = "43.205.74.94";  // IP address of the server
int port = 8082;  // Port number of the server
String url = "/topics/";  // URL path for the HTTP POST request

EthernetClient client;

float temp = 27;
float humidity = 57;
int pm1_0 = 7;
int pm2_5 = 18;
int pm10 = 13;
int co2 = 1472;
float co = 10;
float ch2o = 1250;
double AQI = 140;
String httpRequestData = "";
String device_Id = "ESPTEST_1";

void setup() {
  Serial.begin(115200);
  Ethernet.init(5);         // Set the SPI CS pin for ENC28J60 module
  Ethernet.begin(mac);
  delay(1000);
  Serial.println("Connecting...");
}

void loop() {
  if (client.connect(server, port)) {
    Serial.println("Connected");

    // Construct the payload JSON
    String payloadJson = "{\r\n";
    payloadJson += "  \"records\": [\r\n";
    payloadJson += "    {\r\n";
    payloadJson += "      \"key\": \"device_id\",\r\n";
    payloadJson += "      \"value\": \"" + device_Id + "\"\r\n";
    payloadJson += "    },\r\n";
    payloadJson += "    {\r\n";
    payloadJson += "      \"key\": \"temperature\",\r\n";
    payloadJson += "      \"value\": \"" + String(temp) + "\"\r\n";
    payloadJson += "    },\r\n";
    payloadJson += "    {\r\n";
    payloadJson += "      \"key\": \"humidity\",\r\n";
    payloadJson += "      \"value\": \"" + String(humidity) + "\"\r\n";
    payloadJson += "    },\r\n";
    payloadJson += "    {\r\n";
    payloadJson += "      \"key\": \"pm1\",\r\n";
    payloadJson += "      \"value\": \"" + String(pm1_0) + "\"\r\n";
    payloadJson += "    },\r\n";
    payloadJson += "    {\r\n";
    payloadJson += "      \"key\": \"pm25\",\r\n";
    payloadJson += "      \"value\": \"" + String(pm2_5) + "\"\r\n";
    payloadJson += "    },\r\n";
    payloadJson += "    {\r\n";
    payloadJson += "      \"key\": \"pm10\",\r\n";
    payloadJson += "      \"value\": \"" + String(pm10) + "\"\r\n";
    payloadJson += "    },\r\n";
    payloadJson += "    {\r\n";
    payloadJson += "      \"key\": \"co2\",\r\n";
    payloadJson += "      \"value\": \"" + String(co2) + "\"\r\n";
    payloadJson += "    },\r\n";
    payloadJson += "    {\r\n";
    payloadJson += "      \"key\": \"co\",\r\n";
    payloadJson += "      \"value\": \"" + String(co) + "\"\r\n";
    payloadJson += "    },\r\n";
    payloadJson += "    {\r\n";
    payloadJson += "      \"key\": \"ch2o\",\r\n";
    payloadJson += "      \"value\": \"" + String(ch2o) + "\"\r\n";
    payloadJson += "    },\r\n";
    payloadJson += "    {\r\n";
    payloadJson += "      \"key\": \"AQI\",\r\n";
    payloadJson += "      \"value\": \"" + String(AQI) + "\"\r\n";
    payloadJson += "    }\r\n";
    payloadJson += "  ]\r\n";
    payloadJson += "}\r\n";

    // Construct the HTTP request
    String httpRequest = "POST " + url + device_Id + " HTTP/1.1\r\n" +
                         "Host: " + server + "\r\n" +
                         "Content-Type: application/vnd.kafka.json.v2+json\r\n" +
                         "Content-Length: " + String(payloadJson.length()) + "\r\n" +
                         "Connection: close\r\n\r\n" +
                         payloadJson;

    // Send the HTTP request
    client.print(httpRequest);

    // Wait for the server's response
    delay(100);  // Adjust the delay if needed

    // Read and print the server's response
    while (client.available()) {
      char c = client.read();
      Serial.write(c);
    }

    // Disconnect from the server
    client.stop();
    Serial.println("HTTP POST request completed");

    delay(10000);  // Delay for 10 seconds before sending the next request
  }
  else {
    Serial.println("Connection failed");
  }
}
