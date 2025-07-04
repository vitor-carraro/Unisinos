int iPot = 0;
int iValorPot = 0;
int iValorTransformado = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  iValorPot = analogRead(iPot);
  iValorTransformado = map(iValorPot, 0, 1023, 0, 100);
  Serial.print("Valor Original = ");
  Serial.print(iValorPot);
  Serial.print("\t Valor Transformado = ");
  Serial.println(iValorTransformado);
  delay(100);
}