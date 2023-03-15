#include <SPIFFS.h>
#include <ESPAsyncWebServer.h>
#include "webtransfer.h"

void webtransfer::begin()
{
  Serial.printf("Connect to http://microphone.local ");
  server = new AsyncWebServer(80);
  ws = new AsyncWebSocket("/audio_stream");
  // start off spiffs so we can serve the static files

  if (!SPIFFS.begin())
  {
    Serial.println("SPIFFS failed");
  }
  else
  {
    Serial.println("SPIFFS sucess");
  }

  // setup cors to allow connections from anywhere - handy for testing from localhost
  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Methods", "GET, PUT");
  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Headers", "*");
  // serving index.html file

  server->serveStatic("/", SPIFFS, "/").setDefaultFile("index.html");

  // ws server
  ws->onEvent([this](AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len)
              {
                if (type == WS_EVT_CONNECT)
                {
                  Serial.printf("ws[%s][%u] connect\n", server->url(), client->id());
                  this->connected_client = client;
                }
                else if (type == WS_EVT_DISCONNECT)
                {
                  Serial.printf("ws[%s][%u] disconnect\n", server->url(), client->id());
                  this->connected_client = NULL;
                }
                else if (type == WS_EVT_ERROR)
                {
                  Serial.printf("ws[%s][%u] error(%u): %s\n", server->url(), client->id(), *((uint16_t *)arg), (char *)data);
                }
              });
  server->addHandler(ws);
  // handle options requests for cors or not found
  server->onNotFound([](AsyncWebServerRequest *request)
                     {
                       if (request->method() == HTTP_OPTIONS)
                       {
                         request->send(200);
                       }
                       else
                       {
                         Serial.println("Not found");
                         request->send(404, "Not found");
                       }
                     });

  server->begin();
}

void webtransfer::send(void *data, size_t len)
{
  if (connected_client && connected_client->canSend())
  {
    connected_client->binary(reinterpret_cast<uint8_t *>(data), len);
  }
}