#include<dht.h> 
dht DHT;
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
//const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// if you require to change the pin number, Edit the pin with your arduino pin.
LiquidCrystal lcd(12,11,5,4,3,2);
#define DHT11_PIN A2
int sensor_pin = A1;
int output_value;

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 7; // Analog output pin that the LED is attached to

float sensorValue = 0;        // value read from the pot
float outputValue = 0.0;        // value output to the PWM (analog out)


void setup() {
     
lcd.begin(16, 2);
  // Print a message to the LCD
lcd.print("Testing soil...");
delay(3000);
Serial.begin(9600); 
lcd.clear();
}



void loop() 
{ 
Serial.begin(9600);
int chk = DHT.read11(DHT11_PIN);
Serial.print("\nwelcome to Soil Tester");
Serial.print("\nHumidity=" );
Serial.print(DHT.humidity, 1);
lcd.print("Humidity=");
lcd.print(DHT.humidity, 1);
delay(1000);
lcd.clear();
Serial.print("\nTemp=");
Serial.print(DHT.temperature, 1);
lcd.print("temp=");
lcd.print(DHT.temperature, 1);
delay(1000);
lcd.clear();
  output_value=analogRead(sensor_pin);
 output_value =map(output_value, 0, 982, 148, 0); 
    delay(100);
//pres=output_value;
  if(output_value>100)
     output_value=100;
  else if(output_value<0)
      output_value=0;
      //map(output_value,1023,329,0,100);
  Serial.print("\nMoisture= ");
    Serial.print(output_value);
  Serial.print("%");

  lcd.print("Moisture=");
  lcd.print(output_value);
  delay(1000);
  lcd.clear();
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
   
  Serial.write("LED: OFF"); // Send back, to the phone, the String "LED: ON"
 } 
 
sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 150, 720, 7, 2.5);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // print the results to the serial monitor:
 // Serial.print("sensor = \n" );
 // Serial.print(sensorValue);
  Serial.print("\nPh=");
    Serial.print(outputValue);

      lcd.print("Ph=");
  lcd.print(outputValue);
delay(1000);

lcd.clear();
  Serial.print("\n Soil test performed SUCCESSFULLY \n\n\n\n");
  lcd.print("Soil test done");
  delay(1500);
  lcd.clear();
  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
Serial.end();
  delay(1000);
}








  
