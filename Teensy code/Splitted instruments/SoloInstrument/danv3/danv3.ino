// Advanced Microcontroller-based Audio Workshop
//
// http://www.pjrc.com/store/audio_tutorial_kit.html
// https://hackaday.io/project/8292-microcontroller-audio-workshop-had-supercon-2015

// WAV files converted to code by wav2sketch
#include "AudioSampleC.h" 

// GUItool: begin automatically generated code
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Bounce.h>

// GUItool: begin automatically generated code
AudioPlayMemory          playMem1;       //xy=77.33332824707031,51.333335876464844
AudioMixer4              mixer1;         //xy=310.1388854980469,112.63888549804688
AudioEffectFreeverb      freeverb1;      //xy=469.3055725097656,140.97222900390625
AudioEffectDelay         delay1;         //xy=649.3055419921875,306.8055725097656
AudioMixer4              mixer3;         //xy=656.8056030273438,160.97232055664062
AudioOutputI2S           i2s2; //xy=846.5000610351562,305.16668701171875
AudioConnection          patchCord1(playMem1, 0, mixer1, 0);
AudioConnection          patchCord2(mixer1, freeverb1);
AudioConnection          patchCord3(freeverb1, 0, mixer3, 0);
AudioConnection          patchCord4(delay1, 0, i2s2, 0);
AudioConnection          patchCord5(delay1, 0, i2s2, 1);
AudioConnection          patchCord6(delay1, 0, mixer3, 3);
AudioConnection          patchCord7(mixer3, delay1);
AudioControlSGTL5000     sgtl5000_1;     //xy=320.1999969482422,516.1999969482422
// GUItool: end automatically generated code

Bounce button0 = Bounce(0, 15);
Bounce button1 = Bounce(1, 15);
Bounce button2 = Bounce(2, 15);
Bounce button3 = Bounce(3, 15);
Bounce button4 = Bounce(4, 15);
Bounce button5 = Bounce(5, 15);
Bounce button6 = Bounce(6, 15);
Bounce button7 = Bounce(7, 15);

// Use these with the Teensy Audio Shield
#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  11
#define SDCARD_SCK_PIN   13

void setup() {
  Serial.begin(9600);
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  AudioMemory(500); // audio samples in block of 128, FS 

 // Mixers preconf
  mixer1.gain(0, 0.5);
  mixer3.gain(0, 0.5);
  mixer3.gain(3, 0.7);
  
  // Audio effects preconf
  delay1.delay(0, 100);// THIS CRASHES WHEN GREATER THAN 500
  
  AudioMemory(500);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.55);
    SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }

  delay(1000);
}

  void loop() {
    /*// ---------------------- feedbackGain
    int knob0 = analogRead(A0);
    float feedbackGain = (float)knob0 / 1023.0;
    mixer3.gain(3, feedbackGain);
    Serial.print("mixer3.gain3.feedbackGain = ");
    Serial.println(feedbackGain);
      // ---------------------- delayTime
    int knob1 = analogRead(A1);
    float delayTime = (float)knob1 / 1023.0;
      if (delayTime > 0.5 && delayTime < 0.7) {
    delay1.delay(0, 300);
      } else if (delayTime > 0.71){
    delay1.delay(0, 400);
      }else{
    delay1.delay(0, 0);
      }
    Serial.print("DelayTime = ");
    Serial.println(delayTime);
    // ------------------------------ uncomment for pin 0 button to double the feedback (allowing unstable)
    if (button0.read() == LOW) {
      mixer1.gain(3, 0.75 * 2.0);
    }*/
    ///////////////////////////////////////////////////////BUTTONS---------------------------------
    button0.update();
    button1.update();
    button2.update();
    button3.update();
    button4.update();
    button5.update();
    button6.update(); 
    
     if (button0.fallingEdge()) {
      Serial.print("Start  C.WAV playing ");
      playMem1.play(AudioSampleC);
    }
        if (button0.read() == LOW) {
      Serial.print("Start  C.WAV playing ");
      playMem1.play(AudioSampleC);
    }
         if (button2.fallingEdge()) {
      Serial.print("Start  C.WAV playing ");
      playMem1.play(AudioSampleC);
    }
         if (button3.fallingEdge()) {
      Serial.print("Start  C.WAV playing ");
      playMem1.play(AudioSampleC);
    }
         if (button4.fallingEdge()) {
      Serial.print("Start  C.WAV playing ");
      playMem1.play(AudioSampleC);
    }
         if (button5.fallingEdge()) {
      Serial.print("Start  C.WAV playing ");
      playMem1.play(AudioSampleC);
    }
         if (button6.fallingEdge()) {
      Serial.print("Start  C.WAV playing ");
      playMem1.play(AudioSampleC);
    }
   /*  if (button1.fallingEdge()) {
      Serial.print("Start Al.WAV playing ");
      playSdWav1.play("D.WAV");
      delay(200); // wait for library to parse WAV info
    }
       if (button2.fallingEdge()) {
      playSdWav1.play("E.WAV");
      delay(200); // wait for library to parse WAV info
    }
     if (button3.fallingEdge()) {
      playSdWav1.play("F.WAV");
      delay(200); // wait for library to parse WAV info
    }
       if (button4.fallingEdge()) {
      playSdWav1.play("G.WAV");
      delay(200); // wait for library to parse WAV info
    }
       if (button5.fallingEdge()) {
      playSdWav1.play("A.WAV");
      delay(200); // wait for library to parse WAV info
    }
       if (button6.fallingEdge()) {
      playSdWav1.play("B.WAV");
      delay(200); // wait for library to parse WAV info
    }*/
    
  }
