// Delay demonstration example, Teensy Audio Library
//   http://www.pjrc.com/teensy/td_libs_Audio.html
// 
// Creates a chirp on the left channel, then
// three delayed copies on the right channel.
//
// Requires the audio shield:
//   http://www.pjrc.com/store/teensy3_audio.html
//
// This example code is in the public domain.

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=506,444
AudioAmplifier           amp1;           //xy=682,431
AudioOutputI2S           i2s2;           //xy=851,436
AudioConnection          patchCord1(i2s1, 0, amp1, 0);
AudioConnection          patchCord2(amp1, 0, i2s2, 0);
AudioConnection          patchCord3(amp1, 0, i2s2, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=691,536
// GUItool: end automatically generated code


void setup() {
  // allocate enough memory for the delay
  AudioMemory(12);
  
  // enable the audio shield
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.8);
  sgtl5000_1.inputSelect(AUDIO_INPUT_LINEIN );
  sgtl5000_1.lineInLevel(0);
  

  amp1.gain(0.8);
}

void loop() {
}
