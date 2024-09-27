void rotate(float targetTheta)
{
    int power = 140;
    float marginOfError = 2.5;

    update();  // Assuming there's a function to get the current angle

    float angleDifference = targetTheta - t;

    // Normalize angle difference to be within the range -180 to 180
    if (angleDifference > 180)
        angleDifference -= 360;
    else if (angleDifference < -180)
        angleDifference += 360;

    if (fabs(angleDifference) <= marginOfError)
    {
        // Already at the target angle, no need to rotate
        turnOffMotors();
        return;
    }

    int direction = (angleDifference > 0) ? -1 : 1;  // -1 for counter-clockwise, 1 for clockwise

    // Adjust power based on the angle difference
    int adjustedPower = power * direction;

    while (fabs(angleDifference) > marginOfError)
    {
        setLeftMotorPWM(adjustedPower);
        setRightMotorPWM(-adjustedPower);
        update();

        angleDifference = targetTheta - t;

        if (angleDifference > 180)
            angleDifference -= 360;
        else if (angleDifference < -180)
            angleDifference += 360;
    }

    turnOffMotors();
}

void rotate2(float targetTheta)
{
    int power = 140;
    float marginOfError = 1.5;

    update();  // Assuming there's a function to get the current angle

    float angleDifference = targetTheta - t;

    // Normalize angle difference to be within the range -180 to 180
    if (angleDifference > 180)
        angleDifference -= 360;
    else if (angleDifference < -180)
        angleDifference += 360;

    if (fabs(angleDifference) <= marginOfError)
    {
        // Already at the target angle, no need to rotate
        turnOffMotors();
        return;
    }

    int direction = (angleDifference > 0) ? -1 : 1;  // -1 for counter-clockwise, 1 for clockwise

    // Adjust power based on the angle difference
    int adjustedPower = power * direction;

    while (fabs(angleDifference) > marginOfError)
    {
        setLeftMotorPWM(adjustedPower);
        setRightMotorPWM(-adjustedPower);
        delay(50);
        turnOffMotors();
        delay(250);
        update();

        angleDifference = targetTheta - t;

        if (angleDifference > 180)
            angleDifference -= 360;
        else if (angleDifference < -180)
            angleDifference += 360;
    }

    Tank.turnOffMotors();
}

void travel(float distance)
{
  float marginOfError = 0.05;
  float inX = x;
  float inY = y;
  if(distance == 0)
  {
    update();
  }
  else{
    setBothMotors(255);
    while(!((x < (inX + distance + marginOfError) && x > (inX + distance - marginOfError)) || (y < (inY + distance + marginOfError) && y > (inY + distance - marginOfError)) || (y < (inY - distance + marginOfError) && y > (inY - distance - marginOfError))))
    {
     update();
    }
  }  
  turnOffMotors();
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

void travel2a(double target){
  double marginOfError2 = 0.1;
      while(!((y < target + marginOfError2  && y > target - marginOfError2)))
        {
          if(y < target){
            setBothMotors(150);
          }
          else{
            setBothMotors(-150);
          }
         update();
      }
      turnOffMotors();
}
void travel2b(double target){
  double marginOfError2 = 0.1;
      while(!((y < target + marginOfError2  && y > target - marginOfError2)))
        {
          if(y > target){
            setBothMotors(150);
          }
          else{
            setBothMotors(-150);
          }
         update();
      }
      turnOffMotors();
}
