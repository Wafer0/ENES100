#include "Enes100.h"
#include "Tank.h"
#include <math.h>
float x = 0;
float y = 0;
float t = 0;
bool oneA = false;
bool oneB = true;
bool oneC = false; 
bool twoA = true; 
bool twoB = false; 
bool twoC = true; 
bool v = false;
float inX = 0;
float inY = 0;
int startingPosition = 0;
/* The code inside void setup() runs only once, before the code in void loop(). */
void setup() {
  Enes100.begin("Team Name Here", CRASH_SITE, 3, 8, 9); // Required before you can use any other Enes100 functions.
  Tank.begin(); // Required before you can use any other Tank functions.
   // Set both motors to full power.
}

/* The code in void loop() runs repeatedly forever */ 
void loop() { 
  update();
  printToSystem();
  startingPosition = getStartingPosition();
  printToSystem();
  rotateFaceMission();
  printToSystem();
  travToMission();
  printToSystem();
  prepEndNav();
  printToSystem();
  endNav();
  printToSystem();
  while(1);
}

/* This is an example function to make both motors drive
 * at the given power.
 */
void setBothMotors(int speed) {
  Tank.setLeftMotorPWM(speed);
  Tank.setRightMotorPWM(speed);
}

/* Another example function that prints pi. */
void printPi() {
  Enes100.println(M_PI);  // M_PI is from the math.h library above.
}
void update() {
  Enes100.updateLocation();
  x = Enes100.location.x; 
    y = Enes100.location.y;  
  t = Enes100.location.theta * 180 / M_PI;  

}
void rotate(float targetTheta)
{ 
  float marginOfError = 2;
  if(t >= 0 && targetTheta >= 0)
  {
    if(targetTheta<t){
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         Tank.setLeftMotorPWM(100);
         Tank.setRightMotorPWM(-100);
         update();
        }
    }
    else{
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         Tank.setLeftMotorPWM(-100);
         Tank.setRightMotorPWM(100);
         update();
        }
    } 
  }
  if(t <= 0 && targetTheta <= 0)
  {
    if(targetTheta<t){
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         Tank.setLeftMotorPWM(100);
         Tank.setRightMotorPWM(-100);
         update();
        }
    }
    else{
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         Tank.setLeftMotorPWM(-100);
         Tank.setRightMotorPWM(100);
         update();
        }
    }
  }
  if((t >= 0  && targetTheta <= 0))
  {
    if(t>=90)
    {
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         Tank.setLeftMotorPWM(-100);
         Tank.setRightMotorPWM(100);
         update();
        }
    } 
    else 
    {
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         Tank.setLeftMotorPWM(100);
         Tank.setRightMotorPWM(-100);
         update();
        }
    }
    
  }
  if(t >= 0  && targetTheta <= 0)
  {
    if(t>=90)
    {
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         Tank.setLeftMotorPWM(-100);
         Tank.setRightMotorPWM(100);
         update();
        }
    } 
    else 
    {
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         Tank.setLeftMotorPWM(100);
         Tank.setRightMotorPWM(-100);
         update();
        }
    }
    
  }
  if(t <= 0 && targetTheta >= 0)
  {
    if(t<=-90)
    {
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         Tank.setLeftMotorPWM(100);
         Tank.setRightMotorPWM(-100);
         update();
        }
    } 
    else 
    {
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         Tank.setLeftMotorPWM(-100);
         Tank.setRightMotorPWM(100);
         update();
        }
    }
  }

}


void rotateFaceMission() {
  //Rotates the otv to face towards the mision
  
  if (startingPosition == 1)
    {
      if(!(t == 90))
        {
        rotate(90);
      }
    }
  if (startingPosition == 2)
  {
    if(!(t == -90))
    {
      rotate(-90);
        }
    }
}
int getStartingPosition()
{
  if(y < 1)
  {
    return 1;
  }
  else
  {
    return 2;
  }
}
void travel(float distance)
{
  float marginOfError = 0.05;
  float inX = x;
  float inY = y;
  setBothMotors(125);
  
  while(!((x < (inX + distance + marginOfError) && x > (inX + distance - marginOfError)) || (y < (inY + distance + marginOfError) && y > (inY + distance - marginOfError)) || (y < (inY - distance + marginOfError) && y > (inY - distance - marginOfError))))
  {
     update();
  }
  Tank.turnOffMotors();
}
void travToMission() {
  
  travel(0.3);
  update();
  travel(0.3);
  update();
}

void prepEndNav() {
  
  rotate(0);
   update();

  travel(0.25);
   update();

  if(startingPosition == 1)
  {
    rotate(-90);
    update();
  }
  else
  {
    rotate(90);
    update();
  }
  
  travel(0.3);
  update();

  rotate(0);
  update();
}
void endNav(){
  if((oneB && twoA && twoC) || (twoC && oneB && oneA))
  {

    rotate(-90);
    travel(0.6);
    rotate(0);
    travel(1.3);
    rotate(90);
    travel(0.6);
    rotate(0);
    travel(1.1);
    rotate(-90);
    travel(0.6);
    rotate(0);
    travel(1.1);
  travel(0);
  }

  if((oneA && twoB && oneC) || (oneC && twoA && twoB))
  {
    travel(1.3);
    rotate(-90);
    travel(0.6);
    rotate(0);
    travel(2.5);
  travel(0);
  }

  if(oneA && twoB && twoC)
  {
    travel(1.3);
    rotate(90);
    travel(0.6);
    rotate(0);
    travel(1.3);
    rotate(-90);
    travel(0.6);
    rotate(0);
    travel(1.1);
  travel(0);
  }

  if(twoA && oneB && twoC)
  { 
    rotate(90);
    travel(0.6);
    rotate(0);
    travel(1.1); 
    rotate(-90);
    travel(0.6);
    rotate(0);
    travel(1.3);
    rotate(-90);
    travel(0.6);
    rotate(0);
    travel(1.1);
  travel(0);
  }
}


void printToSystem()
{
    Enes100.print("X cordinate: ");
    Enes100.println(x); 
    Enes100.print("Y cordinate: ");
    Enes100.println(y);
    Enes100.print("Angle: ");
    Enes100.println((int)t);
    Enes100.print("Starting Position: ");
    Enes100.println(startingPosition);
}
