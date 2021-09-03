// liman324@yandex.ru rcl-radio.ru


#ifndef PT2329_H
#define PT2329_H

#define PT2329_address 0b1000001

#define LCH_VOL      0b00000000
#define RCH_VOL      0b00000001
#define BASS         0b00000010
#define TREB         0b00000011
#define IN_GAIN      0b00000100
#define IN_SEL       0b00000101

#include <Arduino.h>
class PT2329
{
  public:
    PT2329();
      void LCH_Volume(byte l_volume); 
// l_volume >>> byte 87...0 === -87...0 dB step 1 dB || int 127 === mute
      void RCH_Volume(byte r_volume); 
// r_volume >>> byte 87...0 === -87...0 dB step 1 dB || int 127 === mute
      void setBass(char set_bass);
// set_bass >>> char -15...+15 === -15...+15 dB step 1 dB
      void setTreb(char set_treb);
// set_treb >>> char -15...+15 === -15...+15 dB step 1 dB
      void setIn_gain(byte in_gain);
// in_gain >>> byte 0...12 === 0...12 dB step 1 dB
      void setIn_sel(byte in_sel, byte rec, byte rec_gain, byte surr, byte mode);
// in_sel >>> byte 1..6 === in1...in6, int 0 === mute
// rec >>> byte 0...1 === If A=0 means IN6 output OFF, than A=1 means IN6 output ON
// rec_gain >>> byte 0 === -2 dB, 1 === 0 dB
// surr >>> byte 0 === Surround Low, 1 === Surround High
// mode >>> byte 0 === Bypass, 1 === Tone, 2 === Tone & Sur
		
 private:
	void writeWire(byte a, byte b);
};
	
#endif //PT2329_H
