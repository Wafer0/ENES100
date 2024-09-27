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

const int PinMotor1Forward = 5;
const int PinMotor1Reverse = 4;
const int PinMotor2Forward = 2;
const int PinMotor2Reverse = 3;

const int PinMotor3Forward = 9;
const int PinMotor3Reverse = 8;
const int PinMotor4Forward = 7;
const int PinMotor4Reverse = 6;

void setup() { 

  // Starts connection with vision system
  beginMotors();
 	delay(2000);
  Enes100.begin("MikeIsTheImposter", DATA, 205, 12, 13); // Required before you can use any other Enes100 functions.
	delay(2000);

  // Sets the required pins on the arduino as an output
}

void loop() {
  // Updates Cordinate Varibles
  delay(2000);
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
