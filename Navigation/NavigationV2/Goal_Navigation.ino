void endNav(){
  if((oneB && twoA && twoC) || (oneC && oneB && twoA))
  {
    //implement blue line
    rotate(t, -M_PI/2);
    travel(0.5);
    rotate(t, 0);
    travel(1);
    rotate(t, M_PI/2);
    travel(0.5);
    rotate(t, 0);
    travel(1);
    rotate(t, -M_PI/2);
    travel(0.5);
    rotate(t, 0);
    travel(1);
  }

  if((oneA && twoC && twoB) || (oneC && twoA && twoB))
  {
    //implement red line
    rotate(t,0);
    travel(1);
    rotate(t,M_PI/2);
    travel(0.5);
    rotate(t,0);
    travel(1);
    rotate(t,-M_PI/2);
    travel(1);
    rotate(t,0);
    travel(1);   
  }

  if(oneA && twoB && twoC)
  {
    //implement green line
    rotate(t,0);
    travel(1);
    rotate(t,-M_PI/2);
    travel(0.5);
    rotate(t,0);
    travel(1);
    rotate(t,-M_PI/2);
    travel(1);
    rotate(t,0);
    travel(1);
  }

  if(twoA && oneB && oneC)
  {
    //implement purple line 
    rotate(t, M_PI/2);
    travel(0.5);
    rotate(t, 0);
    travel(1); 
    rotate(t, -M_PI/2);
    travel(0.5);
    rotate(t, 0);
    travel(1);
    rotate(t, -M_PI/2);
    travel(0.5);
    rotate(t,0);
    travel(1);
  }
}
    
