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
    
    int numC=0;
    int numL=0;
    int numF=0;
    int numR=0;
    int Fmax;
    int Fmin;
    int Cmax;
    int Cmin;
    
    for(int x = 0; x < 320; x++){        //scan top
      pixelval = get_pixel(x,160,3);
      if(pixelval > 80){
        // pixel white
        if(x>Fmax){
          Fmax=x;
         }else if(x<Fmin){
          Fmin=x;
         }
        numF = 1;
      }else{
        //pixel black
        numF = 0;
      }
    forwardpix = forwardpix + numF;
    }
    
    for(int x = 0; x <320 ; x++){        //scan center
      pixelval = get_pixel(x,120,3);
      if(pixelval > 80){
       // pixel white
       if(x>Cmax){
          Cmax=x;
        }else if(x<Cmin){
          Cmin=x;
        }
       numC = 1;
      }else{
       //pixel black
       numC = 0;
      }
      centerpix = centerpix + numC;
    }
    
    for(int i=0;i<240;i++){
      pixelval = get_pixel(50,i,3);
      if(pixelval > 80){
          // pixel white
          numL = 1;
      }else{
          //pixel black
          numL = 0;
      }
      leftpix = leftpix + numL;
    }
    
    for(int i=0;i<240;i++){
      pixelval = get_pixel(320,i,3);
      if(pixelval > 80){
          // pixel white
          numR = 1;
      }else{
          //pixel black
          numR = 0;
      }
      rightpix = rightpix + numR;
    }
    
    printf("num=%d\n", num);
    printf("center=%d\n", centerpix);
    printf("error=%d\n",error);
    printf("forward=%d\n",forwardpix);
    printf("Left=%d\n",leftpix);
    printf("Right=%d\n",rightpix);
    
    if(forwardpix>0){
      printf("ForwardFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF\n");
      int Fmean=(Fmax+Fmin)/2;
      int Cmean=(Cmax+Cmin)/2;
      error=40/(Fmean-Cmean);
      int v1 = -90 + 0.8*error;
      int v2 = -90 - 0.8*error;
      printf("v1 = %d v2 = %d\n",v1,v2);
      set_motor(1,v1);
      set_motor(2,v2);
      Sleep(0,500000);
    }else{
      // no white pixels at all
      printf("Backing\n");
      set_motor(1,90);
      set_motor(2,90);
      Sleep(0,500000);
    }
    
    if(forwardpix<5 && leftpix>10 && rightpix>10 && centerpix>10){
      printf("TInter===================================\n");
      set_motor(1,100);
      set_motor(2,-100);
      Sleep(1,0);
    }
    
    printf("////////////////// \n");
  }
return 0;}
