#include <ESP8266WebServer.h>

// LM35DZ thermometer configuration
#define DEVICE_VOLTAGE 3.3
#define ADC_RESOLUTION 1024.0
#define MULTIPLIER 100.0
#define TEMPERATURE_SENSOR_PIN A0

// WiFi access point configuration
const char* ssid = "TEMPERATURE_API";
const char* password = "temperature";

// Network IP configuration
IPAddress address(192, 168, 0, 10);
IPAddress gateway(192, 168, 0, 255);
IPAddress subnet(255, 255, 255, 0);

// HTTP server configuration
#define SERVER_PORT 80
ESP8266WebServer server(SERVER_PORT);


float getTemperature()
{
  float sensorRead = analogRead(TEMPERATURE_SENSOR_PIN);
  float temperature = (sensorRead * DEVICE_VOLTAGE * MULTIPLIER) / ADC_RESOLUTION;
  return temperature;
}

void handleTemperatureRequest() 
{
  float temperature = getTemperature();
  server.send(200, "text/plain", String(temperature));
}


void setup()
{
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(address, gateway, subnet);
  WiFi.softAP(ssid, password);
  
  server.on("/", handleTemperatureRequest);
  server.begin();
}

void loop()
{
  server.handleClient();
}
