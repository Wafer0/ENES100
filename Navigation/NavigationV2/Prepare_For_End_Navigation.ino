void prepEndNav() {
  rotate(t,0);

  travel(0.25);

  if(startingPosition = 1)
  {
    rotate(t,(-M_PI/2));
  }
  else
  {
    rotate(t,(M_PI/2));
  }
  
  travel(0.45);

  rotate(t, 0);
  
}
