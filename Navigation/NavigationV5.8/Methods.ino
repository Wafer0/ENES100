void rotate(float targetTheta)
{	
  int power = 140;
	float marginOfError = 2.5;

	
	if(t >= 0 && targetTheta >= 0)
	{
		if(targetTheta<t){
		  while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
  		  {
   			 setLeftMotorPWM(power);
    		 setRightMotorPWM(-power);
    		 update();
  		  }
       turnOffMotors();
		}
		else{
		  while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
  		  {
   			 setLeftMotorPWM(-power);
    		 setRightMotorPWM(power);
    		 update();
  		  }
       turnOffMotors();
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
       turnOffMotors();
		}
		else{
		  while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
  		  {
   			 setLeftMotorPWM(-power);
    		 setRightMotorPWM(power);
    		 update();
  		  }
       turnOffMotors();
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
       turnOffMotors();
		} 
		else 
		{
		  while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
  		  {
   			 setLeftMotorPWM(power);
    		 setRightMotorPWM(-power);
    		 update();
  		  }
       turnOffMotors();
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
       turnOffMotors();
		} 
		else 
		{
		  while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
  		  {
   			 setLeftMotorPWM(-power);
    		 setRightMotorPWM(power);
    		 update();
  		  }
       turnOffMotors();
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
void rotate2(float targetTheta)
{  
  int power = 140;
  float marginOfError = 1.5;

  
  if(t >= 0 && targetTheta >= 0)
  {
    if(targetTheta<t){
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         setLeftMotorPWM(power);
         setRightMotorPWM(-power);
         delay(200);
         turnOffMotors();
         delay(200);
         update();
        }
    }
    else{
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         setLeftMotorPWM(-power);
         setRightMotorPWM(power);
                  delay(200);
         turnOffMotors();
         delay(200);
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
         delay(200);
         turnOffMotors();
         delay(200);
         update();
        }
        turnOffMotors();
    }
    else{
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         setLeftMotorPWM(-power);
         setRightMotorPWM(power);
         delay(200);
         turnOffMotors();
         delay(200);
         update();
        }
        turnOffMotors();
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
         delay(200);
         turnOffMotors();
         delay(200);
         update();
        }
        turnOffMotors();
    } 
    else 
    {
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         setLeftMotorPWM(power);
         setRightMotorPWM(-power);
         delay(200);
         turnOffMotors();
         delay(200);
         update();
        }
        turnOffMotors();
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
         delay(200);
         turnOffMotors();
         delay(200);
         update();
        }
        turnOffMotors();
    } 
    else 
    {
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         setLeftMotorPWM(-power);
         setRightMotorPWM(power);
         delay(200);
         turnOffMotors();
         delay(200);
         update();
        }
        turnOffMotors();
    }
  }
}
