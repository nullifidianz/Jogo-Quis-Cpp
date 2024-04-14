#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);

boolean jogoRodando = false;
boolean inicioClicado = false;
boolean perguntaRespondida = false;

String Questions[] = {
    "Neymar jogou no PSG?",
    "Messi eh argentino?",
    "CR7 eh portugues?",
    "O Brasil tem 5 Copas?",
    "Bayern eh da Alemanha?",
    "Liverpool venceu a Champions?",
    "PSG ganhou a Champions?",
    "CR7 ja jogou na Inter?",
    "Real Madrid eh espanhol?",
    "Chelsea venceu a Premier?",
    "Liverpool tem 7 Champions?",
    "Arsenal ganhou a Europa L?",
    "Zidane foi tecnico?",
    "Scolari treinou o Real?",
    "Pele jogou na Europa?",
    "O City tem 3 Premier?",
    "O Barca tem 6 Champions?",
    "O Boca ganhou Libertadores?"
};

int NumQuestions = 0;
boolean respostas[] = {
  true, 
  true, 
  true, 
  true, 
  true,
  true,
  false,
  false,
  true,
  true,
  false,
  false,
  true,
  false,
  false,
  false,
  false,
  true
};    //1 correto - 0 errado
int pontos[] = {
  1, 
  1, 
  1,
  1,
  1,
  1,
  2, 
  2,
  2,
  2,
  2,
  2,
  3, 
  3,
  3,
  3,
  3,
  3
};
int perguntasSelecDificuldades[3] = {0, 0, 0};
int perguntas[15];
int score = 0;
int pulos = 3;
int segundos = 0;
int milisegundos = 0;
int centesimos = 0;
boolean pularClicado = false;

void setup()
{
  pinMode(9, INPUT);  //NAO
  pinMode(8, INPUT);   //SIM
  pinMode(13, OUTPUT); //LED
  pinMode(2, INPUT);  //INICIAR
  pinMode(3, INPUT);  //PULAR
  
  attachInterrupt(digitalPinToInterrupt(2), inicio, RISING);
  attachInterrupt(digitalPinToInterrupt(3), pulo, RISING);
  
  lcd.begin(16, 2);
  lcd.print(F("Pressione"));
  lcd.setCursor(0,1);
  lcd.print(F("Iniciar"));
  randomSeed(analogRead(0));
}

void inicio() {
  inicioClicado = true;
}

void pulo() {
  pularClicado = true;
}

void pular() {
  pularClicado = false;
  if (pulos > 0) {
    lcd.clear();
    pulos--;
    lcd.setCursor(0,0);
    lcd.print(F("Questao pulada!"));
    lcd.setCursor(0,1);
    lcd.print(F("Pulos rsts:"));
    lcd.setCursor(15,1);
    lcd.print(pulos);
    NumQuestions++;
    delay(2000);
    lcd.clear();    
    perguntaRespondida = true;
  }
  else {
   lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Sem pulos rsts"));
    delay(2000);
    lcd.clear();
    exibirPergunta(false);
  }
}

void inicioGame() {
  inicioClicado = false;
  if (!jogoRodando) {
    lcd.clear();
    lcd.setCursor(0, 0);             
    lcd.print("Bem-vindo");
    lcd.setCursor(0, 1);
    lcd.print("Ao quiz!");
    tone(10, 660, 100);
    delay(300);
    tone(10, 510, 100);
    delay(100);
    delay(3000);
    lcd.clear();
    jogoRodando = true;
    NumQuestions = 0;
    pulos = 3;
    escolherPerguntas();
    score=0;
    exibirPergunta(true);
  }
  else {
    fimDeJogo();
  }
}

void fimDeJogo() {
  lcd.clear();
  lcd.print(F("Pressione"));
  lcd.setCursor(0, 1);
  lcd.print(F("Iniciar"));
  jogoRodando = false;
  perguntaRespondida = false;
  score = 0;
  NumQuestions = 0;
  pulos = 3;
  perguntasSelecDificuldades[0] = 0;
  perguntasSelecDificuldades[1] = 0;
  perguntasSelecDificuldades[2] = 0;
  for (int i=0; i<15; i++) {
    perguntas[i] = 90; 
  }
}

void correctAnswer()
{                  
  lcd.setCursor(0, 1);
  lcd.print("Resposta Correta");
  score += pontos[perguntas[NumQuestions]];
  NumQuestions++;
  
  if (score<10){
    lcd.setCursor(15, 0);
    lcd.print(score);
  }
  else {
    lcd.setCursor(14, 0);
    lcd.print(score);
  }
  
  tone(10, 2500, 100);
  delay(100);
  tone(10, 3500, 100);
  delay(250);
  noTone(10);
  delay(3000);
  lcd.clear();
  perguntaRespondida = true;
}

void wrongAnswer()
{
  lcd.setCursor(0, 1);
  lcd.print("Resposta Errada");
  digitalWrite(13, HIGH);
  tone(10, 1350, 100);
  delay(100);
  tone(10, 1000, 100);
  delay(250);
  digitalWrite(13, LOW);
  noTone(10);
  delay(3000);
  lcd.clear();
  fimDeJogo();
}

void marioIntro()
{
  tone(10, 660, 100);
  delay(150);
  tone(10, 660, 100);
  delay(300);
  tone(10, 660, 100);
  delay(300);
  tone(10, 510, 100);
  delay(100);
  tone(10, 660, 100);
  delay(300);
  tone(10, 770, 100);
  delay(550);
  tone(10, 380, 100);
  delay(575);
}

void showScore()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Voce acertou!");
  lcd.setCursor(0, 1);
  lcd.print("Fim de Jogo");
  delay(1000);
  marioIntro();
  lcd.clear();
  lcd.print(F("Pontuacao: "));
  lcd.print(score);
  delay(20000);
  fimDeJogo();
}

void escolherPerguntas() {
  for (int i=0; i<15; i++) {
    int pergunta = random(0,18);
    boolean existe = false;
    for (int j=0; j<15; j++) {
      if (perguntas[j] == pergunta) {
        existe = true;
        break;
      }
    }

    if (existe) {
      i--;
    }
    else if (perguntasSelecDificuldades[pontos[pergunta]-1] == 5){
      i--; 
    }
    else
    {
      perguntasSelecDificuldades[pontos[pergunta]-1]++;
      perguntas[i] = pergunta;
    }
  }
}

void exibirPergunta(boolean zerarSegundos) {
  if (NumQuestions < 15) {
    lcd.setCursor(0, 0);
    lcd.print(F("Questao "));
    if (NumQuestions < 9) {
      lcd.print(F("0")); 
    }
    lcd.print(NumQuestions+1);
    lcd.print(F(":"));
    delay(1000);
    lcd.clear();
    lcd.print(Questions[perguntas[NumQuestions]]);
    delay(1000);
    if ((Questions[perguntas[NumQuestions]].length()) > 16) {
      for (int i=0; i<(Questions[perguntas[NumQuestions]].length())-16; i++) {
        lcd.scrollDisplayLeft(); 
        delay(500);
      }
    }  
    delay(1000);
  }
  else {
    lcd.setCursor(0, 0);
    lcd.print(F("Questao Final:"));
    delay(1000);
    lcd.clear();
    lcd.print(F("Ferenc Puskas ganhou uma Copa do Mundo?"));
    delay(1000);
    for (int i=0; i<23; i++) {
      lcd.scrollDisplayLeft(); 
      delay(500);
    }
    delay(1000);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F("Q-"));
  if (NumQuestions < 9) {
    lcd.print(F("0")); 
  }
  lcd.print(NumQuestions+1);
  lcd.setCursor(8,0);
  lcd.print(F("score="));
  if (score < 10) {
    lcd.print(F("0"));
  }
  lcd.print(score);
  lcd.setCursor(3,1);
  lcd.print(F("Sim ou Nao"));
  if (zerarSegundos) {
    segundos = 0; 
  }
  perguntaRespondida = false;
}

void cronometro(){
  milisegundos = millis ();
  if(milisegundos % 10 == 0){
    centesimos++;
    if(centesimos == 100){
      centesimos = 0;
      segundos++;
    }
  }
  if (segundos >= 10 && segundos < 15) {
    if (digitalRead(13) == LOW && centesimos < 50) {
      digitalWrite(13, HIGH); 
    }
    else if (digitalRead(13) == HIGH && centesimos > 50){
      digitalWrite(13, LOW); 
    }
  }
  else if (segundos == 16) {
    if (pulos > 0) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(F("Tempo esgotado!"));
      lcd.setCursor(0,1);
      lcd.print(F("Questao pulada"));
      delay(2000);
      pular();
    }
    else {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(F("Tempo esgotado!"));
      lcd.setCursor(0,1);
      lcd.print(F("Voce perdeu!"));
      fimDeJogo();
    }
  }
}

// PINO 8 = SIM; PINO 9 = NAO
void checkButtons() {
  if (digitalRead(8) == HIGH || digitalRead(9) == HIGH) {
    if (NumQuestions < 15) {
      if (digitalRead(8) == HIGH && respostas[perguntas[NumQuestions]]) {
        correctAnswer();
      } else if (digitalRead(9) == HIGH && !respostas[perguntas[NumQuestions]]) {
        correctAnswer();
      } else {
        wrongAnswer();
      }
    }
    else {
      if (digitalRead(8) == HIGH) {
        wrongAnswer(); 
      }
      else if (digitalRead(9) == HIGH) {
        showScore();
      }
    }
  }
}

void loop()
{
  if (inicioClicado) {
    inicioGame(); 
  }
  if (pularClicado) {
    pular(); 
  }

  if (jogoRodando) {
    cronometro();

    lcd.setCursor(5,0);
    lcd.print(segundos);    

    if (!perguntaRespondida) {
      checkButtons();
    }
    else if (perguntaRespondida) {
      if (NumQuestions < 16) {
        exibirPergunta(true); 
      }
    }
  }
}
