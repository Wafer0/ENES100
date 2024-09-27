void travToMission() {
  travel2(0.3);
  int d1 = distanceObject(startingPosition);
  bool temp1 = d1 > 300 && d1 < 1000;
  if(startingPosition == 1)
  {
    if(temp1)
    {
      oneC = true;
    }
    else
    {
      twoC = true;
    }
  }
  else
  {
    if(temp1)
    {
      oneA = true;
    }
    else
    {
      twoA = true;
    }
  }


  travel2(1.0);
  delay(2000);
  
  int d2 = distanceObject(startingPosition);
  bool temp2 = d2 > 300 && d2 < 1000;
  if(temp2)
  {
    oneB = true;
  }
  else
  {
    twoB = true;
  }

  travel2(1.5);
  delay(2000);

  int d3 = distanceObject(startingPosition);
  bool temp3 = d3 > 300 && d3 < 1000;
  if(startingPosition == 1)
  {
    if(temp3)
    {
      oneA = true;
    }
    else
    {
      twoA = true;
    }
  }
  else
  {
    if(temp3)
    {
      oneC = true;
    }
    else
    {
      twoC = true;
    }
  }
  
}
