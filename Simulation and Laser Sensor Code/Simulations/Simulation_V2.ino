#include "Enes100.h"
#include "Tank.h"
#include <math.h>
float x = 0;
float y = 0;
float t = 0;
bool oneA = true;
bool twoA = false;
bool oneB = false; 
bool twoB = true; 
bool oneC = true; 
bool twoC = false; 
bool v = false;
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
	rotateFaceMission();
    delay(2000);

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
  	printPi();
	Enes100.updateLocation();
	x = Enes100.location.x; 
    y = Enes100.location.y;  
	t = Enes100.location.theta * 180 / M_PI;  
	startingPosition = getStartingPosition();
    Enes100.print(x); 
    Enes100.print(",");
    Enes100.print(y);
    Enes100.print(",");
    Enes100.println(t);
    Enes100.print(",");
	Enes100.print(startingPosition);
}
void rotate(float targetTheta)
{
  while(!((t < targetTheta + 5  && t > targetTheta - 5)))
  {
    Tank.setLeftMotorPWM(125);
    Tank.setRightMotorPWM(-125);
    update();
  }
  Tank.turnOffMotors();
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
