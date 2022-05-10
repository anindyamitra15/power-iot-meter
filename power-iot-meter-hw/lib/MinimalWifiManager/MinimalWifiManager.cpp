#include "MinimalWifiManager.h"

MinimalWifiManager::MinimalWifiManager(AsyncWebServer *serverObj, fs::SPIFFSFS &fs)
{
    this->server = serverObj;
    this->filesystem = fs; // FIXME: test this reference
}

String MinimalWifiManager::getSSID()
{
    return FileOperation::readFile(this->filesystem, SSID_PATH);
}

void MinimalWifiManager::setSSID(String ssid)
{
    this->_ssid = ssid;
    FileOperation::writeFile(this->filesystem, SSID_PATH, ssid);
}

String MinimalWifiManager::getPassword()
{
    return FileOperation::readFile(this->filesystem, PASS_PATH);
}

void MinimalWifiManager::setPassword(String pass)
{
    this->_pass = pass;
    FileOperation::writeFile(this->filesystem, PASS_PATH, pass);
}

bool MinimalWifiManager::autoConnect()
{
    /**
     * @brief
     * attempts connection
     * checks failure
     * if no connection details present
     * check ssid.txt and pass.txt
     * if wrong credential
     * stop station mode
     * start ap mode
     * take credentisls, attempts to connect
     * after successful connection save credential to ssid.txt and pass.txt
     */
    return false; // FIXME: introduce success flag
}

bool MinimalWifiManager::resetSettings()
{
    return false; // FIXME: introduce success flag
}

bool MinimalWifiManager::bindServer()
{

    this->server->serveStatic("/", SPIFFS, "/");
    this->server
        ->on(
            "/",
            HTTP_GET,
            [this](AsyncWebServerRequest *req)
            { this->_to_scan = true;
              req->send(this->filesystem, "/index.html", "text/html"); });

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
                    _to_scan = true;
                }
                req->send(200, "text/plain", scanResults);
                this->_to_scan = true;
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
                             this->_ssid = param->value();
                             Serial.println(_ssid);
                         }
                         if (param->name() == String("pass"))
                         {
                             Serial.print("pass: ");
                             this->_pass = param->value();
                             Serial.println(_pass);
                         }
                     }
                 }
                 req->send(200, "text/html", "{\"ssid\":\"" + _ssid + "\", \"pass\":\"" + _pass + "\"}");
                 this->setStationMode(true);
             });

    this->server->begin();
    return false; // FIXME: introduce success flag
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
    bool success = false;
    if (disableAp)
    {
        success &= WiFi.softAPdisconnect();
    }
    WiFi.mode(WIFI_STA);
    if (this->_ssid == "")
        success &= WiFi.enableSTA(true);
    else
    {
        WiFi.begin(this->_ssid.c_str(), this->_pass.c_str()); // FIXME: introduce success flagF
        success &= WiFi.setAutoConnect(true);
        success &= WiFi.setAutoReconnect(true);
        WiFi.persistent(true); // FIXME: introduce success flag
    }
    return success;
}

void MinimalWifiManager::loop()
{
    if (this->_to_scan)
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
        this->_to_scan = false;
    }
}