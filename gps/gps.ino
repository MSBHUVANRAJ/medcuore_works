#include <SoftwareSerial.h>
// Define the GPS module connection pins
#define GPS_RX_PIN 19
#define GPS_TX_PIN 18
// Create a SoftwareSerial object for GPS communication
SoftwareSerial gpsSerial(GPS_RX_PIN, GPS_TX_PIN);
void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  gpsSerial.begin(9600);
  // Wait for GPS module to stabilize
  delay(5000);
}
void loop() {
  // Check if GPS data is available
  if (gpsSerial.available()) {
    Serial.println("GPS data available"); // Debug statement
    // Read the incoming GPS data
    String gpsData = gpsSerial.readStringUntil('\n');
    // Print the GPS data to the serial monitor
    Serial.println(gpsData);
  } else {
    Serial.println("No GPS data available"); // Debug statement
  }
  delay(5000);
}

/*
 * Rui Santos 
 * Complete Project Details https://randomnerdtutorials.com
 */
// 
//#include <TinyGPS++.h>
//#include <SoftwareSerial.h>
//
//static const int RXPin = 19, TXPin = 18;
//static const uint32_t GPSBaud = 9600;
//
//// The TinyGPS++ object
//TinyGPSPlus gps;
//
//// The serial connection to the GPS device
//SoftwareSerial ss(RXPin, TXPin);
//
//void setup(){
//  Serial.begin(115200);
//  ss.begin(GPSBaud);
//}
//
//void loop(){
//  // This sketch displays information every time a new sentence is correctly encoded.
//  while (ss.available() > 0){
//    gps.encode(ss.read());
//    if (gps.location.isUpdated()){
//      Serial.print("Latitude= "); 
//      Serial.print(gps.location.lat(), 6);
//      Serial.print(" Longitude= "); 
//      Serial.println(gps.location.lng(), 6);
//    }
//  }
//}

//#include <Wire.h>
//#include <TinyGPS++.h>
//#define RXD2 17
//#define TXD2 16
//HardwareSerial neogps(1);
//char   datoCmd = 0;
//#define NMEA 0
//TinyGPSPlus gps;
//void setup() 
//{
//  Serial.begin(9600);
//  neogps.begin(9600, SERIAL_8N1, RXD2, TXD2); 
//  delay(2000);
//
//}
//void loop() 
//{
//if (NMEA)
// {
//    while (neogps.available())
//    {
//     datoCmd  = (char)neogps.read(); 
//     Serial.print (datoCmd );
//    }
// } 
//
//else
// {
//  boolean newData = false;
//  for (unsigned long start = millis(); millis() - start < 1000;)
//  {
//    while (neogps.available())
//    {
//      if (gps.encode(neogps.read()))
//      {
//        newData = true;         
//      }
//    }
//  }  
//
//  if(newData == true)
//  {
//    newData = false;
//    Serial.println(gps.satellites.value());    
//    Visualizacion_Serial();
//  }
//  else
//  {
//    
//  }  
//  
// }
//}
//void Visualizacion_Serial(void)
//{ 
//   
//  if (gps.location.isValid() ==  1)
//  {  
//    Serial.print("Lat: ");
//    Serial.println(gps.location.lat(),6);
//    Serial.print("Lng: ");
//    Serial.println(gps.location.lng(),6);  
//    Serial.print("Speed: ");
//    Serial.println(gps.speed.kmph());    
//    Serial.print("SAT:");
//    Serial.println(gps.satellites.value());
//    Serial.print("ALT:");   
//    Serial.println(gps.altitude.meters(), 0);     
//
//    Serial.print("Date: ");
//    Serial.print(gps.date.day()); Serial.print("/");
//    Serial.print(gps.date.month()); Serial.print("/");
//    Serial.println(gps.date.year());
//
//    Serial.print("Hour: ");
//    Serial.print(gps.time.hour()); Serial.print(":");
//    Serial.print(gps.time.minute()); Serial.print(":");
//    Serial.println(gps.time.second());
//    Serial.println("---------------------------");
//  }
//  else
//  {
//    Serial.println("NO SIgnal gps");  
//  }  
//
//}
//
//#include <SoftwareSerial.h>
//
//// Define the GPS module connection pins
//#define GPS_RX_PIN 17
//#define GPS_TX_PIN 16
//
//// Create a SoftwareSerial object for GPS communication
//SoftwareSerial gpsSerial(GPS_RX_PIN, GPS_TX_PIN);
//
//// Variables to store latitude and longitude
//float latitude = 0.0;
//float longitude = 0.0;
//
//void setup() {
//  // Initialize serial communication
//  Serial.begin(115200);
//  gpsSerial.begin(9600);
//
//  // Wait for GPS module to stabilize
//  delay(2000);
//}
//
//void loop() {
//  // Check if GPS data is available
//  if (gpsSerial.available()) {
//    Serial.println("GPS data available"); // Debug statement
//
//    // Read the incoming GPS data
//    String gpsData = gpsSerial.readStringUntil('\n');
//
//    // Print the GPS data to the serial monitor
//    Serial.println(gpsData);
//
//    // Extract latitude and longitude
//    if (parseGPSData(gpsData)) {
//      // Store latitude and longitude
//      latitude = parseLatitude(gpsData);
//      longitude = parseLongitude(gpsData);
//
//      // Print latitude and longitude
//      Serial.print("Latitude: ");
//      Serial.println(latitude, 6); // Print with 6 decimal places
//      Serial.print("Longitude: ");
//      Serial.println(longitude, 6); // Print with 6 decimal places
//    }
//  } else {
//    Serial.println("No GPS data available"); // Debug statement
//  }
//  delay(5000);
//}
//
//bool parseGPSData(const String& gpsData) {
//  // Implement your parsing logic here
//  // This function should extract and validate the latitude and longitude from the GPS data
//  // Return true if parsing is successful, false otherwise
//  // You need to customize this function based on the format and protocol of your GPS data
//
//  // Example parsing logic for NMEA sentences
//  // Extract latitude and longitude fields using appropriate string manipulation functions
//  // Validate the extracted values
//  // Return true if parsing is successful, false otherwise
//
//  // Placeholder code to be replaced with actual parsing logic
//  // This example assumes a valid NMEA sentence format like "$GPGGA,092132.00,latitude,longitude,..."
//  if (gpsData.startsWith("$GPGGA")) {
//    // Split the GPS data using comma as the delimiter
//    // You may need to adjust the field index based on the specific format of your GPS data
//    String parts[15];
//    int count = 0;
//    int startPos = 0;
//    int endPos = gpsData.indexOf(',');
//
//    while (endPos != -1) {
//      parts[count] = gpsData.substring(startPos, endPos);
//      startPos = endPos + 1;
//      endPos = gpsData.indexOf(',', startPos);
//      count++;
//    }
//
//    // Validate the parsed fields
//    if (count >= 4) {
//      // Extract and validate latitude
//      String latitudeStr = parts[2];
//      float latValue = latitudeStr.toFloat();
//      if (latValue != 0.0) {
//        // Extract and validate longitude
//        String longitudeStr = parts[4];
//        float lonValue = longitudeStr.toFloat();
//        if (lonValue != 0.0) {
//          return true;
//        }
//      }
//    }
//  }
//
//  return false;
//}
//
//float parseLatitude(const String& gpsData) {
//  // Implement your latitude extraction logic here
//  // This function should extract and return the latitude value from the GPS data
//  // You need to customize this function based on the format and protocol of your GPS data
//
//  // Placeholder code to be replaced with actual latitude extraction logic
//  // This example assumes a valid NMEA sentence format like "$GPGGA,092132.00,latitude,longitude,..."
//  if (gpsData.startsWith("$GPGGA")) {
//    // Split the GPS data using comma as the delimiter
//    // You may need to adjust the field index based on the specific format of your GPS data
//    String parts[15];
//    int count = 0;
//    int startPos = 0;
//    int endPos = gpsData.indexOf(',');
//
//    while (endPos != -1) {
//      parts[count] = gpsData.substring(startPos, endPos);
//      startPos = endPos + 1;
//      endPos = gpsData.indexOf(',', startPos);
//      count++;
//    }
//
//    // Extract and return the latitude value
//    if (count >= 4) {
//      return parts[2].toFloat();
//    }
//  }
//
//  return 0.0;
//}
//
//float parseLongitude(const String& gpsData) {
//  // Implement your longitude extraction logic here
//  // This function should extract and return the longitude value from the GPS data
//  // You need to customize this function based on the format and protocol of your GPS data
//
//  // Placeholder code to be replaced with actual longitude extraction logic
//  // This example assumes a valid NMEA sentence format like "$GPGGA,092132.00,latitude,longitude,..."
//  if (gpsData.startsWith("$GPGGA")) {
//    // Split the GPS data using comma as the delimiter
//    // You may need to adjust the field index based on the specific format of your GPS data
//    String parts[15];
//    int count = 0;
//    int startPos = 0;
//    int endPos = gpsData.indexOf(',');
//
//    while (endPos != -1) {
//      parts[count] = gpsData.substring(startPos, endPos);
//      startPos = endPos + 1;
//      endPos = gpsData.indexOf(',', startPos);
//      count++;
//    }
//
//    // Extract and return the longitude value
//    if (count >= 4) {
//      return parts[4].toFloat();
//    }
//  }
//
//  return 0.0;
//}
//#include <SoftwareSerial.h>
//#include <TinyGPS++.h>
//
//// Define the GPS module connection pins
//#define GPS_RX_PIN 19
//#define GPS_TX_PIN 18
//
//// Create a SoftwareSerial object for GPS communication
//SoftwareSerial gpsSerial(GPS_RX_PIN, GPS_TX_PIN);
//
//// Create a TinyGPS++ object
//TinyGPSPlus gps;
//
//void setup() {
//  // Initialize serial communication
//  Serial.begin(115200);
//  gpsSerial.begin(9600);
//
//  // Wait for GPS module to stabilize
//  delay(2000);
//}
//
//void loop() {
//  // Check if GPS data is available
//  if (gpsSerial.available()) {
//    // Read the incoming GPS data
//    while (gpsSerial.available()) {
//      gps.encode(gpsSerial.read());
//    }
//
//    // Check if new GPS data is parsed successfully
//   if (gps.location.isValid()) {
//      // Extract latitude and longitude values
//      float latitude = gps.location.lat();
//      float longitude = gps.location.lng();
//
//      // Print latitude and longitude
//      Serial.print("Latitude: ");
//      Serial.println(latitude, 6);
//      Serial.print("Longitude: ");
//      Serial.println(longitude, 6);
//   } else {
//      Serial.println("Invalid GPS data");
//    }
//  }
//
//  delay(5000);
//}
