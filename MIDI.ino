//----------------------------MIDI-----------------------------------------------------------------
//MIDI INPUTS SWITCER
/*
  void serialEvent() {
  byte command = Serial2.read();
  byte data1 = Serial2.read();
  byte data2 = Serial2.read();
  switch (command)     // Get the type of the message we caught
  {
    case 144:
      noteByte = data1;
      velocityByte = data2;
    //search empty note:
      for (int i = 0; i < 6; i++) {
        if (oldnoteByte[i] == 0)
        {
          generatornumber = i;
        }
      }
      gorbetime[generatornumber] = 0;
      ptrnullaz();
      wavefreq[generatornumber] = noteertek[noteByte];
      waveveloc[generatornumber]  = data2;
      oldnoteByte[generatornumber] = noteByte;
      //next note on set
      generatornumber++;
      if (generatornumber == 6) {
        generatornumber = 0;
      }
      break;
    case 128:
      noteByte = data1;
      //  velocityByte = data2;
      if (noteByte == oldnoteByte[0]) {
        gorbetime[0] = maxrelease;
        oldnoteByte[0] = 0;
        //   generatornumber=0;
      }
      if (noteByte == oldnoteByte[1]) {
        gorbetime[1] = maxrelease;
        oldnoteByte[1] = 0;
        //  generatornumber=1;
      }
      if (noteByte == oldnoteByte[2]) {
        gorbetime[2] = maxrelease;
        oldnoteByte[2] = 0;
        //  generatornumber=2;
      }
      if (noteByte == oldnoteByte[3]) {
        gorbetime[3] = maxrelease;
        oldnoteByte[3] = 0;
        //  generatornumber=3;
      }
      if (noteByte == oldnoteByte[4]) {
        gorbetime[4] = maxrelease;
        oldnoteByte[4] = 0;
        //   generatornumber=4;
      }
      if (noteByte == oldnoteByte[5]) {
        gorbetime[5] = maxrelease;
        oldnoteByte[5] = 0;
        //   generatornumber=5;
      }
      break;
    case 192:
      noteByte = MIDI2.getData1();
      velocityByte = MIDI2.getData2();
      programchange(noteByte);
      break;
    case 176:
      noteByte = data1;
      velocityByte = data2;
      parameterchange2();
      break;
    case 248:
      //sendmidiclock();
      break;
  }
  }
*/
//byte pichvaluearray[128]={3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,4,4,4,4,4,4,5,5,5,5,6,6,6,6,6,7,7,7,7,7,8,8,8,8,8,8,8,9,9,9,9,9,9,10,10,10,10,10,10,10,11,11,11,11,11,12,12,12,12,12,13,13,13,13,14,14,14,14,14,15,15,15,15,15,16,16,16,16,16,17,17,17,17,18,18,18,18,18,19,19,19,19,19,20,20,20,21,21,21,22,22,23,23,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24,24};
void serialEvent() {
  if (MIDI2.read(midichan)) {
    switch (MIDI2.getType())     // Get the type of the message we caught
    {
      case midi::NoteOn:
        noteByte = MIDI2.getData1();
        velocityByte = MIDI2.getData2();
        //search empty note:
        lfo2delay = 0;
        lfo2arrayindex = 0;
        // lfo2tempvolume = 0;
        /*
          for (int i = 5; i >= 0; i--) {
          if (oldnoteByte[i] == 0)
          {
            generatornumber = i;
          }
          }
        */
        gorbetime[generatornumber] = 0;
        ptrnullaz();
        wavefreq[generatornumber] = noteertek[noteByte];

        waveveloc[generatornumber]  = velocityByte;
        oldnoteByte[generatornumber] = noteByte;
        //next note on set
        generatornumber++;
        if (generatornumber == 6) {
          generatornumber = 0;
        }
        break;
      case midi::NoteOff:
        noteByte = MIDI2.getData1();
        //  velocityByte = MIDI2.getData2();
        if (noteByte == oldnoteByte[0]) {
          gorbetime[0] = maxrelease;
          oldnoteByte[0] = 0;
          //   generatornumber=0;
        }
        if (noteByte == oldnoteByte[1]) {
          gorbetime[1] = maxrelease;
          oldnoteByte[1] = 0;
          //  generatornumber=1;
        }
        if (noteByte == oldnoteByte[2]) {
          gorbetime[2] = maxrelease;
          oldnoteByte[2] = 0;
          //  generatornumber=2;
        }
        if (noteByte == oldnoteByte[3]) {
          gorbetime[3] = maxrelease;
          oldnoteByte[3] = 0;
          //  generatornumber=3;
        }
        if (noteByte == oldnoteByte[4]) {
          gorbetime[4] = maxrelease;
          oldnoteByte[4] = 0;
          //   generatornumber=4;
        }
        if (noteByte == oldnoteByte[5]) {
          gorbetime[5] = maxrelease;
          oldnoteByte[5] = 0;
          //   generatornumber=5;
        }

        /*
          switch (noteByte)
          {
          case  oldnoteByte1: gorbetime[0] = maxrelease; break;
          case  oldnoteByte2: gorbetime[1] = maxrelease; break;
          case  oldnoteByte3: gorbetime[2] = maxrelease; break;
          case  oldnoteByte4: gorbetime[3] = maxrelease; break;
          case  oldnoteByte5: gorbetime[4] = maxrelease; break;
          case  oldnoteByte6: gorbetime[5] = maxrelease; break;
          }
        */
        break;
      case midi:: ProgramChange:

        noteByte = MIDI2.getData1();
        velocityByte = MIDI2.getData2();
        programchange(noteByte);
        break;

      case midi:: AfterTouchPoly:

        break;
      case midi:: PitchBend:
       /*
        noteByte = 104;
        velocityByte = MIDI2.getData2();
        op1generatorfreq=pichvaluearray[velocityByte];
        */
   /*
        if (velocityByte <= 63 )
        {
           op1generatorfreq =op1generatorfreqorig-((64-velocityByte)>>2);
          //  op1detune = (op1detunep << 12) -  ((64-velocityByte)<<11);
          //op1detune=(op1detunep << 12)-(64-velocityByte)<<13;
         
        } else if (velocityByte >= 65) {
            op1generatorfreq =op1generatorfreqorig+((velocityByte-64)>>2);
          //   op1detune = (op1detunep << 12) + (velocityByte-64)<<11);
          //   op1detune=(op1detunep << 12)+(velocityByte-62)<<13;
        }
        else {
          op1generatorfreq = op1generatorfreqorig;
           //op1detune = (op1detunep << 12);
         
        }
*/

        parameterchange2();

        break;
      case midi:: ControlChange:
        noteByte = MIDI2.getData1();
        velocityByte = MIDI2.getData2();
        //pichband(44, noteByte);
        parameterchange2();
        /*
          Serial.print(noteByte);
          Serial.print(" ");
          Serial.print(velocityByte);
          Serial.print("\n");
        */
        break;
      case midi:: Clock:
        sendmidiclock();
        break;
    }
  }

}

//MODULATION METHOD
byte lastmodulation = 0;
void pichband() {
  if (lastmodulation != modulation)
  {
    if (modulation < 21 and modulation > 0 )
    {
      op1volume = op1volumeorig;
      op2volume = op2volumeorig;
      op3volume = op3volumeorig;
      op4volume = op4volumeorig;
      op5volume = op5volumeorig;
      op6volume = op6volumeorig;
    }
    if (modulation >= 21 and modulation <= 33)
    {
      op1detune = (op1detunep << 12);
      op2detune = (op2detunep << 12);
      op3detune = (op3detunep << 12);
      op4detune = (op4detunep << 12);
      op5detune = (op5detunep << 12);
      op6detune = (op6detunep << 12);
    }

    if (modulation >= 34 and modulation <= 41)
    {
      f0 = f0orig;
      f02 = f02orig ;
    }

    lastmodulation = modulation;
  } else {
    switch (modulation) {
      case 1:  op1volume = op1volumeorig + ((lfo2value * lfo2volume) >> 10);  break;
      case 2:  op2volume = op2volumeorig + ((lfo2value * lfo2volume) >> 10);  break;
      case 3:  op3volume = op3volumeorig + ((lfo2value * lfo2volume) >> 10);  break;
      case 4:  op4volume = op4volumeorig + ((lfo2value * lfo2volume) >> 10);  break;
      case 5:  op5volume = op5volumeorig + ((lfo2value * lfo2volume) >> 10);  break;
      case 6:  op6volume = op6volumeorig + ((lfo2value * lfo2volume) >> 10);  break;
      case 7:  op1volume = op1volumeorig + ((lfo2value * lfo2volume) >> 10); op2volume = op2volumeorig + ((lfo2value * lfo2volume) >> 10); break;
      case 8:  op1volume = op1volumeorig + ((lfo2value * lfo2volume) >> 10); op2volume = op2volumeorig - ((lfo2value * lfo2volume) >> 10);  break;
      case 9:  op1volume = op1volumeorig + ((lfo2value * lfo2volume) >> 10); op3volume = op3volumeorig + ((lfo2value * lfo2volume) >> 10);  break;
      case 10: op1volume = op1volumeorig + ((lfo2value * lfo2volume) >> 10); op3volume = op3volumeorig - ((lfo2value * lfo2volume) >> 10);  break;
      case 11: op1volume = op1volumeorig + ((lfo2value * lfo2volume) >> 10); op4volume = op4volumeorig + ((lfo2value * lfo2volume) >> 10);  break;
      case 12: op1volume = op1volumeorig + ((lfo2value * lfo2volume) >> 10); op4volume = op4volumeorig - ((lfo2value * lfo2volume) >> 10);  break;
      case 13: op1volume = op1volumeorig + ((lfo2value * lfo2volume) >> 10); op5volume = op5volumeorig + ((lfo2value * lfo2volume) >> 10); break;
      case 14: op1volume = op1volumeorig + ((lfo2value * lfo2volume) >> 10); op5volume = op5volumeorig + ((lfo2value * lfo2volume) >> 10);  break;
      case 15: op1volume = op1volumeorig + ((lfo2value * lfo2volume) >> 10); op2volume = op2volumeorig + ((lfo2value * lfo2volume) >> 10);; op3volume = op3volumeorig + ((lfo2value * lfo2volume) >> 10); break;
      case 16: op1volume = op1volumeorig + ((lfo2value * lfo2volume) >> 10); op2volume = op2volumeorig - ((lfo2value * lfo2volume) >> 10); op3volume = op3volumeorig + ((lfo2value * lfo2volume) >> 10); break;
      case 17: op2volume = op2volumeorig + ((lfo2value * lfo2volume) >> 10); op4volume = op4volumeorig + ((lfo2value * lfo2volume) >> 10); op6volume = op6volumeorig + ((lfo2value * lfo2volume) >> 10); break;
      case 18: op2volume = op2volumeorig + ((lfo2value * lfo2volume) >> 10); op4volume = op4volumeorig - ((lfo2value * lfo2volume) >> 10); op6volume = op6volumeorig + ((lfo2value * lfo2volume) >> 10); break;
      case 19: op2volume = op2volumeorig + ((lfo2value * lfo2volume) >> 10); op3volume = op3volumeorig + ((lfo2value * lfo2volume) >> 10); op5volume = op5volumeorig + ((lfo2value * lfo2volume) >> 10); break;
      case 20: op2volume = op2volumeorig + ((lfo2value * lfo2volume) >> 10); op3volume = op3volumeorig - ((lfo2value * lfo2volume) >> 10); op5volume = op5volumeorig + ((lfo2value * lfo2volume) >> 10); break;
      case 21: op1detune = (op1detunep << 12) + lfo2value * expgains128[lfo2volume] ; break;
      case 22: op2detune = (op2detunep << 12) + lfo2value * expgains128[lfo2volume]; break;
      case 23: op3detune = (op3detunep << 12) + lfo2value * expgains128[lfo2volume]; break;
      case 24: op4detune = (op4detunep << 12) + lfo2value * expgains128[lfo2volume]; break;
      case 25: op5detune = (op5detunep << 12) + lfo2value * expgains128[lfo2volume]; break;
      case 26: op6detune = (op6detunep << 12) + lfo2value * expgains128[lfo2volume]; break;
      case 27: op1detune = (op1detunep << 12) + lfo2value;  op2detune = (op2detunep << 12) + lfo2value; break;//1,2
      case 28: op2detune = (op2detunep << 12) + lfo2value;  op3detune = (op3detunep << 12) + lfo2value; break;//2,3
      case 29: op3detune = (op3detunep << 12) + lfo2value;  op5detune = (op5detunep << 12) + lfo2value;  break;//3,5
      case 30: op3detune = (op3detunep << 12) + lfo2value;  op6detune = (op6detunep << 12) + lfo2value;  break;//3,6
      case 31: op1detune = (op1detunep << 12) + lfo2value;  op5detune = (op5detunep << 12) + lfo2value; break; //1,5
      case 32: op2detune = (op2detunep << 12) + lfo2value;  op6detune = (op6detunep << 12) + lfo2value;  break;//2,6
      case 33: op1detune = (op1detunep << 12) + lfo2value;  op3detune = (op3detunep << 12) + lfo2value; op4detune = (op4detunep << 12) + lfo2value; break;//1,3,4
      case 34: f0 = f0orig + ((lfo2value * lfo2volume) >> 1);   eqkiszamol(); break;
      case 35: f02 = f02orig + ((lfo2value * lfo2volume) >> 1);   eqkiszamol2(); break;
      case 36: f0 = f0orig + ((lfo2value * lfo2volume) >> 1);   eqkiszamol();   eqkiszamol(); f02 = f02orig + ((lfo2value * lfo2volume) >> 1);   eqkiszamol2(); break;
      case 37: f0 = f0orig + ((lfo2value * lfo2volume) >> 1); op1volume = op1volumeorig + ((lfo2value * lfo2volume) >> 10);  eqkiszamol(); break;
      case 38: f02 = f02orig + ((lfo2value * lfo2volume) >> 1);   op4volume = op4volumeorig + ((lfo2value * lfo2volume) >> 10); eqkiszamol2(); break;

        /*
          case 34: f0 = f0orig + (expgains128[lfo2value]>>1) ;   eqkiszamol(); break;
          case 35: f02 = f02orig + (expgains128[lfo2value]>>1);   eqkiszamol2(); break;
          case 36: f0 = f0orig + (expgains128[lfo2value]>>1);   eqkiszamol();   eqkiszamol(); f02 = f02orig +(expgains128[lfo2value]>>1);   eqkiszamol2(); break;
        */
    }
  }
}

//MIDI CONTROLLERS
//----------------------------------------------------------------------
//X-Novation Xstation 25 Controller
//----------------------------------------------------------------------
/*
  MIDI Command Novation X-Station 25
  B0-6C Attack Dec: 108
  B0-6D Decay Dec:109
  B0-6E Sustain Dec: 110
  B0-6F Release Dec: 111
  B0-72 Attack2  Dec: 114
  B0-73 Decay2   Dec: 115
  B0-74 Sustain2 Dec: 116
  B0-75 Release2 Dec: 117
  B0-70 Velocity Dec: 112
  B0-05 Portamento Dec: 05
  B0-28 Semitone Dec: 40
  B0-29 Detune Dec: 29
  B0-48 Level Dec: 72
  B0-2B LFO Depth Dec: 43
  B0-2c Env Depth Dec: 44
  B0-2D PWM Dec: 45
  B0-69 Frequency Dec: 105
  B0-6A Resonance Dec: 106
  B0-6b ENV Depth Dec: 107
  B0-xx Key track:  006
  B0-66 LFO Depth Dec: 102
  B0-68 Overdrive Dec: 104
  B0-50 Speed Dec: 80
  B0-52 Delay Amount LFO Dec: 82
  B0-09 Tempo Dec: 09
  B0-07 Effect Level Dec: 07
*/
void parameterchange2() {
  byte value = velocityByte;
  switch (noteByte) {
    case 0:
      switch (opmenuoldal) {
        case 1: op1generatorfreqfixp = value; op1generatorfreqfix = value << 15; break;
        case 2: op2generatorfreqfixp = value; op2generatorfreqfix = value << 15; break;
        case 3: op3generatorfreqfixp = value; op3generatorfreqfix = value << 15; break;
        case 4: op4generatorfreqfixp = value; op4generatorfreqfix = value << 15; break;
        case 5: op5generatorfreqfixp = value; op5generatorfreqfix = value << 15; break;
        case 6: op6generatorfreqfixp = value; op6generatorfreqfix = value << 15; break;
      }
      menuoldal = 15;
      menukiir();
      break;
    case 1:
      lfo2volume = value;
      if (lfo2delay < lfo2delaytime)
      {
        lfo2delay = lfo2delaytime;
      }

      break;
    case 5:
      switch (opmenuoldal) {
        case 1:
          op1volumeorig = value;
          op1volume = value;
          if (op1volumeorig == 0) {
            op1 = false;
          } else {
            op1 = true;
          } break;
        case 2:
          op2volumeorig = value;
          op2volume = value;
          if (op2volumeorig == 0) {
            op2 = false;
          } else {
            op2 = true;
          } break;
        case 3:
          op3volumeorig = value;
          op3volume = value;
          if (op3volumeorig == 0) {
            op3 = false;
          } else {
            op3 = true;
          } break;
        case 4:
          op4volumeorig = value;
          op4volume = value;
          if (op4volumeorig == 0) {
            op4 = false;
          } else {
            op4 = true;
          } break;
        case 5:
          op5volumeorig = value;
          op5volume = value;
          if (op5volumeorig == 0) {
            op5 = false;
          } else {
            op5 = true;
          } break;
        case 6:
          op6volumeorig = value;
          op6volume = value;
          if (op6volumeorig == 0) {
            op6 = false;
          } else {
            op6 = true;
          } break;
      }
      ops = String(op1) + String(op2) + String(op3) + String(op4) + String(op5) + String(op6);
      menuoldal = 11;
      menukiir();
      break;
    case 6:
      if (value < 17) {
        switch (opmenuoldal)
        {
          case 1: op1waveform = value; generatorinitone(op1waveform, generator1); break;
          case 2: op2waveform = value; generatorinitone(op2waveform, generator2); break;
          case 3: op3waveform = value; generatorinitone(op3waveform, generator3); break;
          case 4: op4waveform = value; generatorinitone(op4waveform, generator4); break;
          case 5: op5waveform = value; generatorinitone(op5waveform, generator5); break;
          case 6: op6waveform = value; generatorinitone(op6waveform, generator6); break;
        }
        menuoldal = 14;
      }
      else
      {
        if (value == 28)
        {
          switch (opmenuoldal)
          {
            case 1: op1notefixed = true; break;
            case 2: op2notefixed = true; break;
            case 3: op3notefixed = true; break;
            case 4: op4notefixed = true; break;
            case 5: op5notefixed = true; break;
            case 6: op6notefixed = true; break;
          }
          menuoldal = 13;
        }
        if (value == 29)
        {
          switch (opmenuoldal)
          {
            case 1: op1notefixed = false; break;
            case 2: op2notefixed = false; break;
            case 3: op3notefixed = false; break;
            case 4: op4notefixed = false; break;
            case 5: op5notefixed = false; break;
            case 6: op6notefixed = false; break;
          }
          menuoldal = 13;
        }
        if (value == 32)
        {
          switch (opmenuoldal)
          {
            case 1: op1pich = 0; break;
            case 2: op2pich = 0; break;
            case 3: op3pich = 0; break;
            case 4: op4pich = 0; break;
            case 5: op5pich = 0; break;
            case 6: op6pich = 0; break;
          }
          menuoldal = 23;
        }
        if (value == 33)
        {
          switch (opmenuoldal)
          {
            case 1: op1pich = 1;  break;
            case 2: op2pich = 1; break;
            case 3: op3pich = 1; break;
            case 4: op4pich = 1; break;
            case 5: op5pich = 1; break;
            case 6: op6pich = 1; break;
          }
          menuoldal = 23;

        }
        if (value == 34)
        {
          switch (opmenuoldal)
          {
            case 1: op1pich = 2; break;
            case 2: op2pich = 2; break;
            case 3: op3pich = 2; break;
            case 4: op4pich = 2; break;
            case 5: op5pich = 2; break;
            case 6: op6pich = 2; break;
          }
          menuoldal = 23;

        }






        //opmenuincrement
        if (value == 52)
        {
          if (opmenuoldal < 7)
          {
            opmenuoldal++;
          } else
          {
            opmenuoldal = 1;
          }
        }
        //opmenudecrement
        if (value == 53)
        {
          if (opmenuoldal > 1)
          {
            opmenuoldal--;
          } else
          {
            opmenuoldal = 7;
          }
        }
        //opmenuset
        if (value == 54)
        {
          opmenuoldal = 1;
        }
        if (value == 55)
        {
          opmenuoldal = 2;
        }
        if (value == 56)
        {
          opmenuoldal = 3;
        }
        if (value == 57)
        {
          opmenuoldal = 4;
        }
        if (value == 58)
        {
          opmenuoldal = 5;
        }
        if (value == 59)
        {
          opmenuoldal = 6;
        }
      }
      menukiir();
      break;
    case 7:
      switch (opmenuoldal) {
        case 1:  reverblevel = value + 1; break;
        case 2:  reverbdiffusion = value; break;
        case 3:  delaytime = value; break;
        case 4:  delay2time = value; break;
        case 5:  ; break;
        case 6:  ; break;
      }
      menuoldal = 33;
      menukiir();
      break;
    case  9:
      /*
        choruslevel = value;
        menuoldal = 34;
        menukiir();
      */
      break;
    case 25:
      break;
    case 35:
      //button rew
      break;
    case 36:
      //button forward
      break;
    case 37:
      //test parameters
      parameterstest();
      break;
    case 38:
  
     
      break;
    case 39:
      //button rec
      break;
    case 40:
      algorithm = value;
      alg = value  % 7;
      alg2 = value  / 7;
      menuoldal = 18;
      menukiir();
      break;
    case 41:
      chorusfreq = value;
      menuoldal = 35;
      menukiir();
      break;
    case 42:
      szorzo = value;
      hangokinit();
      menuoldal = 17;
      menukiir();
      break;
    case 43:
      choruslevel = value;
      //    chorusfreq =value;
      menuoldal = 34;
      menukiir();
      break;
    case 44:
      switch (opmenuoldal) {
        case 1:   break;
        case 2: op2generatorfreqorig = value; break;
        case 3: op3generatorfreqorig = value; break;
        case 4: op4generatorfreqorig = value; break;
        case 5: op5generatorfreqorig = value; break;
        case 6: op6generatorfreqorig = value; break;
      }
      menuoldal = 12;
      menukiir();
      break;
    case 45:
      oplevel = value / 2 + 1;
      menuoldal = 38;
      menukiir();
      break;
    case 46:
      switch (opmenuoldal) {
        case 1: limitgain = value;   break;
        case 2: limitgain2 = value;   break;

      }
      menuoldal = 42;
      menukiir();
      break;
    case 47:
      //menupage
      menuoldal = value;
      menukiir();
      break;
    case 48:
      released = value >> 4;
      menuoldal = 45;
      menukiir();
      break;
    case 49:
      ofset = value << 10;
      menuoldal = 44;
      menukiir();
      break;
    case 50:
      if (value > 0) {
        if (menuoldal < 51) {

          menuoldal++;
        } else {
          menuoldal = 0;
        }
        menukiir();
      }
      break;
    case 51:
      if (value > 0) {
        if (menuoldal > 0) {

          menuoldal--;
        } else {
          menuoldal = 51;
        }
        menukiir();
      }
      break;
    case 52:
      if (value > 0) {
        inc = true;
        menukiir();
      }
      break;
    case 53:
      if (value > 0) {
        dec = true;
        menukiir();
      }
      break;

    case 72:
      level = value;
      menuoldal = 19;
      menukiir();
      break;
    case 80:
      feedbacklevel = value;
      menuoldal = 16;
      menukiir();
      break;
    case 82:
      switch (opmenuoldal) {
        case 1:  op1lep = value / 8 + 13; break;
        case 2:  op2lep = value / 8 + 13; break;
        case 3:  op3lep = value / 8 + 13; break;
        case 4:  op4lep = value / 8 + 13; break;
        case 5:  op5lep = value / 8 + 13; break;
        case 6:  op6lep = value / 8 + 13; break;
      }
      menuoldal = 41;
      menukiir();
      break;
    case 94:
      switch (opmenuoldal) {
        case 1: pareqfreq0 = value;  f0orig = expgains128[pareqfreq0] >> 1 + 1; break;
        case 2: pareqfreq1 = value;  f02orig = expgains128[pareqfreq1] >> 1 + 1; break;
        case 3:   break;
        case 4:    break;
        case 5:  break;
        case 6:   break;
      }
      menuoldal = 29;
      menukiir();

      break;
    case 95:
      switch (opmenuoldal) {
        case 1:  Q = value / 25.0; break;
        case 2:  Q2 = value / 25.0; break;
        case 3:   break;
        case 4:   break;
        case 5:   break;
        case 6:   break;
      }
      menuoldal = 28;
      menukiir();
      break;

    case 96:

      break;
    case 97:
      lfo2delaytime = value;
      menuoldal = 27;
      menukiir();
      break;
    case 98:
      c = 4000 + value * 30;
      menuoldal = 51;
      menukiir();
      hangokinit();
      break;

    case 99:
      switch (opmenuoldal) {
        case 1:  if (value == 0) {
            parametereqlefton = false;
          } else {
            parametereqlefton = true;
          } break;
        case 2:  if (value == 0) {
            delaylowpasseqlefton = false;
          } else {
            delaylowpasseqlefton = true;
          } break;
        case 3:  if (value == 0) {
            highpasslefteqon = false;
          } else {
            highpasslefteqon = true;
          } break;
        case 4:  if (value == 0) {
            limiterlefton = false;
          } else {
            limiterlefton = true;
          } break;
        case 5:   break;
        case 6:   break;
      }
      menuoldal = 30;
      menukiir();
      break;

    case 100:
      switch (opmenuoldal) {
        case 1:  if (value == 0) {
            parametereqrighton = false;
          } else {
            parametereqrighton = true;
          } break;
        case 2:  if (value == 0) {
            delaylowpasseqrighton = false;
          } else {
            delaylowpasseqrighton = true;
          } break;
        case 3:  if (value == 0) {
            highpassrighteqon = false;
          } else {
            highpassrighteqon = true;
          } break;
        case 4:  if (value == 0) {
            limiterrighton = false;
          } else {
            limiterrighton = true;
          } break;
        case 5:   break;
        case 6:   break;
      }
      menuoldal = 31;
      menukiir();
      break;

    case 101:
      frame = value;
      menuoldal = 20;
      menukiir();
      break;
    case 102:
      modulation = value;
      menuoldal = 40;
      menukiir();
      break;
    case 103:
      pichkezd = value;
      menuoldal = 36;
      menukiir();
      break;
    case 104:
      lfo2freq = value;
      menuoldal = 37;
      menukiir();
      break;
    case 105:
      eqvalue = value * 96;
      menuoldal = 32;
      freq1 = (eqvalue / 123) * 100;
      freq2 = (127 - eqvalue / 99) * 100;
      menukiir();
      break;
    case 106:
      picheglevel = value << 10;
      menuoldal = 21;
      menukiir();
      break;
    case 107:
      if (value >= 0)
      {
        lfo2volume = value;
      }
      menuoldal = 39;
      menukiir();
      break;
    case 108:
      switch (opmenuoldal) {
        case 1: op1al = value; break;
        case 2: op2al = value; break;
        case 3: op3al = value; break;
        case 4: op4al = value; break;
        case 5: op5al = value; break;
        case 6: op6al = value; break;
        case 7: pichal = value; break;
      }
      menuoldal = 3;
      opgorbeinittry();
      menukiir();
      break;
    case 109:
      switch (opmenuoldal) {
        case 1: op1d1l = value;  break;
        case 2: op2d1l = value; break;
        case 3: op3d1l = value;  break;
        case 4: op4d1l = value;  break;
        case 5: op5d1l = value;  break;
        case 6: op6d1l = value; break;
        case 7: pichd1l = value; break;
      }
      menuoldal = 4;
      opgorbeinittry();
      menukiir();
      break;
    case 110:
      switch (opmenuoldal) {
        case 1: op1d2l = value; break;
        case 2: op2d2l = value; break;
        case 3: op3d2l = value; break;
        case 4: op4d2l = value; break;
        case 5: op5d2l = value; break;
        case 6: op6d2l = value; break;
        case 7: pichd2l = value; break;
      }
      menuoldal = 6;
      opgorbeinittry();
      menukiir();
      break;
    case 111:
      switch (opmenuoldal) {
        case 1: op1rl = value; break;
        case 2: op2rl = value; break;
        case 3: op3rl = value; break;
        case 4: op4rl = value; break;
        case 5: op5rl = value; break;
        case 6: op6rl = value; break;
        case 7: pichrl = value; break;
      }
      menuoldal = 8;
      opgorbeinittry();
      menukiir();
      break;
    case 112:
      switch (opmenuoldal) {
        case 1: op1veloc = value >> 2 + 1; menuoldal = 10; break;
        case 2: op2veloc = value >> 2 + 1; menuoldal = 10; break;
        case 3: op3veloc = value >> 2 + 1; menuoldal = 10; break;
        case 4: op4veloc = value >> 2 + 1; menuoldal = 10; break;
        case 5: op5veloc = value >> 2 + 1; menuoldal = 10; break;
        case 6: op6veloc = value >> 2 + 1; menuoldal = 10; break;
        case 7: pichkezd = value;  menuoldal = 20; break;
      }
      menukiir();
      break;
    case 113:
      switch (opmenuoldal) {
        case 1: op1detunep = value; op1detune = value << 12; break;
        case 2: op2detunep = value; op2detune = value << 12;  break;
        case 3: op3detunep = value; op3detune = value << 12; break;
        case 4: op4detunep = value; op4detune = value << 12;  break;
        case 5: op5detunep = value; op5detune = value << 12;  break;
        case 6: op6detunep = value; op6detune = value << 12;  break;
      }
      menuoldal = 22; //!!!!
      menukiir();
      break;
    case 114:
      switch (opmenuoldal) {
        case 1: op1ar = value; break;
        case 2: op2ar = value; break;
        case 3: op3ar = value; break;
        case 4: op4ar = value; break;
        case 5: op5ar = value; break;
        case 6: op6ar = value; break;
        case 7: pichar = value; break;
      }
      menuoldal = 2;
      opgorbeinittry();
      menukiir();
      break;
    case 115:

      switch (opmenuoldal) {
        case 1: op1d1r = value; break;
        case 2: op2d1r = value; break;
        case 3: op3d1r = value; break;
        case 4: op4d1r = value; break;
        case 5: op5d1r = value; break;
        case 6: op6d1r = value; break;
        case 7: pichd1r = value; break;

      }
      menuoldal = 5;
      opgorbeinittry();
      menukiir();
      break;
    case 116:
      switch (opmenuoldal) {
        case 1: op1d2r = value; break;
        case 2: op2d2r = value; break;
        case 3: op3d2r = value; break;
        case 4: op4d2r = value; break;
        case 5: op5d2r = value; break;
        case 6: op6d2r = value; break;
        case 7: pichd2r = value; break;
      }
      menuoldal = 7;
      opgorbeinittry();
      menukiir();
      break;
    case 117:
      switch (opmenuoldal) {
        case 1: op1rr = value; break;
        case 2: op2rr = value; break;
        case 3: op3rr = value; break;
        case 4: op4rr = value; break;
        case 5: op5rr = value; break;
        case 6: op6rr = value; break;
        case 7: pichrr = value; break;
      }
      menuoldal = 9;
      opgorbeinittry();
      menukiir();
      break;
    case 126:
      if (value == 1) {
        sendparameter();
      }
      break;
    case 127: break;

  }
}

void opgorbeinittry() {
  //preroll
  if (ido - elozoinit > 5000) {

    switch (opmenuoldal) {
      case 1: op1gorbeinit(); break;
      case 2: op2gorbeinit(); break;
      case 3: op3gorbeinit(); break;
      case 4: op4gorbeinit(); break;
      case 5: op5gorbeinit(); break;
      case 6: op6gorbeinit(); break;
      case 7: pichgorbeinit(); break;
    }

    maxreleaseset();

    // openvelopetest(op1gorbe, "op1");
    elozoinit = ido;

  }
}

//MIDICLOCK
void sendmidiclock() {
  Serial2.write(0xF8);
}

//SENDPARAMETER (not function)
void sendparameter() {
  // lcdkiir("mukodj!", "JEE!");
}

//MIDI PROGRAM CHANGED
void programchange(byte program) {
  // Audio.end();
  if (program < 11) {
    switch (program) {
      case 0:
        program0();
        break;
      case 1:
        Serial.println("User Prog1") ;
        load(1);
        break;
      case 2:
        Serial.println("User Prog2") ;
        load(2);
        break;
      case 3:
        Serial.println("User Prog3") ;
        load(3);
        break;
      case 4:
        Serial.println("User Prog4") ;
        load(4);
        break;
      case 5:
        Serial.println("User Prog5") ;
        load(5);
        break;
      case 6:
        Serial.println("User Prog6") ;
        load(6);
        break;
      case 7:
        Serial.println("User Prog7") ;
        load(7);
        break;
      case 8:
        Serial.println("User Prog8") ;
        load(8);
        break;
      case 9:
        Serial.println("User Prog9") ;
        load(9);
        break;
      case 10:
        Serial.println("User Prog10") ;
        load(10);
        break;
    }
    /*
      opgorbeinittry();
      maxreleaseset();
      menukiir();
    */
  } else {
    if (program <= 16) {
      load(program);
    }


  }
}
