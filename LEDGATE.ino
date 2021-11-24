#include "Config.h" // все настройки в этой вкладке
#include "WIFI.h"
#include "Server.h"
#include "MQTT.h"

void setup(){
  Serial.begin(115200);
  pinMode(led_pin, OUTPUT); 
  WIFI_init(MODE_AP);
  server_init();
  MQTT_init();
  mqtt_cli.publish("esp826/state" , "hello from esp");
  mqtt_cli.subscribe("esp826/command");
  //leds_init();
  //ArtNet_init(); 
}

void loop()
{
  server.handleClient();
  mqtt_cli.loop();
  //Serial.print(ssid);
  //Serial.print(password);
  //artnet.read();
}
