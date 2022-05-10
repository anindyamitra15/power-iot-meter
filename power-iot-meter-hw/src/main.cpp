#include <Arduino.h>
#include <SPI.h>
#include <SPIFFS.h>
#include <MinimalWifiManager.h>

AsyncWebServer server(80);
MinimalWifiManager wifi(&server, SPIFFS);

void setup()
{
  Serial.begin(115200);
  FileOperation::initFlashFileSystem(SPIFFS);
  // wifi.autoConnect();
  // listDir(SPIFFS);
}

void loop()
{
  wifi.loop();
}
