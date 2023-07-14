#include "GSheet32.h"
#include <UIPEthernet.h>

UIPEthernetClass eth;
EthernetClient client;
GSheet32::GSheet32(String GAS_ID){
    _GAS_ID = GAS_ID;
}

void GSheet32::connectEthernet(){
    uint8_t mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
    if (eth.begin(mac) == 0) {
        Serial.println("Failed to configure Ethernet using DHCP");
        // Check for Ethernet hardware present
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

void GSheet32::sendData(String colC){
    String url = "https://script.google.com/macros/s/" + _GAS_ID + "/exec?value1=" + colC;
    if (client.connect(server, 443)) {
        client.print("GET " + url + " HTTP/1.1\r\n" +
                     "Host: " + server + "\r\n" +
                     "Connection: close\r\n\r\n");
        while (!client.available()) {
            delay(1);
        }
        while (client.available()) {
            String line = client.readStringUntil('\r');
            Serial.print(line);
        }
    }
    else {
        Serial.println("Failed to connect to server");
    }
    client.stop();
}

void GSheet32::sendData(String colC, String colD){
    String url = "https://script.google.com/macros/s/" + _GAS_ID + "/exec?value1=" + colC + "&value2=" + colD;
    if (client.connect(server, 443)) {
        client.print("GET " + url + " HTTP/1.1\r\n" +
                     "Host: " + server + "\r\n" +
                     "Connection: close\r\n\r\n");
        while (!client.available()) {
            delay(1);
        }
        while (client.available()) {
            String line = client.readStringUntil('\r');
            Serial.print(line);
        }
    }
    else {
        Serial.println("Failed to connect to server");
    }
    client.stop();
}

void GSheet32::sendData(String colC, String colD, String colE){
    String url = "https://script.google.com/macros/s/" + _GAS_ID + "/exec?value1=" + colC + "&value2=" + colD + "&value3=" + colE;
    if (client.connect(server, 443)) {
        client.print("GET " + url + " HTTP/1.1\r\n" +
                     "Host: " + server + "\r\n" +
                     "Connection: close\r\n\r\n");
        while (!client.available()) {
            delay(1);
        }
        while (client.available()) {
            String line = client.readStringUntil('\r');
            Serial.print(line);
        }
    }
    else {
        Serial.println("Failed to connect to server");
    }
    client.stop();
}

void GSheet32::sendData(String colC, String colD, String colE, String colF){
    String url = "https://script.google.com/macros/s/" + _GAS_ID + "/exec?value1=" + colC + "&value2=" + colD + "&value3=" + colE + "&value4=" + colF;
    if (client.connect(server, 443)) {
        client.print("GET " + url + " HTTP/1.1\r\n" +
                     "Host: " + server + "\r\n" +
                     "Connection: close\r\n\r\n");
        while (!client.available()) {
            delay(1);
        }
        while (client.available()) {
            String line = client.readStringUntil('\r');
            Serial.print(line);
        }
    }
    else {
        Serial.println("Failed to connect to server");
    }
    client.stop();
}

void GSheet32::sendData(String colC, String colD, String colE, String colF, String colG){
    String url = "https://script.google.com/macros/s/" + _GAS_ID + "/exec?value1=" + colC + "&value2=" + colD + "&value3=" + colE + "&value4=" + colF + "&value5=" + colG;
    if (client.connect(server, 443)) {
        client.print("GET " + url + " HTTP/1.1\r\n" +
                     "Host: " + server + "\r\n" +
                     "Connection: close\r\n\r\n");
        while (!client.available()) {
            delay(1);
        }
        while (client.available()) {
            String line = client.readStringUntil('\r');
            Serial.print(line);
        }
    }
    else {
        Serial.println("Failed to connect to server");
    }
    client.stop();
}

void GSheet32::clearData(){
    String url = "https://script.google.com/macros/s/" + _GAS_ID + "/exec?clearData=true";
    if (client.connect(server, 443)) {
        client.print("GET " + url + " HTTP/1.1\r\n" +
                     "Host: " + server + "\r\n" +
                     "Connection: close\r\n\r\n");
        while (!client.available()) {
            delay(1);
        }
        while (client.available()) {
            String line = client.readStringUntil('\r');
            Serial.print(line);
        }
    }
    else {
        Serial.println("Failed to connect to server");
    }
    client.stop();
}
