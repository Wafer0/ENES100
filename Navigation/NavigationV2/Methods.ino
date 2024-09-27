void rotate(float theta, float targetTheta)
{
  while(!((theta <= targetTheta + 5*M_PI/180 && theta >= targetTheta) || (theta >= targetTheta - 5*M_PI/180 && theta <= targetTheta)))
  {
    Tank.setLeftMotorPWM(255);
    Tank.setRightMotorPWM(-255);
    t = Enes100.getTheta();
  }
  
}

void travel(int distance)
{
  int inX = x;
  int inY = y;
  setBothMotors(125);
  while(!(((abs((inX+inY) - (x + y))) < distance + 0.1 && (abs((inX+inY) - (x + y))) >= distance) || ((abs((inX+inY) - (x + y))) > distance - 0.1 && (abs((inX+inY) - (x + y))) <= distance)))
  {
    x = Enes100.getX();
    y = Enes100.getY();
  }
  Tank.turnOffMotors();
}

int distanceObject(int startingPosition)
{
  int distanceTooObject = 0;
  if(startingPosition = 1)
  {
    distanceTooObject = Tank.readDistanceSensor(1);
  }
  else
  {
    distanceTooObject = Tank.readDistanceSensor(2);
  }
  // change return later the simulation limits the distance sensor to 1 meter
  return 0.01; 
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

void setBothMotors(int speed) 
{
  Tank.setMotorPWM(1, speed);
  Tank.setMotorPWM(2, speed);
  Tank.setMotorPWM(3, speed);
  Tank.setMotorPWM(4, speed);
}
