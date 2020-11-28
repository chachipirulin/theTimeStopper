/* NEXT PHASE

 - Record the 4 sequences on Ableton of the first song
 - Write the notes and its duration
 
*/
#include <Bounce.h>
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include "epiano_samples.h"
#include "piano_samples.h"

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWavetable      wavetable;      //xy=1666.0625,2615.5
AudioSynthWavetable      wavetable1;     //xy=1673.8126220703125,2698.8125
AudioEffectFreeverbStereo freeverbs2; //xy=1886.5625,2647.6875
AudioEffectFreeverbStereo freeverbs1;     //xy=1887.0625,2582.5
AudioMixer4              mixer1; //xy=2067.8125,2685.1875
AudioMixer4              mixer;          //xy=2081.0625,2581.5
AudioOutputI2S           i2s1;           //xy=2326.0625,2719.5
AudioConnection          patchCord1(wavetable, freeverbs1);
AudioConnection          patchCord2(wavetable1, freeverbs2);
AudioConnection          patchCord3(freeverbs2, 0, mixer, 1);
AudioConnection          patchCord4(freeverbs2, 1, mixer1, 1);
AudioConnection          patchCord5(freeverbs1, 0, mixer, 0);
AudioConnection          patchCord6(freeverbs1, 1, mixer1, 0);
AudioConnection          patchCord7(mixer1, 0, i2s1, 1);
AudioConnection          patchCord8(mixer, 0, i2s1, 0);
AudioControlSGTL5000     sgtl5000_1;     //xy=2045.0625,2278.5
// GUItool: end automatically generated code


// Bounce objects to read pushbuttons 
Bounce button1 = Bounce(1, 15);  // 15 ms debounce time
int aux;
//pRNG prng;

void setup() { 
  Serial.begin(115200);
  pinMode(1, INPUT_PULLUP);
  AudioMemory(20);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.8);
  mixer.gain(0, 0.1);
  mixer.gain(1, 0.1);

  wavetable.setInstrument(epiano); // epiano
  wavetable.amplitude(0.1);
  wavetable.setInstrument(piano); // piano
  wavetable.amplitude(0.1);
  randomSeed(analogRead(10));
}

bool playing = false;

void loop() {

    // READ PHOTORESISTOR VALUE (analog input A2)
  int fader = analogRead(A4); // Max = 872 , min = 17;
    int knob = analogRead(A3); // Max = 872 , min = 17;
        int a5 = analogRead(A5); // Max = 872 , min = 17;
        int a6 = analogRead(A6); // Max = 872 , min = 17;

  int faderThres = 670;
  Serial.print("fader value= ");
  Serial.println(fader);
    Serial.print("knob value= ");
  Serial.println(knob);
      Serial.print("a5 value= ");
  Serial.println(a5);
        Serial.print("a6 value= ");
  Serial.println(a6);



  
  int numberCase;

  
  if(fader<400){
  numberCase = 1;
          Serial.print("CASE 1\n ");
          }
  if(401<fader && fader<830){
  numberCase = 2;
        Serial.print("CASE 2\n ");
    }
      if(830<fader && fader<852){
  numberCase = 3;
        Serial.print("CASE 3\n ");
    }
      if(852<fader){
  numberCase = 4;
        Serial.print("CASE 4\n ");
    }
   
      
  randomSeed(analogRead(10));
  int randNumber1;
  int randNumber2;
  
  /*
  switch (analog2SeqNumber()) {
  case 1:
    //randomSeqAndOct();
      int randNumber1 = random(1,3); // generate random number between 1 & 2
      int randNumber2 = random(4,6); // generate random number between 1 & 2
      Serial.print("randNumber1 1: \n ");
      Serial.println(randNumber1);
      Serial.print("randNumber2 2: \n ");
      Serial.println(randNumber2);
      playSequenceOct(randNumber1, randNumber2);

    break;
  case 2:
    playSequenceOct(1,5);
    break;
      case 3:
    playSequenceOct(2,4);
    break;
      case 4:
    playSequenceOct(2,5);
    break;
      case 5:
    playSequenceOct(1,4);
    break;
    default:
    playSequenceOct(1,4);
    break;
    }*/
    delay(500);
}


  

    void randomSeqAndOct(){
      int randNumber1 = random(1,3); // generate random number between 1 & 2
      int randNumber2 = random(4,6); // generate random number between 1 & 2
      int seqAndOct[] = {randNumber1, randNumber2};
      Serial.print("seqAndOct 1: \n ");
      Serial.println(seqAndOct[0]);
      Serial.print("seqAndOct 2: \n ");
      Serial.println(seqAndOct[1]);
      playSequenceOct(seqAndOct[0],seqAndOct[1]);
    }
    int analog2SeqNumber()
      {
        int knob = analogRead(A0);
        float anaValue = (float)knob / 1023.0;
        Serial.print("analogKnobRead: \n ");
        Serial.println(anaValue);

        if (anaValue<0.20){
            Serial.print("Selected sequence : 1\n ");
            return 1;
        }
        if (0.20<anaValue && anaValue<0.60){
            Serial.print("Selected sequence : 2\n");
            return 2;
        }
     if (0.60<anaValue && anaValue<0.85){
              Serial.print("Selected sequence : 3\n");
              return 3;
        }
     if (0.85<anaValue && anaValue<0.95){
          Serial.print("Selected sequence : 4\n");
         return 4;
        }
     if (0.95<anaValue){
          Serial.print("Selected sequence = 5\n");
         return 5;
        }
      }

void playSequenceOct(int seq, int oct){ 

       if (seq == 1 && oct == 4){             

      wavetable.playFrequency(73.4161919794);//D // sequence 1 in 4th octave
                  wavetable.amplitude(0.1);
      delay(850);
      wavetable.stop();

      wavetable.playFrequency(97.9988589954);//G
                  wavetable.amplitude(0.1);

      delay(850);
      wavetable.stop();
      wavetable.playFrequency(110.0000000000);//A
            wavetable.amplitude(0.1);
      delay(5150);
      wavetable.stop();
      wavetable.playFrequency(73.4161919794);//D
            wavetable.amplitude(0.1);
      delay(8570);
      wavetable.stop();
      wavetable.playFrequency(73.4161919794);//D
            wavetable.amplitude(0.1);
      delay(4300);
      wavetable.stop();
      }

       if (seq == 1 && oct == 5){                                  // sequence 1 in 5th octave
              wavetable.amplitude(0.1);
      wavetable.playFrequency(146.8323839587 );//D
                  wavetable.amplitude(0.1);
      delay(850);
      wavetable.stop();
      wavetable.playFrequency(195.9977179909);//G
                  wavetable.amplitude(0.1);
      delay(850);
      wavetable.stop();
      wavetable.playFrequency(220.0000000000 );//A
                  wavetable.amplitude(0.1);
      delay(5150);
      wavetable.stop();
      wavetable.playFrequency(146.8323839587 );//D
                  wavetable.amplitude(0.1);
      delay(8570);
      wavetable.stop();
      wavetable.playFrequency(146.8323839587 );//D
                  wavetable.amplitude(0.1);
      delay(4300);
      wavetable.stop();
     }

       if (seq == 2 && oct == 4){                                 // sequence 1 in 5th octave
              wavetable.amplitude(0.1);
      wavetable.playFrequency(97.9988589954);//G
                  wavetable.amplitude(0.1);
      delay(1710);
      wavetable.stop();
      wavetable.playFrequency(82.4068892282);//E
                  wavetable.amplitude(0.1);
      delay(1710);
      wavetable.stop();
      wavetable.playFrequency(92.4986056779);//F#
                  wavetable.amplitude(0.1);
      delay(8570);
      wavetable.stop();
      wavetable.playFrequency(73.4161919794);//D
                  wavetable.amplitude(0.1);
      delay(7710);
      wavetable.stop();
      }

       if (seq == 2,oct == 5){                              // sequence 1 in 5th octave
              wavetable.amplitude(0.1);
      wavetable.playFrequency(195.9977179909);//G
                  wavetable.amplitude(0.1);
      delay(1710);
      wavetable.stop();
      wavetable.playFrequency(164.8137784564);//E
                  wavetable.amplitude(0.1);
      delay(1710);
      wavetable.stop();
      wavetable.playFrequency(184.9972113558);//F#
                  wavetable.amplitude(0.1);
      delay(8570);
      wavetable.stop();
      wavetable.playFrequency(146.8323839587 );//D
                  wavetable.amplitude(0.1);
      delay(7710);
      wavetable.stop();
    }
 }

// http://subsynth.sourceforge.net/midinote2freq.html
const float tune_frequencies2_PGM[128] =
{
    8.1758,    8.6620,    9.1770,    9.7227,    10.3009,    10.9134,    11.5623,    12.2499,
    12.9783,   13.7500,   14.5676,   15.4339,   16.3516,    17.3239,    18.3540,    19.4454,
    20.6017,   21.8268,   23.1247,   24.4997,   25.9565,    27.5000,    29.1352,    30.8677,
    32.7032,   34.6478,   36.7081,   38.8909,   41.2034,    43.6535,    46.2493,    48.9994,
    51.9131,   55.0000,   58.2705,   61.7354,   65.4064,    69.2957,    73.4162,    77.7817,
    82.4069,   87.3071,   92.4986,   97.9989,   103.8262,   110.0000,   116.5409,   123.4708,
    130.8128,  138.5913,  146.8324,  155.5635,  164.8138,   174.6141,   184.9972,   195.9977,
    207.6523,  220.0000,  233.0819,  246.9417,  261.6256,   277.1826,   293.6648,   311.1270,
    329.6276,  349.2282,  369.9944,  391.9954,  415.3047,   440.0000,   466.1638,   493.8833,
    523.2511,  554.3653,  587.3295,  622.2540,  659.2551,   698.4565,   739.9888,   783.9909,
    830.6094,  880.0000,  932.3275,  987.7666,  1046.5023,  1108.7305,  1174.6591,  1244.5079,
    1318.5102, 1396.9129, 1479.9777, 1567.9817, 1661.2188,  1760.0000,  1864.6550,  1975.5332,
    2093.0045, 2217.4610, 2349.3181, 2489.0159, 2637.0205,  2793.8259,  2959.9554,  3135.9635,
    3322.4376, 3520.0000, 3729.3101, 3951.0664, 4186.0090,  4434.9221,  4698.6363,  4978.0317,
    5274.0409, 5587.6517, 5919.9108, 6271.9270, 6644.8752,  7040.0000,  7458.6202,  7902.1328,
    8372.0181, 8869.8442, 9397.2726, 9956.0635, 10548.0818, 11175.3034, 11839.8215, 12543.8540
};

const float velocity2amplitude[127] = {
0.01778,0.01966,0.02164,0.02371,0.02588,0.02814,0.03049,0.03294,0.03549,0.03812,
0.04086,0.04369,0.04661,0.04963,0.05274,0.05594,0.05924,0.06264,0.06613,0.06972,
0.07340,0.07717,0.08104,0.08500,0.08906,0.09321,0.09746,0.10180,0.10624,0.11077,
0.11539,0.12011,0.12493,0.12984,0.13484,0.13994,0.14513,0.15042,0.15581,0.16128,
0.16685,0.17252,0.17828,0.18414,0.19009,0.19613,0.20227,0.20851,0.21484,0.22126,
0.22778,0.23439,0.24110,0.24790,0.25480,0.26179,0.26887,0.27605,0.28333,0.29070,
0.29816,0.30572,0.31337,0.32112,0.32896,0.33690,0.34493,0.35306,0.36128,0.36960,
0.37801,0.38651,0.39511,0.40381,0.41260,0.42148,0.43046,0.43953,0.44870,0.45796,
0.46732,0.47677,0.48631,0.49595,0.50569,0.51552,0.52544,0.53546,0.54557,0.55578,
0.56609,0.57648,0.58697,0.59756,0.60824,0.61902,0.62989,0.64085,0.65191,0.66307,
0.67432,0.68566,0.69710,0.70863,0.72026,0.73198,0.74380,0.75571,0.76771,0.77981,
0.79201,0.80430,0.81668,0.82916,0.84174,0.85440,0.86717,0.88003,0.89298,0.90602,
0.91917,0.93240,0.94573,0.95916,0.97268,0.98629,1.00000
};
/*
 * 
 * 
 */
