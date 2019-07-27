#include <Audio.h>

/*================
 * SOFTPOT
 *================*/
const int SOFTPOT = 32; // A13


/*================
 * FSRs
 *================*/
const int FSR0 = 33; // A14
const int FSR1 = 34; // A15


/*================
 * POTS
 *================*/
const int POT0 = 35; // A16
const int POT1 = 36; // A17


/*================
 * AUDIO NETWORK
 *================*/
#include "faustPM.h"

faustPM               faust;

AudioInputI2S         in;
AudioOutputI2S        out;
AudioControlSGTL5000  audioShield;

// piezo to bell
AudioConnection       patchCord0(in,0,faust,0);

// mono faust to stereo line out
AudioConnection       patchCord1(faust,0,out,0);
AudioConnection       patchCord2(faust,0,out,1);


void setup() {
//  Serial.begin(9600);

  analogReadResolution(12);

  AudioMemory(6);

  // TODO: adjust for piezo input
//  audioShield.inputSelect(AUDIO_INPUT_LINEIN);
//  audioShield.lineInLevel(5);

  audioShield.enable();
  audioShield.volume(0.5);
}

unsigned long last_time = millis();
void loop() {
  /*
   * Note - Tube Length
   * [0 - 2]
   */
  double softpot = analogRead(SOFTPOT);
  float tubeLength = softpot / 2048; // [2 - 0]
  tubeLength = 2.4 - map(tubeLength, 0, 2, 0.6, 1.8);
//  Serial.println(tubeLength);
  faust.setParamValue("tubeLength", tubeLength);

  /*
   * Mouth Position
   * [0 - 1]
   * FSR0
   */
  double fsr0 = analogRead(FSR0);
  float mouthPosition = fsr0 / 1024;
  mouthPosition = map(pow(mouthPosition, 4), 0, 200, 0.8, 0.1);
//  Serial.println(mouthPosition);
  faust.setParamValue("mouthPosition", mouthPosition);

  /*
   * Pressure
   * [0 - 2]
   * FSR1
   */
  double fsr1 = analogRead(FSR1);
  float pressure = fsr1 / 1024;
  pressure = map(pow(pressure, 4), 0, 200, 0, 2);
//  Serial.println(pressure);
  faust.setParamValue("pressure", pressure);


  // LEFT POT: Bell Hit Sensitivity
  float pot1 = analogRead(POT1);
  float gainIn = pot1 / 1024;
  gainIn = map(pow(gainIn, 2), 0, 16, 0, 1);
//  Serial.println(gainIn);
  faust.setParamValue("gainIn", gainIn);

  // RIGHT POT: Bell Hold Length
  float pot0 = analogRead(POT0);
  float holdLength = pot0 / 1024;
  holdLength = map(holdLength, 0, 1024, 10, 300);
  faust.setParamValue("holdLength", holdLength);


  delay(4);
//  delay(100);

  if(millis() - last_time >= 8000) {

    /*
     * Strike Position
     * vary randomly
     */
    faust.setParamValue("strikePosition", (int)random(0, 5));
  }
}
