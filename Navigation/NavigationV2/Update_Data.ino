void update() {
  if (v) // If the ArUco marker is visible
  {
      Enes100.print(x); // print out the location
      Enes100.print(",");
      Enes100.print(y);
      Enes100.print(",");
      Enes100.println(t);
  }
  else { // otherwise
      Enes100.println("Not visible"); // print not visible
  }

  int startingPosition = getStartingPosition();
}
