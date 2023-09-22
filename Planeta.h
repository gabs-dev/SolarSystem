#pragma once
#ifndef PLANETA_H
#define PLANETA_H

struct Planeta {
    double raio; // Raio do planeta
    double raioOrbita; // Raio da órbita
    double angulo; // Ângulo da órbita (em graus)
    double velocidadeTranslacao; // Velocidade de translação
    double velocidadeRotacao; // Velocidade de rotação
};

// Função para inicar a animação do processo de tranlação do pleneta.
// O tempo é o incremento que será feito no valor ângulo para fazer a rotação.
void iniciarTranslacao(Planeta& planeta);

// Retorna a posição X do planeta no sitema de coordenadas.
double getPosicaoX(Planeta& planeta);

// Retorna a posição Y do planeta no sitema de coordenadas.
double getPosicaoY(Planeta& planeta);

#endif // !PLANETA_H
