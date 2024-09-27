int low;
int high;

void setup() {
Serial.begin(9600);
pinMode(0, INPUT);

}

void loop() {

low = pulseIn(13, HIGH);
high = pulseIn(13,LOW);

double total = low + high;
double vin = low/total;

 if (vin > .85 )
  Serial.println("Data Cycle : 9");
 if (vin > .65 && vin < .85)
  Serial.println("Data Cycle : 7");
 if (vin > .45 && vin < .65 )
  Serial.println("Data Cycle : 5");
 if (vin > .25 && vin < .45)
  Serial.println("Data Cycle : 3");
 if (vin < .25 ) 
  Serial.println("Data Cycle : 1");
  delay(1000);
}






