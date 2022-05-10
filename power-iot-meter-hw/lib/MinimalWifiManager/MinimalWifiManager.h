#ifndef _MinimalWiFiManager_H_
#define _MinimalWiFiManager_H_

#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ArduinoJson.h>
#include <SPIFFS.h>
#include <FileOperation.h>

#define WM_PORT 80
#define AP_SSID "Power IoT Meter"
#define AP_PASS "powermeter"

#define SSID_PATH "/ssid.txt"
#define PASS_PATH "/pass.txt"

class MinimalWifiManager
{
    AsyncWebServer *server;
    fs::SPIFFSFS filesystem;
    bool _to_scan = false;
    String scanResults = "";
    String _ssid = "", _pass = "";
    int numberOfNetworks = 0;
    bool bindServer();
    bool setApMode();
    bool setStationMode(bool disableAp);
    void setSSID(String ssid);
    void setPassword(String pass);

public:
    MinimalWifiManager(AsyncWebServer *serverObj, fs::SPIFFSFS &fs);
    bool autoConnect();
    String getSSID();
    String getPassword();
    bool resetSettings();
    void loop();
};

#endif