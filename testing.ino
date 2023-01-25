//TESTS SETUP AND CONDITION

void setuptest() {
  variabletest();
  tuningtest();
  opparametertest();
  envelopetest();
  wavetabletest();
  generatortest();
  lfo2test();
  conditiontest();
}

void parameterstest() {
  Serial.println("---PARAMETERTEST BEGIN---");
  programglobalvaluetest();
  opparametertest();
  opgeneratorarametertest();
  pichparametertest();
  Serial.println("---PARAMETERTEST END---");
}

void conditiontest() {
  volumetest();
  bufferdatatest();
  bufferbdatatest();
}

void lfo2test() {
  Serial.println("---LFO2TEST BEGIN---");
  byte minvalue = 127;
  byte maxvalue = -128;
  Serial.println("byte max=127 ");
  for (int i = 0; i < FG_SIZE; i++)
  {
    Serial.print(lfoarray[i]);
    Serial.print(" ");
    if (lfoarray[i] < minvalue)
    {
      minvalue = lfoarray[i];
    }
    if (lfoarray[i] > maxvalue)
    {
      maxvalue = lfoarray[i];
    }
  }
  Serial.print("\n");
  Serial.println("Min value:" + String(minvalue));
  Serial.println("Max value:" + String(maxvalue));
}

void lfo2actualtest() {
  Serial.println("lfo2 value: " + String(lfo2value) + " lfo2 freq:" + String(lfo2freq) + " lfo2volume: " + String(lfo2volume) + " lfo2tempvolume: " + String(lfo2tempvolume) +  " " + " lfo2arrayindex>>22: " + String(lfo2arrayindex >> 23) + " " + " lfo2arrayindex: " + String(lfo2arrayindex ) + " ");
}

void volumetest() {
  Serial.println("---OP VOLUMME on LFO(uint16_t) & ORIG(uint16_t) & KeyLevel[0]=envelope*opvolume(long)---");
  Serial.print("op1volume: " + String(op1volume) + " op1volumeorig: " + String(op1volumeorig) + " op1level: " + String(op1level[0]) + "\n" );
  Serial.print("op2volume: " + String(op2volume) + " op2volumeorig: " + String(op2volumeorig) + " op2level: " + String(op2level[0]) + "\n" );
  Serial.print("op3volume: " + String(op3volume) + " op3volumeorig: " + String(op3volumeorig) + " op3level: " + String(op3level[0]) + "\n" );
  Serial.print("op4volume: " + String(op4volume) + " op4volumeorig: " + String(op4volumeorig) + " op4level: " + String(op4level[0]) + "\n" );
  Serial.print("op5volume: " + String(op5volume) + " op5volumeorig: " + String(op5volumeorig) + " op5level: " + String(op5level[0]) + "\n" );
  Serial.print("op6volume: " + String(op6volume) + " op6volumeorig: " + String(op6volumeorig) + " op6level: " + String(op6level[0]) + "\n" );
}

void bufferdatatest() {
  Serial.println("---BUFFER BEGIN---");
  shorttest();
  shortinfotest();
  Serial.print("BufferData:\n");
  int32_t minvalue = 2147483647;
  int32_t maxvalue = -2147483648;
  for (int i = 0; i < bufferLen; i++)
  {
    // Serial.print(String(i)+": ");
    Serial.print(buffer[i]);
    Serial.print(" ");
    if (buffer[i] < minvalue)
    {
      minvalue = buffer[i];
    }
    if (buffer[i] > maxvalue)
    {
      maxvalue = buffer[i];
    }
  }
  Serial.print("\n");
  Serial.println("Min buffer value:" + String(minvalue));
  Serial.println("Max buffer value:" + String(maxvalue));
  Serial.println("---BUFFER END---");
}

void bufferbdatatest() {
  Serial.println("---DELAYBUFFER BEGIN---");
  int32test();
  int32infotest();
  Serial.print("DelayBufferData:\n");
  int32_t minvalue = 2147483647;
  int32_t maxvalue = -2147483648;
  for (int i = 0; i < delaybuffersize; i++)
  {
    // Serial.print(String(i)+": ");
    Serial.print(delaybuffer[i]);
    Serial.print(" ");
    if (delaybuffer[i] < minvalue)
    {
      minvalue = delaybuffer[i];
    }
    if (delaybuffer[i] > maxvalue)
    {
      maxvalue = delaybuffer[i];
    }
  }
  Serial.print("\n");
  Serial.println("Min Delaybuffer value:" + String(minvalue));
  Serial.println("Max Delaybuffer value:" + String(maxvalue));
  Serial.println("---DELAY BUFFER END---");
}

void variabletest() {
  uint16test();
  uint16infotest();
  uint32test();
  uint32infotest();
  int16test();
  int16infotest();
}
void int16infotest() {
  int16_t t;
  Serial.println("int16_t size of bytes:" + String(sizeof(t)));
  if (sizeof(t) == 2)
  {
    Serial.println("True");
  }
}

void int32infotest() {
  int16_t t;
  Serial.println("int32_t size of bytes:" + String(sizeof(t)));
  if (sizeof(t) == 4)
  {
    Serial.println("True");
  }
}

void shorttest()
{
  Serial.println("short variable properties:");
  Serial.println("short min=-32,768 ");
  Serial.println("short max=32,767 ");
}

void shortinfotest() {
  short t;
  Serial.println("short size of bytes:" + String(sizeof(t)));
  if (sizeof(t) == 2)
  {
    Serial.println("True");
  }
}

void int16test()
{
  Serial.println("int16-t variable properties:");
  Serial.println("int16 min=-32,768 ");
  Serial.println("int16 max=32,767 ");
}

void int32test()
{
  Serial.println("int32-t variable properties:");
  Serial.println("int32 min=-2147483648 ");
  Serial.println("int32 max=2147483647 ");
}

void uint16infotest() {
  uint16_t t;
  Serial.println("uint16_t size of bytes:" + String(sizeof(t)));
  if (sizeof(t) == 2)
  {
    Serial.println("True");
  }
}

void uint32infotest() {
  uint32_t t;
  Serial.println("uint32_t size of bytes:" + String(sizeof(t)));
  if (sizeof(t) == 4)
  {
    Serial.println("True");
  }
}

void uint16test()
{
  Serial.println("Uint16-t variable properties:");
  Serial.println("Uint16 min=0");
  Serial.println("Uint16 max=65535");
  Serial.println("Uint16 not negative!");
}

void uint32test() {
  Serial.println("Uint32-t variable!");
  Serial.println("Uint32-t variable properties:");
  Serial.println("Uint32 min=0");
  Serial.println("Uint32 max=4294967295");
  Serial.println("Uint32 not negative!");
}

void opparametertest() {
  Serial.println("op1al: " + String(op1al)+";");
  Serial.println("op1ar: " + String(op1ar)+";");
  Serial.println("op1d1l: " + String(op1d1l)+";");
  Serial.println("op1d1r: " + String(op1d1r)+";");
  Serial.println("op1d2l: " + String(op1d2l)+";");
  Serial.println("op1d2r: " + String(op1d2r)+";");
  Serial.println("op1rl: " + String(op1rl)+";");
  Serial.println("op1rr: " + String(op1rr)+";");
  Serial.println("op2al: " + String(op2al)+";");
  Serial.println("op2ar: " + String(op2ar)+";");
  Serial.println("op2d1l: " + String(op2d1l)+";");
  Serial.println("op2d1r: " + String(op2d1r)+";");
  Serial.println("op2d2l: " + String(op2d2l)+";");
  Serial.println("op2d2r: " + String(op2d2r)+";");
  Serial.println("op2rl: " + String(op2rl)+";");
  Serial.println("op2rr: " + String(op2rr)+";");
  Serial.println("op3al: " + String(op3al)+";");
  Serial.println("op3ar: " + String(op3ar)+";");
  Serial.println("op3d1l: " + String(op3d1l)+";");
  Serial.println("op3d1r: " + String(op3d1r)+";");
  Serial.println("op3d2l: " + String(op3d2l)+";");
  Serial.println("op3d2r: " + String(op3d2r)+";");
  Serial.println("op3rl: " + String(op3rl)+";");
  Serial.println("op3rr: " + String(op3rr)+";");
  Serial.println("op4al: " + String(op4al)+";");
  Serial.println("op4ar: " + String(op4ar)+";");
  Serial.println("op4d1l: " + String(op4d1l)+";");
  Serial.println("op4d1r: " + String(op4d1r)+";");
  Serial.println("op4d2l: " + String(op4d2l)+";");
  Serial.println("op4d2r: " + String(op4d2r)+";");
  Serial.println("op4rl: " + String(op4rl)+";");
  Serial.println("op4rr: " + String(op4rr)+";");
  Serial.println("op5al: " + String(op5al)+";");
  Serial.println("op5ar: " + String(op5ar)+";");
  Serial.println("op5d1l: " + String(op5d1l)+";");
  Serial.println("op5d1r: " + String(op5d1r)+";");
  Serial.println("op5d2l: " + String(op5d2l)+";");
  Serial.println("op5d2r: " + String(op5d2r)+";");
  Serial.println("op5rl: " + String(op5rl)+";");
  Serial.println("op5rr: " + String(op5rr)+";");
  Serial.println("op6al: " + String(op6al)+";");
  Serial.println("op6ar: " + String(op6ar)+";");
  Serial.println("op6d1l: " + String(op6d1l)+";");
  Serial.println("op6d1r: " + String(op6d1r)+";");
  Serial.println("op6d2l: " + String(op6d2l)+";");
  Serial.println("op6d2r: " + String(op6d2r)+";");
  Serial.println("op6rl: " + String(op6rl)+";");
  Serial.println("op6rr: " + String(op6rr)+";");
}

void opgeneratorarametertest() {
  Serial.println("op1volume= " + String(op1volume)+";");
  Serial.println("op1waveform= " + String(op1waveform)+";");
  Serial.println("op1generatorfreq= " + String(op1generatorfreq)+";");
  Serial.println("op1notefixed= " + String(op1notefixed)+";");
  Serial.println("op1generatorfreqfixp= " + String(op1generatorfreqfixp)+";");
  Serial.println("op1detunep= " + String(op1detunep)+";");
  Serial.println("op1lep= " + String(op1lep)+";");
  Serial.println("op1pich= " + String(op1pich)+";");
  Serial.println("op2volume= " + String(op2volume)+";");
  Serial.println("op2waveform= " + String(op2waveform)+";");
  Serial.println("op2generatorfreq= " + String(op2generatorfreq)+";");
  Serial.println("op2notefixed= " + String(op2notefixed)+";");
  Serial.println("op2generatorfreqfixp= " + String(op2generatorfreqfixp)+";");
  Serial.println("op2detunep= " + String(op2detunep)+";");
  Serial.println("op2lep= " + String(op2lep)+";");
  Serial.println("op2pich= " + String(op2pich)+";");
  Serial.println("op3volume= " + String(op3volume)+";");
  Serial.println("op3waveform= " + String(op3waveform)+";");
  Serial.println("op3generatorfreq= " + String(op3generatorfreq)+";");
  Serial.println("op3notefixed= " + String(op3notefixed)+";");
  Serial.println("op3generatorfreqfixp= " + String(op3generatorfreqfixp)+";");
  Serial.println("op3detune= " + String(op3detunep)+";");
  Serial.println("op3lep= " + String(op3lep)+";");
  Serial.println("op3pich= " + String(op3pich)+";");
  Serial.println("op4volume= " + String(op4volume)+";");
  Serial.println("op4waveform= " + String(op4waveform)+";");
  Serial.println("op4generatorfreq= " + String(op4generatorfreq)+";");
  Serial.println("op4notefixed= " + String(op4notefixed)+";");
  Serial.println("op4generatorfreqfixp= " + String(op4generatorfreqfixp)+";");
  Serial.println("op4detunep= " + String(op4detunep)+";");
  Serial.println("op4lep= " + String(op4lep)+";");
  Serial.println("op4pich= " + String(op4pich)+";");
  Serial.println("op5volume= " + String(op5volume)+";");
  Serial.println("op5waveform= " + String(op5waveform)+";");
  Serial.println("op5generatorfreq= " + String(op5generatorfreq)+";");
  Serial.println("op5notefixed= " + String(op5notefixed)+";");
  Serial.println("op5generatorfreqfixp= " + String(op5generatorfreqfixp)+";");
  Serial.println("op5detunep= " + String(op5detunep)+";");
  Serial.println("op5lep= " + String(op5lep)+";");
  Serial.println("op5pich= " + String(op5pich)+";");
  Serial.println("op6volume= " + String(op6volume)+";");
  Serial.println("op6waveform= " + String(op6waveform)+";");
  Serial.println("op6generatorfreq= " + String(op6generatorfreq)+";");
  Serial.println("op6notefixed= " + String(op6notefixed)+";");
  Serial.println("op6generatorfreqfixp= " + String(op6generatorfreqfixp)+";");
  Serial.println("op6detunep= " + String(op6detunep)+";");
  Serial.println("op6lep= " + String(op6lep)+";");
  Serial.println("op6pich= " + String(op6pich)+";");
}

void pichparametertest() {
  Serial.println("pichvolume= " + String(pichvolume)+";");
  Serial.println("pichkezd= " + String(pichkezd)+";");
  Serial.println("pichal= " + String(pichal)+";");
  Serial.println("pichar= " + String(pichar)+";");
  Serial.println("pichd1l= " + String( pichd1l)+";");
  Serial.println("pichd1r= " + String(pichd1r)+";");
  Serial.println("pichd2l= " + String( pichd2l)+";");
  Serial.println("pichd2r= " + String(pichd2r)+";");
  Serial.println("pichrl= " + String(pichrl)+";");
  Serial.println("pichrr= " + String(pichrr)+";");
 /* duplicated value
  Serial.println("op1pich= " + String(op1pich)+";");
  Serial.println("op2pich= " + String(op2pich)+";");
  Serial.println("op3pich= " + String(op3pich)+";");
  Serial.println("op4pich= " + String(op4pich)+";");
  Serial.println("op5pich= " + String(op5pich)+";");
  Serial.println("op6pich= " + String(op6pich)+";");
  */
}

void programglobalvaluetest() {
  Serial.println("delaylowpasseqrighton=" +String( delaylowpasseqrighton)+";");
  Serial.println("delaylowpasseqlefton=" + String(delaylowpasseqlefton)+";");
  Serial.println("limiterlefton=" + String(limiterlefton)+";");
  Serial.println("limiterrighton=" + String(limiterrighton)+";");
  Serial.println("highpassrighteqon=" + String(highpassrighteqon)+";");
  Serial.println("parametereqrighton=" +String( parametereqrighton)+";");
  Serial.println("highpasslefteqon=" + String(highpasslefteqon)+";");
  Serial.println("parametereqlefton=" + String(parametereqlefton)+";");
  Serial.println("mastertune=" + String(mastertune)+";");
  Serial.println("szorzo=" + String(szorzo))+";";
  Serial.println("lfo2volume=" + String(lfo2volume)+";");
  Serial.println("modulation=" + String(modulation)+";");
  Serial.println("lfo2freq=" + String(lfo2freq)+";");
  Serial.println("lfo2delay=" + String(lfo2delay)+";");
  Serial.println("Q2p=" +String( Q2p)+";");
  Serial.println("Qp=" + String(Qp)+";");
  Serial.println("pareqfreq0=" + String(pareqfreq0)+";");
  Serial.println("pareqfreq1=" + String(pareqfreq1)+";");
  Serial.println("eqvalue=" + String(eqvalue)+";");
  Serial.println("chorusfreq=" + String(chorusfreq)+";");
  Serial.println("choruslevel=" + String(choruslevel)+";");
  Serial.println("delay2time=" + String(delay2time)+";");
  Serial.println("delaytime=" + String(delaytime)+";");
  Serial.println("reverbdiffusion=" + String(reverbdiffusion)+";");
  Serial.println("reverblevel=" + String(reverblevel)+";");
  Serial.println("limitgain=" + String(limitgain)+";");
  Serial.println("algorithm=" + String(algorithm)+";");
  Serial.println("alg=" + String(alg)+";");
  Serial.println("alg2=" + String(alg2)+";");
  Serial.println("frame=" + String(frame)+";");
  Serial.println("level=" + String(level)+";");
  Serial.println("oplevel=" + String(oplevel)+";");
  Serial.println("feedbacklevel=" + String(feedbacklevel)+";");
  Serial.println("pachname='" + String(pachname)+"';");
}
void envelopetest() {
  Serial.println("---ENVELOPE BEGIN---");
  Serial.println("OP envelope value:");
  Serial.println("6 piece envelope:");
  Serial.println("Uint16-t variable!");
  uint16test();
  Serial.println("2048 value!");
  Serial.println("OP envelope value:");
  openvelopetest(op1gorbe, "op1");
  openvelopetest(op2gorbe, "op2");
  openvelopetest(op3gorbe, "op3");
  openvelopetest(op4gorbe, "op4");
  openvelopetest(op5gorbe, "op5");
  openvelopetest(op6gorbe, "op6");
  Serial.println("---ENVELOPE END---");
}

void openvelopetest(uint16_t  opgorbe[], String nev) {
  Serial.print("Opgorbe: ") ;
  Serial.print(nev);
  Serial.print(" \n");
  for (int i = 0; i < GORBE_SIZE; i++)
  {
    Serial.print(opgorbe[i]);
    Serial.print(" ") ;
  }
  Serial.print("\n");
  uint16_t minopvalue = 65535;
  uint16_t maxopvalue = 0;
  for (int i = 0; i < GORBE_SIZE; i++)
  {

    if (opgorbe[i] < minopvalue)
    {
      minopvalue = opgorbe[i];
    }
    if (opgorbe[i] > maxopvalue)
    {
      maxopvalue = opgorbe[i];
    }
  }
  Serial.println("Min OP value:" + String(minopvalue));
  Serial.println("Max OP value:" + String(maxopvalue));
}

void tuningtest() {
  //tunning
  Serial.println("---TUNINGTEST BEGIN---");
  Serial.println("Uint32-t variable!");
  Serial.println("128 value");
  Serial.println("Tuning the keyboard keys:");
  Serial.println("C: " + String(noteertek[0]));
  Serial.println("Cisz: " + String(noteertek[1]));
  Serial.println("D: " + String(noteertek[2]));
  Serial.println("Disz: " + String(noteertek[3]));
  Serial.println("E: " + String(noteertek[4]));
  Serial.println("F: " + String(noteertek[5]));
  Serial.println("Fisz: " + String(noteertek[6]));
  Serial.println("G: " + String(noteertek[7]));
  Serial.println("Gisz: " + String(noteertek[8]));
  Serial.println("A: " + String(noteertek[9]));
  Serial.println("B: " + String(noteertek[10]));
  Serial.println("H: " + String(noteertek[11]));
  Serial.println("Note Array Value:");
  uint32_t minnotevalue = 2147483647;
  uint32_t maxnotevalue = 0;
  for (int i = 0; i < 127; i++)
  {
    Serial.println("Notevalue:" + String(noteertek[i]));
    if (noteertek[i] < minnotevalue)
    {
      minnotevalue = noteertek[i];
    }
    if (noteertek[i] > maxnotevalue)
    {
      maxnotevalue = noteertek[i];
    }
  }
  Serial.println("Min note value:" + String(minnotevalue));
  Serial.println("Max note value:" + String(maxnotevalue));
  Serial.println("---TUNINGTEST END---");
}


void wavetabletest() {
  Serial.println("Int16-t variable!");
  int16test();
  Serial.println("Basic waveform 1-9:");
  wavetabledatatest(sinusfg, "1 Sinus");
  wavetabledatatest(fmsinusfg, "2 SinusFM");
  wavetabledatatest(haromszogfg, "3 Triangle");
  wavetabledatatest(haromszogfg, "4 TriangleFM");
  wavetabledatatest(fureszfg, "5 SawTooth");
  wavetabledatatest(fureszfg, "6 SawToothFM");
  wavetabledatatest(negyszogfg, "7 Square");
  wavetabledatatest(negyszogfg, "8 SquareFM");
  wavetabledatatest(zajfg, "9 Noise");

  Serial.println("Wavetable 1-4:");
  wavetabledatatest(wavetable1fg, "10 Wavetable1");
  wavetabledatatest(wavetable2fg, "11 Wavetable2");
  wavetabledatatest(wavetable3fg, "12 Wavetable3");
  wavetabledatatest(wavetable4fg, "13 Wavetable4");
  Serial.println("Double and Tripla Sinus:");
  wavetabledatatest(duplafg, "14 Double");
  wavetabledatatest(triplafg, "15 Triple");
  //...
}

void wavetabledatatest(int16_t  wavetablefg[], String name) {
  Serial.print(name + ":\n");
  int16_t minvalue = 32767;
  int16_t maxvalue = -32768;
  Serial.println("short max=32,767 ");
  for (int i = 0; i < FG_SIZE; i++)
  {
    Serial.print(wavetablefg[i]);
    Serial.print(" ");
    if (wavetablefg[i] < minvalue)
    {
      minvalue = wavetablefg[i];
    }
    if (wavetablefg[i] > maxvalue)
    {
      maxvalue = wavetablefg[i];
    }
  }
  Serial.print("\n");
  Serial.println("Min value:" + String(minvalue));
  Serial.println("Max value:" + String(maxvalue));
}

void generatortest() {
  Serial.println("Int16-t variable!");
  int16test();
  Serial.println("OP generator waveform 1-6:");
  Serial.println("int16-t variable!");
  int16test();
  wavetabledatatest(generator1, "Generator 1:");
  wavetabledatatest(generator2, "Generator 2:");
  wavetabledatatest(generator3, "Generator 3:");
  wavetabledatatest(generator4, "Generator 4:");
  wavetabledatatest(generator5, "Generator 5:");
  wavetabledatatest(generator6, "Generator 6:");
}
void ptrnullaztest(byte generator) {
  Serial.println(generator);
}
