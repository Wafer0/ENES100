void rotate(float targetTheta)
{  
  float marginOfError = 2;
  if(t >= 0 && targetTheta >= 0)
  {
    if(targetTheta<t){
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         setLeftMotorPWM(100);
         setRightMotorPWM(-100);
         update();
        }
    }
    else{
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         setLeftMotorPWM(-100);
         setRightMotorPWM(100);
         update();
        }
    } 
  }
  if(t <= 0 && targetTheta <= 0)
  {
    if(targetTheta<t){
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         setLeftMotorPWM(100);
         setRightMotorPWM(-100);
         update();
        }
    }
    else{
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         setLeftMotorPWM(-100);
         setRightMotorPWM(100);
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
         setLeftMotorPWM(-100);
         setRightMotorPWM(100);
         update();
        }
    } 
    else 
    {
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         setLeftMotorPWM(100);
         setRightMotorPWM(-100);
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
         setLeftMotorPWM(-100);
         setRightMotorPWM(100);
         update();
        }
    } 
    else 
    {
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         setLeftMotorPWM(100);
         setRightMotorPWM(-100);
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
         setLeftMotorPWM(100);
         setRightMotorPWM(-100);
         update();
        }
    } 
    else 
    {
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         setLeftMotorPWM(-100);
         setRightMotorPWM(100);
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
  turnOffMotors();
}
