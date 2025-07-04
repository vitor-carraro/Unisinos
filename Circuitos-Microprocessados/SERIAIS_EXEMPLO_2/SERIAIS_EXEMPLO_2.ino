void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  char buffer[5] = "teste";
  
  Serial.write(buffer);

  delay(100);
}