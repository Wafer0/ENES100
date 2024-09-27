void beginMotors() {
    pinMode(PIN_MOTOR_1_FORWARD, OUTPUT);
    pinMode(PIN_MOTOR_1_REVERSE, OUTPUT);
    pinMode(PIN_MOTOR_2_FORWARD, OUTPUT);
    pinMode(PIN_MOTOR_2_REVERSE, OUTPUT);
    pinMode(PIN_MOTOR_3_FORWARD, OUTPUT);
    pinMode(PIN_MOTOR_3_REVERSE, OUTPUT);
    pinMode(PIN_MOTOR_4_FORWARD, OUTPUT);
    pinMode(PIN_MOTOR_4_REVERSE, OUTPUT);
}

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
        forward_pin = PIN_MOTOR_1_FORWARD;
        reverse_pin = PIN_MOTOR_1_REVERSE;
    }
    else if (motorId == 2) {
        forward_pin = PIN_MOTOR_2_FORWARD;
        reverse_pin = PIN_MOTOR_2_REVERSE;
    }
    else if (motorId == 3) {
        forward_pin = PIN_MOTOR_3_FORWARD;
        reverse_pin = PIN_MOTOR_3_REVERSE;
    }
    else {
        forward_pin = PIN_MOTOR_4_FORWARD;
        reverse_pin = PIN_MOTOR_4_REVERSE;
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

void setLeftMotorPWM(int pwm) {
    setMotorPWM(1, pwm);
    setMotorPWM(2, pwm);
}

void setRightMotorPWM(int pwm) {
    setMotorPWM(3, pwm);
    setMotorPWM(4, pwm);
}

void turnOffMotors() {
    setMotorPWM(1, 0);
    setMotorPWM(2, 0);
    setMotorPWM(3, 0);
    setMotorPWM(4, 0);
}
