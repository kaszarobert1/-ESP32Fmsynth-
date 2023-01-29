//  memoria.ino

#include "EEPROM.h"



void save() {
  //EEPROM.begin(EEPROMsize);
  saveprog--;
  int kezdocim = saveprog * 150;
  Serial.println("SAVE ADRESS BEGIN:" + String(kezdocim)) ;
  //1
  Serial.println("SAVE BEGIN") ;
  MIDIsave.put(kezdocim++, op1waveform);
  MIDIsave.put(kezdocim++, op2waveform);
  MIDIsave.put(kezdocim++, op3waveform);
  MIDIsave.put(kezdocim++, op4waveform);
  MIDIsave.put(kezdocim++, op5waveform);
  MIDIsave.put(kezdocim++, op6waveform);
  MIDIsave.put(kezdocim++, op1al);
  MIDIsave.put(kezdocim++, op2al);
  MIDIsave.put(kezdocim++, op3al);
  MIDIsave.put(kezdocim++, op4al);
  MIDIsave.put(kezdocim++, op5al);
  MIDIsave.put(kezdocim++, op6al);
  //13
  MIDIsave.put(kezdocim++, op1ar);
  MIDIsave.put(kezdocim++, op2ar);
  MIDIsave.put(kezdocim++, op3ar);
  MIDIsave.put(kezdocim++, op4ar);
  MIDIsave.put(kezdocim++, op5ar);
  MIDIsave.put(kezdocim++, op6ar);
  MIDIsave.put(kezdocim++, op1d1l);
  MIDIsave.put(kezdocim++, op2d1l);
  MIDIsave.put(kezdocim++, op3d1l);
  MIDIsave.put(kezdocim++, op4d1l);
  MIDIsave.put(kezdocim++, op5d1l);
  MIDIsave.put(kezdocim++, op6d1l);
  //25
  MIDIsave.put(kezdocim++, op1d1r);
  MIDIsave.put(kezdocim++, op2d1r);
  MIDIsave.put(kezdocim++, op3d1r);
  MIDIsave.put(kezdocim++, op4d1r);
  MIDIsave.put(kezdocim++, op5d1r);
  MIDIsave.put(kezdocim++, op6d1r);
  MIDIsave.put(kezdocim++, op1d2l);
  MIDIsave.put(kezdocim++, op2d2l);
  MIDIsave.put(kezdocim++, op3d2l);
  MIDIsave.put(kezdocim++, op4d2l);
  MIDIsave.put(kezdocim++, op5d2l);
  MIDIsave.put(kezdocim++, op6d2l);
  //37
  MIDIsave.put(kezdocim++, op1d2r);
  MIDIsave.put(kezdocim++, op2d2r);
  MIDIsave.put(kezdocim++, op3d2r);
  MIDIsave.put(kezdocim++, op4d2r);
  MIDIsave.put(kezdocim++, op5d2r);
  MIDIsave.put(kezdocim++, op6d2r);
  MIDIsave.put(kezdocim++, op1rl);
  MIDIsave.put(kezdocim++, op2rl);
  MIDIsave.put(kezdocim++, op3rl);
  MIDIsave.put(kezdocim++, op4rl);
  MIDIsave.put(kezdocim++, op5rl);
  MIDIsave.put(kezdocim++, op6rl);
  //49
  MIDIsave.put(kezdocim++, op1rr);
  MIDIsave.put(kezdocim++, op2rr);
  MIDIsave.put(kezdocim++, op3rr);
  MIDIsave.put(kezdocim++, op4rr);
  MIDIsave.put(kezdocim++, op5rr);
  MIDIsave.put(kezdocim++, op6rr);
  MIDIsave.put(kezdocim++, pichal);
  MIDIsave.put(kezdocim++, pichar);
  MIDIsave.put(kezdocim++, pichd1l);
  MIDIsave.put(kezdocim++, pichd1r);
  MIDIsave.put(kezdocim++, pichd2l);
  MIDIsave.put(kezdocim++, pichd2r);
  MIDIsave.put(kezdocim++, pichrl);
  MIDIsave.put(kezdocim++, pichrr);
  //63
  MIDIsave.put(kezdocim++, op1volume );
  MIDIsave.put(kezdocim++, op2volume );
  MIDIsave.put(kezdocim++, op3volume );
  MIDIsave.put(kezdocim++, op4volume );
  MIDIsave.put(kezdocim++, op5volume );
  MIDIsave.put(kezdocim++, op6volume );
  MIDIsave.put(kezdocim++, op1veloc );
  MIDIsave.put(kezdocim++, op2veloc );
  MIDIsave.put(kezdocim++, op3veloc );
  MIDIsave.put(kezdocim++, op4veloc );
  MIDIsave.put(kezdocim++, op5veloc );
  MIDIsave.put(kezdocim++, op6veloc );
  //75
  MIDIsave.put(kezdocim++, op1generatorfreq );
  MIDIsave.put(kezdocim++, op2generatorfreq );
  MIDIsave.put(kezdocim++, op3generatorfreq );
  MIDIsave.put(kezdocim++, op4generatorfreq );
  MIDIsave.put(kezdocim++, op5generatorfreq );
  MIDIsave.put(kezdocim++, op6generatorfreq );
  MIDIsave.put(kezdocim++, op1generatorfreqfixp);
  MIDIsave.put(kezdocim++, op2generatorfreqfixp);
  MIDIsave.put(kezdocim++, op3generatorfreqfixp);
  MIDIsave.put(kezdocim++, op4generatorfreqfixp);
  MIDIsave.put(kezdocim++, op5generatorfreqfixp);
  MIDIsave.put(kezdocim++, op6generatorfreqfixp);
  //87
  MIDIsave.put(kezdocim++, op1pich );
  MIDIsave.put(kezdocim++, op2pich );
  MIDIsave.put(kezdocim++, op3pich );
  MIDIsave.put(kezdocim++, op4pich );
  MIDIsave.put(kezdocim++, op5pich );
  MIDIsave.put(kezdocim++, op6pich );
  MIDIsave.put(kezdocim++, pichkezd );
  MIDIsave.put(kezdocim++, op1detunep);
  MIDIsave.put(kezdocim++, op2detunep);
  MIDIsave.put(kezdocim++, op3detunep);
  MIDIsave.put(kezdocim++, op4detunep);
  MIDIsave.put(kezdocim++, op5detunep);
  MIDIsave.put(kezdocim++, op6detunep);
  MIDIsave.put(kezdocim++, op1notefixed );
  MIDIsave.put(kezdocim++, op2notefixed );
  MIDIsave.put(kezdocim++, op3notefixed );
  MIDIsave.put(kezdocim++, op4notefixed );
  MIDIsave.put(kezdocim++, op5notefixed );
  MIDIsave.put(kezdocim++, op6notefixed );
  //106
  MIDIsave.put(kezdocim++, frame );
  MIDIsave.put(kezdocim++, szorzo );
  MIDIsave.put(kezdocim++, algorithm );
  MIDIsave.put(kezdocim++, level);
  MIDIsave.put(kezdocim++, feedbacklevel);
  MIDIsave.put(kezdocim++, mastertune);
  MIDIsave.put(kezdocim++, Qp);
  MIDIsave.put(kezdocim++, Q2p);
  MIDIsave.put(kezdocim++, pareqfreq0 );
  MIDIsave.put(kezdocim++, pareqfreq1);
  MIDIsave.put(kezdocim++, limitgain);
  MIDIsave.put(kezdocim++, limitgain2);
  MIDIsave.put(kezdocim++, (oplevel - 1) * 2);
  MIDIsave.put(kezdocim++, pichvolume );//!!!
  MIDIsave.put(kezdocim++, lfo2freq);
  MIDIsave.put(kezdocim++, lfo2delaytime);
  MIDIsave.put(kezdocim++, lfo2volume );
  MIDIsave.put(kezdocim++, modulation);
  //123
  MIDIsave.put(kezdocim++, reverblevel - 1 );
  MIDIsave.put(kezdocim++, reverbdiffusion);
  MIDIsave.put(kezdocim++, delaytime );
  MIDIsave.put(kezdocim++, delay2time );
  MIDIsave.put(kezdocim++, released);
  MIDIsave.put(kezdocim++, chorusfreq);
  MIDIsave.put(kezdocim++, choruslevel);
  MIDIsave.put(kezdocim++, eqvalue);
  MIDIsave.put(kezdocim++, parametereqlefton);
  MIDIsave.put(kezdocim++, parametereqrighton);
  MIDIsave.put(kezdocim++, parametereqlefton);
  MIDIsave.put(kezdocim++, limiterrighton);
  MIDIsave.put(kezdocim++, limiterlefton);
  MIDIsave.put(kezdocim++, limiterrighton);
  MIDIsave.put(kezdocim++, delaylowpasseqlefton);
  MIDIsave.put(kezdocim++, delaylowpasseqlefton);
  MIDIsave.put(kezdocim++, highpassrighteqon);
  MIDIsave.put(kezdocim++, highpasslefteqon);
  //140

 MIDIsave.commit();
  Serial.println("SAVE END") ;
  Serial.println("ADRESS END:" + String(kezdocim)) ;
  if (kezdocim >= EEPROMsize)
    Serial.println("Kicsi a lefoglalt EEPROM tomb merete: " + String(kezdocim));

  parameterstest();
}

void load(byte loadprog) {
  loadprog--;
  //EEPROM.begin(EEPROMsize);
  int kezdocim = loadprog * 150;
  Serial.println("LOAD ADRESS BEGIN:" + String(kezdocim)) ;
  //1
  Serial.println("Load 1.") ;
  MIDIsave.get(kezdocim++, op1waveform);
  MIDIsave.get(kezdocim++, op2waveform);
  MIDIsave.get(kezdocim++, op3waveform);
  MIDIsave.get(kezdocim++, op4waveform);
  MIDIsave.get(kezdocim++, op5waveform);
  MIDIsave.get(kezdocim++, op6waveform);
  MIDIsave.get(kezdocim++, op1al);
  MIDIsave.get(kezdocim++, op2al);
  MIDIsave.get(kezdocim++, op3al);
  MIDIsave.get(kezdocim++, op4al);
  MIDIsave.get(kezdocim++, op5al);
  MIDIsave.get(kezdocim++, op6al);
  //13
  Serial.println("Load 13.") ;
  MIDIsave.get(kezdocim++, op1ar);
  MIDIsave.get(kezdocim++, op2ar);
  MIDIsave.get(kezdocim++, op3ar);
  MIDIsave.get(kezdocim++, op4ar);
  MIDIsave.get(kezdocim++, op5ar);
  MIDIsave.get(kezdocim++, op6ar);
  MIDIsave.get(kezdocim++, op1d1l);
  MIDIsave.get(kezdocim++, op2d1l);
  MIDIsave.get(kezdocim++, op3d1l);
  MIDIsave.get(kezdocim++, op4d1l);
  MIDIsave.get(kezdocim++, op5d1l);
  MIDIsave.get(kezdocim++, op6d1l);
  //25
  MIDIsave.get(kezdocim++, op1d1r);
  MIDIsave.get(kezdocim++, op2d1r);
  MIDIsave.get(kezdocim++, op3d1r);
  MIDIsave.get(kezdocim++, op4d1r);
  MIDIsave.get(kezdocim++, op5d1r);
  MIDIsave.get(kezdocim++, op6d1r);
  MIDIsave.get(kezdocim++, op1d2l);
  MIDIsave.get(kezdocim++, op2d2l);
  MIDIsave.get(kezdocim++, op3d2l);
  MIDIsave.get(kezdocim++, op4d2l);
  MIDIsave.get(kezdocim++, op5d2l);
  MIDIsave.get(kezdocim++, op6d2l);
  //37
  Serial.println("Load 37.") ;
  MIDIsave.get(kezdocim++, op1d2r);
  MIDIsave.get(kezdocim++, op2d2r);
  MIDIsave.get(kezdocim++, op3d2r);
  MIDIsave.get(kezdocim++, op4d2r);
  MIDIsave.get(kezdocim++, op5d2r);
  MIDIsave.get(kezdocim++, op6d2r);
  MIDIsave.get(kezdocim++, op1rl);
  MIDIsave.get(kezdocim++, op2rl);
  MIDIsave.get(kezdocim++, op3rl);
  MIDIsave.get(kezdocim++, op4rl);
  MIDIsave.get(kezdocim++, op5rl);
  MIDIsave.get(kezdocim++, op6rl);
  //49
  Serial.print("Load 49.") ;
  MIDIsave.get(kezdocim++, op1rr);
  MIDIsave.get(kezdocim++, op2rr);
  MIDIsave.get(kezdocim++, op3rr);
  MIDIsave.get(kezdocim++, op4rr);
  MIDIsave.get(kezdocim++, op5rr);
  MIDIsave.get(kezdocim++, op6rr);
  MIDIsave.get(kezdocim++, pichal);
  MIDIsave.get(kezdocim++, pichar);
  MIDIsave.get(kezdocim++, pichd1l);
  MIDIsave.get(kezdocim++, pichd1r);
  MIDIsave.get(kezdocim++, pichd2l);
  MIDIsave.get(kezdocim++, pichd2r);
  MIDIsave.get(kezdocim++, pichrl);
  MIDIsave.get(kezdocim++, pichrr);
  //63
  Serial.println("Load 63.") ;
  MIDIsave.get(kezdocim++, op1volume);
  MIDIsave.get(kezdocim++, op2volume);
  MIDIsave.get(kezdocim++, op3volume);
  MIDIsave.get(kezdocim++, op4volume);
  MIDIsave.get(kezdocim++, op5volume);
  MIDIsave.get(kezdocim++, op6volume);
  MIDIsave.get(kezdocim++, op1veloc);
  MIDIsave.get(kezdocim++, op2veloc);
  MIDIsave.get(kezdocim++, op3veloc);
  MIDIsave.get(kezdocim++, op4veloc);
  MIDIsave.get(kezdocim++, op5veloc);
  MIDIsave.get(kezdocim++, op6veloc);
  //75
  Serial.println("Load 75.") ;
  MIDIsave.get(kezdocim++, op1generatorfreq);
  MIDIsave.get(kezdocim++, op2generatorfreq);
  MIDIsave.get(kezdocim++, op3generatorfreq);
  MIDIsave.get(kezdocim++, op4generatorfreq);
  MIDIsave.get(kezdocim++, op5generatorfreq);
  MIDIsave.get(kezdocim++, op6generatorfreq);
  MIDIsave.get(kezdocim++, op1generatorfreqfixp);
  MIDIsave.get(kezdocim++, op2generatorfreqfixp);
  MIDIsave.get(kezdocim++, op3generatorfreqfixp);
  MIDIsave.get(kezdocim++, op4generatorfreqfixp);
  MIDIsave.get(kezdocim++, op5generatorfreqfixp);
  MIDIsave.get(kezdocim++, op6generatorfreqfixp);
  //87
  Serial.println("Load 87.") ;
  MIDIsave.get(kezdocim++, op1pich);
  MIDIsave.get(kezdocim++, op2pich);
  MIDIsave.get(kezdocim++, op3pich);
  MIDIsave.get(kezdocim++, op4pich);
  MIDIsave.get(kezdocim++, op5pich);
  MIDIsave.get(kezdocim++, op6pich);
  MIDIsave.get(kezdocim++, pichkezd);
  MIDIsave.get(kezdocim++, op1detunep);
  MIDIsave.get(kezdocim++, op2detunep);
  MIDIsave.get(kezdocim++, op3detunep);
  MIDIsave.get(kezdocim++, op4detunep);
  MIDIsave.get(kezdocim++, op5detunep);
  MIDIsave.get(kezdocim++, op6detunep);
  MIDIsave.get(kezdocim++, op1notefixed);
  MIDIsave.get(kezdocim++, op2notefixed);
  MIDIsave.get(kezdocim++, op3notefixed);
  MIDIsave.get(kezdocim++, op4notefixed);
  MIDIsave.get(kezdocim++, op5notefixed);
  MIDIsave.get(kezdocim++, op6notefixed);
  //107

  Serial.println("Load 107.") ;
  MIDIsave.get(kezdocim++, frame);
  MIDIsave.get(kezdocim++, szorzo);
  MIDIsave.get(kezdocim++, algorithm);
  MIDIsave.get(kezdocim++, level);
  MIDIsave.get(kezdocim++, feedbacklevel);
  MIDIsave.get(kezdocim++, mastertune);
  MIDIsave.get(kezdocim++, Qp);
  MIDIsave.get(kezdocim++, Q2p);
  MIDIsave.get(kezdocim++, pareqfreq0 );
  MIDIsave.get(kezdocim++, pareqfreq1);
  MIDIsave.get(kezdocim++, limitgain);
  MIDIsave.get(kezdocim++, limitgain2);
  MIDIsave.get(kezdocim++, oplevel);
  MIDIsave.get(kezdocim++, pichvolume );
  MIDIsave.get(kezdocim++, lfo2freq);
  MIDIsave.get(kezdocim++, lfo2delaytime);
  MIDIsave.get(kezdocim++, lfo2volume );
  MIDIsave.get(kezdocim++, modulation);
  //123
  MIDIsave.get(kezdocim++, reverblevel);
  MIDIsave.get(kezdocim++, reverbdiffusion);
  MIDIsave.get(kezdocim++, delaytime );
  MIDIsave.get(kezdocim++, delay2time );
  MIDIsave.get(kezdocim++, released);
  MIDIsave.get(kezdocim++, chorusfreq);
  MIDIsave.get(kezdocim++, choruslevel);
  MIDIsave.get(kezdocim++, eqvalue);
  MIDIsave.get(kezdocim++, parametereqlefton);
  MIDIsave.get(kezdocim++, parametereqrighton);
  MIDIsave.get(kezdocim++, parametereqlefton);
  MIDIsave.get(kezdocim++, limiterrighton);
  MIDIsave.get(kezdocim++, limiterlefton);
  MIDIsave.get(kezdocim++, limiterrighton);
  MIDIsave.get(kezdocim++, delaylowpasseqlefton);
  MIDIsave.get(kezdocim++, delaylowpasseqlefton);
  MIDIsave.get(kezdocim++, highpassrighteqon);
  MIDIsave.get(kezdocim++, highpasslefteqon);
  //140
  Serial.println("Load END") ;
  Serial.println("ADRESS END:" + String(kezdocim)) ;

  proginit();
  parameterstest();
  if (kezdocim >= EEPROMsize)
    Serial.println("Kicsi a lefoglalt EEPROM tomb merete: " + String(kezdocim));

}
