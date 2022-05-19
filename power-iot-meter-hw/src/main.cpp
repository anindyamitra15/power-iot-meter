#include <Arduino.h>
#include <SPI.h>
#include <SPIFFS.h>
#include <MinimalWifiManager.h>
#include <FirebaseHandler.h>

AsyncWebServer server(80);
MinimalWifiManager wifi;

void setup()
{
  Serial.begin(115200);
  Serial.println("setup");
  wifi.begin(&server, SPIFFS);
  // wifi.resetSettings();
  wifi.autoConnect();
  Serial.println("Exiting setup()..");
  firebaseHandler.firebase_connect();
  Serial.println(firebaseHandler.fetchData("/test"));
  FirebaseJson data;
  data.add<String, int>("testInner", 678);
  firebaseHandler.updateData("/test", &data);
  Serial.println(firebaseHandler.fetchData("/test"));
  FileOperation::listDir(SPIFFS);
}

void loop()
{
  wifi.loop();
}
