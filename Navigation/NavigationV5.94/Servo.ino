void beginServo(){
  pinMode(HallSensor,INPUT);
  pinMode(LED,OUTPUT);
  pinMode(A0, INPUT);
s1.attach(10);

}
void endServo(){
  s1.detach();
  pinMode(HallSensor,LOW);
}
