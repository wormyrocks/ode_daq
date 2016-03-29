//Evan Kahn
//ODE Research Lab
//3/20/16

#define DAC_PIN A0
#define READ_PIN A1
#define CMD_BYTES 32

#include "waveforms.h"
#define oneHzSample 1000000/maxSamplesNum

int amp;
int freq;
float dlay = 0;
float x = 0;
char cmd[CMD_BYTES] = {};
int y = 0;

void setup() {
  analogWriteResolution(10); // we can write bits between 0 and 1023
  analogReadResolution(12);  // we can read bits between 0 and 4096
  SerialUSB.begin(9600);     // data output port
}
//http://arduino.stackexchange.com/questions/1013/how-do-i-split-an-incoming-string
void loop() {
  while (SerialUSB.available() == 0) {}
  SerialUSB.readBytes(cmd, CMD_BYTES);
  parseCMD(cmd);
}

void parseCMD(char* cmd) {

  char type;
  char val_1[2];

  cpsection(cmd, &type, 0, 2);
  cpsection(cmd, val_1, 2, 4);
  
}

void cpsection(char* in1, char* in2, unsigned start, unsigned size){
  unsigned i = 0;
  while (i < size){
    in2[i] = in1[i+start];
    ++i;
  }
}

