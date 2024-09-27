#include <Tank.h>
#include <Enes100.h>
#include <math.h>
#include <Wire.h>
#include <Servo.h>

// For Distance Sensor
unsigned char ok_flag;
unsigned char fail_flag;
 
unsigned short lenth_val = 0;
unsigned char i2c_rx_buf[16];
unsigned char dirsend_flag=0;

// Cordinate Variables
float x = 0;
float y = 0;
float t = 0;
bool v = false;
int startingPosition = 0;
int distance = 0;
int distance2 = 0;

// Obsticle Position Variables
bool oneA = false;
bool oneB = false;
bool oneC = false; 
bool twoA = false; 
bool twoB = false; 
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

int relay = 11;
int low;
int high;
int HallSensor = A1;
int LED = 13;
int state = 0;
Servo s1;

void setup() { 
  Wire.begin(); 
  Serial.begin(9600,SERIAL_8N1);
  printf_begin(); 

  // Starts connection with vision system
  beginMotors();
 	delay(3000);
  Enes100.begin("MikeIsTHEBEST", FIRE, 11, 12, 11 ); // Required before you can use any other Enes100 functions.
	delay(3000);
  update();

}

void loop() {
//  update4();
  
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

  if(startingPosition == 1){
    travelToMission1();
    printToSystem();
  }
  if(startingPosition == 2) {
    travelToMission2();
    printToSystem();
  }
  beginServo();
  delay(2000);
  mission();
  delay(2000);
  endServo();
  
  //Enes100.println("Detected Magnetism");
  //Enes100.println("The Number is 7");
  delay(1000);
  
  printToSystem();
  // Preps OSV for Hard Coding Phase
  prepEndNav();
  
  printToSystem();
  update3();
  
  // Complete Hard Coded Path Based on Obsticle Location Data
	endNav();
 
  printToSystem();
  
	while(1);
}
