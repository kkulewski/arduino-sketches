#define BUILTIN_LED_PIN 2

void setup()
{
  pinMode(BUILTIN_LED_PIN, OUTPUT);
}

void loop()
{
  digitalWrite(BUILTIN_LED_PIN, HIGH);
  delay(500);
  digitalWrite(BUILTIN_LED_PIN, LOW);
  delay(500);
}
