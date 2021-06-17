*** //coding part for water level meaurement in EGC system// ***
const int trigP = 2;  
const int echoP = 0;  

long duration;
int distance;

void setup() {
pinMode(trigP, OUTPUT);  
pinMode(echoP, INPUT);   
Serial.begin(9600);      
}

void loop() {

digitalWrite(trigP, LOW);   
delayMicroseconds(2);       

digitalWrite(trigP, HIGH); 
delayMicroseconds(10);      
digitalWrite(trigP, LOW);   

duration = pulseIn(echoP, HIGH);  
distance = duration*0.034/2;      
Serial.print("Distance = ");       
Serial.println(distance);
delay(3000);                        
}



*** //coding part for Detecting gas in a container by mq2 sensor// ***
int redLed = 12;
int greenLed = 11;
int buzzer = 10;
int smokeA0 = A5;
int sensorThres = 400;

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  if (analogSensor > sensorThres)
  {
    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
    tone(buzzer, 1000, 200);
  }
  else
  {
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  }
  delay(100);
}
