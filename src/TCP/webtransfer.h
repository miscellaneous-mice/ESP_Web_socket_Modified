#pragma once
#include "transfer.h"

class AsyncWebServer;
class AsyncWebSocket;
class AsyncWebSocketClient;

class webtransfer : public transfer
{
private:
  AsyncWebServer *server = NULL;
  AsyncWebSocket *ws = NULL;
  // allow for one client at a time
  AsyncWebSocketClient *connected_client = NULL;

public:
  void begin();
  void send(void *data, size_t size) override;
};