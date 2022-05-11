#include <Arduino.h>
#include <SPI.h>
#include <SPIFFS.h>
#include <MinimalWifiManager.h>

AsyncWebServer server(80);


void setup()
{
  Serial.begin(115200);
  Serial.println("setup");
  MinimalWifiManager wifi(&server, SPIFFS);
  wifi.begin();
  wifi.resetSettings();
  wifi.autoConnect();
  Serial.println("Exiting setup()..");
  // listDir(SPIFFS);
}

void loop()
{
  // wifi.loop();
}
