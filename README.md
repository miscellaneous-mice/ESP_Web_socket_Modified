# Audio Recording using ESP32 via websocket communication

## About the project


*This project so as to livestream audio data from ESP32 using MEMS microphones recorded using VB cable as our virtual audio driver on audacity*


## Parts Used are 

ESP32 board used : https://www.adafruit.com/product/3405

MEMS microphone : https://www.adafruit.com/product/3421

-------



**This is project is done on Platformio which is available here**  :  https://platformio.org/

**Or we can use VScode extension available in the addons where the following requirements are to be satisfied**

*Board used is Espressif ESP32 Dev Module : https://docs.platformio.org/en/latest/boards/espressif32/esp32dev.html?utm_source=platformio&utm_medium=piohome*

*Install Live server for vscode as extension*



## Requirements to get the project working

Install VB cable for windows : https://support.restream.io/en/articles/4358320-vb-audio-cable-setup

Download Audacity : https://www.audacityteam.org/download/

Connection to MEMS is as follows

```
#define I2S_MIC_SERIAL_CLOCK GPIO_NUM_14
#define I2S_MIC_LEFT_RIGHT_CLOCK GPIO_NUM_15
#define I2S_MIC_SERIAL_DATA GPIO_NUM_32
```

## Steps to get the project working


1) Import the code to platformio 

2) Compile the code and dump the code to ESP32

3) Use the phone to connect the WiFi “makerfabs-ap” build by the esp32.

4) Enter the address “192.168.4.1” to log in to the server in the browser on your mobile phone 

5) Enter the SSID and password ESP32 has to connect

6) After dumping the code right click on Webpage -> index.html and left click on the file open with live server

7) Select the VB Cable input device in the web server, a visualiser should pop up

8) Open audacity Select VB cable as output

9) Start Record



## Note:
-	**This is a mono channel recording for dual channel recording change in parameters.cpp line 8 : ```.channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT```** 
- **If the audio appears too much distorted change** ***bool fixSPH0645*** **to True or false in lib/sampler/src/SamplerMEMS.h line 19**
- **If the library used is : https://github.com/me-no-dev/ESPAsyncWebServer**
- **For automatically connecting to Wifi library is : https://github.com/Makerfabs/Makerfabs_FAQ/tree/master/Arduino_ESP32/arduino_example/wifi_set_demo**
