#define DEVICE_VOLTAGE 3.3
#define ADC_RESOLUTION 1024.0
#define MULTIPLIER 100.0
#define TEMPERATURE_SENSOR_PIN A0

int sensorRead;
float temperature;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  sensorRead = analogRead(TEMPERATURE_SENSOR_PIN);
  temperature = (sensorRead * DEVICE_VOLTAGE) / ADC_RESOLUTION;
  temperature *= MULTIPLIER;

  Serial.print(temperature);
  Serial.print(" C \n");
  delay(1000);
}
