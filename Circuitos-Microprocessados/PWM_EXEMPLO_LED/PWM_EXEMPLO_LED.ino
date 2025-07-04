int iLED = 8;

void setup()
{
  pinMode(iLED, OUTPUT);
}

void loop()
{
  analogWrite(iLED, 255);
}