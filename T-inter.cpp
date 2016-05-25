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

  
    while(1){

       take_picture();
       int pixelval = 0;
       int num = 0;
       int error=0;
       int s;
       bool left = false;
       bool straight = false;
       bool right = false;
       

       for(int x = 0; x < 320; x++){
            pixelval = get_pixel(x,120,3);
            if(pixelval > 127){ 
              // pixel white
              s = 1;
              if ( x =< 80){
                  left = true;
              }else if{ x >= 140 && x <= 200){
                  straight = true;
              }else if(x >= 280){
                  right = true
              }
            }
            else{
              //pixel black
                s = 0;
            }
            error = error+(x-160)*s;
            num = num + s;
         }

         printf("error=%d\n",error);
         printf("num= %d\n",num);
if(num<150){
         if(num>0){ 
              // at least one white pixel
              printf("Forward\n");
              error=error/num;

              //printf("%d\n", pixelval);
              //error=error/num; 
              int v1 = -90 + 0.75*error;  
              int v2 = -90 - 0.75*error;
              printf("v1 = %d v2 = %d\n",v1,v2); 
              set_motor(1,v1);
              set_motor(2,v2);
          }else{
              // no white pixels at all
              printf("Backing\n");
              //we need to change this so instead of backing, it will turn around.
              set_motor(1,0);
              set_motor(2,90);
          }
          Sleep(0,400000);  
          
//may need to write methods about if some are wrong and some are false?? I have no clue.
}else if(num>150){
printf("T-intersection\n")
// all we need to do is code it, so that it prioritses turning left > straight > right.
if (left && straight && right){
    //turn left
}else if(left && straight){
    //turn left
}else if(left && right){
    //turn left
}else if(left){
    //turn left
}else if(straight && right){
    //go straight
}else if(straight){
    //go straight
}else if(right){
    //go right
}
}
}
}
         }// while

            return 0;
