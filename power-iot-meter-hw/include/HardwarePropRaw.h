/**
 * @file HardwarePropRaw.h
 * @author @anindyamitra15 @RandomDelta6
 * @brief This will be measuring the voltage and current and deriving power from that
 * @version 0.1
 * @date 2022-06-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __HardwarePropRaw_H__
#define __HardwarePropRaw_H__
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
    data->max_peak_volt = 35.0;
    data->current_rms = 5.0;
    data->voltage_rms = 220.0;
    data->apparent_power = data->voltage_rms * data->current_rms;
    data->real_power = data->apparent_power * POWER_FACTOR;
}

#endif