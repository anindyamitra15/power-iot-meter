#include <Arduino.h>
#include <SPI.h>
#include <SPIFFS.h>
#include "fileOperation.h"


void setup()
{
  Serial.begin(115200);
  initFileSystem();
  
  listDir(SPIFFS);
  writeFile(SPIFFS, "/lastlog.json", "");
  readFile(SPIFFS, "/lastlog.json");
  SPIFFS.end();
}

void loop()
{
}