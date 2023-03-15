#pragma once

class transfer
{
public:
  virtual void begin() = 0;
  virtual void send(void *data, size_t bytes) = 0;
};