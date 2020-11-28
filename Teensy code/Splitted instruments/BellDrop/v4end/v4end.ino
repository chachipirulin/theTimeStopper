/* Bell drop
A0  14  Y Y   LED 2
A1  15  Y Y   LED 2
A2  16    Y   Photoresistor
*/

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine4; //xy=61.16667175292969,856.351806640625
AudioSynthWaveformSine   sine1;          //xy=62.27778625488281,721.1665344238281
AudioSynthWaveformSine   sine3; //xy=63.38890075683594,809.68505859375
AudioSynthWaveformSine   sine6; //xy=63.38890075683594,947.462890625
AudioSynthWaveformSine   sine7; //xy=63.38890075683594,1007.462890625
AudioSynthWaveformSine   sine8; //xy=63.38890075683594,1057.462890625
AudioSynthWaveformSine   sine9; //xy=63.38890075683594,1106.3516845703125
AudioSynthWaveformSine   sine5; //xy=64.50001525878906,904.1295166015625
AudioSynthWaveformSine   sine2; //xy=65.61112976074219,765.2406616210938
AudioSynthWaveformSine   sine13; //xy=65.61112976074219,1293.7593688964844
AudioSynthWaveformSine   sine10; //xy=66.72224426269531,1158.5740966796875
AudioSynthWaveformSine   sine12; //xy=67.83335876464844,1247.0926208496094
AudioSynthWaveformSine   sine15; //xy=67.83335876464844,1384.8704528808594
AudioSynthWaveformSine   sine16; //xy=67.83335876464844,1444.8704528808594
AudioSynthWaveformSine   sine17; //xy=67.83335876464844,1494.8704528808594
AudioSynthWaveformSine   sine18; //xy=67.83335876464844,1543.7592468261719
AudioSynthWaveformSine   sine14; //xy=68.94447326660156,1341.5370788574219
AudioSynthWaveformSine   sine11; //xy=70.05558776855469,1202.6482238769531
AudioEffectMultiply      multiply2; //xy=185.6111602783203,829.6851348876953
AudioEffectMultiply      multiply6; //xy=185.6111297607422,1219.6851196289062
AudioEffectMultiply      multiply7; //xy=187.83335876464844,1317.4630737304688
AudioEffectMultiply      multiply3; //xy=197.8333282470703,927.4630126953125
AudioEffectMultiply      multiply1;      //xy=203.38890075683594,745.6110534667969
AudioEffectMultiply      multiply4; //xy=203.38890075683594,1000.7962646484375
AudioEffectMultiply      multiply5; //xy=204.49998474121094,1130.7963256835938
AudioEffectMultiply      multiply8; //xy=203.38890075683594,1424.1296997070312
AudioEffectMultiply      multiply9; //xy=235.61119079589844,1514.1297607421875
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
AudioEffectFreeverb      freeverb1;      //xy=1134.499755859375,1028.9443054199219
AudioOutputI2S           i2s1;           //xy=1283.3887939453125,1022.2777404785156
AudioConnection          patchCord1(sine4, 0, multiply2, 1);
AudioConnection          patchCord2(sine1, 0, multiply1, 0);
AudioConnection          patchCord3(sine3, 0, multiply2, 0);
AudioConnection          patchCord4(sine6, 0, multiply3, 1);
AudioConnection          patchCord5(sine7, 0, multiply4, 0);
AudioConnection          patchCord6(sine8, 0, multiply4, 1);
AudioConnection          patchCord7(sine9, 0, multiply5, 0);
AudioConnection          patchCord8(sine5, 0, multiply3, 0);
AudioConnection          patchCord9(sine2, 0, multiply1, 1);
AudioConnection          patchCord10(sine13, 0, multiply7, 0);
AudioConnection          patchCord11(sine10, 0, multiply5, 1);
AudioConnection          patchCord12(sine12, 0, multiply6, 1);
AudioConnection          patchCord13(sine15, 0, multiply8, 0);
AudioConnection          patchCord14(sine16, 0, multiply8, 1);
AudioConnection          patchCord15(sine17, 0, multiply9, 0);
AudioConnection          patchCord16(sine18, 0, multiply9, 1);
AudioConnection          patchCord17(sine14, 0, multiply7, 1);
AudioConnection          patchCord18(sine11, 0, multiply6, 0);
AudioConnection          patchCord19(multiply2, amp2);
AudioConnection          patchCord20(multiply6, amp6);
AudioConnection          patchCord21(multiply7, amp7);
AudioConnection          patchCord22(multiply3, amp3);
AudioConnection          patchCord23(multiply1, amp1);
AudioConnection          patchCord24(multiply4, amp4);
AudioConnection          patchCord25(multiply5, amp5);
AudioConnection          patchCord26(multiply8, amp8);
AudioConnection          patchCord27(multiply9, amp9);
AudioConnection          patchCord28(amp4, 0, mixer1, 3);
AudioConnection          patchCord29(amp1, 0, mixer1, 0);
AudioConnection          patchCord30(amp3, 0, mixer1, 2);
AudioConnection          patchCord31(amp6, 0, mixer2, 1);
AudioConnection          patchCord32(amp7, 0, mixer2, 2);
AudioConnection          patchCord33(amp8, 0, mixer4, 0);
AudioConnection          patchCord34(amp9, 0, mixer4, 1);
AudioConnection          patchCord35(amp5, 0, mixer2, 0);
AudioConnection          patchCord36(amp2, 0, mixer1, 1);
AudioConnection          patchCord37(mixer2, envelope2);
AudioConnection          patchCord38(mixer1, envelope1);
AudioConnection          patchCord39(mixer4, envelope3);
AudioConnection          patchCord40(envelope1, 0, mixer3, 0);
AudioConnection          patchCord41(envelope2, 0, mixer3, 1);
AudioConnection          patchCord42(envelope3, 0, mixer3, 2);
AudioConnection          patchCord43(mixer3, freeverb1);
AudioConnection          patchCord44(freeverb1, 0, i2s1, 0);
AudioConnection          patchCord45(freeverb1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=632.2777811686198,711.1666700575087
// GUItool: end automatically generated code


void setup() {
    Serial.print("Begin ");
  Serial.println(__FILE__);
  
  Serial.begin(9600);
  AudioMemory(8);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);
  delay(1000);

  // CONFIG
  float generalLevel = 0.3;
  
  // sines amp
  sine1.amplitude(generalLevel);
  sine2.amplitude(generalLevel);
  sine3.amplitude(generalLevel);
  sine4.amplitude(generalLevel);
  sine5.amplitude(generalLevel);
  sine6.amplitude(generalLevel);
  sine7.amplitude(generalLevel);
  sine8.amplitude(generalLevel);
  sine9.amplitude(generalLevel);
  sine10.amplitude(generalLevel);
  sine11.amplitude(generalLevel);
  sine12.amplitude(generalLevel);
  sine13.amplitude(generalLevel);
  sine14.amplitude(generalLevel);
  sine15.amplitude(generalLevel);
  sine16.amplitude(generalLevel);
  sine17.amplitude(generalLevel);
  sine18.amplitude(generalLevel);

  // Sine freqs
  sine1.frequency(112); // Sine main
    sine2.frequency(113);// enharmonic sine (for beating effect)
  sine3.frequency(184);
    sine4.frequency(185);
  sine5.frequency(238);
    sine6.frequency(239);
  sine7.frequency(342);
    sine8.frequency(343);
  sine9.frequency(400);
    sine10.frequency(401);
  sine11.frequency(548);
    sine12.frequency(549);
  sine13.frequency(600);
    sine14.frequency(601);
  sine15.frequency(752);
    sine16.frequency(753);
  sine17.frequency(814);
    sine18.frequency(815);

// Amps
  amp1.gain(0.7);
  amp2.gain(0.5);
  amp3.gain(0.5*0.5);
  amp4.gain(0.5*0.5*0.5);
  amp5.gain(0.5*0.5*0.5*0.5);
  amp6.gain(0.5*0.5*0.5*0.5*0.5);
  amp7.gain(0.5*0.5*0.5*0.5*0.5*0.5);
  amp8.gain(0.5*0.5*0.5*0.5*0.5*0.5*0.5);
  amp9.gain(0.5*0.5*0.5*0.5*0.5*0.5*0.5*0.5);


  // Envelopes
    envelope1.attack(1);
    envelope1.hold(100);
    envelope1.decay(50);
    envelope1.sustain(2500);
    envelope1.release(5000);
// TOTAL is = 6 ms +1 silence
    envelope2.attack(1);
    envelope2.hold(70);
    envelope2.decay(40);
    envelope2.sustain(1500);
    envelope2.release(4000);

    envelope3.attack(1);
    envelope3.hold(60);
    envelope3.decay(30);
    envelope3.sustain(1500);
    envelope3.release(3000);

// Reverb
freeverb1.roomsize(0.7);
freeverb1.damping(0.3);
}

void loop() {

  // READ PHOTORESISTOR VALUE (analog input A2)
  float photoR = analogRead(A2); // Max = 1023;
  float lightThreshold = 670;
  Serial.print("Phototransistor value= ");
  Serial.println(photoR);
  
  delay(500);
    if(lightThreshold<photoR){ // It's raining, play bell
            Serial.print("It's raining, play bell ");
            // On and OFF sines
            envelope1.noteOn();
            envelope2.noteOn();
            envelope3.noteOn();  
            delay(7000);
            envelope1.noteOff();
            envelope2.noteOff();
            envelope3.noteOff();
            delay(7000);
      }
}
