#include <Tank.h>
#include <Enes100.h>
#include <math.h>
#include "Tank.h"

float x = 0;
float y = 0;
float t = 0;
bool oneA = false;
bool twoA = false;
bool oneB = false; 
bool twoB = false; 
bool oneC = false; 
bool twoC = false; 
bool v = false;
int startingPosition = 1;

void setup() { 
 	Enes100.begin("MikeIsTheImposter", DATA, 3, 8, 9); // Required before you can use any other Enes100 functions.
	Tank.begin(); // Required before you can use any other Tank functions.
}

void loop() {
  x = Enes100.getX();  // Your X coordinate! 0-4, in meters, -1 if no aruco is not visibility (but you should use Enes100.isVisible to check that instead)
  y = Enes100.getY();  // Your Y coordinate! 0-2, in meters, also -1 if your aruco is not visible.
  t = Enes100.getTheta();  //Your theta! -pi to +pi, in radians, -1 if your aruco is not visible.
  v = Enes100.isVisible(); // Is your aruco visible? True or False.
  
  //Prints the x, y, theta, and if the vehicle is visible
  update();
  
  //Rotates the otv to face towards the mission
  rotateFaceMission();

  //Makes the otv travel to the mission make three stops and determines where each object is
  travToMission();

  //Does the mission
  mission();

  //Brings the otv from the mission to the position it needs too be to start end navigation
  prepEndNav();

  //Based on where the obsticle is it will decide which of the four paths it will take to reach the end
  endNav();
}
