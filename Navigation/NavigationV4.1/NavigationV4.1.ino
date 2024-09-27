#include <Tank.h>
#include <Enes100.h>
#include <math.h>

// Cordinate Variables
float x = 0;
float y = 0;
float t = 0;
bool v = false;
int startingPosition = 0;

// Obsticle Position Variables
bool oneA = true;
bool oneB = false;
bool oneC = true; 
bool twoA = false; 
bool twoB = true; 
bool twoC = false; 

// Travel Holding Varibales
float inX = 0;
float inY = 0;

// Motor Pins

const int PIN_MOTOR_1_FORWARD = 0;
const int PIN_MOTOR_1_REVERSE = 0;
const int PIN_MOTOR_2_FORWARD = 0;
const int PIN_MOTOR_2_REVERSE = 0;
const int PIN_MOTOR_3_FORWARD = 0;
const int PIN_MOTOR_3_REVERSE = 0;
const int PIN_MOTOR_4_FORWARD = 0;
const int PIN_MOTOR_4_REVERSE = 0;

void setup() { 
 	delay(2000);
  Enes100.begin("MikeIsTheImposter", DATA, 15, 52, 50); // Required before you can use any other Enes100 functions.
	delay(2000);
  beginMotors();
  Tank.begin(); // Required before you can use any other Tank functions.
}

void loop() {
  // Updates Cordinate Varibles
  update();

  // Updates Starting Position Varibale
	startingPosition = getStartingPosition();

  // Prints Variables Too System
  printToSystem();

  // Initial Rotation too face System
	rotateFaceMission();
  
  printToSystem();

  // Travels Too Missions and Makes 3 Stops
	travToMission();
  
  printToSystem();

  // Preps OSV for Hard Coding Phase
	prepEndNav();
 
  printToSystem();

  // Complete Hard Coded Path Based on Obsticle Location Data
	endNav();
 
  printToSystem();
  
	while(1);
}
