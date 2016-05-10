# Team-5DeBuggers

Week 1 Checklist:
- [x]  Ei Htoo(E2): Writing up the AVC Task Plan
- [x]  E2: Writing weekly updates/ checklists
- [x]  E2: Ensure all team members have signed the plan agreement
- [x]  Ned: Setup team GitHub repository
- [x]  Sahil: Checking each member has successfully submitted their AVC plans
- [ ]  ~~Sahil: Writing codes to get the robot to communicate with the computer~~
- [x]  Zihao: Assembling the robot
- [ ]  ~~Zihao: Develop a prototype chassis~~(he will concentrate mainly on the 3D printing, modelling and designing of the robot - he started on the 3D printing)
- [x]  Haochen(Harry): Helping zihao with the assembling of the robot
- [ ]  ~~Haryy: Physically connecting the computer to the robot~~(he was unable to do this because there was not enough time)
    

Week 1 Review (22nd Apil 2016)
- [x] Everyone this really well this week given the fact our first lab was on a Friday - so we were not able to do much. Our AVC plans were due that Friday at midnight so our main
focus was completing our AVC plans.
- [x] Everyone other than Sahil and Harry completed their assigned tasks - Sahil started on writing some some codes but did not complete and Harry had not time left to try and connect
the computer to the robot.
- [x] We have set goals for the next week(Week 2 checklist)
- [x] Sahil would try to finish writing his code
- [x] Since the following week was a mid-break, it was very difficult for any of the team members get anything/much done, as the ENGR 101 labs were not available to use. Especically, for
Harry and Zihao as they were both responsible for the hardware part of this AVC challenge. And even if Sahil and Ned had written some codes, they would be unable to go use the labs
to test if the code works.
- [x] Everyone signed the AVC plan. 





Week 2 Checklist:
- [x]   Ei Htoo(E2): Arrange team meetings/ meet-ups via facebook
- [x]   E2: Update GitHub with progress; write weekly updates/ checklists
- [ ]   ~~Ned: Create code for the camera to take a picture and measure the whiteness of the pixels, allowing the robot to move toward the white line~~(he wrote some basic codes
but he could not test them to see if his codes actually worked as the labs were closed during the mid-break)
- [x]   Sahil: Do research on SSH
- [x]   Sahil: Start writing the code to make the gate open up (he started to write basic codes after researching SSH)
- [ ]   ~~Ned: Getting the robot to move~~
- [ ]   ~~Ned: Write code to set-up the hardware and get the robot moving~~
- [ ]   ~~Harry: Assembling the robot~~ (he was unable to do this as it was mid-break and the computer labs were unavailable to for use)
- [ ]   ~~Harry: Finalised designs of the model (robot) - providing some feedback, suggestions and opinions on the final robot design~~
- [ ]   ~~Zihao: Use the 3D printer to print the path of the final design for the robot~~ (he was unable to do this because it was mid-break)


Incomplete Tasks from Week 1:
- [ ]  ~~Sahil: Writing codes to get the robot to communicate with the computer~~ (there was no time left)
- [ ]  ~~Zihao: Develop a prototype chassis~~(he still could not get this done as it was mid-break)
- [ ]  ~~Haryy: Physically connecting the computer to the robot~~(it was mid-break, so the labs were closed)


Week 2 Review:
- [x] Since the following week was a mid-break, it was very difficult for any of the team members to get anything/much done, as the ENGR 101 labs were not available to use. 
Especically, for Harry and Zihao as they are both working on the hardware part of this AVC challenge. And even if Sahil and Ned had written some codes, they would be unable to go and
test if the code works in the labs.




Week 3 Checklist: 
- [x]   E2: Check each member progress
- [ ]   ~~E2: Debug codes~~ (there was no time left)
- [x]   E2: Writing weekly updates/ checklists - Update GitHub 
- [x]   Sahil: Figure out SSH/ do SSH and upload the code.
- [ ]   ~~Ned: Develop robot movement~~(he was sick so Sahil stepped in and wrote a code to get the robot moving)
- [x]   Zihao: Make modifications to the robot design if any error were to occur during the trial runs/ experiements/ when testing if the code works
- [ ]   ~~Zihao: Modify the design~~ (he was unable to use the 3D printer as others were also using it
- [x]   Harry: Help Zihao modify the design if any errors were to pop up when running the robot
- [x]   Harry: Observe the robot when it is moving along the maze 


Incomplete Tasks from Week 1:
- [x]  Sahil: Writing codes to get the robot to communicate with the computer
- [x]  Zihao: Develop a prototype chassis
- [x]  Haryy: Physically connecting the computer to the robot (Sahil helped with this)
- [x]  Sahil: Writing codes to get the robot to communicate with the computer (SSH)


Incomplete Tasks from Week 2
- [ ]   ~~Ned: Create code for the camera to take a picture and measure the whiteness of the pixels, allowing the robot to move toward the white line~~(he wrote some basic codes
but he could not test them to see if his codes actually worked as the labs were closed during the mid-break)
- [ ]   ~~Ned: Getting the robot to move~~
- [ ]   ~~Ned: Write code to set-up the hardware and get the robot moving~~
- [x]   Harry: Assembling the robot
- [x]   Harry: Finalised designs of the model (robot) - providing some feedback, suggestions and opinions on the final robot design
- [x]  ~~Zihao: Use the 3D printer to print the path of the final design for the robot~~ (there was no time left - he had to go complete one of his assignments)


Week 3 Review:

Everyone except Ned came to the team meeting this week - where we were supposed to work on some codes and develop a prototype chassis (Ned sent his apologies due to illness).
We were able to finally get the robot moving. Sahil's code to open the gate worked successfully but.....



Week 4 Checklist:


















    
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

