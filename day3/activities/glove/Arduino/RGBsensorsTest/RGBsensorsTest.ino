/***************************************************
  This is a library for the Si1145 UV/IR/Visible Light Sensor

  Designed specifically to work with the Si1145 sensor in the
  adafruit shop
  ----> https://www.adafruit.com/products/1777

  These sensors use I2C to communicate, 2 pins are required to
  interface
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
#include "Adafruit_SI1145.h"
#include "Adafruit_TCS34725.h"
//#include "adafruit_neopixel-master/Adafruit_NeoPixel.h"
//#include "Adafruit_SI1145_Library/Adafruit_SI1145.h"
//#include "adafruit_tcs34725-master/Adafruit_TCS34725.h"


// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      1

// our RGB -> eye-recognized gamma color
byte gammatable[256];


// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);



//Color sensor
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

void setup() {
  Serial.begin(9600);

  //wait to start serial
  while (!Serial)
  {
    // do nothing
  } ;

  Serial.println("I am in setup");



  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // halt!
  }

  // thanks PhilB for this gamma table!
  // it helps convert RGB colors to what humans see
  // SPI
  for (int i = 0; i < 256; i++) {
    float x = i;
    x /= 255;
    x = pow(x, 2.5);
    x *= 255;

    gammatable[i] = x;

    //Serial.println(gammatable[i]);
  }

  pixels.begin(); // This initializes the NeoPixel library.


  Serial.println("OK!");
}

void loop() {

  uint16_t clear, red, green, blue;

  //Color sensor  and UViR
  tcs.setInterrupt(false);      // turn on LED

  delay(60);  // takes 50ms to read

  tcs.getRawData(&red, &green, &blue, &clear);

  tcs.setInterrupt(true);  // turn off LED


  // Figure out some basic hex code for visualization
  uint32_t sum = clear;
  float r, g, b;

  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;

  for (int i = 0; i < NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(gammatable[(int)r], gammatable[(int)g], gammatable[(int)b] )); // Moderately bright green color.
    //    pixels.setPixelColor(i, pixels.Color(0,75,75));
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
  pixels.setPixelColor(0, pixels.Color(75, 0, 0));
  pixels.show();
  delay(6000);
  pixels.setPixelColor(0, pixels.Color(0, 75, 0));
  pixels.show();
  delay(6000);
  pixels.setPixelColor(0, pixels.Color(0, 0, 75));
  pixels.show();
  delay(6000);

  Serial.print(gammatable[(int)r]);
  Serial.print(" ");
  Serial.print(gammatable[(int)g]);
  Serial.print(" ");
  Serial.print(gammatable[(int)b]);
  Serial.println();


}
