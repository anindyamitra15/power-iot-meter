#include <Arduino.h>
#include <SPI.h>
#include <SPIFFS.h>
#include <MinimalWifiManager.h>
#include <FirebaseHandler.h>
#include <HardwareProp.h>
#include <Timing.h>

void fetchDataFromFirebase();
void pushDataToFirebase();


AsyncWebServer server(80);
MinimalWifiManager wifi;
FirebaseJson power_outage_log;
packet_t data;
double total_energy = 0;


void setup()
{
  Serial.begin(115200);
  Serial.println("setup()");
  wifi.begin(&server, SPIFFS);
  // // wifi.resetSettings();
  wifi.autoConnect();
  set_time_from_ntp();
  printLocalTime();
  firebaseHandler.begin(SPIFFS);
  firebaseHandler.firebase_connect();
  fetchDataFromFirebase();

  fetchSensorDataTest(&data); // updates the data struct

  FileOperation::listDir(SPIFFS);
  Serial.println("Exiting setup()..");
}

void loop()
{
  wifi.loop();
  // printLocalTime();
  Serial.println(get_timestamp());
  delay(1000);
}

void fetchDataFromFirebase()
{
  String raw = firebaseHandler.fetchData("/" + firebaseHandler.getUid() + "/users");
  Serial.println(raw);

  // update total_energy from this data

  // parse the total energy and maybe the power outage log
  //  then keep them in global var

  // FirebaseJson json;
  // json.setJsonData(data.c_str());
}

void pushDataToFirebase()
{
  FirebaseJson json;
  //prepare to send all the data

  json.add<String, double>("apparent_power", data.apparent_power);
  json.add<String, double>("real_power", data.real_power);
  json.add<String, double>("voltage_rms", data.voltage_rms);
  json.add<String, double>("current_rms", data.current_rms);
  json.add<String, double>("max_peak_volt", data.max_peak_volt);
  json.add<String, double>("total_energy", total_energy);//TODO: check energy calculation code
  //add timestamp



  // firebaseHandler.updateData("/" + firebaseHandler.getUid(), &json);
}


void updatePowerOutageLog(); //prepare json, check meter1 schema for reference