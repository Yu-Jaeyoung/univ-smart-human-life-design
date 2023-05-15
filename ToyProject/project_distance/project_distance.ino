#include <Adafruit_NeoPixel.h>
#define PIN 9
#define NUMPIXELS 4  // NeoPixel ring size

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

const int trigPin = 12;
const int echoPin = 14;
int led_show = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;

  if (distance <= 10.00) {
    if (led_show == 0) {
      led_show = 1;
    } else {
      led_show = 0;
    }
  }

  if (come == 1) {
    pixels.begin();
    pixels.clear();
    pixels.setPixelColor(0, pixels.Color(127, 127, 127));
    pixels.setPixelColor(1, pixels.Color(127, 127, 127));
    pixels.setPixelColor(2, pixels.Color(127, 127, 127));
    pixels.setPixelColor(3, pixels.Color(127, 127, 127));
    pixels.show();
  }

  else if (led_show == 0) {
    pixels.clear();
    pixels.show();
  }
  delay(1000);
}