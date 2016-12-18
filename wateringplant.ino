
// Analog input pin that the soil moisture sensor is attached to
const int analogInPin = 1;  

// value read from the soil moisture sensor
int sensorValue = 0; 

 // if the readings from the soil sensor drop below this number, then turn on the pump
int dryValue = 500;   

void setup() {
  
  pinMode(12, OUTPUT);
  
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);                   

  //Turns on the water pump if the soil is too dry
  //Increasing the delay will increase the amount of water pumped
  if(sensorValue > dryValue){
    digitalWrite(12, HIGH);
    delay(3000);
    digitalWrite(12, LOW);
  }
    
  // print the sensor to the serial monitor:
  Serial.print("sensor = " );                       
  Serial.println(sensorValue);  

  //slow your roll - I mean... slow down the code a little
  delay(100);                     
}
