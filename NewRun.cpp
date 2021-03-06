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
  init(1);
  int x;

  connect_to_server("130.195.6.196", 1024); //Opening the gate code
   send_to_server("Please");
   char message[24];
   receive_from_server(message);
   printf("%s", message);
   send_to_server(message);



   for (x = 0; x < 8; x++)
    {
      select_IO(x,0);
      write_digital(x,1);
    }
    while(1){
       take_picture();
       int sum = 0;
       float kp = 0.5;
       int w;
       int s;
       int proportional_signal=0;
       for(int x = 0; x < 320; x++){
            w = get_pixel(x,120,3);
       if(w>127){s=1;}
       else{s=0;};
       sum = sum + (x-160)*s;}
       proportional_signal = sum * kp;
            if (sum < 0){
                set_motor(1, proportional_signal);
                set_motor(2, -1*proportional_signal);
            }
            else if (sum > 0){
                set_motor(1, -1*proportional_signal);
                set_motor(2, proportional_signal);
            }
            else{
                 set_motor(1, proportional_signal);
                set_motor(2,  proportional_signal);
            }
       update_screen();

       for (x = 0 ; x < 8; x++)
       {
       int adc_reading = read_analog(x);
       printf("ai=%d av=%d\n",x,adc_reading);
       }
     }

    set_motor(1,0);
    set_motor(2,0);

    return 0;
}
