int pinoSensorBaixo = 2;
int pinoSensorAlto = 7;

bool sensorbaixo = 0;
bool sensoralto = 0;

int botaotroca = 3;
int botaodesliga = 4;
int botaoliga = 5;

bool estbotaotroca = 0;
bool estbotaodesliga = 0;
bool estbotaoliga = 0;

unsigned long tempoanterior = 0;
unsigned long tempoanterior1 = 0;
unsigned long intervalo = 10000; // 10 segundos

int bomba = 6;

int estado = 0;
int fase = 0;

bool sensorbaixo1;
bool sensoralto1;
bool leiturabotaoA;
bool leiturabotaoB;
bool leiturabotaoC;

void setup() {
  pinMode(pinoSensorBaixo, INPUT);
  pinMode(pinoSensorAlto, INPUT);

  pinMode(botaotroca, INPUT_PULLUP);
  pinMode(botaodesliga, INPUT_PULLUP);
  pinMode(botaoliga, INPUT_PULLUP);

  pinMode(bomba, OUTPUT);
}

void loop() {
  sensorbaixo1 = digitalRead(pinoSensorBaixo);
  sensoralto1 = digitalRead(pinoSensorAlto);

  leiturabotaoA = digitalRead(botaotroca);
  leiturabotaoB = digitalRead(botaodesliga);
  leiturabotaoC = digitalRead(botaoliga);

  if (leiturabotaoC != estbotaoliga && fase == 0) {
    estado = 1;
  }

  if (leiturabotaoB != estbotaodesliga && fase == 0) {
    estado = 0;
  }

  if (leiturabotaoA != estbotaotroca && estado == 1) {
    fase = 1;  
    }

  switch (estado) {

    case 0:
      digitalWrite(bomba, LOW);
      break;

    case 1:
      digitalWrite(bomba, HIGH);
      break;
  }

    switch (fase) {
    case 1: {
  unsigned long tempoatual = millis();

  if (sensorbaixo1 == HIGH) {

    if (tempoanterior == 0) {
      tempoanterior = tempoatual; 
    }

    if (tempoatual - tempoanterior >= intervalo) {
      digitalWrite(bomba, HIGH);
      fase = 2;
      tempoanterior = 0;
    }

  } else {
    tempoanterior = 0;
  }

  break;
}

    case 2: {
      unsigned long tempoatual1 = millis();

      if (sensoralto1 == HIGH) {
        if (tempoanterior1 == 0) {
       tempoanterior1 = tempoatual1;
        }
        if (tempoatual1 - tempoanterior1 >= intervalo) {
          digitalWrite(bomba, LOW);
             tempoanterior1 = 0;
          fase = 0;
        }
      } else {
          tempoanterior1 = 0;
      }
       break;    
    
  }
  estbotaoliga = leiturabotaoC;
  estbotaodesliga = leiturabotaoB;
  estbotaotroca = leiturabotaoA;
    }
}