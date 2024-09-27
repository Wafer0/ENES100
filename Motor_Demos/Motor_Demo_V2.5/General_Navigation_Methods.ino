void rotate(float targetTheta)
{  
    float marginOfError = 3;
      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
        {
         setLeftMotorPWM(power);
         setRightMotorPWM(-power);
         update();
        }
    turnOffMotors();
}
//    else{
//      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
//        {
//         setLeftMotorPWM(-power);
//         setRightMotorPWM(power);
//         update();
//           printToSystem();
//        }
//    } 
//  }
//  if(t <= 0 && targetTheta <= 0)
//  {
//    if(targetTheta<t){
//      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
//        {
//         setLeftMotorPWM(power);
//         setRightMotorPWM(-power);
//         update();
//           printToSystem();
//        }
//    }
//    else{
//      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
//        {
//         setLeftMotorPWM(-power);
//         setRightMotorPWM(power);
//         update();
//        }
//    }
//  }
//  if((t >= 0  && targetTheta <= 0))
//  {
//    if(t>=90)
//    {
//      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
//        {
//         setLeftMotorPWM(-power);
//         setRightMotorPWM(power);
//         update();
//           printToSystem();
//        }
//    } 
//    else 
//    {
//      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
//        {
//         setLeftMotorPWM(power);
//         setRightMotorPWM(-power);
//         update();
//           printToSystem();
//        }
//    }
//    
//  }
//  if(t >= 0  && targetTheta <= 0)
//  {
//    if(t>=90)
//    {
//      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
//        {
//         setLeftMotorPWM(-power);
//         setRightMotorPWM(power);
//         update();
//           printToSystem();
//        }
//    } 
//    else 
//    {
//      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
//        {
//         setLeftMotorPWM(power);
//         setRightMotorPWM(-power);
//         update();
//           printToSystem();
//        }
//    }
//    
//  }
//  if(t <= 0 && targetTheta >= 0)
//  {
//    if(t<=-90)
//    {
//      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
//        {
//         setLeftMotorPWM(power);
//         setRightMotorPWM(-power);
//         update();
//           printToSystem();
//        }
//    } 
//    else 
//    {
//      while(!((t < targetTheta + marginOfError  && t > targetTheta - marginOfError)))
//        {
//         setLeftMotorPWM(-power);
//         setRightMotorPWM(power);
//         update();
//           printToSystem();
//        }
//    }
//  }
//
//}

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
    setBothMotors(power);
    while(!((x < (inX + distance + marginOfError) && x > (inX + distance - marginOfError)) || (y < (inY + distance + marginOfError) && y > (inY + distance - marginOfError)) || (y < (inY - distance + marginOfError) && y > (inY - distance - marginOfError))))
    {
     update();
    }
  }  
  turnOffMotors();
}
