#include <Arduino.h>
#include <SPI.h>
#include <SPIFFS.h>
#include <MinimalWifiManager.h>
#include <ArduinoJson.h>
#include <FirebaseHandler.h>
#include <HardwarePropRaw.h>
// #include <HardwarePropModule.h>
#include <Timing.h>

// #define DEBUGGING
#define SCHEDULE(and_logic, num, delay) \
  if (and_logic && (millis() - last_time[num] > delay))
#define SCHEDULES 1
#define TSK1 30000 // ms

void fetchEnergyFromFirebase();
void pushStatsToFirebase();

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
  firebaseHandler.begin(SPIFFS);
  firebaseHandler.firebase_connect();

  fetchSensorDataTest(&data); // updates the data struct

  FileOperation::listDir(SPIFFS);
  Serial.println("Exiting setup()..");
}

void loop()
{
  static unsigned long last_time[SCHEDULES] = {0};
  wifi.loop();
  /**
   * @brief
   * Create a scheduler for Firebase fetch and push
   * fetch
   * calculate
   * push
   *
   */
  SCHEDULE(true, 0, TSK1)
  {
    fetchEnergyFromFirebase();
    fetchSensorDataTest(&data);
    pushStatsToFirebase();
    last_time[0] = millis();
  }
}

void fetchEnergyFromFirebase()
{
  // update total_energy from this data
  total_energy = firebaseHandler.fetchData("/" + firebaseHandler.getUid() + "/total_energy").toDouble();
}

void fetchPowerOutagesFromFirebase()
{
  /**
   * @brief to peek at the power outage logs
   *
   */
  String power_outages = firebaseHandler.fetchData("/" + firebaseHandler.getUid() + "/power_outages");
  DynamicJsonDocument doc(512);
  deserializeJson(doc, power_outages);
#ifdef DEBUGGING
  serializeJson(doc, Serial);
  Serial.println();
  Serial.println(total_energy);
#endif
}

void pushStatsToFirebase()
{
  FirebaseJson json;
  // prepare to send all the data
  json.add<String, double>("apparent_power", data.apparent_power);
  json.add<String, double>("active_power", data.active_power);
  json.add<String, double>("voltage_rms", data.voltage_rms);
  json.add<String, double>("current_rms", data.current_rms);
  json.add<String, double>("max_peak_volt", data.max_peak_volt);
  json.add<String, double>("total_energy", total_energy); // TODO: check energy calculation code
  // add timestamp
  data.timestamp = getTimestamp();
  json.add<String, String>("timestamp", data.timestamp);
  firebaseHandler.updateData("/" + firebaseHandler.getUid(), &json);
#ifdef DEBUGGING
  Serial.println(json.raw());
#endif
}

void updatePowerOutageLog(); // prepare json, check meter1 schema for reference