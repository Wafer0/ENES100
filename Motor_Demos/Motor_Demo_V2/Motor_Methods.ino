// Initliazes the pins and preps the motors for activation
void beginMotors() {
    pinMode(PinMotor1Forward, OUTPUT);
    pinMode(PinMotor1Reverse, OUTPUT);
    pinMode(PinMotor2Forward, OUTPUT);
    pinMode(PinMotor2Reverse, OUTPUT);
    pinMode(PinMotor3Forward, OUTPUT);
    pinMode(PinMotor3Reverse, OUTPUT);
    pinMode(PinMotor4Forward, OUTPUT);
    pinMode(PinMotor4Reverse, OUTPUT);
}

// Sets the specified motor to a specific pwm
void setMotorPWM(int motorId, int pwm) 
{
    // Inputs: motorId, an int [1, 4] to select the target motor
    //         pwm, the pwm of the motor, can be + or - to indicate direction

    // Verify and correct bounds on pwm value
    if (pwm > 255) {pwm = 255;} 
    else if (pwm < -255) {pwm = -255;}

    // Verify motorId
    if (motorId < 1 || motorId > 4) {return;}

    int forward_pin;
    int reverse_pin;
    
    // Get pins to use
    if (motorId == 1) {
        forward_pin = PinMotor1Forward;
        reverse_pin = PinMotor1Reverse;
    }
    else if (motorId == 2) {
        forward_pin = PinMotor2Forward;
        reverse_pin = PinMotor2Reverse;
    }
    else if (motorId == 3) {
        forward_pin = PinMotor3Forward;
        reverse_pin = PinMotor3Reverse;
    }
    else {
        forward_pin = PinMotor4Forward;
        reverse_pin = PinMotor4Reverse;
    }

    // Set pin PWM and GND
    if (pwm >= 0) {
        analogWrite(forward_pin, abs(pwm));
        digitalWrite(reverse_pin, 0);
    }
    else {
        digitalWrite(forward_pin, 0);
        analogWrite(reverse_pin, abs(pwm));
  }
}

// left motors to a certain pwm
void setLeftMotorPWM(int pwm) {
    setMotorPWM(1, pwm);
    setMotorPWM(2, pwm);
}

// right motors to a certain pwm
void setRightMotorPWM(int pwm) {
    setMotorPWM(3, pwm);
    setMotorPWM(4, pwm);
}

// turns off the motors
void turnOffMotors() {
    setMotorPWM(1, 0);
    setMotorPWM(2, 0);
    setMotorPWM(3, 0);
    setMotorPWM(4, 0);
}

// sets all motors to a specified pwm
void setBothMotors(int speed) 
{
  setMotorPWM(1, speed);
  setMotorPWM(2, speed);
  setMotorPWM(3, speed);
  setMotorPWM(4, speed);
}
