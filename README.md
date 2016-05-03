# Team-5DeBuggers

Week 1 Checklist:
- [x]   Ei Htoo(E2): Writing up the AVC Task Plan
- [x]   E2: Writing weekly updates/ checklists
- [x]   E2: Ensure all team members have signed the plan agreement
- [x]   Ned: Setup team GitHub repository
- [x]   Sahil: Checking each member has successfully submitted their AVC plans
- [ ]   ~~Sahil: Writing codes to get the robot to communicate with the computer~~
- [ ]   ~~Haochen(Harry): Physically connecting the computer to the robot~~(he will now mainly focus on assembling the robot - he was unable to do a lot because our team's first lab was on Friday)
- [ ]   ~~Zihao: Assembling the robot – develop a prototype chassis~~(he will concentrate mainly on the 3D printing, modelling and designing of the robot - he was unable to do much but he started on the 3D printing)

NOTE: Harry and Zihao's roles are now switched





Week 2 Checklist:
- [x]   Ei Htoo(E2): Arrange team meetings/ meet-ups via facebook
- [x]   E2: Update GitHub with progress; write weekly updates/ checklists
- [x]   Ned: Create code for the camera to take a picture and measure the whiteness of the pixels, allowing the robot to move toward the white line
- [x]   Ned: Getting the robot to move and also helping Sahil with SSH
- [x]   Ned: Write code to set-up the hardware and get the robot moving
- [x]   Sahil: Do research on SSH
- [ ]   ~~Sahil: Start writing the code to make the gate open up~~
- [ ]   ~~Harry: Assembling the robot~~ (he was unable to do this as it was mid-break and the computer labs were unavailable to for use)
- [ ]   ~~Harry: Finalised designs of the model (robot) - providing some feedback, suggestions and opinions on the final robot design~~ (the robot has not been assembled yet)
- [ ]   ~~Zihao: Use the 3D printer to print the path of the final design for the robot~~ (he was unable to do this because it was mid-break)


Incomplete Tasks from Week 1:
- [ ]  ~~Sahil: Writing codes to get the robot to communicate with the computer~~





Week 3 Checklist:
- [x]   E2: Writing weekly updates/ checklists
- [x]   E2: Check each team member progress 
- [x]   Sahil:Do SSH and upload code
- [x]   Ned: Create code for the camera to take a picture and measure the whiteness of the pixels, allowing the robot to move toward the white line.
- [ ] Ned: Develop robot movement










    
1st code:
Self note:
Motor is left, right
Direction is forward and back
Speed is from 0-255

My code is:

#include <stdio.h>
#include <time.h>

extern "C" int InitHardware();

extern "C" int Sleep(int sec, int usec);
extern "C" int SetMotor(int motor, int dir, int speed);

int main(){

InitHardware();

SetMotor (1, 1, 100);
SetMotor (2, 1,255);
Sleep(0,500000);

SetMotor(1, 1, 255);
SetMotor(2, 1, 100);
Sleep(0,500000);

return 0;}

