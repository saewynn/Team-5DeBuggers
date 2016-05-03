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
  wc = get_pixel(320,240,3);
  //prints the value obtained
  printf("%d\n",wc);
  
  //puts new picture on the screen
  update_screen();
  Sleep(0,1000000);
}
close_screen_stream();
  
}

//need to test with the camera and robot, 
//then I can work on getting checks on pixels on the left and right side of the picture
//once this is done, I can set-up the motor to turn towards the whiter side of the picture
