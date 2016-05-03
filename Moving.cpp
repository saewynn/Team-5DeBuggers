#include <stdio.h>
#include <time.h>

extern "C" int init(int d_lev);
extern "C" int set_motor(int motor, int speed);
extern "C" int Sleep(int sec, int usec);
extern "C" int write_digital(int chan, char level);
extern "C" int read_analog (int ch_adc);


int main(){
init(1);

set_motor(1,127);
Sleep(0,50000);
set_motor(2,127);
Sleep(0,50000);

return 0;}
