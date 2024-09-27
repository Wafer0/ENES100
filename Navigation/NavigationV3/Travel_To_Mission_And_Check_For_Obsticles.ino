void travToMission() {
  int d1 = distanceObject(startingPosition);
  if(startingPosition == 1)
  {
    if(d1 < 0.9)
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
    if(d1 < 0.9)
    {
      oneA = true;
    }
    else
    {
      twoA = true;
    }
  }
  
  travel(0.3);
  
  int d2 = distanceObject(startingPosition);
  if(d2 < 0.9)
  {
    oneB = true;
  }
  else
  {
    twoB = true;
  }

  travel(0.3);

  int d3 = distanceObject(startingPosition);
  if(startingPosition == 1)
  {
    if(d1 < 0.9)
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
    if(d1 < 0.9)
    {
      oneC = true;
    }
    else
    {
      twoC = true;
    }
  }
  
  travel(0.3);
}