
 #include "MQ135.h"
 //OLED Display libraries
 #include <SPI.h>
 #include <Wire.h>
  
      

 //In and Out
 int RedLed = 9;
 int GreenLed = 8;
 int Buzzer = 7;
 
void setup()
 {
  pinMode(RedLed, OUTPUT);   // initialize digital pin RedLed as an output.
  pinMode(GreenLed, OUTPUT); // initialize digital pin GreenLed as an output.
  pinMode(Buzzer, OUTPUT);   // initialize digital pin Buzzer as an output.
  // Start serial communication between arduino and your computer
  Serial.begin(9600);
  

 }
 
 
void loop()
 {
  // Read Senso value
  MQ135 gasSensor = MQ135(A0);
  float air_quality = gasSensor.getPPM();
  // Print Senso value on Serial Monitor Window
  Serial.print("Air Quality:");  
  Serial.print(air_quality);
  Serial.println(" PPM");
    // when air quality value less than 1000PPM 
    if (air_quality<=1000)
     {
      digitalWrite(GreenLed, HIGH); // turn the Green LED on
      digitalWrite(RedLed,LOW);    // turn the Red LED off
      noTone(Buzzer);              // turn the Buzzer off
     }
    // when air quality value greater than 1000PPM & less than 2000PPM  
    else if( air_quality>=1000 && air_quality<=2000 )
     {
      digitalWrite(GreenLed,LOW);  // turn the Green LED off
      digitalWrite(RedLed, HIGH ); // turn the Red LED on
      noTone(Buzzer);              // turn the Buzzer off      
     }
    // when air quality value greater than 2000PPM 
    else if (air_quality>=2000 )
     {
      digitalWrite(GreenLed,LOW);  // turn the Green LED off
      digitalWrite(RedLed,HIGH);   // turn the Red LED on
      tone(Buzzer, 1000, 200);     // turn the Buzzer on
     }
    }
