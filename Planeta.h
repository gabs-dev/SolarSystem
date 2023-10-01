#pragma once
#ifndef PLANETA_H
#define PLANETA_H

typedef struct Lua
{
    double raio;
    double raioOrbita;
    double angulo;
    double velocidadeTranslacao;
};

struct Planeta 
{
    double raio; // Raio do planeta
    double raioOrbita; // Raio da órbita
    double angulo; // Ângulo da órbita (em graus)
    double velocidadeTranslacao; // Velocidade de translação
    double velocidadeRotacao; // Velocidade de rotação
    bool exibir = true; // Atributo para indicar se o planeta deverá ou não ser exibido na tela
    Lua lua;
};

// Função para inicar a animação do processo de tranlação do pleneta.
// O tempo é o incremento que será feito no valor ângulo para fazer a rotação.
void iniciarTranslacao(Planeta& planeta);

// Retorna a posição X do planeta no sitema de coordenadas.
double getPosicaoX(Planeta& planeta);

// Retorna a posição Y do planeta no sitema de coordenadas.
double getPosicaoY(Planeta& planeta);

void iniciarTranslacaoLua(Lua& lua);

double getPosicaoXLua(Planeta& planeta);

double getPosicaoYLua(Planeta& planeta);

Lua criarLua(double raio, double raioOrbita, double angulo, double velocidadeTranslacao);

#endif // !PLANETA_H
