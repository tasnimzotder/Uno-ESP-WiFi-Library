/**
 * @file uno-esp-wifi.h
 * @author Tasnim Zotder <hello@tasnimzotder.com>
 * @brief Library for Arduino to communicate with ESP-01 to send data to server
 * @version 0.1
 * @date 2022-04-04
 *
 * @copyright Tasnim Zotder (c) 2022
 */

#ifndef UNOESPWIFI_H
#define UNOESPWIFI_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class UnoESPWiFi {
private:
    String serverIP;
    int serverPort;

public:
    SoftwareSerial* espSerial;

    UnoESPWiFi(int Rx, int Tx);
    ~UnoESPWiFi();

    void serialBegin(unsigned long baudRate);

    // set configs
    String connect(String ssid, String password);
    void serverConfig(String host, int port);

    // commands
    String connectToServer(String serverIP, int serverPort);
    String writeToServer(String cmd);

    // test functions
    void printSerial(String msg);
};

#endif