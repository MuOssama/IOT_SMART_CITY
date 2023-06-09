/*
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/03dab678-06c4-43de-b386-2ac011ad1309

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  float temperature;
  int brightness;
  int waterLevel;
  int wind_Speed;
  bool light_Bulbs;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"


//Pins
const int LightPin = 2;
const int BrighttnessPin = 36;
const int WindsensorPin = 39;
const int TemperaturePin = 34;
const int WaterLevel_0_Pin = 5;
const int WaterLevel_1_Pin = 18;
const int WaterLevel_2_Pin = 19;
const int WaterLevel_3_Pin = 21;
#define ADC_VREF_mV    3300.0 // in millivolt
#define ADC_RESOLUTION 4096.0

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);
  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
  
    pinMode(LightPin,OUTPUT);
    pinMode(BrighttnessPin,INPUT);
    pinMode(WindsensorPin,INPUT);
    pinMode(TemperaturePin,INPUT);
    pinMode(WaterLevel_0_Pin,INPUT);
    pinMode(WaterLevel_1_Pin,INPUT);
    pinMode(WaterLevel_2_Pin,INPUT);
    pinMode(WaterLevel_3_Pin,INPUT);


}

void loop() {
  ArduinoCloud.update();
  brightness = (analogRead(BrighttnessPin)*(100))/ ((ADC_RESOLUTION));
  temperature = int((analogRead(TemperaturePin)*(ADC_VREF_mV)) / ((ADC_RESOLUTION)*10));
  wind_Speed = (analogRead(WindsensorPin)*(ADC_VREF_mV)) / ((ADC_RESOLUTION));
  waterLevel = ((digitalRead(WaterLevel_0_Pin)+
  digitalRead(WaterLevel_1_Pin)+
  digitalRead(WaterLevel_2_Pin)+
  digitalRead(WaterLevel_3_Pin))*100)/4;
  delay(200);
  
}







/*
  Since LightBulbs is READ_WRITE variable, onLightBulbsChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLightBulbsChange()  {
  if(light_Bulbs)
  digitalWrite(LightPin,HIGH);
  else{
      digitalWrite(LightPin,LOW);

  }
  
}
