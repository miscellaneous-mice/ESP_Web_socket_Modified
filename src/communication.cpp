#include <freertos/FreeRTOS.h>
#include "communication.h"
#include <SamplerMEMS.h>
#include "TCP/webtransfer.h"
#include "parameters.h"

void communication::begin()
{
  this->input = new SamplerMEMS(I2S_NUM_0, i2s_mic_pins, i2s_mic_Config);


  this->input = input;
  this->transport1 = new webtransfer();
  this->input->start();
  this->transport1->begin();
  TaskHandle_t task_handle;
  xTaskCreate(communication::streamer_task, "task", 8192, this, 0, &task_handle);
}

void communication::streamer_task(void *param)
{
  communication *app = (communication *)param;
  // now just read from the microphone and send to the clients
  int16_t *samples = (int16_t *)malloc(sizeof(int16_t) * 1024);
  while (true)
  {
    // read from the microphone
    int samples_read = app->input->read(samples, 1024);
    // send to the two transports
    app->transport1->send(samples, samples_read * sizeof(int16_t));
  }
}
