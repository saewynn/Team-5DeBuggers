
#include <unistd.h>
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
printf("My process ID : %d\n", getpid());
    connect_to_server("130.195.6.196", 1024);
   send_to_server("Please");
   char message[24];
   receive_from_server(message);
   printf("%s", message);
   send_to_server(message);
    while(1){

       take_picture();
       int pixelval = 0;
       int num = 0;
       int error=0;
       int s;
        int leftpix=0;
        int centerpix=0;
        int rightpix=0;
        int forwardpix=0;
        int numL=0;
        int numR=0;
        int numC=0;
        int numF=0;
        
        

       
        for(int x = 0; x <20 ; x++){        //LEft pixels 0-10
            pixelval = get_pixel(x,120,3);
            if(pixelval > 80){
              // pixel white
              numL = 1;
            }
            else{
              //pixel black
                numL = 0;
            }

            leftpix = leftpix + numL;
         }

        for(int x = 165; x <175 ; x++){        //Center pixels 155-165
            pixelval = get_pixel(x,120,3);
            if(pixelval > 80){
              // pixel white
              numC = 1;
            }
            else{
              //pixel black
              numC = 0;
            }

            centerpix = centerpix + numC;
         }

        for(int x = 300; x <320 ; x++){        //Right pixels 310-320
            pixelval = get_pixel(x,120,3);
            if(pixelval > 80){
              // pixel white
              numR = 1;
            }
            else{
              //pixel black
              numR = 0;
            }

            rightpix = rightpix + numR;
         }

        for(int x = 0; x <30 ; x++){        //Going Downn camera Y
            pixelval = get_pixel(150,x,3);      //To check if there is a line ahead
            if(pixelval > 80){
              // pixel white
              numF = 1;
            }
            else{
              //pixel black
              numF = 0;
            }

            forwardpix = forwardpix + numF;
         }

        printf("num=%d\n", num);
        printf("center=%d\n", centerpix);
        printf("error=%d\n",error);
        printf("forward=%d\n",forwardpix);
        printf("Left=%d\n",leftpix);
        printf("Right=%d\n",rightpix);


if(centerpix>7 && leftpix>7 && rightpix>7 && forwardpix>25){
printf("Intersection++++++++++++++++++++++++++++++++++\n");
set_motor(1,-200);
set_motor(2,-200);

Sleep(0,500000);



}else if(centerpix>7 && leftpix>7 && rightpix>7 && forwardpix<25){
printf("TInter===================================\n");
set_motor(1,-150);
set_motor(2,-150);
Sleep(0,500000);
set_motor(1,-150);
set_motor(2,150);

Sleep(1,00000);



}else if(centerpix>7 && leftpix>7 && rightpix==0 && forwardpix<15){
printf("left\n");
set_motor(1,-150);
set_motor(2,-150);
Sleep(0,500000);
set_motor(1,-150);
set_motor(2,150);

Sleep(1,00000);



}else if(centerpix>7 && rightpix>7 && leftpix==0 && forwardpix<15){
printf("right\n");
set_motor(1,-200);
set_motor(2,-200);
Sleep(0,500000);
set_motor(1,150);
set_motor(2,-150);

Sleep(1,00000);




}else{
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
            error = error+(x-160)*s;
            num = num + s;
            }
            
         if(num>0){
              // at least one white pixel
              printf("Forward\n");
              error=error/num;

              //printf("%d\n", pixelval);
              //error=error/num;
              int v1 = -90 + 0.82*error;
              int v2 = -90 - 0.82*error;
              printf("v1 = %d v2 = %d\n",v1,v2);
              set_motor(1,v1);
              set_motor(2,v2);
          }else{
              // no white pixels at all
              printf("Backing\n");
              set_motor(1,80);
              set_motor(2,80);
          }
          Sleep(0,500000);
}

printf("////////////////// \n");
}// while

            return 0;}
          

/*            
void stop(){
set_motor(1,0);
set_motor(2,0);
Sleep(0,500000);
}
            
void turnLeft(){
set_motor(1,-100);
set_motor(2,100);
Sleep(0,500000);
}            
            
void turnRight(){
set_motor(1,100);
set_motor(2,-100);
Sleep(0,500000);
}            
            
void goStraight(){
set_motor(1,-100);
set_motor(2,-100);
Sleep(0,500000);
}
void goBack(){
set_motor(1,90);
set_motor(2,90);
Sleep(0,500000);
}
    



/*
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
       int leftnum=0;
       int straightnum=0;
       int rightnum=0;
       bool left = false;
       bool straight = false;
       bool right = false;
       

       for(int x = 0; x < 320; x++){
            pixelval = get_pixel(x,120,3);//middle
            if(pixelval > 127){ 
              // pixel white
              s = 1;
              if ( x =< 80){
                  leftnum = leftnum+s;
              }else if{ x >= 140 && x <= 200){
                  straightnum = strightnum+s;
              }else if(x >= 280){
                  rightnum = rightnum+s;
              }
            }
            else{
              //pixel black
                s = 0;
            }
            error = error+(x-160)*s;
            num = num + s;
         }
         
         if(leftnum>10){
            left=true; 
         }
         if(straightnum>10){
            straight=true; 
         }
         if(rightnum>10){
            right=true; 
         }
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
}else if(num=240){
printf("T-intersection\n");


// all we need to do is code it, so that it prioritses turning left > straight > right.
if (left && straight && right){
    turnLeft();
}else if(left && straight){
    turnLeft();
}else if(left && right){
    turnLeft();
}else if(left){
    turnLeft();
}else if(straight && right){
    goStraight();
}else if(straight){
    goStraight();
}else if(right){
    turnRight();
}
}
}
}
         }// while

            return 0;}
void stop(){
SetMotor(1,0);
SetMotor(2,0);
Sleep(0,500000);
}
            
void turnLeft(){
SetMotor(1,-90);
SetMotor(2,90);
Sleep(0,500000);
}            
            
void turnRight(){
SetMotor(1,90);
SetMotor(2,-90);
Sleep(0,500000);
}            
            
void goStraight(){
SetMotor(1,-90);
SetMotor(2,-90);
Sleep(0,500000);
}
*/

