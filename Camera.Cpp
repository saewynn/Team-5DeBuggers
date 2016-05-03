#include <stdio.h>
#include <time.h>

extern "C" int init(int d_lev);
extern "C" int Sleep( int sec, int usec);
extern "C" int set_motor(int dir, int motor, int speed);
extern "C" int get_pixel(int pixel, int pixel, int pixel);
extern "C" int take_picture();
extern "C" int display_picture(int delay_sec,int delay_usec);
extern "C" int open_screen_stream();
extern "C" int close_screen_stream();
extern "C" int update_screen();


int main(){
//initalises the hardware and ensures it is working correctly
init(0);

//sets a variable for the centre of the picture
char wc;
//sets a variable for the left side of the picture
char wl;
//sets a variable for the right side of the picture
char wr;

//connects the camera to the screen
open_stream_screen();

while(true){
  take_picture();
  //checks the whiteness of the center pixel
  wc = get_pixel(160,120,3);
  //prints the value obtained
  printf("%d\n",wc);
  //checks the whiteness of the left center pixel
  wl = get_pixel(80,60,3);
  //prints the value obtained
  printf("%d\n",wl);
  //checks the whiteness of the right center pixel
  wr = get_pixel(240,180,3);
  //prints the value obtained
  printf("%d\n",wr);
  
  if (wl > wc){
  turn_left();
  }else if (wr > wc){
  turn_right();
  }else{
  keep_foward();
  }
  
  //puts new picture on the screen
  update_screen();
  Sleep(0,1000000);
}
close_screen_stream();
  
}

//need to test with the camera and robot, 
//then I can create the variables for turn_left and turn_right
//after this is done, I can set-up the motor to turn towards the whiter side of the picture
//once all of that is complete, I will refine the code using the method from the lecute
//Multiplying ‘whiteness’ by pixel location and sum the result.
