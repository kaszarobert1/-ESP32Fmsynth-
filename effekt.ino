//REVERB-DELAY EFFECT LEFT
//bufferbe: actual sample, delaybuffer array, reverblecel, reverbdiffusion, delaytime,
int32_t atlag = 0;
int32_t atlag2 = 0;
void reverbleft() {
  bufferbe =   bufferbe + delaybuffer[delaybufferindex];
  atlag += (reverblevel - 1) * bufferbe / reverblevel;
  delaystep++;
  if (delaystep >= delaytime) {
    delaybuffer[delaybufferindex] = ((atlag / delaystep) << 4) / reverbdiffusion;
    atlag = 0;
    delaybufferindex ++;
    delaystep = 0;
  }
  if (delaybufferindex >= reverbtime) {
    delaybufferindex = 0;
  }
}

//REVERB-DELAY EFFECT RIGHT
//bufferbe: actual sample right, delaybuffer2 array, reverblevel, reverbdiffusion, delaytime2, delaystep2

void reverbright() {
  bufferbe =   bufferbe + delaybuffer2[delaybufferindex2];
  atlag2 += (reverblevel - 1) * bufferbe / reverblevel;
  delay2step++;
  if (delay2step >= delay2time) {
    delaybuffer2[delaybufferindex2] = ((atlag2 / delay2step) << 4) / reverbdiffusion;
    atlag2 = 0;
    delaybufferindex2 ++;
    delay2step = 0;
  }
  if (delaybufferindex2 >= reverbtime2) {
    delaybufferindex2 = 0;
  }
}

//HIGHPASS FILTER LEFT
//bufferbe: actual sample left, y->prev samples, freq1, freq2
/*
    eqvalue 0-127
    freq1 = (eqvalue / 123) * 100;
    freq2 = (127 - eqvalue / 99) * 100;
*/
void highpasseqleft() {
  y9 = y7; //prevsample2
  y7 = y5; //prevsample1
  y5 = bufferbe; //prevsample0
  //bufferbe =((freq1 * y7 - freq2 * y5) / 11500+(freq1 * y7 + freq2 * y9) / 11500+(freq1 * y - freq2 * y3) / 11500)>>1;
  bufferbe = ((freq1 * y7 - freq2 * y5) / 11500 + (freq1 * y7 + freq2 * y9) / 11500 + (freq1 * y - freq2 * y3) / 11500) >> 1;
  y3 = y; //prevbuffer2
  y = bufferbe; //prevbuffer1
}

//HIGHPASS FILTER RIGHT
//bufferbe: actual sample right, y->prev samples, freq1, freq2
void highpasseqright() {
  y10 = y8; //prevsample2
  y8 = y6; //prevsample1
  y6 = bufferbe; //prevsample0
  bufferbe = ((freq1 * y8 - freq2 * y6) / 11500 + (freq1 * y8 + freq2 * y10) / 11500 + (freq1 * y2 - freq2 * y4) / 11500) >> 1;
  y4 = y2; //prevbuffer2
  y2 = bufferbe; //prevbuffer1
}

//LOWPASSFILTER LEFT
//lowpassfilter in delaybuffer!!!
//delaybuffer actual sample, x: delaybuffer prev sample
int16_t x = 0;
void lowpassfilterleft() {
  delaybuffer[delaybufferindex] = (delaybuffer[delaybufferindex] + x) >> 1;
  x = delaybuffer[delaybufferindex];
}

//LOWPASSFILTER RIGHT
//lowpassfilter in delaybuffer!!!
//delaybuffer actual sample, x2: delaybuffer prev sample
int16_t x2 = 0;
void lowpassfilterright() {
  delaybuffer2[delaybufferindex2] = (delaybuffer2[delaybufferindex2] + x2) >> 1;
  x2 = delaybuffer2[delaybufferindex2];
}

//PARAMETRIC EQ LEFT
float Fs = 48000;
float Pi = 3.141592;
/* cut-off (or center) frequency in Hz */
/* filter Q */
/*
  https://ethanwiner.com/eq-dsp.htm
*/

//parametric eq left default:
float w0 = 2 * Pi * f0 / Fs;
float alpha = sin(w0) / (2 * Q);
float a0 = (1 + alpha);
float a1 = (-2 * cos(w0));
float a2 = (1 - alpha) ;
float b0 = ((1 + cos(w0)) / 2);
float b1 = (-(1 + cos(w0))) ;
float b2 = ((1 + cos(w0)) / 2) ;

//parametric eq left init:
void eqkiszamol() {
  w0 = 2 * Pi * f0 / Fs;
  alpha = sin(w0) / (2 * Q);
  a0 = (1 + alpha) * 100 ;
  a1 = (-2 * cos(w0)) * 100;
  a2 = (1 - alpha) * 100;
  b0 = ((1 + cos(w0)) / 2) * 100;
  b1 = (-(1 + cos(w0))) * 100;
  b2 = ((1 + cos(w0)) / 2) * 100;
}

//parametric eq left counts actual value:
int16_t PrevSample[3];
int16_t lastbuffer;
int16_t lastlastbuffer;

//parametric eq left function
void parametereqleft() {
  PrevSample[2] = PrevSample[1];
  PrevSample[1] = PrevSample[0];
  PrevSample[0] = bufferbe;
  bufferbe = ( b0 / a0 * PrevSample[0]) +
             (b1 / a0 * PrevSample[1]) +
             (b2 / a0 * PrevSample[2]) -
             (a1 / a0 * lastbuffer) -
             (a2 / a0 * lastlastbuffer);
  lastlastbuffer = lastbuffer;
  lastbuffer = bufferbe;
}

//parametric eq2 right default:
float w02 = 2 * Pi * f02 / Fs;
float alpha2 = sin(w02) / (2 * Q2);
float a02 = (1 + alpha2);
float a12 = (-2 * cos(w02));
float a22 = (1 - alpha2) ;
float b02 = ((1 + cos(w02)) / 2);
float b12 = (-(1 + cos(w02))) ;
float b22 = ((1 + cos(w02)) / 2) ;

//parametric eq2 right init:
void eqkiszamol2() {
  w02 = 2 * Pi * f02 / Fs;
  alpha2 = sin(w02) / (2 * Q2);
  a02 = (1 + alpha2) * 100 ;
  a12 = (-2 * cos(w02)) * 100;
  a22 = (1 - alpha2) * 100;
  b02 = ((1 + cos(w02)) / 2) * 100;
  b12 = (-(1 + cos(w02))) * 100;
  b22 = ((1 + cos(w02)) / 2) * 100;
}

//parametric eq2 right counts actual value:
int16_t PrevSample2[3];
int16_t lastbuffer2;
int16_t lastlastbuffer2;
void parametereqright() {
  PrevSample2[2] = PrevSample2[1];
  PrevSample2[1] = PrevSample2[0];
  PrevSample2[0] = bufferbe;
  bufferbe = (b02 / a02 * PrevSample2[0]) +
             (b12 / a02 * PrevSample2[1]) +
             (b22 / a02 * PrevSample2[2]) -
             (a12 / a02 * lastbuffer2) -
             (a22 / a02 * lastlastbuffer2);
  lastlastbuffer2 = lastbuffer2;
  lastbuffer2 = bufferbe;
}
void limitcount() {
  limitplus =expgains128[limitgain];
  limitminus = -limitplus;

}

void limitcount2() {
  limitplus2 = expgains128[limitgain2];
  limitminus2 = -limitplus2;

}


//LIMITER
void limiterleft() {
  if (bufferbe > limitplus) {
    bufferbe = limitplus;
  }
  if (bufferbe < limitminus) {
    bufferbe = limitminus;
  }
}
//LIMITER
void limiterright() {
  if (bufferbe > limitplus2) {
    bufferbe = limitplus2;
  }
  if (bufferbe < limitminus2) {
    bufferbe = limitminus2;
  }
}


void limiter3() {
  if (bufferbe > limitplus3) {
    bufferbe = limitplus3;
  }
  if (bufferbe < limitminus3) {
    bufferbe = limitminus3;
  }
}

//--------------------------CHORUS LEFT------------------------------


int16_t chorusbufferleft[512];
uint16_t chorusbufferindex = 0;
uint16_t chorusindex;
void chorusleft() {
  chorusbufferleft[chorusbufferindex] = bufferbe;
  chorusbufferindex++;
  chorusbufferindex &= (chorusbuffersize);
  chorusindex = (lfovalue[0] + chorusbufferindex) % chorusbuffersize;
  bufferbe = (bufferbe + ((chorusbufferleft[chorusindex] * chorusLevelLeft) >> 7));
}

//--------------------------CHORUS RIGHT------------------------------

int16_t chorusbufferright[512];
uint16_t chorusbufferindex2 = 0;
uint16_t chorusindex2;
void chorusright() {
  chorusbufferright[chorusbufferindex2] = bufferbe;
  chorusbufferindex2++;
  chorusbufferindex2 &= (chorusbuffersize2);


  // Serial.println("chorusbufferindex2 : " + String(chorusbufferindex2 ));

  chorusindex2 = (lfovalue[1] + chorusbufferindex2) % chorusbuffersize2;
  bufferbe = (bufferbe + ((chorusbufferright[chorusindex2] * chorusLevelRight) >> 7));
}


/*
  void reverbold(){
    //Delay:
      bufferbe += delaybuffer[delaybufferindex];
      delaybuffer[delaybufferindex] = (reverblevel - 1) * bufferbe / reverblevel;
      if (bufferindex % revalg == 0) {
        delaybufferindex++;
      }
      if (delaybufferindex > reverbtime) {
        delaybufferindex = 0;
      }
  }
*/
