 int led = 2;
int botaoA = 3;
int botaoB = 4;

unsigned conta = 0;

int estadobotaoB = HIGH; 

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(botaoA,INPUT_PULLUP);
  pinMode(botaoB, INPUT_PULLUP);
}

void loop()
{
  int leituraA = digitalRead(botaoA);
  int leituraB = digitalRead(botaoB);
  
  if(leituraB == LOW && estadobotaoB == HIGH){
  	 conta++;
    
    if (conta > 1){
      conta = 0;
  }
 }
     estadobotaoB = leituraB;
    Serial.println(leituraB);

  
 if (leituraA == LOW && conta == 1) {
    digitalWrite(led, HIGH);
 }	else {
    digitalWrite(led, LOW);
  }
}

