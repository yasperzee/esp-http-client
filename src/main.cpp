/**************************** main.cpp ******************************

Description: esp_http_client, baseline for this is esp_http_server

Components:   - ESP-01 esp8266 NodeMcu


Librarys:     -

References:   
  // ESP
    // https://arduino-esp8266.readthedocs.io/en/latest/libraries.html

  // WiFi
    // https://www.arduino.cc/reference/en/libraries/wifi/

  // jSon
    // https://tutorial.eyehunts.com/html/display-formatted-json-in-html-example-code/
    // https://arduinojson.org/v6/example/http-server/
    // https://stackoverflow.com/questions/51748948/how-to-give-a-name-to-json-object
    // https://arduinojson.org/v6/api/jsondocument/createnestedobject/

  // Rest
    // https://www.mischianti.org/2020/05/16/how-to-create-a-rest-server-on-esp8266-and-esp32-startup-part-1/
    // https://github.com/sidoh/rich_http_server/blob/master/examples/SimpleRestServer/SimpleRestServer.ino
    // https://www.arduino.cc/reference/en/libraries/arest/
    // https://github.com/brunoluiz/arduino-restserver
 
ToDo:
*******************************************************************************/
/*------------------------------------------------------------------------------    
Version 0.1    12'22     Yasperzee     esp_http_client

 *********** esp_http_server used as baseline ***************
  Version 1.4     12'22     Yasperzee     Renamed to main.cpp

    
#TODO: test OTA
--------------------------------------------------------------------------------------------*/
#include "node_handlers.h"

extern void do_setup();
//extern void handle_iot_rest_client();




#include <ESP8266WiFi.h>

const char* ssid = "TP-Link_E584";
const char* password = "95085746";

//const char* host = "www.example.com";
const char* host = "192.168.0.158";

void setup() {
  do_setup();
/*
    Serial.begin(115200);
  Serial.println();

  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");
  */
  } // setup

void loop() {    
  //handle_iot_rest_client_requests();
    WiFiClient client;

  Serial.printf("\n[Connecting to %s ... ", host);
  if (client.connect(host, 80))
  {
    Serial.println("connected]");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    Serial.println("[Sending a request]");
    client.print(String("GET /") + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n" +
                 "\r\n"
                );

    Serial.println("[Response:]");
    while (client.connected() || client.available())
    {
      if (client.available())
      {
        String line = client.readStringUntil('\n');
        Serial.println(line);
      }
    }
    client.stop();
    Serial.println("\n[Disconnected]");
  }
  else
  {
    Serial.println("connection failed!]");
    client.stop();
  }
  delay(5000);
  } // loop


    