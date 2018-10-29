#include <Adafruit_NeoPixel.h>

#define PIN 1
#define NUM_LEDS 2

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, PIN);

#define FADE_TIME 2000

void setup() {
    pixels.begin();
}

uint32_t time;
void loop() {
    time = millis() % FADE_TIME;

    uint32_t color = pixels.Color(255 - time * 255 / FADE_TIME, 0, 0);

    for(int i = 0; i < NUM_LEDS; i++) {
        pixels.setPixelColor(i, color);
    }
    pixels.show();
}