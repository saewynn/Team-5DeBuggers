#include <stdio.h>
#include <time.h>
#include <string.h>

extern "C" int init_hardware();
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
  
  connect_to_server("130.195.6.196", 1024); //Opening the gate code
   send_to_server("Please");
   char message[24];
   receive_from_server(message);
   printf("%s", message);
   send_to_server(message);
   
  open_screen_stream();
  
  

   
  
  
  
  
   for (x = 0; x < 8; x++)
    {
      select_IO(x,0);
      write_digital(x,1);
    }
    while(1){
       take_picture();
       int sum = 0;
       float kp = 0.5;
       int ,w ,s;
       for(int x = 0; x < 320; x++){
            w = get_pixel(x,120,3);
       if (w>127){s=1;};
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
            else(){
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
    close_screen_stream();
    set_motor(1,0);
    set_motor(2,0);
  
    return 0;
}

//To be completely honest, I have no idea what is going on in this code. But we did run the code as the gate opened so it should be fine
#include <time.h>
#include <string.h>
#include <stdio.h>

extern "C" int init_hardware();
extern "C" int init(int d_lev);

extern "C" int Sleep(int sec, int usec);

extern "C" int take_picture();
extern "C" char get_pixel(int row, int col, int color);
extern "C" void set_pixel(int col, int row, char red,char green,char blue);

extern "C" int open_screen_stream();
extern "C" int close_screen_stream();
extern "C" int update_screen();      //the pics that camera takes can only be seen on the computer screen if we use wire to connect the robot with computer
extern "C" int display_picture(int delay_sec,int delay_usec);
extern "C" int save_picture(char filename[5]);

extern "C" int set_motor(int motor,int speed);

int main() {
  //Initialises hardware
  init(0);
  
  int total_error = 0;
  int error_period = 0.2;
  int previous_error = 0;
  int speed = 45;
  
  //Initilises the camera display on the desktop
  open_screen_stream();

  while(1) {
    take_picture();

    int sum = 0;

    float kp = 0.5;                  //this can be tuned in the future to produce an acceptable response
    float ki = 0;                    //this should initially be 0, and changed after testing
    float kd = 0;                    //this should initially be 0, and changed after testing

    int proportional_signal = 0;  
    int integral_signal = 0;
    int derivative_signal = 0;
    
    int error_difference = 0;
  
    int brightness = 0;              //to store the brightness value of the scanned pixel
    int pixel_type = 0;              //0 is a black pixel and 1 is a white pixel (on the line)

    for(int i = 0, i < 320, i++) {
      brightness = get_pixel(i, 120, 3);
      if(brightness > 127) {
        pixel_type = 1;
      }
      else {
        pixel_type = 0;
      }
      sum = sum + (i - 160)*pixel_type;
    }
    
    total_error = total_error + sum;
    error_difference = sum - previous_error;
    
    previous_error = sum;

    proportional_signal = sum*kp;
    integral_signal = total_error*ki;
    derivative_signal = (error_difference/error_period)*kd;
    
    signal_sum = proportional_signal + integral_signal + derivative_signal;

    set_motor(1, speed + signal_sum);
    set_motor(2, speed + signal_sum);
    
    Sleep(0,200000);
  }
  return 0;
}
