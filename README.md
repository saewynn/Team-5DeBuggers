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
- [ ]   ~~Ned: Create code for the camera to take a picture and measure the whiteness of the pixels, allowing the robot to move toward the white line~~
- [x]   Sahil: Do research on SSH
- [ ]   ~~Ned: Getting the robot to move~~
- [ ]   ~~Ned: Write code to set-up the hardware and get the robot moving~~

- [ ]   ~~Sahil: Start writing the code to make the gate open up~~
- [ ]   ~~Harry: Assembling the robot~~ (he was unable to do this as it was mid-break and the computer labs were unavailable to for use)
- [ ]   ~~Harry: Finalised designs of the model (robot) - providing some feedback, suggestions and opinions on the final robot design~~ (the robot has not been assembled yet)
- [ ]   ~~Zihao: Use the 3D printer to print the path of the final design for the robot~~ (he was unable to do this because it was mid-break)


Incomplete Tasks from Week 1:
- [ ]  ~~Sahil: Writing codes to get the robot to communicate with the computer~~

We 











Week 3 Checklist: 
- [x]   E2: Writing weekly updates/ checklists - Update GitHub
- [ ]   ~~E2: Debug codes~~
- [x]   E2: Check each team member progress 
- [x]   Sahil: Figure out SSH 
- [ ]   ~~Ned: Create code for the camera to take a picture and measure the whiteness of the pixels, allowing the robot to move toward the white line~~
- [ ]   ~~Ned: Develop robot movement~~
- [x]   Harry: Make modifications to the robot design if any errors were to occur
- [ ]   ~~Harry: Observe the robot when it is moving along the maze~~ (we have not tried 
- [ ]   Zihao modify the design if any errors pop up and develop the design.



Incomplete Task from Week 1:


- [x]  Sahil: Writing codes to get the robot to communicate with the computer (SSH)



Incomplete Tasks from Week 2

- [x] Sahil: Start writing the code to make the gate open up
- [ ]   ~~Ned: Getting the robot to move~~
- [ ]   ~~Ned: Write code to set-up the hardware and get the robot moving~~
- [x]   Harry: Assembling the robot
- [ ]   ~~Harry: Finalised designs of the model (robot) - providing some feedback, suggestions and opinions on the final robot design (Sahil also contributed to this as well)
- [x]   Zihao: Use the 3D printer to print the path of the final design for the robot (he 3D printed the for the remaining 


    
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

