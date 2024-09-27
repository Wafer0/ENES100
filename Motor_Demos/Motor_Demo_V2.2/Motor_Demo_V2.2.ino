#include <Enes100.h>
#include <math.h>

// WE NEED TOO BE CONNECTED TOO VISION SYSTEM FOR THE CODE TOO WORK 

// MAKE SURE TOO CHANGE THE aruco ID OTHERWISE IT WONT WORK 

// MAKE SURE TOO CHANGE THE aruco ID OTHERWISE IT WONT WORK 

// MAKE SURE TOO CHANGE THE aruco ID OTHERWISE IT WONT WORK 

const int arucoID = 18;

// MAKE SURE TOO CHANGE THE aruco ID OTHERWISE IT WONT WORK 

// MAKE SURE TOO CHANGE THE aruco ID OTHERWISE IT WONT WORK 

// MAKE SURE TOO CHANGE THE aruco ID OTHERWISE IT WONT WORK 

// Cordinate Variables
float x = 0;
float y = 0;
float t = 0;
bool v = false;

// Motor Pins
const int PinMotor1Forward = 5;
const int PinMotor1Reverse = 4;
const int PinMotor2Forward = 3;
const int PinMotor2Reverse = 2;
const int PinMotor3Forward = 9;
const int PinMotor3Reverse = 8;
const int PinMotor4Forward = 7;
const int PinMotor4Reverse = 6;

// Travel Holding Varibales
float inX = 0;
float inY = 0;

void setup() {
  delay(2000);
  Enes100.begin("MikeIsTheImposter", FIRE, arucoID, 1, 0  ); // Required before you can use any other Enes100 functions.
  delay(2000);
  beginMotors();
  delay(2000);
}

// Will Travel 4 meters and then it will rotate 90 degrees 4 times with a 5 second delay between each time
void loop() {
//  update();
//  printToSystem();
//  rotate(0);
//  delay(5000);
  
  update();
  printToSystem();
  travel(4);
  delay(5000);
  
//  update();
//  printToSystem();
//  rotate(90);
//  delay(5000);
//  
//  update();
//  printToSystem();
//  rotate(179);
//  delay(5000);
//  
//  update();
//  printToSystem();
//  rotate(-90);
//  delay(5000);
//
//  update();
//  printToSystem();
//  rotate(0);
//  delay(5000);
  
}
