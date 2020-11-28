#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// WAV files converted to code by wav2sketch
#include "AudioSampleC.h" 

// GUItool: begin automatically generated code
AudioPlayMemory          playMem1;       //xy=187.1666717529297,165.1666717529297
AudioEffectDelay         delay1;         //xy=399.16668701171875,319.16668701171875
AudioMixer4              mixer1;         //xy=409.1666717529297,173.1666717529297
AudioOutputI2S           i2s1;           //xy=683.1666870117188,273.1666564941406
AudioConnection          patchCord1(playMem1, 0, mixer1, 0);
AudioConnection          patchCord2(delay1, 0, mixer1, 3);
AudioConnection          patchCord3(delay1, 0, i2s1, 0);
AudioConnection          patchCord4(delay1, 0, i2s1, 1);
AudioConnection          patchCord5(mixer1, delay1);
AudioControlSGTL5000     sgtl5000_1; //xy=472.49993896484375,24.666656494140625
// GUItool: end automatically generated code

#include <Bounce.h>

Bounce button0 = Bounce(0, 5);

void setup() {
  Serial.begin(9600);
  pinMode(0, INPUT_PULLUP);
  AudioMemory(160);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.55);
  mixer1.gain(0, 0.5);
  mixer1.gain(3, 0.7);
  delay1.delay(0, 400);
  delay(1000);
}

void loop() {
    // Update all the button objects
  button0.update();

    if (button0.fallingEdge()) {
    playMem1.play(AudioSampleC);
  }
  
  // uncomment for A3 knob to control the feedback level
  /*
  int knob = analogRead(A3);
  float feedback = (float)knob / 1050.0;
  mixer1.gain(3, feedback);
  */

  // uncomment for pin 0 button to double the feedback (allowing unstable)
  /*
  button0.update();
  if (button0.read() == LOW) {
    mixer1.gain(3, feedback * 2.0);
  }
  */
}
