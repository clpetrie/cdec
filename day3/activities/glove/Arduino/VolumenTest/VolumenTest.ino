#include <Wire.h>
#include <SoftwareSerial.h>
#include "Adafruit_Soundboard.h"

// Choose any two pins that can be used with SoftwareSerial to RX & TX
#define SFX_TX 5
#define SFX_RX 8

// Connect to the RST pin on the Sound Board
#define SFX_RST 12

// our RGB -> eye-recognized gamma color
byte gammatable[256];

//global variables for storing latest intensity values
uint16_t prior_red = 0;
uint16_t prior_green = 0;
uint16_t prior_blue = 0;


// we'll be using software serial
SoftwareSerial ss = SoftwareSerial(SFX_TX, SFX_RX);

// pass the software serial to Adafruit_soundboard, the second
// argument is the debug port (not used really) and the third
// arg is the reset pin
Adafruit_Soundboard sfx = Adafruit_Soundboard(&ss, NULL, SFX_RST);

uint16_t volumenRed = 0;
uint16_t volumenGreen = 0;
uint16_t volumenBlue = 0;

int volArray[] = {204, 180, 170, 160, 150, 140, 120};
int volCounter = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Color View Test!");
  Serial.println("Adafruit Sound Board!");

  // softwareserial at 9600 baud
  ss.begin(9600);
  // can also do Serial1.begin(9600)

  if (!sfx.reset()) {
    Serial.println("Not found");
    while (1);
  }
  Serial.println("SFX board found");

  volumenRed   = 204;
  volumenGreen = 204;
  volumenBlue  = 204;

}


void loop() {

  uint16_t redG = 10;
  uint8_t fileN = 0;

  Serial.print("red ");
  Serial.print(volumenRed);
  Serial.print(" ");

  volumenRed = volume_setter_red(volArray[volCounter], volumenRed);//map(redG, 0, 55, 0, 204));
  Serial.print(" final: ");
  Serial.println(volumenRed);
  Serial.print("  ");
  Serial.println(volCounter);

  volCounter++;
  if (volCounter >=  7) {
    volCounter = 0;
  }


  sfx.playTrack(fileN);




  /*
    int greenG = 10;
    fileN = 1;
    int greenG = gammatable[(int)g];
    volume_setter_green(map(greenG, 0, 55, 0, 204));
    sfx.playTrack(fileN);

    int blueG = 10;
    fileN = 2;
    int blueG = gammatable[(int)b];
    volume_setter_blue(map(blueG, 0, 55, 0, 204));
    sfx.playTrack(fileN);
  */
}


uint16_t volume_setter_red(uint16_t n, uint16_t volRed)
{
  uint16_t goal = n;
  uint16_t currentVol = volRed;
  if (goal % 2 == 1)
  {
    goal--;
  }

  uint16_t diff = uint16_t(abs(goal - currentVol) / 2.0);

  Serial.print(goal);
  Serial.print("g diff ");
  Serial.println(diff);

  if ( goal < currentVol)
  {
    for (uint16_t i = 0; i < diff; i++)
    {
      currentVol = volRed - i * 2;
      sfx.volDown();
    }
  } else if ( goal >= currentVol )
  {
    for (uint16_t i = 0; i < diff; i++)
    {
      currentVol = volRed + i * 2;
      sfx.volUp();
    }
  }
  return  currentVol;
}

int volume_setter_green(int n)
{
  int goal = n;
  int currentVol = volumenGreen;
  if (goal % 2 == 1)
  {
    goal = goal--;
  }

  int diff = int(abs(goal - currentVol) / 2.0);

  if ( goal < currentVol)
  {
    for (int i = 0; i < diff; i++)
    {
      volumenGreen = sfx.volDown();
    }
  }

  if ( goal > currentVol)
  {
    for (int i = 0; i < diff; i++)
    {
      volumenGreen = sfx.volUp();
    }
  }

  return (int)volumenGreen;

}

int volume_setter_blue(int n)
{
  int goal = n;
  int currentVol = volumenBlue;

  if (goal % 2 == 1)
  {
    goal = goal--;
  }

  int diff = int(abs(goal - currentVol) / 2.0);

  if (goal < currentVol)
  {
    for (int i = 0; i < diff; i++)
    {
      volumenBlue = sfx.volDown();
    }
  }

  if ( goal > currentVol)
  {
    for (int i = 0; i < diff; i++)
    {
      volumenBlue = sfx.volUp();
    }
  }

  return (int)volumenBlue;

}

