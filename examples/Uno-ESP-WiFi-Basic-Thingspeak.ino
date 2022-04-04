#include <Arduino.h>
#include <UnoESPWiFi.h>

// configs
String api_key = "";
String server_addr = "";
String wifi_ssid = "";
String wifi_password = "";

// pins
const int wifi_rx = 2;  // D2
const int wifi_tx = 3;  // D3

// create an instance of the class
UnoESPWiFi wifi(wifi_rx, wifi_tx);

void setup() {
    // initialize wifi with baud rate of 115200
    wifi.serialBegin(115200);

    // connect to wifi network
    wifi.connect(wifi_ssid, wifi_password);

    // server config
    wifi.ServerConfig(server_addr, 80);
}

void loop() {
    String data = "hello from another universe!";

    // send data to server (example - thingspeak)
    String data = "GET /update?api_key=";
    data += "API_KEY";
    data += "&field1=";
    data += String(data);
    data += "\r\n\r\n";

    wifi.writeToServer(data);

    delay(5000);
}