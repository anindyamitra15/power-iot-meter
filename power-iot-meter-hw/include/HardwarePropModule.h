/**
 * @file HardwarePropModule.h
 * @author @anubhav666 @arnabdas01
 * @brief This will use PZEM004T module and UART
 * @version 0.1
 * @date 2022-06-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __HardwarePropModule_H__
#define __HardwarePropModule_H__
#include "Arduino.h"
#include "util.h"
#include <PZEM004Tv30.h>

#if !defined(PZEM_RX_PIN) && !defined(PZEM_TX_PIN)
#define PZEM_RX_PIN 16
#define PZEM_TX_PIN 17
#endif

#define PZEM_SERIAL Serial2
#define CONSOLE_SERIAL Serial
PZEM004Tv30 pzem(PZEM_SERIAL, PZEM_RX_PIN, PZEM_TX_PIN);

#define POWER_FACTOR 0.8              // basically cos(36.8698)
#define REACTIVE_POWER_MULTIPLIER 0.6 // basically sin(36.8698)
/**
 * @brief Pin definitions
 * TODO: To be decided Later
 */
#define CURRENT 0 // input pin6  
#define VOLTAGE 0 // output pin

void attach()
{
    pinMode(CURRENT, INPUT);
    pinMode(VOLTAGE, INPUT);
}

void fetchSensorData(packet_t *data)
{
    // FIXME: implementation required after deciding on the sensors
    // float voltage = pzem.voltage();
    // double current = pzem.current();
    // double power = pzem.power();
    // // double energy = pzem.energy();
    // float frequency = pzem.frequency();
    // float pf = pzem.pf();
    // data->max_peak_volt = 35.0;
    data->current_rms = pzem.current();
    data->voltage_rms = pzem.voltage();
    data->apparent_power = pzem.voltage() * pzem.current();
    data->active_power = pzem.power();
}

void fetchSensorDataTest(packet_t *data)
{
    data->max_peak_volt = 35.0;
    data->current_rms = 5.0;
    data->voltage_rms = 220.0;
    data->apparent_power = data->voltage_rms * data->current_rms;
    data->active_power = data->apparent_power * POWER_FACTOR;
}

#endif