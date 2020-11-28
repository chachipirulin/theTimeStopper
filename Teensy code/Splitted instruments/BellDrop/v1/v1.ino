// Bell drop

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
AudioSynthWaveformSine   sine4; //xy=175.6111297607422,1036.3519287109375
AudioSynthWaveformSine   sine1;          //xy=176.7222442626953,901.1666564941406
AudioSynthWaveformSine   sine3; //xy=177.83335876464844,989.6851806640625
AudioSynthWaveformSine   sine6; //xy=177.83335876464844,1127.4630126953125
AudioSynthWaveformSine   sine7; //xy=177.83335876464844,1187.4630126953125
AudioSynthWaveformSine   sine8; //xy=177.83335876464844,1237.4630126953125
AudioSynthWaveformSine   sine9; //xy=177.83335876464844,1286.351806640625
AudioSynthWaveformSine   sine5; //xy=178.94447326660156,1084.129638671875
AudioSynthWaveformSine   sine2; //xy=180.0555877685547,945.2407836914062
AudioAmplifier           amp4; //xy=366.72222900390625,1035.2408142089844
AudioAmplifier           amp1;           //xy=367.8333435058594,900.0555419921875
AudioAmplifier           amp3; //xy=368.9444580078125,988.5740661621094
AudioAmplifier           amp6; //xy=368.9444580078125,1126.3518981933594
AudioAmplifier           amp7; //xy=368.9444580078125,1186.3518981933594
AudioAmplifier           amp8; //xy=368.9444580078125,1236.3518981933594
AudioAmplifier           amp9; //xy=368.9444580078125,1285.2406921386719
AudioAmplifier           amp5; //xy=370.0555725097656,1083.0185241699219
AudioAmplifier           amp2; //xy=371.16668701171875,944.1296691894531
AudioMixer4              mixer2;         //xy=594.5,1014.4999389648438
AudioMixer4              mixer1;         //xy=596.7222900390625,944.5
AudioMixer4              mixer4; //xy=603.388916015625,1103.0184326171875
AudioEffectEnvelope      envelope1;      //xy=766.7222256130642,968.9444478352864
AudioEffectEnvelope      envelope2; //xy=771.166748046875,1014.129638671875
AudioEffectEnvelope      envelope3; //xy=771.1668090820312,1053.0185546875
AudioMixer4              mixer3;         //xy=983.3890380859375,1028.9443969726562
AudioOutputI2S           i2s1;           //xy=1138.9444580078125,1025.611083984375
AudioConnection          patchCord1(sine4, amp4);
AudioConnection          patchCord2(sine1, amp1);
AudioConnection          patchCord3(sine3, amp3);
AudioConnection          patchCord4(sine6, amp6);
AudioConnection          patchCord5(sine7, amp7);
AudioConnection          patchCord6(sine8, amp8);
AudioConnection          patchCord7(sine9, amp9);
AudioConnection          patchCord8(sine5, amp5);
AudioConnection          patchCord9(sine2, amp2);
AudioConnection          patchCord10(amp4, 0, mixer1, 3);
AudioConnection          patchCord11(amp1, 0, mixer1, 0);
AudioConnection          patchCord12(amp3, 0, mixer1, 2);
AudioConnection          patchCord13(amp6, 0, mixer2, 1);
AudioConnection          patchCord14(amp7, 0, mixer2, 2);
AudioConnection          patchCord15(amp8, 0, mixer4, 0);
AudioConnection          patchCord16(amp9, 0, mixer4, 1);
AudioConnection          patchCord17(amp5, 0, mixer2, 0);
AudioConnection          patchCord18(amp2, 0, mixer1, 1);
AudioConnection          patchCord19(mixer2, envelope2);
AudioConnection          patchCord20(mixer1, envelope1);
AudioConnection          patchCord21(mixer4, envelope3);
AudioConnection          patchCord22(envelope1, 0, mixer3, 0);
AudioConnection          patchCord23(envelope2, 0, mixer3, 1);
AudioConnection          patchCord24(envelope3, 0, mixer3, 2);
AudioConnection          patchCord25(mixer3, 0, i2s1, 0);
AudioConnection          patchCord26(mixer3, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=632.2777811686198,711.1666700575087
// GUItool: end automatically generated code

void setup() {
    Serial.print("Begin ");
  Serial.println(__FILE__);
  
  Serial.begin(9600);
  AudioMemory(8);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.3);
  delay(1000);

  // CONFIG

  float generalLevel = 0.3;
  // sines
  sine1.amplitude(generalLevel);
  sine1.frequency(112);
  sine2.amplitude(generalLevel);
  sine2.frequency(184 );
  sine3.amplitude(generalLevel);
  sine3.frequency(238 );
  sine4.amplitude(generalLevel);
  sine4.frequency(342 );
  sine5.amplitude(generalLevel);
  sine5.frequency(400 );
  sine6.amplitude(generalLevel);
  sine6.frequency(548 );
  sine7.amplitude(generalLevel);
  sine7.frequency(600 );
  sine8.amplitude(generalLevel);
  sine8.frequency(752 );
  sine9.amplitude(generalLevel);
  sine9.frequency(814 );

// Amps
  amp1.gain(1);
  amp2.gain(0.5);
  amp3.gain(0.5*0.5);
  amp4.gain(0.5*0.5*0.5);
  amp5.gain(0.5*0.5*0.5*0.5);
  amp6.gain(0.5*0.5*0.5*0.5);
  amp7.gain(0.5*0.5*0.5*0.5);
  amp8.gain(0.5*0.5*0.5*0.5);
  amp9.gain(0.5*0.5*0.5*0.5*0.5);
  amp1.gain(0.5*0.5*0.5*0.5*0.5*0.5);


  // Envelopes
    envelope1.attack(20);
    envelope1.hold(500);
    envelope1.decay(100);
    envelope1.sustain(200);
    envelope1.release(380);
// TOTAL is = 1200 ms
    envelope2.attack(20);
    envelope2.hold(5450);
    envelope2.decay(75);
    envelope2.sustain(150);
    envelope2.release(200);

    envelope3.attack(20);
    envelope3.hold(400);
    envelope3.decay(50);
    envelope3.sustain(100);
    envelope3.release(100);
}

void loop() {

  // READ PHOTORESISTOR VALUE (analog input A2)
  float photoR = analogRead(A2); // Max = 1023;
  float lightThreshold = 670;
  Serial.print("Phototransistor value= ");
  Serial.println(photoR);

    if(lightThreshold<photoR){ // It's raining, play bell
            Serial.print("It's raining, play bell ");
            // On and OFF sines
            envelope1.noteOn();
            envelope2.noteOn();
            envelope3.noteOn();  
            delay(1000);
            envelope1.noteOff();
            envelope2.noteOff();
            envelope3.noteOff();
            delay(1000);
      }
}
