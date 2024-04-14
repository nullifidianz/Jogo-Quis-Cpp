
## Authors

- [João Paulo Paggi Zuanon Dias](https://github.com/nullifidianz)
- [Thales Clemente Pasquotto](https://github.com/thaleeews)

# Jogo quiz para arduino UNO

Jogo de quiz simples implementado em uma plataforma Arduino usando um display de LCD e botões de pressão. O jogo apresenta perguntas com uma resposta binária (Sim ou Não) e calcula a pontuação com base nas respostas corretas. Ele inclui recursos como pular perguntas e um cronômetro. São armazenadas perguntas do nível facíl, médio e difícil e a sua seleção é feita de maneira aleatória para cada partida.

# Funcionalidades
- O jogo começa quando o botão "Iniciar" é pressionado.
- As perguntas são exibidas uma por uma de maneira aleatória e sempre contando com uma final, e o jogador deve responder dentro de um limite de tempo.
- O jogador tem o limite de três pulos de perguntas por jogo.
- O jogo acompanha a pontuação e a exibe após todas as perguntas serem respondidas ou quando o tempo acabar.
- O LED pisca quando o tempo de resposta estiver perto do fim.
- Caso o jogador vença, uma música de vitória será tocada.

# Mecânica do Jogo
- Cada pergunta tem uma resposta correta predefinida (Sim ou Não).
- O jogador ganha pontos para cada resposta correta, com valores de pontos diferentes para diferentes perguntas.
- O jogador perde se o tempo acabar ou se der uma resposta errada depois de ficar sem pulos.
- O jogo inclui um cronômetro regressivo exibido no LCD.

# Componentes Utilizados
- Arduino UNO
- 1 LED vermelho
- 4 botões (push buttons) 
- Resistores conforme necessidade
- Buzzer
- Display LCD 16x2

**Testes Iniciais Feitos usando as plataformas Thinkercad e Fritzing antes da montagem usando a placa física.**

## Images
![foto 1](https://github.com/nullifidianz/Jogo-Quiz-Cpp/blob/main/fotos/img1)
![foto 2](https://github.com/nullifidianz/Jogo-Quiz-Cpp/blob/main/fotos/img2)
![foto 3](https://github.com/nullifidianz/Jogo-Quiz-Cpp/blob/main/fotos/img3)
![foto 4](https://github.com/nullifidianz/Jogo-Quiz-Cpp/blob/main/fotos/img4)
## Documentação Consultada

[Arduino Documentation](https://docs.arduino.cc/)
