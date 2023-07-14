#include "GSheet32.h"
#include <Ethernet.h>
#include <HTTPClient.h>

HTTPClient client;
EthernetClient ethClient;
GSheet32::GSheet32(String GAS_ID){
    _GAS_ID = GAS_ID;
}

void GSheet32::connectEthernet(){
    byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
    Ethernet.begin(mac);
    delay(5000); // Wait for the connection to stabilize
    Serial.println("Ethernet Successfully Initialized");
}

void GSheet32::sendData(String colC){
    String url = "http://script.google.com/macros/s/" + _GAS_ID + "/exec?value1=" + colC;
    client.get(url, ethClient);
    while (client.available()) {
        String line = client.readStringUntil('\r');
        Serial.print(line);
    }
}

void GSheet32::sendData(String colC, String colD){
    String url = "http://script.google.com/macros/s/" + _GAS_ID + "/exec?value1=" + colC + "&value2=" + colD;
    client.get(url, ethClient);
    while (client.available()) {
        String line = client.readStringUntil('\r');
        Serial.print(line);
    }
}

void GSheet32::sendData(String colC, String colD, String colE){
    String url = "http://script.google.com/macros/s/" + _GAS_ID + "/exec?value1=" + colC + "&value2=" + colD + "&value3=" + colE;
    client.get(url, ethClient);
    while (client.available()) {
        String line = client.readStringUntil('\r');
        Serial.print(line);
    }
}

void GSheet32::sendData(String colC, String colD, String colE, String colF){
    String url = "http://script.google.com/macros/s/" + _GAS_ID + "/exec?value1=" + colC + "&value2=" + colD + "&value3=" + colE + "&value4=" + colF;
    client.get(url, ethClient);
    while (client.available()) {
        String line = client.readStringUntil('\r');
        Serial.print(line);
    }
}

void GSheet32::sendData(String colC, String colD, String colE, String colF, String colG){
    String url = "http://script.google.com/macros/s/" + _GAS_ID + "/exec?value1=" + colC + "&value2=" + colD + "&value3=" + colE + "&value4=" + colF + "&value5=" + colG;
    client.get(url, ethClient);
    while (client.available()) {
        String line = client.readStringUntil('\r');
        Serial.print(line);
    }
}

void GSheet32::clearData(){
    String url = "http://script.google.com/macros/s/" + _GAS_ID + "/exec?clearData=true";
    client.get(url, ethClient);
    while (client.available()) {
        String line = client.readStringUntil('\r');
        Serial.print(line);
    }
}
