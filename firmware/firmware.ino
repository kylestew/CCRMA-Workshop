#include <Audio.h>

#include "crunchySaw.h"

crunchySaw crunchy;
AudioOutputI2S out;
AudioControlSGTL5000 audioShield;
AudioConnection patchCord0(crunchy,0,out,0);
AudioConnection patchCord1(crunchy,0,out,1);

void setup() {
  AudioMemory(2);
  audioShield.enable();
  audioShield.volume(0.1);
}

int f = 10;

void loop() {
  f += random(24, 64);
  if (f > 1000) f = 0;

  crunchy.setParamValue("freq", (float)f);

  delay(100);
}