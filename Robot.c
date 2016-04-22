#include <stdio.h>
#include <time.h>

extern "C" int InitHardware();
extern "C" int SetMotor(int motor, int dir, int speed);
extern "C" int Sleep(int sec, int usec);
extern "C" int WriteDigital(int chan, char level);
extern "C" int init(int d_lev);
extern "C" int connect_to_server( char server_addr[15],int port);
extern "C" int send_to_server(char message[24]);
extern "C" int receive_from_server(char message[24]);


int motor1(){
  InitHardware();
  
  
  
  
}
