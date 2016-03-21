//Evan Kahn
//ODE Research Lab
//3/20/16

#define DAC_PIN A0
#define READ_PIN A1

int amp;
int freq;
float dlay = 0;
float x = 0;
String cmd = "";

void setup() {
  analogWriteResolution(10); // we can write bits between 0 and 1023
  analogReadResolution(12);  // we can read bits between 0 and 4096
  
  SerialUSB.begin(9600);     // data output port
  Serial1.begin(9600);       // control input port
  Serial1.println("started");
}
//http://arduino.stackexchange.com/questions/1013/how-do-i-split-an-incoming-string
void loop() {
  if (Serial1.available()){
    cmd = Serial1.readString();
    parseCMD(cmd);
  }
}
void prompt(){
  Serial1.println("Enter frequency: ");
  while (Serial1.available() == 0){}
  int freq = Serial1.parseInt();
  dlay = 8.8/(float)(freq);
  Serial1.println(dlay);
  Serial1.println("Enter amplitude: ");
  while (Serial1.available() == 0){}
  amp = Serial1.parseInt();
  Serial1.println(amp);
}

void v_out(){
  while (x < 100.0){
    int dacVoltage = (int)(511.5 + amp * sin(x) * 155.0);
    x += dlay;
    analogWrite(DAC_PIN, dacVoltage);
    float voltage = analogRead(READ_PIN)*3.3/4096.0;
    SerialUSB.println(voltage);
    delay(freq);
  }
}



