//Estados da maquina de estados
#define SEGUIR_LINHA 0
#define CURVA 1
#define PARADA 2

//Pinos
#define LED_DEBUG 13
#define IR_CONTADOR_LINHA 3
#define IR_OBSTACULO 2
#define IR_SEGUIDOR_DIREITO 11
#define IR_SEGUIDOR_ESQUERDO 12
#define PWM_MOTOR_DIREITO 5
#define PWM_MOTOR_ESQUERDO 6
#define MOTOR_DIREITO_IN_0 7
#define MOTOR_DIREITO_IN_1 8
#define MOTOR_ESQUERDO_IN_0 9
#define MOTOR_ESQUERDO_IN_1 10

//Outros
#define DEBOUNCE_DELAY 900 

//Variaveis globais
int estado = SEGUIR_LINHA;
int iCount = 0;
int isObstaculo = 0;
bool bCallback = false;
int iSensorDireito, iSensorEsquerdo, iSensorContador;

// Últimos tempos de interrupção para cada sensor
volatile unsigned long lastTimeLinha = 0;
volatile unsigned long lastTimeObstaculo = 0;
volatile bool flagObstaculo = false;
volatile bool flagLinha = false;

//Funções de controle
bool passouDebounce(volatile unsigned long &lastTime) {
  unsigned long agora = millis();
  if (agora - lastTime < DEBOUNCE_DELAY) {
    return false;
  }
  lastTime = agora;
  return true;
}

void setup()
{
  //Configuração dos pinos
  pinMode(LED_DEBUG, OUTPUT);
  pinMode(IR_CONTADOR_LINHA, INPUT);
  pinMode(IR_OBSTACULO, INPUT);
  pinMode(IR_SEGUIDOR_DIREITO, INPUT);
  pinMode(IR_SEGUIDOR_ESQUERDO, INPUT);
  pinMode(PWM_MOTOR_DIREITO, OUTPUT);
  pinMode(PWM_MOTOR_ESQUERDO, OUTPUT);
  pinMode(MOTOR_DIREITO_IN_0, OUTPUT);
  pinMode(MOTOR_DIREITO_IN_1, OUTPUT);
  pinMode(MOTOR_ESQUERDO_IN_0, OUTPUT);
  pinMode(MOTOR_ESQUERDO_IN_1, OUTPUT);
  
  //Random flutuante
  randomSeed(analogRead(A0));

  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(IR_OBSTACULO), obstaculoISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(IR_CONTADOR_LINHA), contadorLinhaISR, FALLING);
}

void loop()
{
  //Logica para evitar conflitos de interrupt por meio de flags
  if (flagObstaculo) {
    flagObstaculo = false;
    Obstaculo();
  }

  if (flagLinha) {
    flagLinha = false;
    ContadorLinha();
  }

  switch(estado)
  {
    case SEGUIR_LINHA:
      SeguidorLinha();
      break;
    case CURVA:
      RealizarCurva(false, 0);
      break;
    case PARADA:
      Parar();
      // MeiaVolta(bCallback);
      ReiniciarContadorLinha();
      RealizarCurva(false, 0);
      iCount = 1;
      RealizarCurva(false, 1);
      iCount = 1;

      break;
  }
}

//Operações de direção
void SeguidorLinha()
{
  iSensorDireito = digitalRead(IR_SEGUIDOR_DIREITO);
  iSensorEsquerdo = digitalRead(IR_SEGUIDOR_ESQUERDO);

  if (iSensorEsquerdo == LOW && iSensorDireito == LOW) // Andar Reto
  {
    analogWrite(PWM_MOTOR_DIREITO, 200);
    analogWrite(PWM_MOTOR_ESQUERDO, 200);

    digitalWrite(MOTOR_DIREITO_IN_0, HIGH);
    digitalWrite(MOTOR_DIREITO_IN_1, LOW);

    digitalWrite(MOTOR_ESQUERDO_IN_0, HIGH);
    digitalWrite(MOTOR_ESQUERDO_IN_1, LOW);
  } 
  else if (iSensorEsquerdo == LOW) // Corrigir esquerda
  {
    analogWrite(PWM_MOTOR_DIREITO, 200);
    analogWrite(PWM_MOTOR_ESQUERDO, 200);
    
    digitalWrite(MOTOR_ESQUERDO_IN_0, HIGH);
    digitalWrite(MOTOR_ESQUERDO_IN_1, LOW);
    
    digitalWrite(MOTOR_DIREITO_IN_0, LOW);
    digitalWrite(MOTOR_DIREITO_IN_1, LOW);
  } 
  else if (iSensorDireito == LOW) // Corrigir direita
  {
    analogWrite(PWM_MOTOR_DIREITO, 200);
    analogWrite(PWM_MOTOR_ESQUERDO, 200);

    digitalWrite(MOTOR_ESQUERDO_IN_0, LOW);
    digitalWrite(MOTOR_ESQUERDO_IN_1, LOW);

    digitalWrite(MOTOR_DIREITO_IN_0, HIGH);
    digitalWrite(MOTOR_DIREITO_IN_1, LOW);
  }
  else
  {
    analogWrite(PWM_MOTOR_DIREITO, 200);
    analogWrite(PWM_MOTOR_ESQUERDO, 200);

    digitalWrite(MOTOR_DIREITO_IN_0, HIGH);
    digitalWrite(MOTOR_DIREITO_IN_1, LOW);

    digitalWrite(MOTOR_ESQUERDO_IN_0, HIGH);
    digitalWrite(MOTOR_ESQUERDO_IN_1, LOW);
  }

  bCallback = false;
}

void Parar()
{
  analogWrite(PWM_MOTOR_DIREITO, 0);
  analogWrite(PWM_MOTOR_ESQUERDO, 0);
  
  digitalWrite(MOTOR_DIREITO_IN_0, LOW);
  digitalWrite(MOTOR_DIREITO_IN_1, LOW);

  digitalWrite(MOTOR_ESQUERDO_IN_0, LOW);
  digitalWrite(MOTOR_ESQUERDO_IN_1, LOW);
  // delay(1000);
}

void RealizarCurva(bool aleatorio, int curva)
{
  int movimento;
  aleatorio ? movimento = random(2) : movimento = curva;

  switch (movimento) 
  {
    case 0: // Vira Direita
      DarRe(false);

      digitalWrite(MOTOR_ESQUERDO_IN_0, HIGH);
      digitalWrite(MOTOR_ESQUERDO_IN_1, LOW);

      digitalWrite(MOTOR_DIREITO_IN_0, LOW);
      digitalWrite(MOTOR_DIREITO_IN_1, HIGH);
      delay(700);
      break;
    case 1: //Vira Esquerda
      DarRe(false);

      digitalWrite(MOTOR_ESQUERDO_IN_0, LOW);
      digitalWrite(MOTOR_ESQUERDO_IN_1, HIGH);

      digitalWrite(MOTOR_DIREITO_IN_0, HIGH);
      digitalWrite(MOTOR_DIREITO_IN_1, LOW);
      delay(700);
      break;
  }

  estado = SEGUIR_LINHA;
}

void MeiaVolta(bool &bCallback)
{
  ReiniciarContadorLinha();

  if(bCallback)
    return;

  DarRe(true);

  analogWrite(PWM_MOTOR_DIREITO, 200);
  analogWrite(PWM_MOTOR_ESQUERDO, 200);

  digitalWrite(MOTOR_ESQUERDO_IN_0, LOW);
  digitalWrite(MOTOR_ESQUERDO_IN_1, HIGH);

  digitalWrite(MOTOR_DIREITO_IN_0, HIGH);
  digitalWrite(MOTOR_DIREITO_IN_1, LOW);
  delay(1400);
      
  bCallback = true;
}

void DarRe(bool pararNoFinal)
{
  analogWrite(PWM_MOTOR_DIREITO, 255);
  analogWrite(PWM_MOTOR_ESQUERDO, 255);

  digitalWrite(MOTOR_ESQUERDO_IN_0, LOW);
  digitalWrite(MOTOR_ESQUERDO_IN_1, HIGH);

  digitalWrite(MOTOR_DIREITO_IN_0, LOW);
  digitalWrite(MOTOR_DIREITO_IN_1, HIGH);
  delay(700);

  if(pararNoFinal)
    Parar();
}


//Interupções
void obstaculoISR() {
  if (!passouDebounce(lastTimeObstaculo)) return;
  flagObstaculo = true;
}

void Obstaculo()
{
  isObstaculo = !isObstaculo;
  estado = isObstaculo ? PARADA : SEGUIR_LINHA;

  Serial.print("OBSTACULO -> ");
  Serial.println(isObstaculo ? "DETECTADO (PARADA)" : "LIVRE (SEGUIR_LINHA)");
}

void contadorLinhaISR() {
  if (!passouDebounce(lastTimeLinha)) return;
  flagLinha = true;
}

void ContadorLinha()
{
  if (estado == PARADA)
    return;
    
  iSensorContador = digitalRead(IR_CONTADOR_LINHA);
  if(iSensorContador != HIGH)
  {
    iCount++;

    Serial.print("LINHA CRUZADA: ");
    Serial.println(iCount);

    if(iCount >= 3)
    {
      estado = CURVA;
      iCount = 0;
      Serial.println("LIMITE DE LINHAS -> CURVA");
    }
  }
}

void ReiniciarContadorLinha(){
  lastTimeLinha = millis();
  iCount = 0;
  Serial.println("REINICIADO CONTADOR DE LINHAS");
}

