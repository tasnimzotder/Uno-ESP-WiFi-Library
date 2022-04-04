#include <Arduino.h>
#include <UnoESPWiFi.h>

UnoESPWiFi esp(2, 3);

void setup() {
    Serial.begin(9600);
    Serial.println("Test UnoESPWiFi");

    esp.serialBegin(115200);
}

void loop() {
    esp.printSerial("test 1");
}