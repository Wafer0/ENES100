void rotateFaceMission() {
  //Rotates the otv to face towards the mision
  
	if (startingPosition == 1)
  {
    Enes100.println("Rotating Too Face 2");
  	if(!(t == 90))
    {
     	rotate(80);
      rotate2(90);
    }
  }
	if (startingPosition == 2)
	{
  Enes100.println("Rotating Too Face 2");
		if(!(t == -90))
 		{
			rotate(-80);
      rotate2(-90);
    }
  }
}
