void prepEndNav() {
  if(startingPosition == 1){
    travel2a(1);
  }else{
    travel2b(1);
  }
  update();
  rotate(10);
  rotate2(0);
  update();

  travel(0.65);
  update();
  
  rotate(95);
  rotate2(90);
  update();

  // start detection
  
  travel2a(0.3);
  rotate2(90);
  update();
  delay(1000);
  int d1 = ReadDistance();
  Enes100.println(d1);
  bool temp1 = (d1 > 125) && (d1 < 500);
    if(temp1)
    {
      oneC = true;
    }
    else
    {
      twoC = true;
    }

  travel2a(1);
  rotate2(90);
  update();
  delay(1000);
  int d2 = ReadDistance();
  Enes100.println(d2);
  bool temp2 = d2 > 200 && d2 < 500;
  if((d2 > 125) && (d2 < 400))
  {
    oneB = true;
  }
  else
  {
    twoB = true;
  }

  travel2a(1.5);
  rotate2(90);
  delay(2000);
  update();
  delay(1000);
  int d3 = ReadDistance();
  Enes100.println(d3);
  bool temp3 = (d3 > 125) && (d3 < 500);
    if(temp3)
    {
      oneA = true;
    }
    else
    {
      twoA = true;
    }

  //end detection

  travel2a(1);
  rotate(0);
}
