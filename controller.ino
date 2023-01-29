bool elozogomb1val = true;
bool elozogomb2val = true;
bool elozogomb3val = true;
bool elozogomb4val = true;
bool elozogomb5val = true;
bool elozogomb6val = true;
bool elozogomb7val = true;
bool elozogomb8val = true;
uint8_t  gomb1val=true;
uint8_t  gomb2val=true;
uint8_t  gomb3val=true;
uint8_t  gomb4val=true;
uint8_t  gomb5val=true;
uint8_t  gomb6val=true;
uint8_t  gomb7val=true;
uint8_t  gomb8val=true;

void vezerlok() { 
    int gomb2val = digitalRead(BUTTON_PIN);
    /*
    int gomb3val = digitalRead(gomb3);
    int gomb4val = digitalRead(gomb4);
    int gomb5val = digitalRead(gomb6);
    int gomb6val = digitalRead(gomb5);
    int gomb7val = digitalRead(gomb7);
    int gomb8val = digitalRead(gomb8);
*/
  
  //menufel
  if (elozogomb1val != gomb1val) {
    if (gomb1val == false) {
      if (menuoldal < 50)
      {
        menuoldal++;
      } else {
        menuoldal = 1;
      }
      menukiir();
    }
    elozogomb1val = gomb1val;
  }


  //key
  if (elozogomb2val != gomb2val) {
    if (gomb2val == false) {
      keyon(64);
    }
    if (gomb2val == true) {
     keyoff(64);      
      }
     elozogomb2val = gomb2val;  
  }

/*
  //menule
  if (elozogomb2val != gomb2val) {
    if (gomb2val == false) {
      if (menuoldal > 1)
      {
        menuoldal--;
      } else {
        menuoldal = 50;
      }
      menukiir();
    }
    elozogomb2val = gomb2val;
  }
*/

 //key
  if (elozogomb3val != gomb3val) {
    if (gomb3val == false) {
      keyon(65);
    }
    if (gomb3val == true) {
     keyoff(65);      
      }
     elozogomb3val = gomb3val;  
  }

/*
  //programfel
  if (elozogomb3val != gomb3val) {
    if (gomb3val == false) {
      if (program < 10)
      {
        program++;
        programchange(program);
      } else {
        program = 0;
        programchange(program);
      }
    }
    elozogomb3val = gomb3val;
  }
  */

  //programle
  if (elozogomb4val != gomb4val) {
    if (gomb4val == false) {
      if (program > 0)
      {
        program--;
        programchange(program);
      } else {
        program = 10;
        programchange(program);
      }
    }
    elozogomb4val = gomb4val;
  }


 //key
  if (elozogomb5val != gomb5val) {
    if (gomb5val == false) {
      keyon(67);
    }
    if (gomb5val == true) {
     keyoff(67);      
      }
     elozogomb5val = gomb5val;  
  }
/*
  //incrementvalue
  if (elozogomb5val != gomb5val) {
    if (gomb5val == false) {

      if (inc == false)
      {
        inc = true;
        menukiir();
      }

    }
    elozogomb5val = gomb5val;
  }

  */
  //decrementvalue
  if (elozogomb6val != gomb6val) {
    if (gomb6val == false) {

      if (dec == false)
      {
        dec = true;
        menukiir();
      }

    }
    elozogomb6val = gomb6val;
  }



 //key
  if (elozogomb7val != gomb7val) {
    if (gomb7val == false) {
      keyon(69);
    }
    if (gomb7val == true) {
     keyoff(69);      
      }
     elozogomb7val = gomb7val;  
  }

/*
  //opmenufel
  if (elozogomb7val != gomb7val) {
    if (gomb7val == false) {
      if (opmenuoldal < 7)
      {
        opmenuoldal++;
      } else {
        opmenuoldal = 1;
      }
      menukiir();
    }
    elozogomb7val = gomb7val;
  }
*/

  //opmenule
  if (elozogomb8val != gomb8val) {
    if (gomb8val == false) {
      if (opmenuoldal > 1)
      {
        opmenuoldal--;
      } else {
        opmenuoldal = 7;
      }
      menukiir();
    }
    elozogomb8val = gomb8val;
  }
  
}

//KEYBOARD SOUND KEYON
void keyon(byte noteByte){
   // velocityByte = MIDI2.getData2();
        if (generatornumber == 6) {
          generatornumber = 0;
        }
        gorbetime[generatornumber] = 0;
        ptrnullaz();
        wavefreq[generatornumber] = noteertek[noteByte];
        waveveloc[generatornumber]  = 127;
        oldnoteByte[generatornumber] = noteByte;
        generatornumber++;
  }

//KEYBOARD SOUND KEYOFF
  void keyoff(byte noteByte){  
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
    }
