#include <Wire.h>
#include <PT2329.h>
 PT2329 pt;

void setup() {
  Wire.begin();
  audio();
}

void loop() {
 

}

void audio(){
      pt.LCH_Volume(0); 
// l_volume >>> byte 87...0 === -87...0 dB step 1 dB || int 127 === mute
      pt.RCH_Volume(0); 
// r_volume >>> byte 87...0 === -87...0 dB step 1 dB || int 127 === mute
      pt.setBass(0);
// set_bass >>> char -15...+15 === -15...+15 dB step 1 dB
      pt.setTreb(0);
// set_treb >>> char -15...+15 === -15...+15 dB step 1 dB
      pt.setIn_gain(0);
// in_gain >>> byte 0...12 === 0...12 dB step 1 dB
      pt.setIn_sel(1, 1, 0, 1, 2);
// in_sel >>> byte 1..6 === in1...in6, int 0 === mute
// rec >>> byte 0...1 === If A=0 means IN6 output OFF, than A=1 means IN6 output ON
// rec_gain >>> byte 0 === -2 dB, 1 === 0 dB
// surr >>> byte 0 === Surround Low, 1 === Surround High
// mode >>> byte 0 === Bypass, 1 === Tone, 2 === Tone & Sur
  }
