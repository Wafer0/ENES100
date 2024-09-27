void rotate(float targetTheta)
{	
  int power = 180;
	float marginOfError = 3;
	;

	
	if(t >= 0 && targetTheta >= 0)
	{
		if(targetTheta<t){
		  while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
  		  {
   			 setLeftMotorPWM(power);
    		 setRightMotorPWM(-power);
    		 update();
  		  }
		}
		else{
		  while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
  		  {
   			 setLeftMotorPWM(-power);
    		 setRightMotorPWM(power);
    		 update();
  		  }
		}	
	}
	if(t <= 0 && targetTheta <= 0)
	{
		if(targetTheta<t){
		  while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
  		  {
   			 setLeftMotorPWM(power);
    		 setRightMotorPWM(-power);
    		 update();
  		  }
		}
		else{
		  while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
  		  {
   			 setLeftMotorPWM(-power);
    		 setRightMotorPWM(power);
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
   			 setLeftMotorPWM(-power);
    		 setRightMotorPWM(power);
    		 update();
  		  }
		} 
		else 
		{
		  while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
  		  {
   			 setLeftMotorPWM(power);
    		 setRightMotorPWM(-power);
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
   			 setLeftMotorPWM(-power);
    		 setRightMotorPWM(power);
    		 update();
  		  }
		} 
		else 
		{
		  while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
  		  {
   			 setLeftMotorPWM(power);
    		 setRightMotorPWM(-power);
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
   			 setLeftMotorPWM(power);
    		 setRightMotorPWM(-power);
    		 update();
  		  }
		} 
		else 
		{
		  while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
  		  {
   			 setLeftMotorPWM(-power);
    		 setRightMotorPWM(power);
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
    setBothMotors(255);
    while(!((x < (inX + distance + marginOfError) && x > (inX + distance - marginOfError)) || (y < (inY + distance + marginOfError) && y > (inY + distance - marginOfError)) || (y < (inY - distance + marginOfError) && y > (inY - distance - marginOfError))))
    {
     update();
    }
  }  
  turnOffMotors();
}

int distanceObject(int startingPosition)
{
  int distanceTooObject = 0;
  if(startingPosition = 1)
  {
    update2();
    distanceTooObject = distance;
  }
  else
  {
     distanceTooObject = distance;
  }
  return distanceTooObject; 
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
