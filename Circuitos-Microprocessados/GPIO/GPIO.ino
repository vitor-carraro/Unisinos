//Declarar variáveis
int iLED = 5;

void setup() {
  // put your setup code here, to run once:
    pinMode(iLED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(iLED, HIGH);
  delay(1000);                    
  digitalWrite(iLED, LOW); 
  delay(1000);
}