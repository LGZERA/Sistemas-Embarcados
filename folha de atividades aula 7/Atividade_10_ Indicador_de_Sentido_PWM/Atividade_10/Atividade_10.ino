int led1 = 3;
int led2 = 4;
int potenciometro = A0;
int valor_sensor = 0;

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led1, OUTPUT);
	pinMode(potenciometro, INPUT);
}

void loop()
{
 int valorsensor = analogRead(potenciometro);         
 int luzledA = map(valorsensor, 511, 0, 0, 255);
 int luzledB = map(valorsensor, 512, 1023, 0, 255);
 	analogWrite(led1, luzledA);        
	analogWrite(led2, luzledB);         
}
