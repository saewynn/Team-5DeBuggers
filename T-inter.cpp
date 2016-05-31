

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


    while(1){

       take_picture();
       int pixelval = 0;
       int num = 0;
       int error=0;
       int s;
        int leftpix;
        int centerpix;
        int rightpix;
        int forwardpix;

       for(int x = 0; x < 320; x++){
            pixelval = get_pixel(x,120,3);
            if(pixelval > 127){
              // pixel white
              s = 1;
            }
            else{
              //oixel black
                s = 0;
            }
            }
        for(int x = 0; x <10 ; x++){        //LEft pixels 0-10
            pixelval = get_pixel(x,120,3);
            if(pixelval > 127){
              // pixel white
              leftpix = 1;
            }
            else{
              //pixel black
                leftpix = 0;
            }

            leftpix = leftpix + s;
         }

        for(int x = 155; x <165 ; x++){        //Center pixels 155-165
            pixelval = get_pixel(x,120,3);
            if(pixelval > 127){
              // pixel white
              centerpix = 1;
            }
            else{
              //pixel black
              centerpix = 0;
            }

            centerpix = centerpix + s;
         }

        for(int x = 310; x <320 ; x++){        //Right pixels 310-320
            pixelval = get_pixel(x,120,3);
            if(pixelval > 127){
              // pixel white
              rightpix = 1;
            }
            else{
              //pixel black
              rightpix = 0;
            }

            rightpix = rightpix + s;
         }

        for(int x = 120; x <240 ; x++){        //Going Downn camera Y
            pixelval = get_pixel(160,x,3);      //To check if there is a line ahead
            if(pixelval > 127){
              // pixel white
              forwardpix = 1;
            }
            else{
              //pixel black
              forwardpix = 0;
            }

            forwardpix = forwardpix + s;
         }

        printf("num=%d\n", num);
        printf("center=%d\n", centerpix);
         printf("error=%d\n",error);

if(centerpix>7 && leftpix==0 and rightpix==0){
         if(num>0){
              // at least one white pixel
              printf("Forward\n");
              error=error/num;

              //printf("%d\n", pixelval);
              //error=error/num;
              int v1 = -90 + 0.8*error;
              int v2 = -90 - 0.8*error;
              printf("v1 = %d v2 = %d\n",v1,v2);
              set_motor(1,v1);
              set_motor(2,v2);
          }else{
              // no white pixels at all
              printf("Backing\n");
              set_motor(1,90);
              set_motor(2,90);
          }
          Sleep(0,500000);
}else if(centerpix>7 && leftpix>7 && rightpix>7 && forwardpix>20){
set_motor(1,-85);
set_motor(2,-85);
printf("Intersection\n");

Sleep(0,500000);
}else if(centerpix>7 && leftpix>7 && rightpix>7 && forwardpix==0){
set_motor(1,100);
set_motor(2,-100);
printf("TInter\n");

Sleep(0,500000);
}else if(centerpix>7 && leftpix>7 && rightpix==0){
set_motor(1, 100);
set_motor(2,-100);
printf("left\n");

Sleep(0,500000);
}else if(centerpix>7 && rightpix>7 && leftpix==0){
set_motor(1, -100);
set_motor(2,100);
printf("right\n");

Sleep(0,500000);
}





}// while

            return 0;
}




