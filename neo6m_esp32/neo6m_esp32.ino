//#include <TinyGPS++.h>
//
//// Neo-6M GPS module connections
//const int RX_PIN = 16; // GPS module TX pin connected to ESP32 RX1 pin
//const int TX_PIN = 17; // GPS module RX pin connected to ESP32 TX1 pin
//
//// TinyGPS++ object
//TinyGPSPlus gps;
//
//void setup() {
//  Serial.begin(9600);
//  Serial1.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);
//}
//
//void loop() {
//  while (Serial1.available() > 0) {
//    Serial.println("GPS Connected");
//    if (gps.encode(Serial1.read())) {
//      displayInfo();
//    }
//  }
//}
//
//void displayInfo() {
//  if (gps.location.isValid()) {
//    Serial.print("Latitude: ");
//    Serial.println(gps.location.lat(), 6);
//    Serial.print("Longitude: ");
//    Serial.println(gps.location.lng(), 6);
//    Serial.print("Altitude: ");
//    Serial.println(gps.altitude.meters());
//    Serial.print("Speed: ");
//    Serial.println(gps.speed.kmph());
//    Serial.println("--------------------");
//  } else {
//    Serial.println("GPS data not available");
//  }
//  delay(1000);
//}



// #include <SoftwareSerial.h>
//
// // The serial connection to the GPS module
// SoftwareSerial ss(17, 16);
//void setup(){
//   Serial.begin(115200);
//   ss.begin(9600);
// }
//
//void loop(){
//   while (ss.available() > 0){
////          get the byte data from the GPS
//     byte gpsData = ss.read();
//     Serial.write(gpsData);
//   }
// }


 #include <NeoSWSerial.h>
 NeoSWSerial gpsSerial( 19, 18 );

 void setup()
 {
   Serial.begin( 9600 );
   gpsSerial.begin( 9600 );
 }

 void loop()
 {
   if (gpsSerial.available())
     Serial.write( gpsSerial.read() );
 }
