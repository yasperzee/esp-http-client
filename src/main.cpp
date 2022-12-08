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

//#ifdef NODE_HTTP_SERVER
#include "node_handlers_server.h"
//extern void handle_iot_rest_client();
//#elseif defined NODE_HTTP_CLIENT
// do smthing 
//#else
// Please select Node HTTP role
//#endif
extern void do_setup();

#include <ESP8266WiFi.h>

//#ifdef defined NODE_HTTP_CLIENT
// Then, we need the ESP8266HTTPClient library, which provides the methods to send HTTP requests.
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
//#include "ArduinoJson.h"
//#endif






//#define SERVER_IP "192.168.0.158"
String  server_ip = "192.168.0.164"; // ThinkPad
void setup() {
  do_setup();
  } // setup

void loop() {    

    //(client.begin(client, mainURL+user+"&temp="+temperature+"&type="+type));

if (WiFi.status() == WL_CONNECTED) { //Check WiFi connection status

WiFiClient client;
//ESP8266WebClient client(HTTP_REST_PORT);

HTTPClient http;  //Declare an object of class HTTPClient

String serverName = "http://192.168.0.164:8082/node-data";


//http.begin(client, serverPath.c_str());

http.begin(client,serverName.c_str());  //Specify request destination	
//http.begin(client,"http://jsonplaceholder.typicode.com/users/1");

http.addHeader("Content-Type", "text/json", false,true);

int httpCode = http.GET();                                  //Send the request
//int httpCode = http.POST("{\"hello\":\"world\"}");
Serial.print("httpCode: ");
Serial.println(httpCode);

if (httpCode > 0) { //Check the returning code
  String payload = http.getString();   //Get the request response payload
  Serial.println(payload);             //Print the response payload     
  }

http.end(); 
}
delay(5000);   
  } // loop
/*
  if (WiFi.status() == WL_CONNECTED) { 

  WiFiClient client;
  HTTPClient http;


    Serial.println("[HTTP] begin...\n");
    // configure traged server and url
    http.begin(client, "http://" SERVER_IP "/node-data");  // HTTP
    http.addHeader("Content-Type", "application/json");

    Serial.print("[HTTP] PUT... ");
    // start connection and send HTTP header and body
    int httpCode = http.GET("{\"settings\":\"none\"}");
                          
    // httpCode will be negative on error
    if (httpCode > 0) {
      // HTTP header has been send and Server response header has been handled
      Serial.printf("[HTTP] PUT... code: %d\n", httpCode);

      // file found at server
      if (httpCode == HTTP_CODE_OK) {
        const String& payload = http.getString();
        Serial.println("received payload:\n<<");
        Serial.println(payload);
        Serial.println(">>");
      }
    } else {
      Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
    }

    http.end();
  }
*/


 /*   	
  HTTPClient rest_client;

  rest_client.begin("192.168.0.158");

  	
  int httpCode = http.GET();

*/



/*    
    WiFiClient rest_client;

  Serial.printf("\n[Connecting to %s ... ", host);
  if (rest_client.connect(host, 80))
  {
    Serial.println("connected]");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    Serial.println("[Sending a request]");
    rest_client.print(String("GET /") + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n" +
                 "\r\n"
                );

    Serial.println("[Response:]");
    while (rest_client.connected() || rest_client.available())
    {
      if (rest_client.available())
      {
        String line = rest_client.readStringUntil('\n');
        Serial.println(line);
      }
    }
    rest_client.stop();
    Serial.println("\n[Disconnected]");
  }
  else
  {
    Serial.println("connection failed!]");
    rest_client.stop();
  }
  delay(5000);
*/  
 


    