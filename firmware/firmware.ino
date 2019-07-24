#include <Audio.h>
#include <Bounce.h>

/*
#include "crunchySaw.h"

crunchySaw crunchy;
crunchySaw crunchy2;
AudioOutputI2S out;
AudioControlSGTL5000 audioShield;
AudioConnection patchCord0(crunchy,0,out,0);
AudioConnection patchCord1(crunchy2,0,out,1);
 */

const int buttPin = 12;
Bounce butt = Bounce(buttPin, 10);  // 10 ms debounce
byte buttState = LOW;         // what state was the button last time

void setup() {
  Serial.begin(9600);
  delay(1500);
  Serial.println("Hello");

  pinMode(buttPin, INPUT_PULLUP);

//  AudioMemory(2);
//  audioShield.enable();
//  audioShield.volume(0.1);
}

void loop() {
  if (butt.update()) {
    if (butt.fallingEdge()) {
      buttState = !buttState;
      if (buttState)
        Serial.println("cat");
      else
        Serial.println("dog");
    }
  }
}
