#include <ArtnetWifi.h> //https://github.com/rstephan/ArtnetWifi
// Art-Net settings
ArtnetWifi artnet;

void onDmxFrame(uint16_t universe, uint16_t length, uint8_t sequence, uint8_t* data){
  // set brightness of the whole strip
  //if (universe == 15)
  //{
  //  FastLED.setBrightness(data[0]);
  //  FastLED.show();
  //}

  // read universe and put into the right part of the display buffer
  for (int i = 0; i < length / 3; i++)
  {
    int led = i;
    if (led < NUM_LEDS)
      leds[led] = CRGB(data[i * 3], data[i * 3 + 1], data[i * 3 + 2]);
  }
  FastLED.show();
}

void ArtNet_init(){
  Serial.print("Setup with ");
  Serial.print(NUM_LEDS);
  Serial.println(" leds");
  artnet.begin();
  artnet.setArtDmxCallback(onDmxFrame);
}
