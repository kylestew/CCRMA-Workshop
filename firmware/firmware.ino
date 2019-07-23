// Advanced Microcontroller-based Audio Workshop
//
// http://www.pjrc.com/store/audio_tutorial_kit.html
// https://hackaday.io/project/8292-microcontroller-audio-workshop-had-supercon-2015
// 
// Part 2-8: Oscillators

#include <Bounce.h>

Bounce button0 = Bounce(0, 15);
Bounce button1 = Bounce(1, 15);  // 15 = 15 ms debounce time
Bounce button2 = Bounce(2, 15);


///////////////////////////////////
// copy the Design Tool code here
///////////////////////////////////
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;          //xy=375,562
AudioOutputI2S           i2s2;           //xy=666,571
AudioConnection          patchCord1(sine1, 0, i2s2, 0);
AudioConnection          patchCord2(sine1, 0, i2s2, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=563,686
// GUItool: end automatically generated code




void setup() {
  Serial.begin(9600);
  AudioMemory(20);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.32);

  sine1.frequency(440);
  sine1.amplitude(0.5);
}


void loop() {

}
