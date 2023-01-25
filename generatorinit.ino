//----------------------------GENERATORINIT-------------------------------------
void sinusinit() {
  for (int i = 0; i < FG_SIZE; i++)
  {
    sinusfg[i] = sin(i *  PI / 512) * 32767;
  }
}

void fmsinusinit() {
  for (int i = 0; i <= FG_SIZE; i++)
  { fmsinusfg[i] = sin(i *  PI / 512) * 1024 ;
  }
}

void haromszoginit() {
  int db = FG_SIZE;
  for (int i = 0; i < db; i++) {
    int16_t haromnegyed = db / 4 * 3;
    int16_t fel = db / 2;
    int16_t negyed = db / 4;
    int ertek = 0;
    if (i <= negyed) {
      ertek = i;
    }
    if ((i > negyed) && (i <= haromnegyed)) {
      ertek = -1 * i + fel;
    }
    if (i > haromnegyed) {
      ertek = i - db;
    }
    haromszogfg[i] = ertek <<1;
  }
}

/*
void fmharomszoginit() {
  int db = FG_SIZE;
  for (int i = 0; i < db; i++) {
    int16_t haromnegyed = db / 4 * 3;
    int16_t fel = db / 2;
    int16_t negyed = db / 4;
    int ertek = 0;
    if (i <= negyed) {
      ertek = i;
    }
    if ((i > negyed) && (i <= haromnegyed)) {
      ertek = -1 * i + fel;
    }
    if (i > haromnegyed) {
      ertek = i - db;
    }
    fmharomszogfg[i] = ertek * 2;
  }
}
*/

void fureszoginit() {
  int db = FG_SIZE;
  int ertek = 0;
  for (int i = 0; i < db; i++) {
    ertek = i;
    fureszfg[i] = ertek;
  }
}
/*
void fmfureszoginit() {
  int db = FG_SIZE;
  int ertek = 0;
  for (int i = 0; i < db; i++) {
    ertek = i  * 16;
    fmfureszfg[i] = ertek;
  }
}
*/


/*
void fmtangensinit() {
  for (int i = 0; i < FG_SIZE; i++)
  {
    fmstangensfg[i] = (tan(i *  PI / 512) * 32767) ;
  }
}
*/
void negyszoginit() {
  int db = FG_SIZE;
  int fel = db / 2;
  int max = 8000;
  int min = -8000;
  int ertek = 0;
  for (int i = 0; i < db; i++)
  {
    if (i > fel) 
    {
      ertek = max;
    }
    if (i < fel)
    { ertek = min;
    }
    negyszogfg[i] = ertek;
  }
  // negyszogfg[0] = 0;
  //negyszogfg[FG_SIZE] = 0;
}
/*
void fmnegyszoginit() {
  int db = FG_SIZE;
  int fel = db / 2;
  int max = 1024;
  int min = -1024;
  int ertek = 0;
  for (int i = 0; i < db; i++)
  {
    if (i > fel) 
    {
      ertek = max;
    }
    if (i < fel)
    { ertek = min;
    }
    fmnegyszogfg[i] = ertek;
  }
  // negyszogfg[0] = 0;
  //negyszogfg[FG_SIZE] = 0;
}
*/
void zajinit() {
  int db = FG_SIZE;
  for (int i = 0; i < db; i++) {
    zajfg[i] = random(-1024, 1024);
  }
  for (int i = FG_SIZE/2; i < db; i++) {
    zajfg[i] += random(-5, 5);
  }
  
}
void pwminit()
{
  /*
    for (int i = 0; i < FG_SIZE; i++)
    {
      pwmfg[i] = 2;
    }
    pwmfg[0] = -2;

    for (int i = 0; i < FG_SIZE; i++)
    {
    //           pwmfg[i] = 255;
    }
    //   pwmfg[0] = 1;
  */
}




  void duplafginit() {
    for (int i = 0; i <= FG_SIZE; i++)
    {
      duplafg[i] = sin(i *  PI / 512) * 4000 ;
    }
    for (int i = 0; i <= FG_SIZE / 2; i++) {
      duplafg[i] += sinusfg[i * 2] / 2 ;
      duplafg[i + FG_SIZE / 2] += sinusfg[i * 2] / 2 ;
    }
  }

  void triplafginit() {
    for (int i = 0; i <= FG_SIZE; i++)
    {
      triplafg[i] = sin(i *  PI / 512) * 4000 ;
    }
    for (int i = 0; i <= FG_SIZE / 2; i++) {
      triplafg[i] += sinusfg[i * 2] / 2 ;
      triplafg[i + FG_SIZE / 2] += sinusfg[i * 2] / 2 ;
    }
    for (int i = 0; i <= FG_SIZE / 4; i++) {
      triplafg[i] += sinusfg[i * 4] / 4 ;
      triplafg[i + FG_SIZE / 4] += sinusfg[i * 4] / 4 ;
      triplafg[i + FG_SIZE / 2] += sinusfg[i * 4] / 4 ;
      triplafg[i + 3 * FG_SIZE / 4] += sinusfg[i * 4] / 4 ;
    }
  }


  void generatorinitone(byte opwaveform, int16_t generator[]) {
    switch (opwaveform) {
      case 0:
        for (int i = 0; i < FG_SIZE; i++) {
          generator[i] = 0;
        }
        break;
      case 1:
        for (int i = 0; i < FG_SIZE; i++) {
          generator[i] = sinusfg[i]>>4;
        }
        break;
      case 2:
        for (int i = 0; i < FG_SIZE; i++) {
          generator[i] = fmsinusfg[i]>>1;
        }
        break;
      case 3:
        for (int i = 0; i < FG_SIZE; i++) {
          generator[i] = haromszogfg[i];
        }
        break;
        case 4:
        for (int i = 0; i < FG_SIZE; i++) {
          generator[i] = haromszogfg[i]>>1;
        }
        break;
      case 5:
        for (int i = 0; i < FG_SIZE; i++) {
          generator[i] = fureszfg[i];
        }
        break;
        case 6:
        for (int i = 0; i < FG_SIZE; i++) {
          generator[i] = fureszfg[i]>>2;
        }
        break;
      case 7:
        for (int i = 0; i < FG_SIZE; i++) {
          generator[i] = negyszogfg[i]>>2;
        }
        break;
        case 8:
        for (int i = 0; i < FG_SIZE; i++) {
          generator[i] = negyszogfg[i]>>6;
        }
        break;
      case 9:
        for (int i = 0; i < FG_SIZE; i++) {
         generator[i] =zajfg[i]>>2;
        }
        break;
      case 10:
        for (int i = 0; i < FG_SIZE; i++) {
            generator[i] = wavetable1fg[i]>>6;
        }
        break;
      case 11:
        for (int i = 0; i < FG_SIZE; i++) {
             generator[i] = wavetable2fg[i]>>6;
        }
        break;
      case 12:
        for (int i = 0; i < FG_SIZE; i++) {
             generator[i] = wavetable3fg[i]>>6;
        }
        break;
      case 13:
        for (int i = 0; i < FG_SIZE; i++) {
              generator[i] = wavetable4fg[i]>>6;
        }
        break;
      case 14:
        for (int i = 0; i < FG_SIZE; i++) {
          generator[i] = duplafg[i]>>6;
        }
        break;
      case 15:
        for (int i = 0; i < FG_SIZE; i++) {
          generator[i] = triplafg[i]>>6;
        }
        break;
      case 16:
        for (int i = 0; i < FG_SIZE; i++) {
          generator[i] = triplafg[i] >>6;
          generator[i] += fureszfg[i]>>5;
        }
        break;
      case 17:
        for (int i = 0; i < FG_SIZE; i++) {
          generator[i] = triplafg[i] >>6;
          generator[i] += fureszfg[i]>>5;
          // generator[i]+= zajfg[i]>>4;
        }
        break;
      case 18:
        for (int i = 0; i < FG_SIZE; i++) {
          generator[i] = triplafg[i] >>6;
          generator[i] += fureszfg[i]>>4;
          generator[i] += negyszogfg[i] >>5;
        }
        break;
    
    }
  }

  void generatorinit(byte op1waveform, byte op2waveform, byte op3waveform, byte op4waveform, byte op5waveform, byte op6waveform) {
    generatorinitone(op1waveform, generator1);
    generatorinitone(op2waveform, generator2);
    generatorinitone(op3waveform, generator3);
    generatorinitone(op4waveform, generator4);
    generatorinitone(op5waveform, generator5);
    generatorinitone(op6waveform, generator6);
  }
