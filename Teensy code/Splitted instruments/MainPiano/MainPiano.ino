
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioPlaySdWav           playSdWav1;     //xy=253.1666717529297,347.1666717529297
AudioPlaySdRaw           playSdRaw1;     //xy=263.1666717529297,417.1666717529297
AudioMixer4              mixer1;         //xy=482.16668701171875,409.16668701171875
AudioEffectFreeverb      freeverb1;      //xy=638.1666717529297,417.1666717529297
AudioOutputI2S           i2s2; //xy=812.1666870117188,430.9999694824219
AudioConnection          patchCord1(playSdWav1, 0, mixer1, 0);
AudioConnection          patchCord2(playSdWav1, 1, mixer1, 1);
AudioConnection          patchCord3(playSdRaw1, 0, mixer1, 2);
AudioConnection          patchCord4(mixer1, freeverb1);
AudioConnection          patchCord5(freeverb1, 0, i2s2, 0);
AudioConnection          patchCord6(freeverb1, 0, i2s2, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=489.16668701171875,247
// GUItool: end automatically generated code

#include <Bounce.h>

Bounce button0 = Bounce(0, 15);
Bounce button1 = Bounce(1, 15);

// Use these with the Teensy Audio Shield
#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  11
#define SDCARD_SCK_PIN   13

void setup() {
  Serial.begin(9600);
  pinMode(0, INPUT_PULLUP);
    AudioMemory(1500);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.8);
    SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);
  if (!(SD.begin(SDCARD_CS_PIN))) {
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }
  
  mixer1.gain(0, 1);
  mixer1.gain(1, 1);
  mixer1.gain(2, 1);
  freeverb1.roomsize(0.5);
  delay(2000);
}


void loop() {
  button0.update();
  
   if (button0.fallingEdge()) {
    Serial.print("Start  A.WAV playing ");
    playSdWav1.play("A.WAV");
    delay(200); // wait for library to parse WAV info
  }

     if (button1.fallingEdge()) {
    Serial.print("Start  A.RAW playing ");
    playSdRaw1.play("A.RAW");
    delay(200); // wait for library to parse WAV info
  }

  

}
