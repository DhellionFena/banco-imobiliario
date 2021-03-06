# Banco Imobiliário - Versão SENAI Cimatec
Jogo feito em C++ para a terceira avaliação da disciplina Algoritmos e Estruturas de dados I

## O jogo

Banco Imobiliário padrão:

<img src="https://i.pinimg.com/originals/80/f9/20/80f9201bb694c97f9f868c692e3dd6e5.jpg" width=200px height=200px title="jogo padrão"/>

### Qual o objetivo do jogo?
Conquistar a maior fortuna possível e levar os outros jogadores à falência.

### Preparação
Os jogadores, de 2 a 4, deverão escolher o peão e posicioná-los na casa ‘início’.

### Começa o Jogo
Dispute nos dados quem será o primeiro a jogar. Quem tirar o maior número no dado começa o jogo.

O jogador começa a rodada jogando os dois dados e somando o resultado, então avançar com o peão a quantidade de casas e cumprir o que determina aquela casa.

Caso o jogador tire nos dados dois números iguais, ele tem direito a novo lançamento. Caso tire dois números iguais três vezes, ele vai para a prisão.
#
## Tecnologia utilizada

A tecnologia utilizada para o desenvolvimento do jogo foi a Línguagem de Programação C++.

<div align="center">
    <img src="https://raw.githubusercontent.com/isocpp/logos/master/cpp_logo.png" width=100px title="C++ Logo"/>
</div>

## Funcionalidades implementadas
- Sistema de sorteio, utilizando os dados, para decidir quem será o primeiro a jogar
- Tabuleiro adaptado ao terminal
- Ranking dos jogadores
- Geração de um arquivo binário contendo o ranking

## Como jogar em seu computador

- Caso tenha o Git instalado em seu computador:

1. No repositório, clique no botão verde 'Code'.
2. Copie o link
3. Reserve um diretório em seu computador para clonar o repositório
4. Abra o terminal no diretório criado
5. Digite 'git clone (cole o link aqui)'
6. Dentro da pasta gerada, abra novamente o terminal
7. Digite os seguintes comandos:

```bash
g++ main.cpp -o main
.\main
```
8. Após rodar o jogo pela primeira vez, será gerado um 'main.exe', utilize-o para jogar outras vezes apenas clicando nele.

#
## Sobre o projeto
### Matéria
- Algoritmos e Estruturas de Dados I
### Equipe
- Amanda Rigaud
- Antônio César
- Felipe Ribeiro
### Docente
- Marcos Lapa