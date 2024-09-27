void endNav(){
  if((oneB && twoA && twoC) || (twoC && oneB && oneA))
  {
    Enes100.println("Blue Path");
    rotate(-80);
    rotate2(-90);
    travel(0.6);
    rotate(0);
    rotate2(0);
    travel(0.8);
    rotate(80);
    rotate2(90);
    travel(0.7);
    rotate(10);
    rotate2(0);
    travel(1.1);
    rotate(-80);
    rotate2(-90);
    travel(0.6);
    rotate(10);
    rotate2(0);
    travel(1.1);
    travel(0);
  }

  if((oneA && twoB && oneC) || (oneC && twoA && twoB))
  {
    Enes100.println("Red Path");
    travel(0.8);
    rotate(-80);
    rotate2(-90);
    travel(0.6);
    rotate(10);
    rotate2(0);
    travel(2.5);
    travel(0);
  }

  if(oneA && twoB && twoC)
  {
    Enes100.println("Green Path");
    travel(0.8);
    rotate(80);
    rotate2(90);
    travel(0.6);
    rotate(10);
    rotate2(0);
    travel(1.3);
    rotate(-80);
    rotate2(-90);
    travel(0.6);
    rotate(10);
    rotate2(0);
    travel(1.1);
    travel(0);
  }

  if(twoA && oneB && oneC)
  { 
    // Hardcoded purple path
    Enes100.println("Purple Path"); 
    rotate(80);
    rotate2(90);
    travel(0.6);
    rotate(10);
    rotate2(0);
    travel(0.8); 
    rotate(-80);
    rotate2(-90);
    travel(0.7);
    rotate(0);
    travel(1.2);
    rotate(-80);
    rotate2(-90);
    travel(0.6);
    rotate(-10);
    rotate2(0);
    travel(1.1);
    travel(0);
  }
}
