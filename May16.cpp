#include <stdio.h>
#include <time.h>
#include <string.h>

extern "C" int init(int d_lev);
extern "C" int display_picture(int delay_sec,int delay_usec);
extern "C" int save_picture(char filename[5]);
extern "C" int set_motor(int motor,int speed);
extern "C" int select_IO(int chan, int direct);
extern "C" int read_analog(int ch_adc);
extern "C" int Sleep(int sec, int usec);
extern "C" int write_digital(int chan,char level);
extern "C" int read_digital(int chan);
extern "C" int set_PWM(int chan, int value);
extern "C" int connect_to_server( char server_addr[15],int port);
extern "C" int send_to_server(char message[24]);
extern "C" int receive_from_server(char message[24]);
extern "C" int take_picture();
extern "C" char get_pixel(int row, int col, int color);
extern "C" void set_pixel(int col, int row, char red,char green,char blue);
extern "C" int open_screen_stream();
extern "C" int close_screen_stream();
extern "C" int update_screen();



int main(){

  init(0);
  int x;
  
   for (x = 0; x < 8; x++)
    {
      select_IO(x,0);
      write_digital(x,1);
    }
    while(1){
       take_picture();
       int pixelval = 0;
       int num = 0;
       int error=0;
       
       for(int x = 0; x < 320; x++){
            pixelval = get_pixel(120,x,3);
            error = pixelval - 160;
            printf(pixelval);
            num++;
            }
            if(num>0){
            error=error/num;
            }else{
            set_motor(1,-25);
            set_motor(1,-25);
            }
            
            set_motor(1,65+0.1*error);
            set_motor(2,65-0.1*error);
            }
            sleep(0,1000000);
            
            return;
            }
