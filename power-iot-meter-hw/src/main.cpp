#include <Arduino.h>
#include <SPI.h>
#include <SPIFFS.h>
#include "fileOperation.h"



void setup()
{
  Serial.begin(115200);
  // initFlashFileSystem(SPIFFS);
  // listDir(SPIFFS);
  // SPIFFS.end();

  // WiFi.mode(WIFI_STA);
  // WiFi.begin("AKM_MACHINE_ULTRA", "zaq12wsx");
  // while (WiFi.status() != WL_CONNECTED)
  // {
  //   Serial.println('.');
  //   delay(1000);
  // }
  // Serial.println(WiFi.localIP());


}

void loop()
{
}