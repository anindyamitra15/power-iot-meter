#include <Arduino.h>
#include <SPI.h>
#include <SPIFFS.h>
#include "fileOperation.h"
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
AsyncWebServer server(80);

void setup()
{
  Serial.begin(115200);
  initFlashFileSystem(SPIFFS);

  WiFi.mode(WIFI_STA);
  WiFi.begin("AKM_MACHINE_ULTRA", "zaq12wsx");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println('.');
    delay(1000);
  }
  Serial.println(WiFi.localIP());
  server.serveStatic("/", SPIFFS, "/");
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *req)
            { req->send(SPIFFS, "/index.html", "text/html"); });

  server.on("/scan",
            HTTP_GET,
            [](AsyncWebServerRequest *req)
            {
              int n = WiFi.scanNetworks();
              if (!n)
              {
                req->send(200, "text/plain", n + " network(s) found");
              }
              String dump = "";
              for (int i = 0; i < n; ++i)
              {
                // Print SSID and RSSI for each network found
                // Serial.print(i + 1);
                // Serial.print(": ");
                dump += WiFi.SSID(i);
                dump += " ";
                dump += WiFi.RSSI(i);
                dump += " ";
                dump += (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*";
                dump += "\n";
              }
              req->send(200, "text/plain", dump);
              dump.clear();
            });

  server.begin();
  listDir(SPIFFS);
}

void loop()
{
}