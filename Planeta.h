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
    double raioOrbita; // Raio da �rbita
    double angulo; // �ngulo da �rbita (em graus)
    double velocidadeTranslacao; // Velocidade de transla��o
    double velocidadeRotacao; // Velocidade de rota��o
    bool exibir = true; // Atributo para indicar se o planeta dever� ou n�o ser exibido na tela
    Lua lua;
};

// Fun��o para inicar a anima��o do processo de tranla��o do pleneta.
// O tempo � o incremento que ser� feito no valor �ngulo para fazer a rota��o.
void iniciarTranslacao(Planeta& planeta);

// Retorna a posi��o X do planeta no sitema de coordenadas.
double getPosicaoX(Planeta& planeta);

// Retorna a posi��o Y do planeta no sitema de coordenadas.
double getPosicaoY(Planeta& planeta);

void iniciarTranslacaoLua(Lua& lua);

double getPosicaoXLua(Planeta& planeta);

double getPosicaoYLua(Planeta& planeta);

Lua criarLua(double raio, double raioOrbita, double angulo, double velocidadeTranslacao);

#endif // !PLANETA_H
