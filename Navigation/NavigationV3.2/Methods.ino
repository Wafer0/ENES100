void rotate(float targetTheta)
{	
	float marginOfError = 2;
	if(t >= 0 && targetTheta >= 0)
	{
		if(targetTheta<t){
		  while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
  		  {
   			 Tank.setLeftMotorPWM(100);
    		 Tank.setRightMotorPWM(-100);
    		 update();
  		  }
		}
		else{
		  while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
  		  {
   			 Tank.setLeftMotorPWM(-100);
    		 Tank.setRightMotorPWM(100);
    		 update();
  		  }
		}	
	}
	if(t <= 0 && targetTheta <= 0)
	{
		if(targetTheta<t){
		  while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
  		  {
   			 Tank.setLeftMotorPWM(100);
    		 Tank.setRightMotorPWM(-100);
    		 update();
  		  }
		}
		else{
		  while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
  		  {
   			 Tank.setLeftMotorPWM(-100);
    		 Tank.setRightMotorPWM(100);
    		 update();
  		  }
		}
	}
	if((t >= 0  && targetTheta <= 0))
	{
		if(t>=90)
		{
		  while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
  		  {
   			 Tank.setLeftMotorPWM(-100);
    		 Tank.setRightMotorPWM(100);
    		 update();
  		  }
		} 
		else 
		{
		  while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
  		  {
   			 Tank.setLeftMotorPWM(100);
    		 Tank.setRightMotorPWM(-100);
    		 update();
  		  }
		}
		
	}
	if(t >= 0  && targetTheta <= 0)
	{
		if(t>=90)
		{
		  while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
  		  {
   			 Tank.setLeftMotorPWM(-100);
    		 Tank.setRightMotorPWM(100);
    		 update();
  		  }
		} 
		else 
		{
		  while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
  		  {
   			 Tank.setLeftMotorPWM(100);
    		 Tank.setRightMotorPWM(-100);
    		 update();
  		  }
		}
		
	}
	if(t <= 0 && targetTheta >= 0)
	{
		if(t<=-90)
		{
		  while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
  		  {
   			 Tank.setLeftMotorPWM(100);
    		 Tank.setRightMotorPWM(-100);
    		 update();
  		  }
		} 
		else 
		{
		  while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
  		  {
   			 Tank.setLeftMotorPWM(-100);
    		 Tank.setRightMotorPWM(100);
    		 update();
  		  }
		}
	}

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
    setBothMotors(125);
    while(!((x < (inX + distance + marginOfError) && x > (inX + distance - marginOfError)) || (y < (inY + distance + marginOfError) && y > (inY + distance - marginOfError)) || (y < (inY - distance + marginOfError) && y > (inY - distance - marginOfError))))
    {
     update();
    }
  }  
  Tank.turnOffMotors();
}

int distanceObject(int startingPosition)
{
  int distanceTooObject = 0;
  if(startingPosition = 1)
  {
    // distanceTooObject = ReadDistance_1();
  }
  else
  {
    // distanceTooObject = ReadDistance_2();
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
