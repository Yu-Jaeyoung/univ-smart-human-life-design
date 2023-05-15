#include "DHT.h"
#include <Adafruit_NeoPixel.h>
#define PIN 1
#define NUMPIXELS 4  // NeoPixel ring size
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

DHT dht(10, DHT22);

float humidity;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  humidity = dht.readHumidity();
  
  // Serial.print("습도 = ");
  // Serial.println(humidity);

  if (humidity <= 40) {
    pixels.begin();
    pixels.clear();
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));
    pixels.setPixelColor(1, pixels.Color(255, 0, 0));
    pixels.setPixelColor(2, pixels.Color(255, 0, 0));
    pixels.setPixelColor(3, pixels.Color(255, 0, 0));
    pixels.show();
  } else if (humidity <= 60) {
    pixels.begin();
    pixels.clear();
    pixels.setPixelColor(0, pixels.Color(0, 255, 0));
    pixels.setPixelColor(1, pixels.Color(0, 255, 0));
    pixels.setPixelColor(2, pixels.Color(0, 255, 0));
    pixels.setPixelColor(3, pixels.Color(0, 255, 0));
    pixels.show();
  } else if (humidity <= 80) {
    pixels.begin();
    pixels.clear();
    pixels.setPixelColor(0, pixels.Color(0, 0, 255));
    pixels.setPixelColor(1, pixels.Color(0, 0, 255));
    pixels.setPixelColor(2, pixels.Color(0, 0, 255));
    pixels.setPixelColor(3, pixels.Color(0, 0, 255));
    pixels.show();
  } else {
    pixels.begin();
    pixels.clear();
    pixels.setPixelColor(0, pixels.Color(255, 0, 255));
    pixels.setPixelColor(1, pixels.Color(255, 0, 255));
    pixels.setPixelColor(2, pixels.Color(255, 0, 255));
    pixels.setPixelColor(3, pixels.Color(255, 0, 255));
    pixels.show();
  }

  delay(1000);
}