void prepEndNav() {
  
  rotate(0);
   update();

  travel(0.25);
   update();

  if(startingPosition == 1)
  {
    rotate(-90);
    update();
  }
  else
  {
    rotate(90);
    update();
  }
  
  travel(0.3);
  update();

  rotate(0);
  update();
}
