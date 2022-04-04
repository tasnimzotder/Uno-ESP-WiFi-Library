/**
 * @file   UnoESPWiFi.cpp
 * @author Tasnim Zotder <hello@tasnimzotder.com>
 * @brief Library for Arduino to communicate with ESP-01 to send data to server
 * @version 0.1
 * @date 2022-04-04
 *
 * @copyright Tasnim Zotder (c) 2022
 */

#include "UnoESPWiFi.h"

#include <Arduino.h>

UnoESPWiFi::~UnoESPWiFi() {
    delete espSerial;
}

UnoESPWiFi::UnoESPWiFi(int Rx, int Tx) {
    espSerial = new SoftwareSerial(Rx, Tx);
}

void UnoESPWiFi::serialBegin(unsigned long baudRate) {
    espSerial->begin(baudRate);
}

// set configs
String UnoESPWiFi::connect(String ssid, String password) {
    espSerial->println("AT+RST");
    delay(2000);

    Serial.print("connecting to wifi: ");

    int time_check = 0;
    String response = "";

    while (time_check < 4) {
        Serial.print(".");
        espSerial->print("AT+CWJAP=\"" + ssid + "\",\"" + password + "\"\r\n");

        espSerial->setTimeout(5000);

        if (espSerial->find("WIFI CONNECTED\r\n") == 1) {
            response = "\nWIFI CONNECTED";
            break;
        }

        time_check++;
        response = "\nWIFI NOT CONNECTED";
    }

    Serial.println(response);
    return response;
}

void UnoESPWiFi::serverConfig(String host, int port) {
    UnoESPWiFi::serverIP = host;
    UnoESPWiFi::serverPort = port;
}

// commands
String UnoESPWiFi::connectToServer(String serverIP, int serverPort) {
    espSerial->flush();

    espSerial->println("AT+CIPSTART=\"TCP\",\"" + serverIP + "\"," + serverPort + "\r\n");

    if (espSerial->find("ERROR") == 1) {
        return "ERROR";
    }

    return "OK";
}

String UnoESPWiFi::writeToServer(String cmdStr) {
    connectToServer(UnoESPWiFi::serverIP, UnoESPWiFi::serverPort);

    cmdStr += "\r\n\r\n";

    String cmd = "AT+CIPSEND=" + String(cmdStr.length()) + "\r\n";

    espSerial->println(cmd);
    delay(1000);

    // Todo: need to implement the check for ">" string in return value
    if (true) {
        espSerial->print(cmdStr);
        delay(500);

        String msgBody = "";
        while (espSerial->available()) {
            String line = espSerial->readStringUntil('\n');

            if (line.length() == 1) {
                msgBody = espSerial->readStringUntil('\n');
            }
        }

        return msgBody;
    }

    return "ERROR";
}

// test functions
void UnoESPWiFi::printSerial(String msg) {
    Serial.println(msg);
}