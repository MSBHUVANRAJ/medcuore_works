#include <Arduino.h>
#define BLYNK_TEMPLATE_ID "TMPL6-ZQLQa9i"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_FIRMWARE_VERSION "0.1.1"
//#define BLYNK_AUTH_TOKEN "x6jH8FuMl5Z0X6ZSbfRE-6ZLogilzzTf"
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#define APP_DEBUG 
#include "BlynkEdgent.h" 
const int ledPin = LED_BUILTIN;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  delay(100);
  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  led_blink();

}
void led_blink()
{
   digitalWrite(ledPin, HIGH);  // Turn on the LED
  delay(200);                 // Wait for 1 second
  digitalWrite(ledPin, LOW);   // Turn off the LED
  delay(1000);                 // Wait for 1 second
}
