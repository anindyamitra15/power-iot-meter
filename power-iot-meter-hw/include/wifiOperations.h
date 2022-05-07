#ifndef _wifiOperations_H_
#define _wifiOperations_H_
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
AsyncWebServer server(80);

void initWiFiAP()
{
    WiFi.mode(WIFI_AP);
    IPAddress IP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(IP);
    WiFi.softAP("Power Meter", "PowerMeter");
}

void bindServer()
{
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *req)
              { req->send(200, "text/plain", "Hello there"); });

    server.begin(); 
}

void unbindServer()
{
    server.end();
}

/**
 * TODO:
 * auto connect
 * disconnect
 * 
 * 
 */

#endif