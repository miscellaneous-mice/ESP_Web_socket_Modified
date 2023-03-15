#pragma once

#include <freertos/FreeRTOS.h>
#include <driver/i2s.h>

// network config
#define WIFI_SSID "LiSpire"
#define WIFI_PASSWORD "aaaaa11111"

// #define WIFI_SSID "Narasimha"
// #define WIFI_PASSWORD "Dcshoecousa3732"

#define MDNS_DOMAIN "microphone"

// sample rate for the system
#define SAMPLE_RATE 44100

#define USE_I2S_MIC_INPUT

// Generally they will default to LEFT - but you may need to attach the L/R pin to GND
#define I2S_MIC_CHANNEL I2S_CHANNEL_FMT_ONLY_LEFT
// #define I2S_MIC_CHANNEL I2S_CHANNEL_FMT_ONLY_RIGHT
#define I2S_MIC_SERIAL_CLOCK GPIO_NUM_14
#define I2S_MIC_LEFT_RIGHT_CLOCK GPIO_NUM_15
#define I2S_MIC_SERIAL_DATA GPIO_NUM_32

// i2s config for reading from of I2S
extern i2s_config_t i2s_mic_Config;
// i2s microphone pins
extern i2s_pin_config_t i2s_mic_pins;
