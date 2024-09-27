void mission(){
int i;
low = pulseIn(A0, HIGH);
high = pulseIn(A0,LOW);
int count = 0;
double total = low + high;
double vin = low/total;

s1.write(00);

delay(1000);
if (vin > .85 ){
  Enes100.println("Data Cycle : 9");
}
 else if (vin > .65 && vin < .85){
  Enes100.println("Data Cycle : 7");
 }
 else if (vin > .45 && vin < .65 ){
  Enes100.println("Data Cycle : 5");
 }
 else if (vin > .25 && vin < .45){
  Enes100.println("Data Cycle : 3");
 }
 else if (vin < .25 ) {
  Enes100.println("Data Cycle : 1");
 }else{
    Enes100.println("Data Cycle : 7");
 }
  delay(200);

for(i=0;i<15;i++){

int sensorStatus = digitalRead(HallSensor); // Check the sensor status
  if (sensorStatus == 1) // Check if the pin high or not
  {
    // if the pin is high turn on the onboard Led
    digitalWrite(LED, HIGH); // LED on
    delay(100);
  }
  else  {
    //else turn off the onboard LEDß
    digitalWrite(LED, LOW); // LED off
    count ++;
    delay(100);
  }
}

if(count > 0){
  Enes100.println("Detected");
}else{
  Enes100.println("Not Detected");
}
s1.write(180);

delay(2000);


}
