#include <Adafruit_Sensor.h>
#include <Adafruit_Circuit_Playground.h>

#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN            2         // Pin which is connected to the DHT sensor.

#define DHTTYPE           DHT11   

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
dht.begin();
sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.println("Temperature");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" *C");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" *C");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" *C");  
  Serial.println("------------------------------------");
  delayMS = sensor.min_delay / 1000;


}

void loop() {
  //0  put your main code here, to run repeatedly:
  float x = (analogRead(A0)*5.0)/1024.;
  float maximo = 1.87;
  float nivel1 = maximo/10;
  float nivel2 = nivel1*2;
  float nivel3 = nivel1*3;
  float nivel4 = nivel1*4;
  float nivel5 = nivel1*5;
  float nivel6 = nivel1*6;
  float nivel7 = nivel1*7;
  float nivel8 = nivel1*8;
  float nivel9 = nivel1*9;
  float nivel10=nivel1*10;

  // Delay between measurements.
  delay(delayMS);
  // Get temperature event and print its value.
  sensors_event_t event;  
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println("Error reading temperature!");
  }
  else {
    Serial.print("Temperature: ");
    Serial.print(event.temperature);
    Serial.println(" *C");
  }
  
  if(x >= 0.0 && x < nivel1)
  {
   Serial.println("Humedad al 10%"); 
  }  
  else if( x > nivel1 && x < nivel2)
  {
   Serial.println("Humedad al 20%"); 
  }
  else if( x > nivel2 && x < nivel3)
  {
   Serial.println("Humedad al 30%"); 
  }
  else if( x > nivel3 && x < nivel4)
  {
   Serial.println("Humedad al 40%"); 
  }
  else if( x > nivel4 && x < nivel5)
  {
   Serial.println("Humedad al 50%"); 
  }
  else if( x > nivel5 && x < nivel6)
  {
   Serial.println("Humedad al 60%"); 
  }
  else if( x > nivel6 && x < nivel7)
  {
   Serial.println("Humedad al 70%"); 
  }
  else if( x > nivel7 && x < nivel8)
  {
   Serial.println("Humedad al 80%"); 
  }
  else if( x > nivel8 && x < nivel9)
  {
   Serial.println("Humedad al 90%"); 
  }
  else if( x > nivel9 && x < nivel10)
  {
   Serial.println("Humedad al 100%"); 
  }
  else
  {
    Serial.println("Supero el rango máximo de humedad");
    }
  
  Serial.println(x);
  delay(1000); 

}
