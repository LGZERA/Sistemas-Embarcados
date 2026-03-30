//Luis Gustavo, meca

const int led = 5;
const int botao = 6;

int ultimoestado = HIGH;
int estadoestavel = HIGH;

unsigned long ultimotempo = 0;
const unsigned long debouncedelay = 50;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop() {
  int leitura = digitalRead(botao);

  if (leitura != ultimoestado) {   
    ultimotempo = millis(); //marca o inicio da contagem/ algo ocorreu
  }

  if ((millis() - ultimotempo) > debouncedelay && leitura != estadoestavel) {
    estadoestavel = leitura; //aqui diz se ja passou tempo suficiente desde aql mudança

    if (estadoestavel == LOW) {
      digitalWrite(led, !digitalRead(led));
    }
  }

  ultimoestado = leitura;
}