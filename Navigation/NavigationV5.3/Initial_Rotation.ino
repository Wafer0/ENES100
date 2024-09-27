void rotateFaceMission() {
  //Rotates the otv to face towards the mision
  
	if (startingPosition == 1)
  {
  	if(!(t == 90))
    {
     	rotate(90);
    }
  }
	if (startingPosition == 2)
	{
		if(!(t == -90))
 		{
			rotate(-90);
    }
  }
}
