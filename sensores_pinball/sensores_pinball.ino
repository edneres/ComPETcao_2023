#include <TimerOne.h>


#define pin_reset 4       //pino que reseta latch
#define pin_sensor 2      //pino do arduino que percebe algum evento na mesa
#define delay_read 300000 //tempo periódico em que o arduino reseta o latch

int pontos = 0;           // pontos do player


void setup() 
{
  pinMode(pin_sensor, INPUT);
  pinMode(pin_reset, OUTPUT);

  digitalWrite(pin_reset, HIGH); //sempre reseta latch ao inicializar
  Serial.begin(9600);

  Timer1.initialize(delay_read); //inicia o timer1 

  attachInterrupt(digitalPinToInterrupt(pin_sensor), evento_mesa, RISING ); // inicializa interrupção externa

  Timer1.attachInterrupt(reset_latch, delay_read); //inicializa interrupçaõ do timer


}

// Funão que reseta o Latch
void reset_latch()
{
  digitalWrite(pin_reset, HIGH);
  digitalWrite(pin_reset, LOW);
}

//Função que incrementa os pontos
void evento_mesa()
{                                                                                                                                                                                                                                                                                                                                                                                                           
  pontos++;
}

void loop() 
{
  Serial.println(pontos);
  delay(500);
  

}
