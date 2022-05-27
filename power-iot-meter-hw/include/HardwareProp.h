#ifndef __HardwareProp_H__
#define __HardwareProp_H__
#include "Arduino.h"
#include "util.h"

#define POWER_FACTOR 0.8              // basically cos(36.8698)
#define REACTIVE_POWER_MULTIPLIER 0.6 // basically sin(36.8698)
/**
 * @brief Pin definitions
 * TODO: To be decided Later
 */
#define CURRENT 0 // input pin
#define VOLTAGE 0 // output pin

void attach()
{
    pinMode(CURRENT, INPUT);
    pinMode(VOLTAGE, INPUT);
}

void fetchSensorData(packet_t *data)
{
    // FIXME: implementation required after deciding on the sensors
}

void fetchSensorDataTest(packet_t *data)
{
    data->max_peak_volt = 350;
    data->current_rms = 5.0;
    data->voltage_rms = 220.0;
    data->apparent_power = data->voltage_rms * data->current_rms;
    data->real_power = data->apparent_power * POWER_FACTOR;
}

#endif