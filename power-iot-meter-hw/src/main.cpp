#include <Arduino.h>
#include <SPI.h>
#include <SPIFFS.h>
#include "fileOperation.h"
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>
#include <MinimalWifiManager.h>

AsyncWebServer server(80);
MinimalWifiManager wifi(&server);
bool to_scan;
int n = 0;
String scanResults;

void setup()
{
  Serial.begin(115200);
  initFlashFileSystem(SPIFFS);
  
  listDir(SPIFFS);
}

void loop()
{
  if (to_scan)
  {
    n = WiFi.scanNetworks();
    if (!n)
    {
      return;
    }
    scanResults.clear();
    DynamicJsonDocument doc(1024);
    JsonArray aps = doc.to<JsonArray>();
    for (int i = 0; i < n; ++i)
    {
      // Print SSID and RSSI for each network found
      JsonObject ap = aps.createNestedObject();
      ap["id"] = i + 1;
      ap["ssid"] = WiFi.SSID(i);
      ap["rssi"] = WiFi.RSSI(i);
      ap["enc"] = (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*";
    }
    serializeJson(aps, scanResults);
    to_scan = false;
  }
}
