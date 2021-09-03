#include <Arduino.h>
#include <Wire.h>
#include "PT2329.h"

PT2329::PT2329(){
	Wire.begin();
}

void PT2329::LCH_Volume(byte l_volume){
  writeWire(LCH_VOL, l_volume << 1);	
}
void PT2329::RCH_Volume(byte r_volume){
  writeWire(RCH_VOL, r_volume << 1);	
} 

void PT2329::setBass(char set_bass){
  int bass_f;
  if(set_bass>=0){bass_f = set_bass + 0b10000;}
   else{bass_f = abs(set_bass);}
  writeWire(BASS, bass_f << 3);	
}
void PT2329::setTreb(char set_treb){
  int treb_f;
  if(set_treb>=0){treb_f = set_treb + 0b10000;}
   else{treb_f = abs(set_treb);}
  writeWire(TREB, treb_f << 3);	
}

void PT2329::setIn_gain(byte in_gain){
  writeWire(IN_GAIN, in_gain << 4);
}

void PT2329::setIn_sel(byte in_sel, byte rec, byte rec_gain, byte surr, byte mode){
  writeWire(IN_SEL, (in_sel << 5) + (rec << 4) + (rec_gain << 3) + (surr << 2) + (mode));
}


void PT2329::writeWire(byte a, byte b){
  Wire.beginTransmission(PT2329_address);
  Wire.write (a);
  Wire.write (b);
  Wire.endTransmission();
}
