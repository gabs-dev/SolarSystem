#pragma once
#ifndef PLANETA_H
#define PLANETA_H

struct Planeta {
    double raio; // Raio do planeta
    double raioOrbita; // Raio da �rbita
    double angulo; // �ngulo da �rbita (em graus)
    double velocidadeTranslacao; // Velocidade de transla��o
    double velocidadeRotacao; // Velocidade de rota��o
};

// Fun��o para inicar a anima��o do processo de tranla��o do pleneta.
// O tempo � o incremento que ser� feito no valor �ngulo para fazer a rota��o.
void iniciarTranslacao(Planeta& planeta);

// Retorna a posi��o X do planeta no sitema de coordenadas.
double getPosicaoX(Planeta& planeta);

// Retorna a posi��o Y do planeta no sitema de coordenadas.
double getPosicaoY(Planeta& planeta);

#endif // !PLANETA_H
