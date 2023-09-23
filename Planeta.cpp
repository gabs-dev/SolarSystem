#include "Planeta.h"
#define _USE_MATH_DEFINES
#include <cmath>

void iniciarTranslacao(Planeta& planeta);
double getPosicaoX(Planeta& planeta);
double getPosicaoY(Planeta& planeta);
void iniciarTranslacaoLua(Lua& lua);
double getPosicaoXLua(Planeta& planeta);
double getPosicaoYLua(Planeta& planeta);


void iniciarTranslacao(Planeta& planeta) {
	planeta.angulo += planeta.velocidadeTranslacao;
	iniciarTranslacaoLua(planeta.lua);
}

double getPosicaoX(Planeta& planeta) {
	double x = planeta.raioOrbita * cos(planeta.angulo);

	return x;
}

double getPosicaoY(Planeta& planeta) {
	double y = planeta.raioOrbita * sin(planeta.angulo);

	return y;
}

void iniciarTranslacaoLua(Lua& lua) {
	lua.angulo += lua.velocidadeTranslacao;
}

double getPosicaoXLua(Planeta& planeta) {
	double x = getPosicaoX(planeta) + ((planeta.lua.raioOrbita) * cos(planeta.lua.angulo));

	return x;
}

double getPosicaoYLua(Planeta& planeta) {
	double y = getPosicaoY(planeta) + ((planeta.lua.raioOrbita) * sin(planeta.lua.angulo));

	return y;
}

Lua criarLua(double raio, double raioOrbita, double angulo, double velocidadeTranslacao) {
	Lua lua;
	lua.raio = raio;
	lua.raioOrbita = raioOrbita;
	lua.angulo = angulo;
	lua.velocidadeTranslacao = velocidadeTranslacao;

	return lua;
}