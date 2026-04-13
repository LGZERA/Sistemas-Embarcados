int led = 13; 
int ntc = A0;
int limitesuperior = 108; 
int limiteinferior = 27; 
bool aquecedor = false;
void setup()
{
  pinMode(led, OUTPUT);
}

void loop()
{
 
 int leitura = analogRead(ntc);

  if(leitura <= limiteinferior){
  	aquecedor = true;
}
  if(leitura >= limitesuperior){
	 aquecedor = false;
  }
 
     digitalWrite(led, aquecedor);
    
    }
