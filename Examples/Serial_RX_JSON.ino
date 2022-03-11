/*  Code for Serial Communication using ArduinoJson library.
 *  Transmitt data using Json between ESP Boards and/or Arduino Boards.
 *  Devloped by Joshi Jay 
 *  github.com/JayJoshi16
*/

#include <ArduinoJson.h>
//#include<SoftwareSerial.h> //You can also use SoftwareSerial library
#define RXD2 16
#define TXD2 17

StaticJsonDocument<256> doc;
String jsondata;

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2); //Hardware Serial of ESP32
}

void loop() {
  if (Serial2.available()) {
    jsondata = Serial2.readStringUntil('\n');

    deserializeJson(doc, jsondata);

    const char* data = doc["stringdata"];
    long time          = doc["timestamp"];

    Serial.println("Recieved : ");
    Serial.println(jsondata);
    Serial.println(data);
    Serial.println(time);

  }
}
