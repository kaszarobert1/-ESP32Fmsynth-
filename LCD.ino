//------------------------LCD------------------------------------
//JUST LCD CONTROLS, NOTHING IMPORTANT
//DO NOT USE PARAMETER SETTING FUNCTIONS HERE!
/*----------------
  1  P7:Sine Wave
     Algorithm:005
     ----------------
  2  ALG05 111111 OP1
     AL = 255
     ----------------
  3  ALG05 111111 OP1
     AR = 255
     ----------------
  4  ALG05 111111 OP1
     D1L = 255
     ----------------
  5  ALG05 111111 OP1
     D1R = 255
     ----------------
  6  ALG05 111111 OP1
     D2L = 255
     ----------------
  7  ALG05 111111 OP1
     D2R = 255
     ----------------
  8  ALG05 111111 OP1
     RL = 255
     ----------------
  9  ALG05 111111 OP1
     RR = 255
     ----------------
  10 ALG05 111111 OP1
     OPVELOCITY = 255
     ----------------
  11 ALG05 111111 OP1
     OPVOLUME = 255
     ----------------
  12 ALG05 111111 OP1
     FREQ = 255
     ----------------
  13 ALG05 111111 OP1
     OPREQ = NOTFIXED
     ----------------
  14 ALG05 111111 OP1
       SINE LOW
     ----------------
  15 ALG05 111111 OP1
     FREQFIX =1343488
     ----------------
  16 FEEDBACK LEVEL
     007
     ----------------
  17 FREQ DIV
     018
     ----------------
  18 03    F[[1]-(2)]
      [3]-(4) [5]-(6)
     ----------------
  19 OUTPUT LEVEL
     013
  20 ----------------
     EG SPEED
     008
  21 ----------------
     PICHEG LEVEL
     001
  22 ----------------
    ALG05 111111 OP1
    OPDETUNE = 1234
  23-----------------
    ALG05 111111 OP1
    PICHOP = DETUNE
  24----------------
    ALG05 111111 OP1
    OPDETUNE = 1234
  25----------------
    ALG05 111111 OP1
    -
  26----------------
    ALG05 111111 OP1
    -
  27----------------
    ALG05 111111 OP1
    -
  28----------------
    ALG05 111111 OP1
    -
  29----------------
    ALG05 111111 OP1
    -
  30----------------
    ALG05 111111 OP1
    -
  31----------------
    ALG05 111111 OP1
    -
  32----------------
    REVERB DIFFUSION
    122
  33----------------
    REVERB LEVEL
    24
  34----------------
    CHORUS LEVEL
    24
  35----------------
    CHORUS FREQ
    24
*/
//LCD PARAMETERS
String savestring = "NO";
byte saveprog = 0;
byte menu = 1;
byte oldal = 0;
byte menupos = 0;
const byte lcdsizex = 16;
const byte lcdsizey = 2;
const byte lcdcaractersize = (lcdsizex * lcdsizey) - 1;
char lcdarray [lcdsizey][lcdsizex];
bool lcdchanged[lcdsizey][lcdsizex];
byte lcdmutato = 0;
bool lcdposemode = true;
bool valtozas = false;
String wavestring = "";
String lcdfirstline = "________________";
String lcdsecondline = "________________";

//INIT LCD BUFFER ARRAY
void lcdarrayinit() {
  for (byte i = 0; i < lcdsizex; i++) {
    for (byte j = 0; j < lcdsizey; j++) {
      lcdarray[j][i] = ' ';
      lcdchanged[j][i] = false;
    }
  }
  byte lcdmutato = 0;
  bool lcdposemode = true;
}

//JUST DIFERENT WRITE LCD
void lcdrefreesh() {
  byte fi = lcdmutato / lcdsizex;
  byte si = lcdmutato % lcdsizex;
  if (lcdchanged[fi][si]) {
    if (lcdposemode) {
      lcd.setCursor(si, fi);
      lcdposemode = false;
    } else {
      lcd.print(lcdarray[fi][si]);
      lcdposemode = true;
      lcdchanged[fi][si] = false;
    }
  }
  if (lcdposemode) {
    if (lcdmutato < lcdcaractersize) {
      lcdmutato++;
    } else {
      lcdmutato = 0;
    }
  }
}

//WRITE LCDBUFFER ARRAY ONE ROW
void lcdkiirtomb(String szoveg, byte sor, byte oszlop) {
  if (sor < lcdsizey) {
    for (byte i = 0; i < szoveg.length(); i++) {
      if (oszlop + i < lcdsizex) {
        if (lcdarray [sor][oszlop + i] != szoveg[i]) {
          lcdarray [sor][oszlop + i] = szoveg[i];
          lcdchanged[sor][oszlop + i] = true;
        }
      }
    }
  }
}

//WRITE LCD FULL
void lcdkiir (String szoveg, String szoveg2) {
  lcdkiirtomb(szoveg, 0, 0);
  lcdkiirtomb(szoveg2, 1, 0);
  lcdmutato = 0;
  lcdposemode = true;
}

//LCD MENU
void menukiir() {
  uint16_t voltx = 5;
  switch (menuoldal) {
    case 1:
      //MAIN MENU-------------------------------
      lcdkiir (pachname, "Algorithm: " + String(lcdprint3(algorithm)) + "  ");
      //lcdkiir("PCH: 1   >  2     ", "     " + lcdprint3( eltelttime) + "  " +lcdprint3( eltelttime2) + "    ");
      break;
    case 2:
      //OPAR MENU-------------------------------
      byte *opar;

      switch (opmenuoldal) {
        case 1: opar = &op1ar; break;
        case 2: opar = &op2ar; break;
        case 3: opar = &op3ar; break;
        case 4: opar = &op4ar; break;
        case 5: opar = &op5ar; break;
        case 6: opar = &op6ar; break;
        case 7: opar = &pichar; break;
      }

      if (inc) {
        if (*opar < 127) {
          *opar = *opar + 1;
          voltx = 1;
        } else {
          *opar = 0;
          voltx = 3;
        }
        inc = false;
      }
      if (dec) {
        if (*opar > 0) {
          *opar = *opar - 1;
          voltx = 2;
        } else {
          *opar = 127;
          voltx = 4;
        }
        dec = false;
      }
      if (opmenuoldal < 7) {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP" + String(opmenuoldal), "AR = " + lcdprint3(*opar) + "        ");
      } else {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " PCH", "PICHAR = " + lcdprint3(pichar) + "        ");
      }
      opgorbeinittry();
      break;
    case 3:
      //OPAL MENU-------------------------------
      byte* opal;
      switch (opmenuoldal) {
        case 1: opal = &op1al; break;
        case 2: opal = &op2al; break;
        case 3: opal = &op3al; break;
        case 4: opal = &op4al; break;
        case 5: opal = &op5al; break;
        case 6: opal = &op6al; break;
        case 7: opal = &pichal; break;
      }
      if (inc) {
        if (*opal < 127) {
          *opal += 1;
        } else {
          *opal = 0;
        }
        inc = false;
      }
      if (dec) {
        if (*opal > 0) {
          *opal -= 1;
        } else {
          *opal = 127;
        }
        dec = false;
      }
      if (opmenuoldal < 7) {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP" + String(opmenuoldal), "AL = " + lcdprint3(*opal) + "        ");
      } else {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " PCH", "PICHAL = " + lcdprint3(pichal) + "        ");
      }
      opgorbeinittry();
      break;
    case 4:
      //OPD1L MENU-------------------------------
      byte* opd1l;
      switch (opmenuoldal) {
        case 1: opd1l = &op1d1l; break;
        case 2: opd1l = &op2d1l; break;
        case 3: opd1l = &op3d1l; break;
        case 4: opd1l = &op4d1l; break;
        case 5: opd1l = &op5d1l; break;
        case 6: opd1l = &op6d1l; break;
        case 7: opd1l = &pichd1l; break;
      }
      if (inc) {
        if (*opd1l < 127) {
          *opd1l += 1;
        } else {
          *opd1l = 0;
        }
        inc = false;
      }
      if (dec) {
        if (*opd1l > 0) {
          *opd1l -= 1;
        } else {
          *opd1l = 127;
        }
        dec = false;
      }
      if (opmenuoldal < 7) {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP" + String(opmenuoldal), "D1L = " + lcdprint3(*opd1l) + "       ");
      } else {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " PCH", "PICHD1L = " + lcdprint3(pichd1l) + "       ");
      }
      opgorbeinittry();
      break;
    case 5:
      //OPD1R MENU-------------------------------
      byte* opd1r;
      switch (opmenuoldal) {
        case 1: opd1r = &op1d1r; break;
        case 2: opd1r = &op2d1r; break;
        case 3: opd1r = &op3d1r; break;
        case 4: opd1r = &op4d1r; break;
        case 5: opd1r = &op5d1r; break;
        case 6: opd1r = &op6d1r; break;
        case 7: opd1r = &pichd1r; break;
      }
      if (inc) {
        if (*opd1r < 127) {
          *opd1r += 1;
        } else {
          *opd1r = 0;
        }
        inc = false;
      }
      if (dec) {
        if (*opd1r > 0) {
          *opd1r -= 1;
        } else {
          *opd1r = 127;
        }
        dec = false;
      }
      if (opmenuoldal < 7) {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP" + String(opmenuoldal), "D1R = " + lcdprint3(*opd1r) + "       ");
      } else {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " PCH", "PICHD1R = " + lcdprint3(pichd1r) + "       ");
      }
      opgorbeinittry();
      break;
    case 6:
      //OPD2L MENU-------------------------------
      byte* opd2l;
      switch (opmenuoldal) {
        case 1: opd2l = &op1d2l; break;
        case 2: opd2l = &op2d2l; break;
        case 3: opd2l = &op3d2l; break;
        case 4: opd2l = &op4d2l; break;
        case 5: opd2l = &op5d2l; break;
        case 6: opd2l = &op6d2l; break;
        case 7: opd2l = &pichd2l; break;
      }
      if (inc) {
        if (*opd2l < 127) {
          *opd2l += 1;
        } else {
          *opd2l = 0;
        }
        inc = false;
      }
      if (dec) {
        if (*opd2l > 0) {
          *opd2l -= 1;
        } else {
          *opd2l = 127;
        }
        dec = false;
      }
      if (opmenuoldal < 7) {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP" + String(opmenuoldal), "D2L = " + lcdprint3(*opd2l) + "       ");
      } else {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " PCH", "PICHD2L = " + lcdprint3(pichd2l) + "       ");
      }
      opgorbeinittry();
      break;
    case 7:
      //OPD2R MENU-------------------------------
      byte* opd2r;
      switch (opmenuoldal) {
        case 1: opd2r = &op1d2r; break;
        case 2: opd2r = &op2d2r; break;
        case 3: opd2r = &op3d2r; break;
        case 4: opd2r = &op4d2r; break;
        case 5: opd2r = &op5d2r; break;
        case 6: opd2r = &op6d2r; break;
        case 7: opd2r = &pichd2r; break;

      }
      if (inc) {
        if (*opd2r < 127) {
          *opd2r += 1;
        } else {
          *opd2r = 0;
        }
        inc = false;
      }
      if (dec) {
        if (*opd2r > 0) {
          *opd2r -= 1;
        } else {
          *opd2r = 127;
        }
        dec = false;
      }
      if (opmenuoldal < 7) {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP" + String(opmenuoldal), "D2R = " + lcdprint3(*opd2r) + "       ");
      } else {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " PCH", "PICHD1R = " + lcdprint3(pichd2r) + "       ");
      }
      opgorbeinittry();
      break;
    case 8:
      //OPRL MENU-------------------------------
      byte* oprl;
      switch (opmenuoldal) {
        case 1: oprl = &op1rl; break;
        case 2: oprl = &op2rl; break;
        case 3: oprl = &op3rl; break;
        case 4: oprl = &op4rl; break;
        case 5: oprl = &op5rl; break;
        case 6: oprl = &op6rl; break;
        case 7: oprl = &pichrl; break;
      }
      if (inc) {
        if (*oprl < 127) {
          *oprl += 1;
        } else {
          *oprl = 0;
        }
        inc = false;
      }
      if (dec) {
        if (*oprl > 0) {
          *oprl -= 1;
        } else {
          *oprl = 127;
        }
        dec = false;
      }
      if (opmenuoldal < 7) {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP" + String(opmenuoldal), "RL = " + lcdprint3(*oprl) + "        ");
      } else {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " PCH", "PICHRL = " + lcdprint3(pichrl) + "        ");
      }
      opgorbeinittry();
      break;
    case 9:
      //OPRR MENU-------------------------------
      byte* oprr;
      switch (opmenuoldal) {
        case 1: oprr = &op1rr; break;
        case 2: oprr = &op2rr; break;
        case 3: oprr = &op3rr; break;
        case 4: oprr = &op4rr; break;
        case 5: oprr = &op5rr; break;
        case 6: oprr = &op6rr; break;
        case 7: oprr = &pichrr; break;
      }
      if (inc) {
        if (*oprr < 127) {
          *oprr += 1;
        } else {
          *oprr = 0;
        }
        inc = false;
      }
      if (dec) {
        if (*oprr > 0) {
          *oprr -= 1;
        } else {
          *oprr = 127;
        }
        dec = false;
      }
      if (opmenuoldal < 7) {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP" + String(opmenuoldal), "RR = " + lcdprint3(*oprr) + "        ");
      } else {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " PCH", "PICHRR = " + lcdprint3(pichrr) + "        ");
      }
      opgorbeinittry();
      break;
    case 10:
      //VELOCITY MENU-------------------------------
      uint16_t* opveloc;
      switch (opmenuoldal) {
        case 1: opveloc = &op1veloc; break;
        case 2: opveloc = &op2veloc; break;
        case 3: opveloc = &op3veloc; break;
        case 4: opveloc = &op4veloc; break;
        case 5: opveloc = &op5veloc; break;
        case 6: opveloc = &op6veloc; break;
        case 7: break;
      }
      if (inc) {
        if (*opveloc < 128) {
          *opveloc += 1;
        } else {
          *opveloc = 0;
        }
        inc = false;
      }
      if (dec) {
        if (*opveloc > 0) {
          *opveloc -= 1;
        } else {
          *opveloc = 128;
        }
        dec = false;
      }
      if (opmenuoldal < 7) {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP" + String(opmenuoldal), "OPVELOCITY = " + lcdprint3(*opveloc) + "");
      } else {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " PCH", "VELOCITY = " + lcdprint3(*opveloc) + "  ");
        //pichgorbeinit();
      }
      opgorbeinittry();
      break;
    case 11:
      //OPVOLUME MENU-------------------------------
      byte* opvolumeorig;
      switch (opmenuoldal) {
        case 1: opvolumeorig = &op1volumeorig; break;
        case 2: opvolumeorig = &op2volumeorig; break;
        case 3: opvolumeorig = &op3volumeorig; break;
        case 4: opvolumeorig = &op4volumeorig; break;
        case 5: opvolumeorig = &op5volumeorig; break;
        case 6: opvolumeorig = &op6volumeorig; break;
        case 7:  break;
      }
      if (inc) {
        if (*opvolumeorig < 127) {
          *opvolumeorig += 1;
        } else {
          *opvolumeorig = 0;
        }
        inc = false;
      }
      if (dec) {
        if (*opvolumeorig > 0) {
          *opvolumeorig -= 1;
        } else {
          *opvolumeorig = 127;
        }
        dec = false;
      }
      if (opmenuoldal < 7) {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP" + String(opmenuoldal), "OPVOLUME = " + lcdprint3(*opvolumeorig) + "  ");
      } else {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " PCH", "PCHVOLUME = " + lcdprint3(picheglevel) + " ");
        //pichgorbeinit();
      }
      break;
    case 12:
      //OPGENERATOR FREQ MENU-------------------------------
      byte* opgeneratorfreqorig;
      switch (opmenuoldal) {
        case 1: opgeneratorfreqorig = &op1generatorfreqorig; break;
        case 2: opgeneratorfreqorig = &op2generatorfreqorig; break;
        case 3: opgeneratorfreqorig = &op3generatorfreqorig; break;
        case 4: opgeneratorfreqorig = &op4generatorfreqorig; break;
        case 5: opgeneratorfreqorig = &op5generatorfreqorig; break;
        case 6: opgeneratorfreqorig = &op6generatorfreqorig; break;
        case 7:  break;
      }
      if (inc) {
        if (*opgeneratorfreqorig < 127) {
          *opgeneratorfreqorig += 1;
        } else {
          *opgeneratorfreqorig = 0;
        }
        inc = false;
      }
      if (dec) {
        if (*opgeneratorfreqorig > 0) {
          *opgeneratorfreqorig -= 1;
        } else {
          *opgeneratorfreqorig = 127;
        }
        dec = false;
      }
      if (opmenuoldal < 7) {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP" + String(opmenuoldal), "FREQ = " + lcdprint3(*opgeneratorfreqorig) + "      ");
      } else {
      }
      op1generatorfreq = op1generatorfreqorig;
      op2generatorfreq = op2generatorfreqorig;
      op3generatorfreq = op3generatorfreqorig;
      op4generatorfreq = op4generatorfreqorig;
      op5generatorfreq = op5generatorfreqorig;
      op6generatorfreq = op1generatorfreqorig;

      break;
    case 13:

      //OPGENERATOR FREQ MENU-------------------------------
      bool* notefixedop;
      switch (opmenuoldal) {
        case 1: notefixedop = &op1notefixed; break;
        case 2: notefixedop = &op2notefixed; break;
        case 3: notefixedop = &op3notefixed; break;
        case 4: notefixedop = &op4notefixed; break;
        case 5: notefixedop = &op5notefixed; break;
        case 6: notefixedop = &op6notefixed; break;
        case 7:  break;
      }
      if (inc) {
        if (*notefixedop) {
          *notefixedop = false;
        } else {
          *notefixedop = true;
        }
        inc = false;
      }
      if (dec) {
        if (*notefixedop) {
          *notefixedop = true;
        } else {
          *notefixedop = false;
        }
        dec = false;
      }
      if (opmenuoldal < 7) {

        if (*notefixedop)
        {
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP" + String(opmenuoldal), "OPREQ = NOTFIXED");
        } else
        {
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP" + String(opmenuoldal), "OPREQ = FIXED   ");
        }
      }
      break;
    case 14:
      //OP WAVE MENU---------------------------------------------------------------------------------------------------------------
      byte* opwaveform;
      switch (opmenuoldal) {
        case 1: opwaveform = &op1waveform; break;
        case 2: opwaveform = &op2waveform; break;
        case 3: opwaveform = &op3waveform; break;
        case 4: opwaveform = &op4waveform; break;
        case 5: opwaveform = &op5waveform; break;
        case 6: opwaveform = &op6waveform; break;
      }
      if (inc) {
        if (*opwaveform < 18) {
          *opwaveform += 1;
        } else {
          *opwaveform = 0;
        }
        inc = false;
      }
      if (dec) {
        if (*opwaveform > 0) {
          *opwaveform -= 1;
        } else {
          *opwaveform = 18;
        }
        dec = false;
      }
      switch (*opwaveform)
      {
        case 0: wavestring = "NONE        "; break;
        case 1: wavestring = "SINE HIGH   "; break;
        case 2: wavestring = "SINE LOW    "; break;
        case 3: wavestring = "TRIA HIGH   "; break;
        case 4: wavestring = "TRIA LOW    "; break;
        case 5: wavestring = "SAWHT HIGH  "; break;
        case 6: wavestring = "SAWHT LOW   "; break;
        case 7: wavestring = "SQUARE HIGH "; break;
        case 8: wavestring = "SQUARE LOW  "; break;
        case 9: wavestring = "NOISE 1     "; break;
        case 10: wavestring = "USER WAVE 1 "; break;
        case 11: wavestring = "USER WAVE 2 "; break;
        case 12: wavestring = "USER WAVE 3 "; break;
        case 13: wavestring = "USER WAVE 4 "; break;
        case 14: wavestring = "DOUBLE SINE "; break;
        case 15: wavestring = "TRIPLE SINE "; break;
        case 16: wavestring = "COMPLEX 1   "; break;
        case 17: wavestring = "COMPLEX 2   "; break;
        case 18: wavestring = "COMPLEX 3   "; break;
      }
      switch (opmenuoldal) {
        case 1: lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP1", "    " + wavestring);
          generatorinitone(op1waveform, generator1);
          break;
        case 2: lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP2", "    " + wavestring);
          generatorinitone(op2waveform, generator2);
          break;
        case 3: lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP3", "    " + wavestring);
          generatorinitone(op3waveform, generator3);
          break;
        case 4: lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP4", "    " + wavestring);
          generatorinitone(op4waveform, generator4);
          break;
        case 5: lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP5", "    " + wavestring);
          generatorinitone(op5waveform, generator5);
          break;
        case 6: lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP6", "    " + wavestring);
          generatorinitone(op6waveform, generator6);
          break;
      }

      break;
    case 15:

      //OP GENERATOR FREQ FIX MENU---------------------------------------------------------------------------------------------------------------
      uint32_t* opgeneratorfreqfix;
      switch (opmenuoldal) {
        case 1: opgeneratorfreqfix = &op1generatorfreqfix; break;
        case 2: opgeneratorfreqfix = &op2generatorfreqfix; break;
        case 3: opgeneratorfreqfix = &op3generatorfreqfix; break;
        case 4: opgeneratorfreqfix = &op4generatorfreqfix; break;
        case 5: opgeneratorfreqfix = &op5generatorfreqfix; break;
        case 6: opgeneratorfreqfix = &op6generatorfreqfix; break;
      }
      if (inc) {
        if (*opgeneratorfreqfix < 127) {
          *opgeneratorfreqfix += 1;
        } else {
          *opgeneratorfreqfix = 0;
        }
        inc = false;
      }
      if (dec) {
        if (*opgeneratorfreqfix > 0) {
          *opgeneratorfreqfix -= 1;
        } else {
          *opgeneratorfreqfix = 127;
        }
        dec = false;
      }
      if (opmenuoldal < 7)
      {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP" + String(opmenuoldal), "FREQFIX =" + lcdprint7(*opgeneratorfreqfix) + "");
      }
      break;

    case 16:
      //FEEDBACK MENU------------------
      if (inc) {
        if (feedbacklevel < 127) {
          feedbacklevel += 1;
        } else {
          feedbacklevel = 0;
        }
        inc = false;
      }
      if (dec) {
        if (feedbacklevel >= 0) {
          feedbacklevel -= 1;
        } else {
          feedbacklevel = 127;
        }
        dec = false;
      }
      lcdkiir("FEEDBACK LEVEL  ", lcdprint3(feedbacklevel) + "             ");
      break;

    case 17:
      //FREQ DIV MENU------------------
      if (inc) {
        if (szorzo < 127) {
          szorzo += 1;
        } else {
          szorzo = 1;
        }
        inc = false;
      }
      if (dec) {
        if (szorzo > 0) {
          szorzo -= 1;
        } else {
          szorzo = 127;
        }
        dec = false;
      }
      lcdkiir("FREQ DIV        ", lcdprint3(szorzo) + "             ");
      hangokinit();
      break;


    case 18:
      //ALGORITHM MENU------------------
      if (inc) {
        if (alg < 6) {
          alg += 1;
        } else {
          alg = 0;
        }
        inc = false;
      }
      if (dec) {
        if (alg > 0) {
          alg -= 1;
        } else {
          alg = 6;
        }
        dec = false;
      }
      switch (alg) {
        case 0:
          lcdfirstline = "                ";
          break;
        case 1:
          lcdfirstline = "[1]-(2)-(3)-(4) ";
          break;
        case 2:
          lcdfirstline = "[1]-(2)f [3]-(4)";
          break;
        case 3:
          lcdfirstline = "[1]-(2)-(3)     ";
          break;
        case 4:
          lcdfirstline = "[1]<(2 3)       ";
          break;
        case 5:
          lcdfirstline = "[1]-(2)-(3)f    ";
          break;
        case 6:
          lcdfirstline = "[1]f [2] [3]    ";
          break;
      }
      switch (alg2) {
        case 0:
          lcdfirstline = "                ";
          break;
        case 1:
          lcdsecondline = "[5]-(6)         ";
          break;
        case 2:
          lcdsecondline = "[5]-(DIST6)        ";
          break;
        case 3:
          lcdsecondline = "[1]-(2-3-4-5-6) ";
          break;
        case 4:
          lcdsecondline = "[4]<(5 6)       ";
          break;
        case 5:
          lcdsecondline = "[4]-(5)-(6)    ";
          break;
        case 6:
          lcdsecondline = "[4] [5]-[6]    ";
          break;
      }


      lcdkiir(lcdfirstline, lcdsecondline);


      break;
    case 19:
      //GLOBAL LEVEL MENU------------------
      if (inc) {
        if (level < 127) {
          level++;
        } else {
          level = 1;
        }
        inc = false;
      }
      if (dec) {
        if (level > 0) {
          level--;
        } else {
          level = 127;
        }
        dec = false;
      }
      lcdkiir("OUTPUT LEVEL", lcdprint3(level) + "             ");
      break;
    case 20:
      //GLOBAL EGSPEED MENU------------------
      if (inc) {
        if (frame < 127) {
          frame++;
        } else {
          frame = 1;
        }
        inc = false;
      }
      if (dec) {
        if (frame > 0) {
          frame--;
        } else {
          frame = 127;
        }
        dec = false;
      }
      lcdkiir("EG SPEED        ", lcdprint3(frame) + "             ");

      break;
    case 21:
      //GLOBAL PICHEG LEVEL MENU------------------
      if (inc) {
        if (picheglevel < 127 * 8192) {
          picheglevel += 8192;
        } else {
          picheglevel = 0;
        }
        inc = false;
      }
      if (dec) {
        if (picheglevel > 8191) {
          picheglevel -= 8192;
        } else {
          picheglevel = 127 * 8192;
        }
        dec = false;
      }
      lcdkiir("PICHEG LEVEL    ", lcdprint3(picheglevel) + "             ");

      pichgorbeinit();
      break;
    case 22:
      //OPDETUNE MENU-------------------------------
      int32_t* opdetune;
      switch (opmenuoldal) {
        case 1: opdetune = &op1detune; break;
        case 2: opdetune = &op2detune; break;
        case 3: opdetune = &op3detune; break;
        case 4: opdetune = &op4detune; break;
        case 5: opdetune = &op5detune; break;
        case 6: opdetune = &op6detune; break;
        case 7: break;
      }
      if (inc) {
        if (*opdetune < 127) {
          *opdetune += 1;
        } else {
          *opdetune = 0;
        }
        inc = false;
      }
      if (dec) {
        if (*opdetune > 0) {
          *opdetune -= 1;
        } else {
          *opdetune = 127;
        }
        dec = false;
      }
      if (opmenuoldal < 7) {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP" + String(opmenuoldal), "DETUNE = " + lcdprint3(*opdetune) + "");
      }
      break;
    case 23:
      //PICHOP MENU-------------------------------
      byte* pichop;
      switch (opmenuoldal) {
        case 1: pichop = &op1pich; break;
        case 2: pichop = &op2pich; break;
        case 3: pichop = &op3pich; break;
        case 4: pichop = &op4pich; break;
        case 5: pichop = &op5pich; break;
        case 6: pichop = &op6pich; break;
        case 7: break;
      }
      if (inc) {
        if (*pichop < 2) {
          *pichop += 1;
        } else {
          *pichop = 0;
        }
        inc = false;
      }
      if (dec) {
        if (*pichop > 0) {
          *pichop -= 1;
        } else {
          *pichop = 2;
        }
        dec = false;
      }
      if (opmenuoldal < 7) {
        if (*pichop == 0) {
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP" + String(opmenuoldal), "PICHOP = DETUNE ");
        }
        if (*pichop == 1) {
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP" + String(opmenuoldal), "PICHOP = +      ");
        }
        if (*pichop == 2) {
          lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP" + String(opmenuoldal), "PICHOP = -      ");
        }
      }

      break;
    case 24:
      //????------------------

      break;
    case 25:
      //????------------------

      break;
    case 26:
      //????------------------

      break;
    case 27:
      //LFO2 DELAY TIME------------------
      if (inc) {
        if (lfo2delaytime < 127) {
          lfo2delaytime += 1;
        } else {
          lfo2delaytime = 0;
        }
        inc = false;
      }
      if (dec) {
        if (lfo2delaytime > 0) {
          lfo2delaytime -= 1;
        } else {
          lfo2delaytime = 127;
        }
        dec = false;
      }
      lcdkiir("LFO2 DELAY      ", lcdprint3(lfo2delaytime) + "             ");

      pichgorbeinit();

      break;
    case 28:
      //PAREQ PARAMETERS Q------------------
      float* pareqparameter;
      switch (opmenuoldal) {
        case 1: pareqparameter = &Q; break;
        case 2: pareqparameter = &Q2; break;
        case 3:  break;
        case 4:  break;
        case 5:  break;
        case 6:  break;
        case 7:  break;
      }
      if (inc) {
        if (*pareqparameter < 13) {
          *pareqparameter += 0.1;
        } else {
          *pareqparameter = 0;
        }
        inc = false;
      }
      if (dec) {
        if (*pareqparameter > 0) {
          *pareqparameter -= 0.1;
        } else {
          *pareqparameter = 13 ;
        }
        dec = false;
      }
      if (opmenuoldal < 7) {

        if (opmenuoldal == 1) {
          lcdkiir("PARAEQ        P:" + String(opmenuoldal), "       Q1 = " + lcdprint3(*pareqparameter * 100) + "   ");
          eqkiszamol();
        }

        if (opmenuoldal == 2) {
          lcdkiir("PARAEQ       P:" + String(opmenuoldal),  "       Q2 = " + lcdprint3(*pareqparameter * 100) + "");
          eqkiszamol2();
        }
      }
      Qp = Q * 25;
      Q2p = Q2 * 25;
      break;
    case 29:
      //PAREQ PARAMETERS FREQ------------------
      float* pareqparameter2;
      switch (opmenuoldal) {
        case 1: f0 = f0orig; pareqparameter2 = &f0; break;
        case 2: f02 = f02orig; pareqparameter2 = &f02; break;
        case 3:  break;
        case 4:  break;
        case 5:  break;
        case 6:  break;
        case 7:  break;
      }
      if (inc) {
        if (*pareqparameter2 < 4000) {
          *pareqparameter2 += 25;
        } else {
          *pareqparameter2 = 26;
        }
        inc = false;
      }
      if (dec) {
        if (*pareqparameter2 > 26) {
          *pareqparameter2 -= 25;
        } else {
          *pareqparameter2 = 4000 ;
        }
        dec = false;
      }
      if (opmenuoldal < 7) {
        if (opmenuoldal == 1) {

          lcdkiir("PARAEQ       P:" + String(opmenuoldal), "  EQFREQ1 = " + lcdprint3(*pareqparameter2) + "  ");
          eqkiszamol();
        }

        if (opmenuoldal == 2) {

          lcdkiir("PARAEQ        P:" + String(opmenuoldal), "  EQFREQ2 = " + lcdprint3(*pareqparameter2) + "");
          eqkiszamol2();
        }
      }
      break;
    case 30:
      //EFFECT LEFT ON------------------
      bool *effecton;
      switch (opmenuoldal) {
        case 1: effecton = &parametereqlefton; break;
        case 2: effecton = &delaylowpasseqlefton; break;
        case 3: effecton = &highpasslefteqon; break;
        case 4: effecton = &limiterlefton; break;
        case 5:  break;
        case 6:  break;
        case 7:  break;
      }
      if (inc) {
        *effecton = true;
        inc = false;
      }
      if (dec) {
        *effecton = false;
        dec = false;
      }
      if (opmenuoldal < 7) {
        if (opmenuoldal == 1) {
          lcdkiir("EFFECT LEFT  P:" + String(opmenuoldal), "  PAREQ = " + lcdprint3(*effecton) + "   ");
        }
        if (opmenuoldal == 2) {
          lcdkiir("EFFECT LEFT  P:" + String(opmenuoldal), "DELAYLQ = " + lcdprint3(*effecton) + "   ");
        }
        if (opmenuoldal == 3) {
          lcdkiir("EFFECT LEFT  P:" + String(opmenuoldal), "HPASSEQ = " + lcdprint3(*effecton) + "   ");
        }
        if (opmenuoldal == 4) {
          lcdkiir("EFFECT LEFT  P:" + String(opmenuoldal), "LIMITER = " + lcdprint3(*effecton) + "   ");
        }
      }
      break;
    case 31:
      //EFFECT RIGHT ON------------------
      bool *effecton2;
      switch (opmenuoldal) {
        case 1: effecton2 = &parametereqrighton; break;
        case 2: effecton2 = &delaylowpasseqrighton; break;
        case 3: effecton2 = &highpassrighteqon; break;
        case 4: effecton2 = &limiterrighton; break;
        case 5:  break;
        case 6:  break;
        case 7:  break;
      }
      if (inc) {
        *effecton2 = true;
        inc = false;
      }
      if (dec) {
        *effecton2 = false;
        dec = false;
      }
      if (opmenuoldal < 7) {
        if (opmenuoldal == 1) {
          lcdkiir("EFFECT RIGHT P:" + String(opmenuoldal), "  PAREQ = " + lcdprint3(*effecton2) + "   ");
        }
        if (opmenuoldal == 2) {
          lcdkiir("EFFECT RIGHT P:" + String(opmenuoldal), "DELAYLQ = " + lcdprint3(*effecton2) + "   ");
        }
        if (opmenuoldal == 3) {
          lcdkiir("EFFECT RIGHT P:" + String(opmenuoldal), "HPASSEQ = " + lcdprint3(*effecton2) + "   ");
        }
        if (opmenuoldal == 4) {
          lcdkiir("EFFECT RIGHT P:" + String(opmenuoldal), "LIMITER = " + lcdprint3(*effecton2) + "   ");
        }
      }
      break;
    case 32:
      //EQVALUE------------------
      if (inc) {
        if (eqvalue < 12192) {
          eqvalue += 96;
        } else {
          eqvalue = 0;
        }
        inc = false;
      }
      if (dec) {
        if (eqvalue > 0) {
          eqvalue -= 96;
        } else {
          eqvalue = 12192;
        }

        dec = false;
      }


      lcdkiir(String("EQ VALUE        "), String(lcdprint3(eqvalue)) + "             ");
      break;
    case 33:
      //EFFECT REVERB PARAMETERS------------------
      byte* reverbparameter;
      switch (opmenuoldal) {
        case 1: reverbparameter = &reverblevel; break;
        case 2: reverbparameter = &reverbdiffusion; break;
        case 3: reverbparameter = &delaytime; break;
        case 4: reverbparameter = &delay2time; break;
        case 5:  break;
        case 6:  break;
        case 7:  break;
      }
      if (inc) {
        if (*reverbparameter < 127) {
          *reverbparameter += 1;
        } else {
          *reverbparameter = 0;
        }
        inc = false;
      }
      if (dec) {
        if (*reverbparameter > 0) {
          *reverbparameter -= 1;
        } else {
          *reverbparameter = 127 ;
        }
        dec = false;
      }
      if (opmenuoldal < 7) {
        if (opmenuoldal == 1) {
          lcdkiir("REVERB       P:" + String(opmenuoldal), "   LEVEL = " + lcdprint3(*reverbparameter) + "  ");
        }
        if (opmenuoldal == 2) {
          lcdkiir("REVERB       P:" + String(opmenuoldal), "DIFFUSION = " + lcdprint3(*reverbparameter) + "   ");
        }
        if (opmenuoldal == 3) {
          lcdkiir("REVERB       P:" + String(opmenuoldal), "DELAYTIMEL = " + lcdprint3(*reverbparameter) + "");
        }
        if (opmenuoldal == 4) {
          lcdkiir("REVERB       P:" + String(opmenuoldal), "DELAYTIMER = " + lcdprint3(*reverbparameter) + "");
        }
      }
      break;
    case 34:
      //EFFECT CHORUS LEVEL------------------
      if (inc) {
        if (choruslevel < 127) {
          choruslevel ++;
        } else {
          choruslevel = 0;
        }
        inc = false;
      }
      if (dec) {
        if (choruslevel > 0) {
          choruslevel --;
        } else {
          choruslevel = 127;
        }
        dec = false;
      }
      lcdkiir(String("CHORUS LEVEL   "), String(lcdprint3(choruslevel)) + "             ");
      break;
    case 35:
      //EFFECT CHORUS FREQ------------------
      if (inc) {
        if (chorusfreq < 127) {
          chorusfreq++;
        } else {
          chorusfreq = 0;
        }
        inc = false;
      }
      if (dec) {
        if (chorusfreq > 0) {
          chorusfreq--;
        } else {
          chorusfreq = 127;
        }
        dec = false;
      }
      lcdkiir(String("CHORUS FREQ     "), String(lcdprint3(chorusfreq)) + "             ");

      break;
    case 36:
      //PICH START LEVEL------------------
      if (inc) {
        if (pichkezd < 3000) {
          pichkezd += 23;
        } else {
          pichkezd = 0;
        }
        inc = false;
      }
      if (dec) {
        if (pichkezd > 0) {
          pichkezd -= 23;
        } else {
          pichkezd = 3000;
        }
        dec = false;
      }
      lcdkiir(String("PICH BEGIN      "), String(lcdprint3(pichkezd)) + "             ");
      pichgorbeinit();
      break;

    case 37:
      if (inc) {
        if (lfo2freq < 127) {
          lfo2freq++;
        } else {
          lfo2freq = 0;
        }
        inc = false;
      }
      if (dec) {
        if (lfo2freq > 0) {
          lfo2freq --;
        } else {
          lfo2freq = 127;
        }
        dec = false;
      }
      lcdkiir("LFO FREQ        ", lcdprint3(lfo2freq) + "             ");
      break;


    case 38:
      if (inc) {
        if (oplevel < 127) {
          oplevel ++;
        } else {
          oplevel = 1;
        }
        inc = false;
      }
      if (dec) {
        if (oplevel > 1) {
          oplevel --;
        } else {
          oplevel = 127;
        }
        dec = false;
      }
      lcdkiir(String("OP LEVEL        "), lcdprint3(oplevel) + "        (001)");

      //tvainit();
      stepprogchanged = 17;
      break;

    case 39:
      if (inc) {
        if (lfo2volume < 127) {
          lfo2volume++;
        } else {
          lfo2volume = 0;
        }
        inc = false;
      }
      if (dec) {
        if (lfo2volume > 0) {
          lfo2volume --;
        } else {
          lfo2volume = 127;
        }
        dec = false;
      }


      lcdkiir("LFO VOLUME      ", lcdprint3(lfo2volume) + "             (0)");
      break;



    case 40:

      if (inc) {
        if (modulation < 10) {
          modulation++;
        } else {
          modulation = 1;
        }
        inc = false;
      }
      if (dec) {
        if (modulation > 0) {
          modulation--;
        } else {
          modulation = 10;
        }
        dec = false;
      }
      lcdkiir("MODULATION MODE ", lcdprint3(modulation) + "             (0)");

      break;
    case 41:
      //STEP BIT MENU-------------------------------
      byte* lepop;
      switch (opmenuoldal) {
        case 1: lepop = &op1lep; break;
        case 2: lepop = &op2lep; break;
        case 3: lepop = &op3lep; break;
        case 4: lepop = &op4lep; break;
        case 5: lepop = &op5lep; break;
        case 6: lepop = &op6lep; break;
        case 7: break;
      }
      if (inc) {
        if (*lepop < 28) {
          *lepop++;
        } else {
          *lepop = 16;
        }
        inc = false;
      }
      if (dec) {
        if (*lepop > 16) {
          *lepop--;
        } else {
          *lepop = 28;
        }
        dec = false;
      }
      if (opmenuoldal < 7) {
        lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP" + String(opmenuoldal), "STEPBIT = " + lcdprint3(*lepop) + "   ");
      }
      break;
    case 42:
      byte* limitp;
      switch (opmenuoldal) {
        case 1: limitp = &limitgain; break;
        case 2: limitp = &limitgain2; break;
        case 3:  break;
        case 4:  break;
        case 5:  break;
        case 6:  break;
        case 7: break;

      }
      if (inc) {
        if (*limitp < 127) {
          *limitp += 1;
        } else {
          *limitp = 0;
        }

        inc = false;
      }
      if (dec) {
        if (*limitp > 0) {
          *limitp -= 1;
        } else {
          *limitp = 127;
        }

        dec = false;
      }
      if (opmenuoldal == 1 ) {
        limitcount();
        lcdkiir("LIMITGAIN LEFT  ", lcdprint6(limitplus) + "     (65535)");
      }
      if (opmenuoldal == 2 ) {
        limitcount2();
        lcdkiir("LIMITGAIN RIGHT  ", lcdprint6(limitplus2) + "     (65535)");
      }

      break;
    case 43:


      break;

    case 44:

      if (inc) {
        if (ofset < 65536) {
          ofset += 128;
        } else {
          ofset = 0;
        }
        inc = false;
      }
      if (dec) {
        if (ofset > 0) {
          ofset -= 128;
        } else {
          ofset = 65536;
        }
        dec = false;
      }
      lcdkiir("OFSET      ", lcdprint6(ofset) + "    (2048)");
      break;
    case 45:

      if (inc) {
        if (released < 16) {
          released++;;
        } else {
          released = 0;
        }
        inc = false;
      }
      if (dec) {
        if (released > 0) {
          ofset--;
        } else {
          released = 16;
        }
        dec = false;
      }
      lcdkiir("RELEASED   ", lcdprint3(released) + "       (2)");
      break;

    case 49:
      if (inc) {
        if (saveprog < 9) {
          saveprog++;
        } else {
          saveprog = 1;
        }
        inc = false;
      }
      if (dec) {
        if (saveprog > 1) {
          saveprog--;
        } else {
          saveprog = 9;
        }
        dec = false;
      }
      lcdkiir("Save: PRG<       ", "      " + lcdprint3(saveprog) + "  " + savestring + "    ");
      break;

    case 50:
      if (inc) {
        if (savestring == "YES") {
          save();
          //programmentesfuggveny
          savestring = "NO";
        } else {
          savestring = "YES";
        }
        inc = false;
      }
      if (dec) {
        savestring = "NO";
        dec = false;
      }
      lcdkiir("Save: PRG >      ", "      " + lcdprint3(saveprog) + "  " + savestring + "  ");
      break;
    case 51:
      if (inc) {
        if (c < 8191) {
          c++;
        } else {
          c = 1;
        }
        inc = false;
      }
      if (dec) {
        if (c > 0) {
          c--;
        } else {
          c = 8191;
        }
        dec = false;
      }
      lcdkiir("Alg" + lcdprint2(alg) + " " + ops + " OP6", "TUNE =" + lcdprint7(c));

      break;

  }
}

//02 DIGIT NUMBER CONVERT LCD STRING
String lcdprint2(int cc)
{
  String eredmeny = "";
  eredmeny += (cc % 100) / 10;
  eredmeny += cc % 10;
  return eredmeny;
}

//003 DIGIT NUMBER CONVERT LCD STRING
String lcdprint3(int cc)
{
  String eredmeny = "";
  eredmeny += cc / 100;
  eredmeny += (cc % 100) / 10;
  eredmeny += cc % 10;
  return eredmeny;
}

//0004 DIGIT NUMBER CONVERT LCD STRING
String lcdprint4(int cc)
{
  String eredmeny = "";
  eredmeny += cc / 1000;
  eredmeny += (cc % 1000) / 100;
  eredmeny += (cc % 100) / 10;
  eredmeny += cc % 10;
  return eredmeny;
}

//00005 DIGIT NUMBER CONVERT LCD STRING
String lcdprint5(int cc)
{
  String eredmeny = "";
  eredmeny += cc / 10000;
  eredmeny += (cc % 10000) / 1000;
  eredmeny += (cc % 1000) / 100;
  eredmeny += (cc % 100) / 10;
  eredmeny += cc % 10;
  return eredmeny;
}

//000006 DIGIT NUMBER CONVERT LCD STRING
String lcdprint6(int cc)
{
  String eredmeny = "";
  eredmeny += cc / 100000;
  eredmeny += (cc % 100000) / 10000;
  eredmeny += (cc % 10000) / 1000;
  eredmeny += (cc % 1000) / 100;
  eredmeny += (cc % 100) / 10;
  eredmeny += cc % 10;
  return eredmeny;
}

//0000007 DIGIT NUMBER CONVERT LCD STRING
String lcdprint7(int cc)
{
  String eredmeny = "";
  eredmeny += cc / 1000000;
  eredmeny += (cc % 1000000) / 100000;
  eredmeny += (cc % 100000) / 10000;
  eredmeny += (cc % 10000) / 1000;
  eredmeny += (cc % 1000) / 100;
  eredmeny += (cc % 100) / 10;
  eredmeny += cc % 10;
  return eredmeny;
}

//OPGENERATOR TO STRING (e.g.: 100101)
