#include "Planeta.h"
#define _USE_MATH_DEFINES
#include <cmath>

void iniciarTranslacao(Planeta& planeta) {
	planeta.angulo += planeta.velocidadeTranslacao;
}

double getPosicaoX(Planeta& planeta) {
	double x = planeta.raioOrbita * cos(planeta.angulo);

	return x;
}

double getPosicaoY(Planeta& planeta) {
	double y = planeta.raioOrbita * sin(planeta.angulo);

	return y;
}