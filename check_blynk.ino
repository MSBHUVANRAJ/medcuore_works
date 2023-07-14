///*************************************************************
//
//  This is a simple demo of sending and receiving some data.
//  Be sure to check out other examples!
// *************************************************************/
//
///* Fill-in information from Blynk Device Info here */
//#define BLYNK_TEMPLATE_ID "TMPL6-ZQLQa9i"
//#define BLYNK_TEMPLATE_NAME "Quickstart Template"
//#define BLYNK_AUTH_TOKEN "VtCQFey0gDeQ0QagiI0L_YJhC_tGBrkC"
///* Comment this out to disable prints and save space */
//#define BLYNK_PRINT Serial
//
//
//#include <WiFi.h>
//#include <WiFiClient.h>
//#include <BlynkSimpleEsp32.h>
//
//// Your WiFi credentials.
//// Set password to "" for open networks.
//char ssid[] = "Mazeriikkaa";
//char pass[] = "";
//
//BlynkTimer timer;
//
//// This function is called every time the Virtual Pin 0 state changes
//BLYNK_WRITE(V0)
//{
//  // Set incoming value from pin V0 to a variable
//  int value = param.asInt();
//
//  // Update state
//  Blynk.virtualWrite(V1, value);
//}
//
//// This function is called every time the device is connected to the Blynk.Cloud
//BLYNK_CONNECTED()
//{
//  // Change Web Link Button message to "Congratulations!"
//  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
//  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
//  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
//}
//
//// This function sends Arduino's uptime every second to Virtual Pin 2.
//void myTimerEvent()
//{
//  // You can send any value at any time.
//  // Please don't send more that 10 values per second.
//  Blynk.virtualWrite(V2, millis() / 1000);
//}
//
//void setup()
//{
//  // Debug console
//  Serial.begin(115200);
//
//  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
//  // You can also specify server:
//  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
//  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);
//
//  // Setup a function to be called every second
//  timer.setInterval(1000L, myTimerEvent);
//}
//
//void loop()
//{
//  Blynk.run();
//  timer.run();
//  // You can inject your own code or combine it with other sketches.
//  // Check other examples on how to communicate with Blynk. Remember
//  // to avoid delay() function!
//}
//
/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL6-ZQLQa9i"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_FIRMWARE_VERSION "0.1.0"
#define BLYNK_AUTH_TOKEN "x6jH8FuMl5Z0X6ZSbfRE-6ZLogilzzTf"
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <WiFiManager.h>

const int ledPin = LED_BUILTIN;
BlynkTimer timer;

// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0)
{
  // Set incoming value from pin V0 to a variable
  int value = param.asInt();

  // Update state
  Blynk.virtualWrite(V1, value);
}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

// This function sends Arduino's uptime every second to Virtual Pin 2.
void myTimerEvent()
{
  // You can send any value at any time.
  // Please don't send more than 10 values per second.
  Blynk.virtualWrite(V2, millis() / 1000);
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  // Configure Wi-Fi connection using WiFiManager
  WiFiManager wifiManager;
  wifiManager.autoConnect();

  // Get Wi-Fi credentials from WiFiManager
  String ssid = WiFi.SSID();
  String pass = WiFi.psk();

  // Initialize Blynk with Wi-Fi credentials
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid.c_str(), pass.c_str());

  // Setup a function to be called every second
  timer.setInterval(1000L, myTimerEvent);
}

void loop()
{
  Blynk.run();
  led_blink();
  timer.run();
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid using the delay() function!
}

void led_blink()
{
  digitalWrite(ledPin, HIGH);  // Turn on the LED
  delay(1000);                 // Wait for 1 second
  digitalWrite(ledPin, LOW);   // Turn off the LED
  delay(1000);    
}
