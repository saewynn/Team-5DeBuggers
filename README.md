# Team-5DeBuggers

Week 1 Checklist:
- [x]   Ei Htoo(E2): Writing up the AVC Task Plan.
- [ ]   E2: Writing weekly updates/ checklists.
- [ ]   E2: Ensure all team members have signed the plan agreement.
- [ ]   Ned: Setup team GitHub repository.
- [ ]   Sahil: Checking each member has successfully submitted their AVC plans.
- [ ]   Sahil: Writing codes to get the robot to communicate with the computer.
- [ ]   Haochen(Harry): Physically connecting the computer to the robot (he is now also going to assemble the robot).
- [ ]   Zihao: Assembling the robot – develop a prototype chassis (he will concentrate mainly on the 3D printing, modelling and designing of the robot.

Week 2 Checklist:
- [ ]   Ei Htoo(E2): Arrange team meetings/ meet-ups via facebook
- [ ]   E2: Writing weekly updates/ checklists
- [ ]   E2: Ensure all team members have signed the plan agreement
- [ ]   E2: Arrange te
- [ ]   Ned: Setup team GitHub repository
- [ ]   Sahil: Checking each member has successfully submitted their AVC plans
- [ ]   Sahil: Writing codes to get the robot to communicate with the computer
- [ ]   Haochen(Harry): Physically connecting the computer to the robot (he is now also going to assemble the robot)
- [ ]   Zihao: Assembling the robot – develop a prototype chassis (he will concentrate mainly on the 3D printing, modelling and designing         of the robot.



    
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

