#pragma once

class transfer;
class SamplerI2S;

class communication
{
private:
  transfer *transport1 = NULL;
  SamplerI2S *input = NULL;

public:
  void begin();
  static void streamer_task(void *param);
};