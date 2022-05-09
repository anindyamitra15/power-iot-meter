#include "MinimalWifiManager.h"

MinimalWifiManager::MinimalWifiManager(AsyncWebServer *serverObj)
{
    this->server = serverObj;
}

bool MinimalWifiManager::bindServer()
{

    this->server->serveStatic("/", SPIFFS, "/");
    this->server
        ->on(
            "/",
            HTTP_GET,
            [SPIFFS, this](AsyncWebServerRequest *req)
            { this->to_scan = true;
              req->send(SPIFFS, "/index.html", "text/html"); });

    this->server
        ->on(
            "/scan",
            HTTP_GET,
            [this](AsyncWebServerRequest *req)
            {
                if (!this->numberOfNetworks)
                {
                    // req->send(200, "text/plain", n + " network(s) found");
                    req->send(200, "text/html", String(this->numberOfNetworks) + " network(s) found <br><br>" + scanResults);
                    to_scan = true;
                }
                req->send(200, "text/plain", scanResults);
                this->to_scan = true;
            });

    this->server
        ->on("/save",
             HTTP_POST,
             [this](AsyncWebServerRequest *req)
             {
                 int params = req->params();
                 for (int i = 0; i < params; i++)
                 {
                     AsyncWebParameter *param = req->getParam(i);
                     if (param->isPost())
                     {
                         if (param->name() == String("ssid"))
                         {
                             Serial.print("ssid: ");
                             this->ssid = param->value();
                             Serial.println(ssid);
                         }
                         if (param->name() == String("pass"))
                         {
                             Serial.print("pass: ");
                             this->pass = param->value();
                             Serial.println(pass);
                         }
                     }
                 }
                 req->send(200, "text/html", "{\"ssid\":\"" + ssid + "\", \"pass\":\"" + pass + "\"}");
                 this->setStationMode(true);
             });

    this->server->begin();
    return false;
}

bool MinimalWifiManager::setApMode()
{
    bool success = true;
    success &= WiFi.mode(WIFI_AP);
    success &= WiFi.softAP(AP_SSID, AP_PASS);
    return success;
}

bool MinimalWifiManager::setStationMode(bool disableAp = false)
{
    if (disableAp)
    {
        WiFi.softAPdisconnect();
    }
    WiFi.mode(WIFI_STA);
    if (this->ssid == "")
        WiFi.enableSTA(true);
    else
    {
        WiFi.begin(this->ssid.c_str(), this->pass.c_str());
        WiFi.setAutoConnect(true);
        WiFi.setAutoReconnect(true);
        WiFi.persistent(true);
    }
    return false; // TODO: introduce success flag
}

void MinimalWifiManager::loop()
{
    if (this->to_scan)
    {
        this->numberOfNetworks = WiFi.scanNetworks();
        if (!this->numberOfNetworks)
        {
            return;
        }
        this->scanResults.clear();
        DynamicJsonDocument doc(1024);
        JsonArray aps = doc.to<JsonArray>();
        for (int i = 0; i < numberOfNetworks; ++i)
        {
            // Print SSID and RSSI for each network found
            JsonObject ap = aps.createNestedObject();
            ap["id"] = i + 1;
            ap["ssid"] = WiFi.SSID(i);
            ap["rssi"] = WiFi.RSSI(i);
            ap["enc"] = (WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*";
        }
        serializeJson(aps, this->scanResults);
        this->to_scan = false;
    }
}