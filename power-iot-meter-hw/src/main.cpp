#include <Arduino.h>
#include <SPI.h>
#include <SPIFFS.h>
#include "fileOperation.h"


void setup()
{
  Serial.begin(115200);
  initFlashFileSystem(SPIFFS);
  listDir(SPIFFS);
  SPIFFS.end();
}

void loop()
{
}