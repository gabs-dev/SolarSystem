#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>

#define _USE_MATH_DEFINES
#include <cmath>

#include "Planeta.h";

#include <iostream>

// vari?veis globais
GLfloat eixo = 125;
int tempo = 150;
bool pausado = false;
bool exibirOrbita = true;

Planeta mercurio;
Planeta venus;
Planeta terra;
Planeta marte;
Planeta jupter;
Planeta saturno;
Planeta urano;
Planeta netuno;

static void criarPlanetas() {
	#pragma region Mercúrio

	mercurio.raio = 2;
	mercurio.angulo = 30;
	mercurio.raioOrbita = 15;
	mercurio.velocidadeRotacao = 0;
	mercurio.velocidadeTranslacao = 0.2;

	#pragma endregion

	#pragma region Vênus

	venus.raio = 3;
	venus.angulo = 60;
	venus.raioOrbita = 25;
	venus.velocidadeRotacao = 0;
	venus.velocidadeTranslacao = 0.09;

	#pragma endregion

	#pragma region Terra

	terra.raio = 3;
	terra.angulo = 95;
	terra.raioOrbita = 40;
	terra.velocidadeRotacao = 0;
	terra.velocidadeTranslacao = 0.06;

	/*Lua luaTerra;
	luaTerra.raio = 1;
	luaTerra.raioOrbita = terra.raio + 2;
	luaTerra.angulo = 0;
	luaTerra.velocidadeTranslacao = 0.3;*/

	terra.lua = criarLua(1, terra.raio + 2, 0, 0.3);

	#pragma endregion

	#pragma region Marte

	marte.raio = 2.5;
	marte.angulo = 120;
	marte.raioOrbita = 55;
	marte.velocidadeRotacao = 0;
	marte.velocidadeTranslacao = 0.03;

	marte.lua = criarLua(1, marte.raio + 2, 30, 0.3);

	#pragma endregion

	#pragma region Júpter

	jupter.raio = 4.5;
	jupter.angulo = 210;
	jupter.raioOrbita = 70;
	jupter.velocidadeRotacao = 0;
	jupter.velocidadeTranslacao = 0.005;

	jupter.lua = criarLua(1, jupter.raio + 2, 60, 0.1);

	#pragma endregion

	#pragma region Saturno

	saturno.raio = 4;
	saturno.angulo = 125;
	saturno.raioOrbita = 85;
	saturno.velocidadeRotacao = 0;
	saturno.velocidadeTranslacao = 0.002;

	Lua luaSatruno;
	luaSatruno.raio = 1;
	luaSatruno.raioOrbita = saturno.raio + 2;
	luaSatruno.angulo = 30;
	luaSatruno.velocidadeTranslacao = 0.3;

	saturno.lua = criarLua(1, saturno.raio + 2, 0, 0.2);;

	#pragma endregion

	#pragma region Urano

	urano.raio = 3.5;
	urano.angulo = 280;
	urano.raioOrbita = 100;
	urano.velocidadeRotacao = 0;
	urano.velocidadeTranslacao = 0.001;

	urano.lua = criarLua(1, urano.raio + 2, 270, -0.2);

	#pragma endregion

	#pragma region Netuno

	netuno.raio = 3.5;
	netuno.angulo = 320;
	netuno.raioOrbita = 115;
	netuno.velocidadeRotacao = 0;
	netuno.velocidadeTranslacao = 0.0009;

	netuno.lua = criarLua(1, netuno.raio + 2, -90, 0.2);

	#pragma endregion
}

static void desenharPlaneta(float raio)
{
	float angulo, incremento;

	incremento = (2 * M_PI) / 100;

	glBegin(GL_POLYGON);
	for (angulo = 0; angulo < (2 * M_PI); angulo += incremento) {
		glVertex2f(raio * cos(angulo), raio * sin(angulo));
	}
	glEnd();
}

static void desenharOrbita(int vertices, double raio)
{
	float angulo, incremento;

	incremento = (2 * M_PI) / vertices;

	glBegin(GL_LINE_LOOP);
	for (angulo = 0; angulo < (2 * M_PI); angulo += incremento) {
		glVertex2f(raio * cos(angulo), raio * sin(angulo));
	}
	glEnd();
}

static void orbita(Planeta planeta) {
	if (exibirOrbita) {
		glPushMatrix();
			glColor3f(1.0f, 1.0f, 1.0f);
			desenharOrbita(100, planeta.raioOrbita);
		glPopMatrix();
	}
}

static void planeta(Planeta planeta, GLfloat color[]) {
	glPushMatrix();
		glTranslatef(getPosicaoX(planeta), getPosicaoY(planeta), 0.0f);
		glColor3f(color[0], color[1], color[2]);
		desenharPlaneta(planeta.raio);
	glPopMatrix();
}

// função de redimensionamento da janela de visualiza??o
static void resize(int width, int height) {
}


// função de redesenho da janela de visualiza??o
static void display() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT);

	#pragma region SOL

	// DESENHA O SOL
	glPushMatrix();
	//glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	desenharPlaneta(8);
	glPopMatrix();

	#pragma endregion
	
	#pragma region MERCÚRIO

	// DESENHA A ÓRBITA DE MERCÚRIO

	orbita(mercurio);

	// DESENHA MERCÚRIO
	if (mercurio.exibir) {
		GLfloat corMercurio[] = { 0.6f, 0.6f, 0.6f };
		planeta(mercurio, corMercurio);
	}

	#pragma endregion

	#pragma region VÊNUS

	// ÓRBITA DE VÊNUS
	orbita(venus);

	// VÊNUS
	if (venus.exibir) {
		GLfloat corVenus[] = { 0.9f, 0.6f, 0.1f };
		planeta(venus, corVenus);
	}

	#pragma endregion

	#pragma region TERRA

	// ÓRBITA DA TERRA
	orbita(terra);

	if (terra.exibir) {
		// TERRA
		GLfloat corTerra[] = { 0.2f, 0.0f, 1.0f };
		planeta(terra, corTerra);

		// LUA
		glPushMatrix();
			glTranslatef(getPosicaoXLua(terra), getPosicaoYLua(terra), 0.0f);
			glColor3f(1.0f, 0.9f, 0.2f);
			desenharPlaneta(terra.lua.raio);
		glPopMatrix();
	}

	#pragma endregion

	#pragma region MARTE

	// ÓRBITA DE MARTE
	orbita(marte);

	if (marte.exibir) {
		// MARTE
		GLfloat corMarte[] = { 0.8f, 0.0f, 0.0f };
		planeta(marte, corMarte);

		// LUA
		glPushMatrix();
			glTranslatef(getPosicaoXLua(marte), getPosicaoYLua(marte), 0.0f);
			glColor3f(1.0f, 0.9f, 0.2f);
			desenharPlaneta(marte.lua.raio);
		glPopMatrix();
	}

	#pragma endregion

	#pragma region JÚPTER

	// ÓRBITA DE JÚPTER
	orbita(jupter);

	if (jupter.exibir) {
		// JÚPTER
		GLfloat corJupter[] = { 0.7f, 0.5f, 0.0f };
		planeta(jupter, corJupter);

		// ANEL DO PLANETA
		glPushMatrix();
			glTranslatef(getPosicaoX(jupter), getPosicaoY(jupter), 0.0f);
			glColor3f(1.0f, 1.0f, 1.0f);
			desenharOrbita(50, jupter.lua.raioOrbita);
		glPopMatrix();

		// LUA
		glPushMatrix();
			glTranslatef(getPosicaoXLua(jupter), getPosicaoYLua(jupter), 0.0f);
			glColor3f(1.0f, 0.9f, 0.2f);
			desenharPlaneta(jupter.lua.raio);
		glPopMatrix();
	}

	#pragma endregion

	#pragma region SATURNO

	// ÓRBITA DE SATURNO
	orbita(saturno);

	if (saturno.exibir) {
		// SATURNO
		GLfloat corSaturno[] = { 0.9f, 0.4f, 0.1f };
		planeta(saturno, corSaturno);

		// ANÉIS DO PLANETA
		glPushMatrix();
			glTranslatef(getPosicaoX(saturno), getPosicaoY(saturno), 0.0f);
			glColor3f(1.0f, 1.0f, 1.0f);
			desenharOrbita(50, saturno.lua.raioOrbita);
			desenharOrbita(50, saturno.lua.raioOrbita + 1);
			desenharOrbita(50, saturno.lua.raioOrbita + 1.5);
			desenharOrbita(50, saturno.lua.raioOrbita + 1.6);
			desenharOrbita(50, saturno.lua.raioOrbita + 1.7);
		glPopMatrix();

		// LUA
		glPushMatrix();
			glTranslatef(getPosicaoXLua(saturno), getPosicaoYLua(saturno), 0.0f);
			glColor3f(1.0f, 0.9f, 0.2f);
			desenharPlaneta(saturno.lua.raio);
		glPopMatrix();
	}

	#pragma endregion

	#pragma region URANO

	// ÓRBITA DE URANO
	orbita(urano);

	if (urano.exibir) {
		// URANO
		GLfloat corUrano[] = { 0.1f, 0.8f, 0.7f };
		planeta(urano, corUrano);

		// ANEL DO PLANETA
		glPushMatrix();
			glTranslatef(getPosicaoX(urano), getPosicaoY(urano), 0.0f);
			glColor3f(1.0f, 1.0f, 1.0f);
			desenharOrbita(50, urano.lua.raioOrbita);
		glPopMatrix();

		// LUA
		glPushMatrix();
			glTranslatef(getPosicaoXLua(urano), getPosicaoYLua(urano), 0.0f);
			glColor3f(1.0f, 0.9f, 0.2f);
			desenharPlaneta(urano.lua.raio);
		glPopMatrix();
	}

	#pragma endregion

	#pragma region NETUNO

	// ÓRBITA DE NETUNO
	orbita(netuno);

	if (netuno.exibir) {
		// NETUNO
		GLfloat corNeturno[] = { 0.1f, 0.6f, 1.0f };
		planeta(netuno, corNeturno);

		// ANEL DO PLANETA
		glPushMatrix();
			glTranslatef(getPosicaoX(netuno), getPosicaoY(netuno), 0.0f);
			glColor3f(1.0f, 1.0f, 1.0f);
			desenharOrbita(50, netuno.lua.raioOrbita);
		glPopMatrix();

		// LUA
		glPushMatrix();
			glTranslatef(getPosicaoXLua(netuno), getPosicaoYLua(netuno), 0.0f);
			glColor3f(1.0f, 0.9f, 0.2f);
			desenharPlaneta(netuno.lua.raio);
		glPopMatrix();
	}

	#pragma endregion

	glutSwapBuffers();
}

void animar(int value)
{
	if (!pausado) {
		iniciarTranslacao(mercurio);
		iniciarTranslacao(venus);
		iniciarTranslacao(terra);
		iniciarTranslacao(marte);
		iniciarTranslacao(jupter);
		iniciarTranslacao(saturno);
		iniciarTranslacao(urano);
		iniciarTranslacao(netuno);

		glutPostRedisplay();
		glutTimerFunc(tempo, animar, 1);
	}
}

static void pausar() {

	pausado = !pausado;

	if (!pausado)
		animar(0);

}

static void exibirPlaneta(unsigned char key) {
	int index = key - '0';

	index = index - 1;

	if (index >= 0 && index <= 7) {
		switch (index)
		{
			case 0:
				mercurio.exibir = !mercurio.exibir;
				break;
			case 1:
				venus.exibir = !venus.exibir;
				break;
			case 2:
				terra.exibir = !terra.exibir;
				break;
			case 3:
				marte.exibir = !marte.exibir;
				break;
			case 4:
				jupter.exibir = !jupter.exibir;
				break;
			case 5:
				saturno.exibir = !saturno.exibir;
				break;
			case 6:
				urano.exibir = !urano.exibir;
				break;
			case 7:
				netuno.exibir = !netuno.exibir;
				break;
		}
	}
}

// fun??o para tratar os eventos do teclado
static void key(unsigned char key, int x, int y) {
	if (key == 27)
		exit(0);

	switch (key)
	{
		case '+': // Aumenta a velocidade de translação dos planetas
			tempo = tempo == 0 ? 0 : (tempo - 1);
			break;
		case '-': // Diminui a velocidade de translação dos planetas
			tempo++;
			break;
		case 'p':
		case 'P': // Play/pause na animação
			pausar();
			break;
		case 'o':
		case 'O': // Exibir/ocultar órbitas dos planetas
			exibirOrbita = !exibirOrbita;
			break;
		default:
			exibirPlaneta(key); // Teclas de 1 a 8 exibem/ocultam os seus respectivos planetas.
			break;
	}

	display();
}

// fun??o respons?vel por fazer as inicializa??es
void setup(void) {
	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0f, 0.0f, 0.0f);

	glViewport(0, 0, 800, 800);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-eixo, eixo, -eixo, eixo);

}

// Programa Principal
int main(int argc, char* argv[]) {
	criarPlanetas();

	// utilizada para inicializar a biblioteca GLUT
	glutInit(&argc, argv);

	// define do modo de opera??o da GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	// especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(800, 800);

	// especifica a posi??o inicial da janela GLUT
	glutInitWindowPosition(100, 100);

	// cria a janela passando como t?tulo como argumento
	glutCreateWindow("Sistema Solar");

	// registra a fun??o callback de redesenho da janela de visualiza??o
	glutDisplayFunc(display);

	// registra a fun??o callback para tratar os eventos do teclado
	glutKeyboardFunc(key);

	// registra a fun??o callback de redimensionamento da janela de visualiza??o
	glutReshapeFunc(resize);

	// Registra a fun??o callback que ser? chamada a cada intervalo de tempo
	//https://www.opengl.org/resources/libraries/glut/spec3/node64.html
	glutTimerFunc(tempo, animar, 1);

	// chama a fun??o respons?vel por fazer as inicializa??es
	setup();

	// inicia o processamento e aguarda intera??es do usu?rio
	glutMainLoop();

	return 0;
}
