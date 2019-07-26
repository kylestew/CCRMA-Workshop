#include <Audio.h>

/*================
 * SOFTPOT
 *================*/
const int SOFTPOT = 31; // A12


/*================
 * FSR
 *================*/
const int FSR = 32; // A13


/*================
 * POTS
 *================*/
const int POT1 = 33; // A14
const int POT2 = 34; // A15
const int POT3 = 35; // A16
const int POT4 = 36; // A17


/*================
 * AUDIO NETWORK
 *================*/
#include "faustPM.h"

faustPM               faust;

AudioInputI2S         in;
AudioOutputI2S        out;
AudioControlSGTL5000  audioShield;

AudioConnection       patchCord0(in,0,faust,0);

AudioConnection       patchCord1(faust,0,out,0);
AudioConnection       patchCord2(faust,0,out,1);


void setup() {
  Serial.begin(9600);

  analogReadResolution(12);

  AudioMemory(6);
  audioShield.enable();
  audioShield.volume(0.5);
}


unsigned long last_time = millis();
double lastPressure = 0;
double lastTubeLength = 0;
void loop() {
//  double softpot = analogRead(SOFTPOT);
//
//  Serial.print("softpot: ");
//  Serial.println(val);




/*
  faust.setParamValue("tubeLength", lastTubeLength);
  lastTubeLength += 0.0001;
  if (lastTubeLength > 2) lastTubeLength = 0;


  faust.setParamValue("pressure", lastPressure);
  lastPressure += 0.0007;
  if (lastPressure > 2) lastPressure = 0;
  delay(10);
*/




  if(millis() - last_time >= 5000) {

    // TODO: test bell params
    faust.setParamValue("strikePosition", (int)random(0, 5));
    faust.setParamValue("holdLength", (int)random(10, 90));

    Serial.print("Proc = ");
    Serial.print(AudioProcessorUsage());
    Serial.print(" (");
    Serial.print(AudioProcessorUsageMax());
    Serial.print("),  Mem = ");
    Serial.print(AudioMemoryUsage());
    Serial.print(" (");
    Serial.print(AudioMemoryUsageMax());
    Serial.println(")");

    last_time = millis();
  }
}
