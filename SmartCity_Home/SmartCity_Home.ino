#include <string.h>
#include<Servo.h>
//variables
long duration, inches, cm;
String Incoming_bytes; 
int AnalogReading; 
int AnalogDiff = 99; //this is used to differntiate analog incoming bytes from mob app
int TempSensor = 0;
int GasSensor = 0; 
int VisitorKnockingState = 0;
int EmergencyState = 0;
String Emergency = "No";
String VisitorCame = "No"; //IR detects or not
String VisitorKnocking = "No";


//Pins
int FanPin = 3;
int BuzzerPin = 4;
int ServoPin = 5;
int KnockingButtomPin = 7; //to detect visitor knocking (push buttom)
int EmergencyBttomPin = 8; //Emergency buttom
int TrigPin = 9;
int EchoPin = 10;
int LightPin = 13;
int TempSensorPin = A0;
int GasSensorPin =  A1;


Servo Servo1; 

//functions
unsigned char splitter (char text[]);
long microsecondsToCentimeters(long microseconds);
long microsecondsToInches(long microseconds);

void setup() 
{
  Serial.begin(9600);         //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(13, OUTPUT);        //Sets digital pin 13 as output pin
  pinMode(FanPin, OUTPUT);        
  Servo1.attach(ServoPin);  
  pinMode(BuzzerPin, OUTPUT);      
  pinMode(KnockingButtomPin, INPUT);   
  digitalWrite(KnockingButtomPin,HIGH);    //pull-up resistor        
  pinMode(EmergencyBttomPin, INPUT);
  digitalWrite(EmergencyBttomPin,HIGH);    //pull-up resistor 
  pinMode(TempSensorPin, INPUT);
  pinMode(GasSensorPin, INPUT);
  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin,INPUT);

}  

void loop()
{
  //Sensor Readings
  VisitorKnockingState = digitalRead(KnockingButtomPin);
  EmergencyState = digitalRead(EmergencyBttomPin);
  GasSensor = analogRead(GasSensorPin)*100/1024;
  TempSensor = analogRead(TempSensorPin)*488/(1000);
  if(TempSensor<0||TempSensor>80)
  TempSensor = 0;
  if(GasSensor<0||GasSensor>80)
  GasSensor = 0;
  /*For ultrasonic sensor*/
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  duration = pulseIn(EchoPin, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);


  
  if(cm>0 && cm<10)
    VisitorCame = "yes";
  else{
        VisitorCame = "No";
  }
  
  if(VisitorKnockingState == 0){
    VisitorKnocking = "yes";
    digitalWrite(BuzzerPin,HIGH);}
  else{
        VisitorKnocking = "No";
        digitalWrite(BuzzerPin,LOW);
  }
  
  if(EmergencyState == 0)
    Emergency = "yes";
  else{
        Emergency = "No";
  }

  
  if(Serial.available() > 0)  
  {
    Incoming_bytes = Serial.readString();   
    AnalogReading = splitter(Incoming_bytes.c_str());   
  }        
    if(strcmp(Incoming_bytes.c_str() , "LightOn")==0){       
      digitalWrite(LightPin, HIGH);  
          }
    else if(strcmp(Incoming_bytes.c_str(), "LightOff")==0)       
      digitalWrite(LightPin, LOW);      
    else if(strcmp(Incoming_bytes.c_str(), "DoorOpen")==0)       
         Servo1.write(90);
    else if(strcmp(Incoming_bytes.c_str(), "DoorClose")==0)       
         Servo1.write(180); 
    else if(strcmp(Incoming_bytes.c_str(), "Emergency")==0)       
      digitalWrite(BuzzerPin, HIGH);       
      delay(1000);
      digitalWrite(BuzzerPin, LOW);          

     //Readings output
     Serial.print(Emergency);  
     Serial.print('|');     
     Serial.print(VisitorKnocking);  
     Serial.print('|');   
     Serial.print(VisitorCame);  
     Serial.print('|');  
     Serial.print(TempSensor);  
     Serial.print('|');  
     Serial.print(GasSensor);  
     Serial.print('\n');  
     delay(500);

}


unsigned char splitter (char text[]){
    char d[] = " ";
    char *token1 = strtok(text, d);
    char *token2 = strtok(NULL, d);

    if(strcmp(token1,"FanSpeed")==0){
       analogWrite(FanPin,atoi(token2)*255/100);
       Serial.print(atoi(token2)*255/100);
       Serial.print('\n');  
       AnalogDiff = 1;
       return atoi(token2);
    }
    else if(strcmp(token1,"this")==0){
        AnalogDiff = 1;
        return atoi(token2);
    }
  
}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds){
  return microseconds / 29 / 2;
}
