# Uno ESP-Wi-Fi Library

Library for connecting Arduino Uno to ESP-WiFi and sending data to the internet.

## Add the library (Install)

1. Download the library (this GitHub repository).
1. Unzip the library.
1. Copy the folder `uno-esp-wifi-library` to the Arduino libraries directory.

## Usage

include the library in your sketch and create an instance of the class with the following parameters:

- `Rx`: Rx pin connected to `Tx` pin of ESP-01 (default: `D2`)
- `Tx`: Tx pin connected to `Rx` pin of ESP-01 (default: `D3`)
- `ssid`: SSID of the network
- `password`: Password of the network
- `server`: IP address of the server
- `API_KEY`: API key of the server

```cpp
#include <Arduino.h>
#include <UnoESPWiFi.h>

// create an instance of the class
UnoESPWiFi wifi(2, 3);

void setup() {
    // initialize wifi with baud rate of 115200
    wifi.serialBegin(115200);

    // connect to wifi network
    wifi.connect("ssid", "password");

    // server config
    wifi.ServerConfig("server", 80);
}

void loop () {
    String data = "hello from another universe!");

    // send data to server (example - thingspeak)
    String data = "GET /update?api_key=";
    data += "API_KEY";
    data += "&field1=";
    data += String(data);
    data += "\r\n\r\n";
    
    wifi.writeToServer(data);

    delay(5000);
}
```

## Functions

| Function | Description | Parameters | Return |
|----------|-------------|-----------|-------|
| `serialBegin(baud)` | Initialize the serial port with the given baud rate | `baud`: unsigned long | `void` |
| `connect(ssid, password)` | Connect to the wifi network | `ssid`: String, `password`: String | `String` |
| `serverConfig(server, port)` | Configure the server with the given IP address and port | `server`: String, `port`: unsigned int | `void` |
| `writeToServer(data)` | Send data to the server | `data`: String | `String` |
| `printString(data)` | Print the given string | `data`: String | `void` |

## License

This library is licensed under the [MIT License](./LICENSE).
