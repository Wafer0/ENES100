void update() {

  v = Enes100.isVisible(); // Is your aruco visible? True or False.

  if (v) // If the ArUco marker is visible
  {
    Enes100.updateLocation();
    x = Enes100.getX();  // Your X coordinate! 0-4, in meters, -1 if no aruco is not visibility (but you should use Enes100.isVisible to check that instead)
    y = Enes100.getY();  // Your Y coordinate! 0-2, in meters, also -1 if your aruco is not visible.
    t = Enes100.getTheta()* 180 / M_PI;  //Your theta! -pi to +pi, in radians, -1 if your aruco is not visible.
  }
  else { // otherwise
      Enes100.println("Not visible"); // print not visible
  }
}

void printToSystem()
{
    Enes100.print("X cordinate: ");
    Enes100.println(x); 
    Enes100.print("Y cordinate: ");
    Enes100.println(y);
    Enes100.print("Angle: ");
    Enes100.println((int)t);
    Enes100.print("Starting Position: ");
    Enes100.println(startingPosition);
}

void update2(){
  distance =ReadDistance();
   
  Enes100.print(distance);
  Enes100.println(" mm");
  
  distance2 =ReadDistance2();
   
  Enes100.print(distance);
  Enes100.println(" mm");
  
}

void update3(){
    Enes100.print("oneA");
    Enes100.println(oneA); 
    Enes100.print("oneB");
    Enes100.println(oneB);
    Enes100.print("oneC");
    Enes100.println(oneC);
    Enes100.print("twoA");
    Enes100.println(twoA);
    Enes100.print("twoA");
    Enes100.println(twoA);
    Enes100.print("twoA");
    Enes100.println(twoA);
}
