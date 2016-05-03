#include <stdio.h>
#include <time.h>

extern "C" int InitHardware();
extern "C" int SetMotor(int motor, int dir, int speed);
extern "C" int Sleep(int sec, int usec);
extern "C" int WriteDigital(int chan, char level);
extern "C" int ReadAnalog (int ch_adc);


int main(){
InitHardware();
int adc_reading = ReadAnalog(0);
printf("%d\n",adc_reading);
while(1){
adc_reading = ReadAnalog(0);

if (adc_reading > 50){
SetMotor(1,1,255);
SetMotor(2,1,255);
Sleep(1,500000);
}
else{
SetMotor(1,1,0);
SetMotor(2,1,0);
}
}
return;
}
