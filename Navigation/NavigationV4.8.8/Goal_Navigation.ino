void endNav(){
  if((oneB && twoA && twoC) || (twoC && oneB && oneA))
  {
    // Hardcoded blue path
    rotate(-90);
    travel(0.6);
    rotate(0);
    travel(1.3);
    rotate(90);
    travel(0.7);
    rotate(0);
    travel(1.1);
    rotate(-90);
    travel(0.6);
    rotate(0);
    travel(1.1);
    travel(0);
  }

  if((oneA && twoB && oneC) || (oneC && twoA && twoB))
  {
    // Hard coded red path
    travel(1.3);
    rotate(-90);
    travel(0.6);
    rotate(0);
    travel(2.5);
    travel(0);
  }

  if(oneA && twoB && twoC)
  {
    // Hardcoded green path
    travel(1.3);
    rotate(90);
    travel(0.6);
    rotate(0);
    travel(1.3);
    rotate(-90);
    travel(0.6);
    rotate(0);
    travel(1.1);
    travel(0);
  }

  if(twoA && oneB && twoC)
  { 
    // Hardcoded purple path
    rotate(90);
    travel(0.6);
    rotate(0);
    travel(1.2); 
    rotate(-90);
    travel(0.7);
    rotate(0);
    travel(1.2);
    rotate(-90);
    travel(0.6);
    rotate(0);
    travel(1.1);
    travel(0);
  }
}
