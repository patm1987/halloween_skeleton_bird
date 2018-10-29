#include <Adafruit_NeoPixel.h>

#define PIN 1
#define NUM_LEDS 17

#define EYE_LED_START 0
#define EYE_LED_END 2

#define RING_LED_START 2
#define RING_LED_END 17
#define RING_LED_COUNT (RING_LED_END - RING_LED_START)

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, PIN);

#define EYE_ON_TIME 2000
#define EYE_OFF_TIME 200
#define EYE_TOTAL_TIME (EYE_ON_TIME + EYE_OFF_TIME);
#define LIGHT_RING_TIME 1000
#define ACTIVE_LEDS 7

void setup() {
    pixels.begin();
}

void loop() {
    uint32_t eyeTime = millis() % EYE_TOTAL_TIME;

    uint32_t eyeColor;
    if (eyeTime < EYE_ON_TIME) {
        eyeColor = pixels.Color(255, 0, 0);
    } else {
        eyeColor = pixels.Color(0, 0, 0);
    }

    for(int i = EYE_LED_START; i < EYE_LED_END; i++) {
        pixels.setPixelColor(i, eyeColor);
    }

    uint32_t circleTime = millis() % LIGHT_RING_TIME;
    uint32_t currentLed = circleTime * RING_LED_COUNT / LIGHT_RING_TIME;

    int32_t brightness = 255;
    int32_t brightnessStep = brightness / ACTIVE_LEDS;
    for(int i = 0; i < RING_LED_COUNT; i++) {
        int currentLedIndex = RING_LED_START + ((currentLed - i) % RING_LED_COUNT);
        pixels.setPixelColor(currentLedIndex, pixels.Color(0, brightness, 0));
        if (brightness > 0) {
            brightness -= brightnessStep;
            if (brightness < 0) {
                brightness = 0;
            }
        }
    }

    pixels.show();
}