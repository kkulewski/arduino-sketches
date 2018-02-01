#include <ESP8266WebServer.h>

const char* ssid = "NETWORK_SSID";
const char* password = "NETWORK_PASSWORD";
ESP8266WebServer server(80);


void handleRequest() 
{
  server.send(200, "text/plain", "Hello from esp8266!");

  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
}


void setup(void)
{
  pinMode(LED_BUILTIN, OUTPUT);  
  digitalWrite(LED_BUILTIN, LOW); 
  
  WiFi.begin(ssid, password);
  server.on("/", handleRequest);
  server.begin();
  
  digitalWrite(LED_BUILTIN, HIGH); 
}


void loop(void)
{
  server.handleClient();
}
