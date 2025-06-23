int iValorPot = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  iValorPot = analogRead(A1);
  Serial.println(iValorPot);
  delay(100);
}