#include <WiFi.h>
#include "Audio.h"

#define I2S_DOUT 25
#define I2S_BCLK 27
#define I2S_LRC 26

Audio audio;

//Enter Your wifi credentials.
const char* ssid = "******";
const char* password = "******";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  audio.setPinout(I2S_BCLK, I2S_LRC, I2S_DOUT);
  audio.setVolume(19); //[1,19]
  while(true){
    boolean nc = audio.connecttohost("http://mp3.ffh.de/radioffh/hqlivestream.mp3"); //add your favorate station here
    if(nc == 0) Serial.println("Not connected! Trying again...");
    else{
      Serial.println("Enjoy your music.");
      break;
    }
  }
}

void loop() {
  audio.loop();
}