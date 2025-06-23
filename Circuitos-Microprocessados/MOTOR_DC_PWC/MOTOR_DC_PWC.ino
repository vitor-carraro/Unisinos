#define IN1 2
#define IN2 4
#define ENBA 3

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENBA, OUTPUT);
}

void loop() {
  analogWrite(ENBA, 255);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  delay(2000);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  delay(2000);
}