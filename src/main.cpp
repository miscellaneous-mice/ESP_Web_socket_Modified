#include <Arduino.h>
#include <WiFi.h>
#include <ESPmDNS.h>
#include "parameters.h"
#include "communication.h"
#include "wifi_save.h"

// const char* ssid = "LiSpire1";        //Write your own Wi-Fi name here
// const char* password = "aaaaa11111";  //Write your own password here
void setup()
{
  Serial.begin(115200);
  Serial.println("Starting up");  //192.168.4.1
  delay(1000);
  if (wifi_set_main())
  {
      Serial.println("Connect WIFI SUCCESS");
  }
  else
  {
      Serial.println("Connect WIFI FAULT");
  }
  
//   while (WiFi.status() != WL_CONNECTED)
//   {
//     delay(500);
//     Serial.print(".");
//   }
  
  //disable WiFi sleep mode
  // Serial.printf("Starting WiFi AP = %s", ssid);
  // WiFi.softAP(ssid, password);
  WiFi.setSleep(WIFI_PS_NONE);

  // Serial.println("");
  // Serial.println("WiFi connected");
  // Serial.println("IP address: ");
  // Serial.print(WiFi.localIP());
  Serial.println("");

  // startup MDNS
  if (!MDNS.begin(MDNS_DOMAIN))
  {
    Serial.println("MDNS.begin failed");
  }
  Serial.println("Creating microphone");
  communication *application = new communication();
  application->begin();
}

void loop()
{
  vTaskDelay(pdMS_TO_TICKS(1000));
}
