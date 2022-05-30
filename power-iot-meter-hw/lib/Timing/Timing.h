#ifndef __TIMING_H__
#define __TIMING_H__
#include "Arduino.h"

/**
 * @file Timing.h
 * @author your name (you@domain.com)
 * @brief
 * Fetch time from NTC, according to Timezone
 * Store time in internal RTC and tick
 * fetch timestamp string from RTC time
 *
 * @version 0.1
 * @date 2022-05-30
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "Time.h"

#define NTP_SERVER "pool.ntp.org"

const long gmtOffset_sec = 0;
const int daylightOffset_sec = 3600;
// tm time;

void printLocalTime()
{
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo))
    {
        Serial.println("Failed to obtain time");
        return;
    }
    Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
    Serial.print("Day of week: ");
    Serial.println(&timeinfo, "%A");
    Serial.print("Month: ");
    Serial.println(&timeinfo, "%B");
    Serial.print("Day of Month: ");
    Serial.println(&timeinfo, "%d");
    Serial.print("Year: ");
    Serial.println(&timeinfo, "%Y");
    Serial.print("Hour: ");
    Serial.println(&timeinfo, "%H");
    Serial.print("Hour (12 hour format): ");
    Serial.println(&timeinfo, "%I");
    Serial.print("Minute: ");
    Serial.println(&timeinfo, "%M");
    Serial.print("Second: ");
    Serial.println(&timeinfo, "%S");

    Serial.println("Time variables");
    char timeHour[3];
    strftime(timeHour, 3, "%H", &timeinfo);
    Serial.println(timeHour);
    char timeWeekDay[10];
    strftime(timeWeekDay, 10, "%A", &timeinfo);
    Serial.println(timeWeekDay);
    Serial.println();
}

void set_time_from_ntp()
{
    configTime(gmtOffset_sec, daylightOffset_sec, NTP_SERVER);
    printLocalTime();
}

String get_timestamp()
{
    struct tm timeinfo;
    if (!getLocalTime(&timeinfo))
    {
        Serial.println("Failed to obtain time");
        return "";
    }
    char buffer[80];
    strftime (buffer, 80, "%A, %B %d %Y %H:%M:%S", &timeinfo);
    return buffer;
}

#endif