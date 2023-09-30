// Bibliotecas
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h" 

// Inicia a serial por software nos pinos 6 e 7 (RX, TX) para o módulo DFPlayer Mini
SoftwareSerial mySoftwareSerial(6, 7);

// Criação de objeto
DFRobotDFPlayerMini myDFPlayer;

void setup()
{
  
  mySoftwareSerial.begin(9600); // Comunicacao serial com o modulo

  while (!myDFPlayer.begin(mySoftwareSerial))
  {
    // Verifica se o módulo está respondendo e se o cartão SD foi encontrado
  }

  // Definicoes iniciais para o módulo
  myDFPlayer.setTimeOut(500); // Timeout serial 500ms
  myDFPlayer.volume(30);      // Máximo 
  myDFPlayer.EQ(1);           // Equalizacao Pop

  myDFPlayer.play(18);        // Toca a faixa de saudação
  delay(3500);                // Duração da faixa

  randomSeed(analogRead(0));  // "Semente" para geração de número aleatórioa cada execução do loop
}

void loop()
{
  
  int faixa = random(18);     // Gera um número aleatório entre 0 e 17
  
  myDFPlayer.play(faixa);

  while(myDFPlayer.readState()) 
  {
    // Enquanto uma música estiver sendo executada, não executará outra
  }
}

