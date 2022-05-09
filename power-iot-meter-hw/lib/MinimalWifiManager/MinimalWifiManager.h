#ifndef _MinimalWiFiManager_H_
#define _MinimalWiFiManager_H_

#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>
#include <SPIFFS.h>

#define WM_PORT 80
#define AP_SSID "Power IoT Meter"
#define AP_PASS "powermeter"

class MinimalWifiManager
{
    AsyncWebServer *server;
    bool to_scan = false;
    String scanResults = "";
    String ssid = "", pass = "";
    int numberOfNetworks = 0;
    bool bindServer();
    bool setApMode();
    bool setStationMode(bool disableAp);

public:
    MinimalWifiManager(AsyncWebServer *serverObj);
    bool autoConnect(String ssid, String pass);
    void loop();
};

#endif