/***************************
*
*    Trabalho de eletrônica geral -  Sensor de TEMPERATURA E UMIDADE
*    Professor: Carlos Augusto Guimarães Medeiros
*    Grupo: Erick, Carine, Luca e Igor
*
***************************/
#include <dht.h>// Inclui a biblioteca no seu código
#include <LiquidCrystal.h> //Carrega a biblioteca LiquidCrystal nativa na IDE

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
 
dht SEN11; // Cria um objeto da classe dht
uint32_t timer = 0; // criando a variavel timer
 
void som(char pino, int freq, int dur){
  float per = 1000.0/freq; // periodo em ms
  for(int i=0; i<dur/(per); i++){
    digitalWrite(pino, HIGH);
    delayMicroseconds(per*500); // metade do periodo em ms
    digitalWrite(pino, LOW);
    delayMicroseconds(per*500);
  }
}

void setup()
{
  Serial.begin(9600); // Inicializa serial com taxa de transmissão de 9600 bauds
  lcd.begin(16, 2); // Define o display com 16 colunas e 2 linhas
  lcd.clear(); // limpa a tela do display
  pinMode(10, OUTPUT);
}
 
void loop() {
  int temp=0, umi=0; // criando a variavel temperatura e umidade

  // Executa 1 vez a cada 1 segundos
  if(millis() - timer>= 1000)
  {
 
    SEN11.read11(A1); // chama método de leitura da classe dht,
                    // com o pino de transmissão de dados ligado no pino A1
 
    temp = SEN11.temperature; // guardando o valor da temperatura
    umi = SEN11.humidity; // guardando o valor da umidade
    // Exibe na serial o valor de umidade
    Serial.print("Umidade = ");
    Serial.print(SEN11.humidity);
    Serial.print(" %  ");
 
    // Exibe na serial o valor da temperatura
    Serial.print("Temperatura = ");
    Serial.print(SEN11.temperature); 
    Serial.println(" Celsius  ");

    // Exibe no display LCD o valor da humidade
    lcd.setCursor(0,0); // Define o cursor na posição de início
    lcd.print("Humd. = ");
    lcd.print(SEN11.humidity);
    lcd.print("%");

    // Exibe no display LCD o valor da temperatura
    lcd.setCursor(0,1); // Define o cursor na posição de início
    lcd.print("Temp. = ");
    lcd.print(SEN11.temperature);
    lcd.write(B11011111); // Imprime o símbolo de grau
    lcd.print("C");

    timer = millis(); // Atualiza a referência
  }
  if(umi>60.00 || temp>27.00)
  {
    delay(1000);
    int tempo = 400;
    som(10, 440, tempo); // LA
    delay(tempo);

  }
}