#include <Arduino.h>
#include <SPI.h>
#include <SPIFFS.h>
#include <MinimalWifiManager.h>

AsyncWebServer server(80);
MinimalWifiManager wifi;

void setup()
{
  Serial.begin(115200);
  Serial.println("setup");
  wifi.begin(&server, SPIFFS);
  // wifi.resetSettings();
  wifi.autoConnect();
  Serial.println("Exiting setup()..");
  FileOperation::listDir(SPIFFS);
}

void loop()
{
  wifi.loop();
}
