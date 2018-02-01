/* Arduino Uno R3 
*  
*  LCM1602 LCD Display - I2C
*  VCC -> D13
*  GND -> GND
*  SCL -> A5
*  SDA -> A4
*  
*  LM35DZ Thermometer
*  VCC -> D13 (as 5V)
*  GND -> GND
*  DTA -> A0
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define VCC_ON_DIGITAL 13

#define DEVICE_VOLTAGE 5.0
#define ADC_RESOLUTION 1024.0
#define MULTIPLIER 100

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int tempSensorPin = A0;
int sensorRead;
float temperature;

void setup()  
{
  pinMode(VCC_ON_DIGITAL, OUTPUT);
  digitalWrite(VCC_ON_DIGITAL, HIGH);
  
  lcd.begin(16, 2);   // init 16x2 LCD
  lcd.backlight(); // init backlight
}

void loop() 
{
  sensorRead = analogRead(tempSensorPin);
  temperature = (sensorRead * DEVICE_VOLTAGE) / ADC_RESOLUTION;
  temperature *= MULTIPLIER;

  String outputRow1 = String("Current temp: ");
  String outputRow2 = String(String(temperature, 1) + " C");

  lcd.setCursor(0,0);
  lcd.print(outputRow1);
  lcd.setCursor(8,1);
  lcd.print(outputRow2);
  
  delay(1000);
}
