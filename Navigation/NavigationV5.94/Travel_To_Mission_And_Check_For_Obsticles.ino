void travelToMission1(){
  Enes100.println("Called One");
  travel2a(.6);
  delay(500);
  rotate2(90);
  delay(500);
  travel2a(1.2);
  rotate2(80);
  travel2aPrep(1.3);
}
void travelToMission2(){
  Enes100.println("Called Two");
  travel2b(1);
  delay(500);
  rotate2(-90);
  delay(500);
  travel2b(0.60);
}
