int botao = 3;

void setup() {
  pinMode(botao, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int leitura = digitalRead(botao);

  while(leitura == HIGH){
    Serial.println("esperando ordem");
    delay(1000);
    leitura = digitalRead(botao); 
  }

  Serial.println("botao pressionado");
  delay(1000);
}