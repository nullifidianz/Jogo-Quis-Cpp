#include <Arduino.h>;
#include <LiquidCrystal.h>;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int btnSim = 2;
const int btnNão = 3;
const int btnPular = 4;
const int btnIniciar = 5;

const int ledV = 6;

const int buzzer = 7;

int nivelAtual = 1;
int pontos = 0;
int perguntasCertas = 0;
int tentativas = 3;
int jogoRodando = false;

String perguntasFaceis[7] = {
    "O Arduino é uma plataforma de prototipagem eletrônica de código aberto.",
    "As placas Arduino são programadas usando a linguagem de programação C/C++.",
    "O Arduino é amplamente utilizado em projetos de automação residencial.",
    "Os pinos digitais de um Arduino podem ser configurados como entrada ou saída.",
    "O Arduino pode ser alimentado por meio de uma bateria de 9 volts.",
    "O Arduino Uno possui 14 pinos digitais de entrada/saída.",
    "É possível conectar sensores e atuadores ao Arduino para interagir com o ambiente físico.",
};

String perguntasMedias[7] = {
    "O Arduino Mega possui mais pinos de entrada/saída do que o Arduino Uno.",
    "O Arduino Nano é uma versão compacta do Arduino Uno.",
    "O Arduino pode se comunicar com outros dispositivos usando protocolos como I2C e SPI.",
    "Shields são placas de expansão que podem ser conectadas ao Arduino para adicionar funcionalidades.",
    "O Arduino pode ser programado usando a IDE do Arduino.",
    "É possível usar o Arduino para criar projetos de robótica.",
    "A biblioteca 'Servo.h' é utilizada para controlar servomotores com o Arduino.",
};

String perguntasDificeis[7] = {
    "O bootloader é um pequeno programa armazenado na memória flash do Arduino que permite a programação do microcontrolador.",
    "É possível usar o Arduino para criar sistemas de monitoramento e controle remoto.",
    "O Arduino pode ser programado usando linguagens de programação como Python.",
    "A placa Arduino Leonardo possui capacidade de emulação de dispositivos USB.",
    "Shields de Ethernet permitem que o Arduino se conecte à internet.",
    "É possível programar o Arduino usando linguagens de programação de alto nível, como Scratch.",
    "O Arduino Due utiliza um microcontrolador baseado na arquitetura ARM."};

bool respostasFaceis[7] = {
    true,
    true,
    true,
    true,
    true,
    true,
    true,
};

bool respostasMedias[7] = {
    true,
    true,
    true,
    true,
    true,
    true,
    true,
};

bool respostasDificeis[7] = {
    true,
    true,
    false,
    true,
    true,
    false,
    true};

String perguntaFinal = "Teste";
bool respostaFinal = true;

void tocaSom(int tipoSom)
{
  switch (tipoSom)
  {
  case 1:
    // acerto
    tone(buzzer, 1250, 200);
    break;

  case 2:
    // erro
    tone(buzzer, 1000, 200);
    break;

  case 3:
    // pular pergunta
    tone(buzzer, 750, 200);
    break;
  case 4:
    // desistir
    tone(buzzer, 500, 200);
    break;
  case 5:
    // Vitória
    tone(buzzer, 1500, 200);
    break;
  }
}

bool verificarResposta(bool respostaUsuario, bool respostaCorreta)
{
  if (respostaUsuario == respostaCorreta)
  {
    return true;
  }
  else
  {
    false;
  }
}
