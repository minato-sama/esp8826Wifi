#include <PubSubClient.h>

PubSubClient mqtt_cli(wifiClient);

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.println("Received data");
}

void MQTT_init() {
  mqtt_cli.setServer(mqtt_broker, mqtt_port);
  mqtt_cli.setCallback(callback);

  while (!mqtt_cli.connected()) {
    String Client_id = "esp8266-" + String(WiFi.macAddress());
    Serial.println("Start connection");
    if(mqtt_cli.connect(Client_id.c_str())) {
      Serial.println("Connected");
      delay(2600);     
    }
    else {
      Serial.println("NOT Connected");
    }
  }
}
