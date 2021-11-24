#define FASTLED_INTERNAL
#include <FastLED.h> // https://github.com/FastLED/FastLED

#define DATA_PIN 2
#define CLOCK_PIN 3

const int NUM_LEDS = 170;
CRGB leds[NUM_LEDS];

void leds_init()
{
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  Serial.println("initTest!");
  for(int i=0; i < NUM_LEDS;i++) {
    leds[i] = CRGB::Green; delay(10); FastLED.show();
  }
  for(int i=0; i < NUM_LEDS;i++) {
    leds[i] = CRGB::Black; delay(10); FastLED.show();
  }
  FastLED.clear();
}
