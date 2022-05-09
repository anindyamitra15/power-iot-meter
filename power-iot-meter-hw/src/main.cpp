#include <Arduino.h>
#include <SPI.h>
#include <SPIFFS.h>
#include "fileOperation.h"
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>

AsyncWebServer server(80);
bool to_scan;
int n = 0;
String scanResults;

void setup()
{
  Serial.begin(115200);
  initFlashFileSystem(SPIFFS);

  WiFi.mode(WIFI_AP);
  WiFi.softAP("Power IoT Meter", "powermeter");
  
  server.serveStatic("/", SPIFFS, "/");
  server
      .on(
          "/",
          HTTP_GET,
          [](AsyncWebServerRequest *req)
          { to_scan = true;
              req->send(SPIFFS, "/index.html", "text/html"); });

  server
      .on(
          "/scan",
          HTTP_GET,
          [](AsyncWebServerRequest *req)
          {
            if (!n)
            {
              // req->send(200, "text/plain", n + " network(s) found");
              req->send(200, "text/html", String(n) + " network(s) found <br><br>" + scanResults);
              to_scan = true;
            }
            req->send(200, "text/plain", scanResults);
            to_scan = true;
          });

  server
      .on("/save",
          HTTP_POST,
          [](AsyncWebServerRequest *req)
          {
            int params = req->params();
            String ssid, pass;
            for (int i = 0; i < params; i++)
            {
              AsyncWebParameter *param = req->getParam(i);
              if (param->isPost())
              {
                if (param->name() == String("ssid"))
                {
                  Serial.print("ssid: ");
                  ssid = param->value();
                  Serial.println(ssid);
                }
                if (param->name() == String("pass"))
                {
                  Serial.print("pass: ");
                  pass = param->value();
                  Serial.println(pass);
                }
              }
            }

            req->send(200, "text/html", "{\"ssid\":\"" + ssid + "\", \"pass\":\"" + pass + "\"}");
          });

  server.begin();

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
