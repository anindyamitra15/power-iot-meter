#ifndef _util_H_
#define _util_H_
#include <Arduino.h>

uint32_t getChipId()
{
#ifdef ESP8266
    return ESP.getChipId();
#elif ESP32
    uint32_t chipId = 0;
    for (int i = 0; i < 17; i = i + 8)
    {
        chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
    }
    return chipId;
#endif
}

typedef struct timestamp_t
{
    uint8_t hr;
    uint8_t min;
    uint8_t sec;
    uint32_t ms;
} timestamp_t;

typedef struct packet_t
{
    double apparent_power;
    double real_power;
    double max_peak_volt;
    double voltage_rms;
    double current_rms;
    timestamp_t time;

} packet_t;
#endif
