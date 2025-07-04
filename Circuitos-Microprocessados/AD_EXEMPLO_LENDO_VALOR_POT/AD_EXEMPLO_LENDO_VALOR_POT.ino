int iPot = 0;
int iValorPot = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  iValorPot = analogRead(iPot);
  Serial.print("Potenciometro = ");
  Serial.println(iValorPot);
  delay(100);
}