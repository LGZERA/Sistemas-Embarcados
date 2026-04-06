int led1 = 9;
int pin_sensor = A0;
int valor_sensor = 0;

void setup() {
pinMode(led1, OUTPUT);
pinMode(pin_sensor, INPUT);
}

void loop() {
  int valorsensor = analogRead(pin_sensor);          // Lê o valor (0 a 1023)
  int luzled = map(valorsensor, 0, 1023, 0, 255);                
analogWrite(led1, luzled);         // Define o brilho do LED
}
