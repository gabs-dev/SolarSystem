#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdio.h>

#define _USE_MATH_DEFINES
#include <cmath>

#include "Planeta.h";

// vari?veis globais
GLfloat eixo = 120;
GLfloat angulo = 30;

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
	mercurio.velocidadeTranslacao = 0.3;

	#pragma endregion

	#pragma region Vênus

	venus.raio = 3;
	venus.angulo = 60;
	venus.raioOrbita = 25;
	venus.velocidadeRotacao = 0;
	venus.velocidadeTranslacao = 0.07;

	#pragma endregion

	#pragma region Terra

	terra.raio = 3;
	terra.angulo = 95;
	terra.raioOrbita = 40;
	terra.velocidadeRotacao = 0;
	terra.velocidadeTranslacao = 0.04;

	#pragma endregion

	#pragma region Marte

	marte.raio = 2.5;
	marte.angulo = 120;
	marte.raioOrbita = 55;
	marte.velocidadeRotacao = 0;
	marte.velocidadeTranslacao = 0.02;

	#pragma endregion

	#pragma region Júpter

	jupter.raio = 4.5;
	jupter.angulo = 210;
	jupter.raioOrbita = 70;
	jupter.velocidadeRotacao = 0;
	jupter.velocidadeTranslacao = 0.003;

	#pragma endregion

	#pragma region Saturno

	saturno.raio = 4;
	saturno.angulo = 125;
	saturno.raioOrbita = 85;
	saturno.velocidadeRotacao = 0;
	saturno.velocidadeTranslacao = 0.001;

	#pragma endregion

	#pragma region Urano

	urano.raio = 3.5;
	urano.angulo = 280;
	urano.raioOrbita = 95;
	urano.velocidadeRotacao = 0;
	urano.velocidadeTranslacao = 0.0009;

	#pragma endregion

	#pragma region Netuno

	netuno.raio = 3.5;
	netuno.angulo = 320;
	netuno.raioOrbita = 110;
	netuno.velocidadeRotacao = 0;
	netuno.velocidadeTranslacao = 0.0005;

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

static void desenharOrbita(int vertices, int raio)
{
	float angulo, incremento;

	incremento = (2 * M_PI) / vertices;

	glBegin(GL_LINE_LOOP);
	for (angulo = 0; angulo < (2 * M_PI); angulo += incremento) {
		glVertex2f(raio * cos(angulo), raio * sin(angulo));
	}
	glEnd();
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
	glPushMatrix();
		//glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
		glColor3f(0.6f, 0.6f, 0.6f);
		desenharOrbita(50, mercurio.raioOrbita);
	glPopMatrix();

	// DESENHA MERCÚRIO
	glPushMatrix();
		glTranslatef(getPosicaoX(mercurio), getPosicaoY(mercurio), 0.0f);
		glColor3f(0.6f, 0.6f, 0.6f);
		desenharPlaneta(mercurio.raio);
	glPopMatrix();

	#pragma endregion

	#pragma region VÊNUS

	// ÓRBITA DE VÊNUS
	glPushMatrix();
		glColor3f(0.9f, 0.6f, 0.1f);
		desenharOrbita(100, venus.raioOrbita);
	glPopMatrix();

	// VÊNUS
	glPushMatrix();
		glTranslatef(getPosicaoX(venus), getPosicaoY(venus), 0.0f);
		glColor3f(0.9f, 0.6f, 0.1f);
		desenharPlaneta(venus.raio);
	glPopMatrix();

	#pragma endregion

	#pragma region TERRA

	// ÓRBITA DA TERRA
	glPushMatrix();
		glColor3f(0.2f, 0.0f, 1.0f);
		desenharOrbita(100, terra.raioOrbita);
	glPopMatrix();

	// TERRA
	glPushMatrix();
		glTranslatef(getPosicaoX(terra), getPosicaoY(terra), 0.0f);
		glColor3f(0.2f, 0.0f, 1.0f);
		desenharPlaneta(terra.raio);
	glPopMatrix();

	#pragma endregion

	#pragma region MARTE

	// ÓRBITA DE MARTE
	glPushMatrix();
		glColor3f(0.8f, 0.0f, 0.0f);
		desenharOrbita(100, marte.raioOrbita);
	glPopMatrix();

	// MARTE
	glPushMatrix();
		glTranslatef(getPosicaoX(marte), getPosicaoY(marte), 0.0f);
		glColor3f(0.8f, 0.0f, 0.0f);
		desenharPlaneta(marte.raio);
	glPopMatrix();

	#pragma endregion

	#pragma region JÚPTER

	// ÓRBITA DE JÚPTER
	glPushMatrix();
		glColor3f(0.7f, 0.5f, 0.0f);
		desenharOrbita(100, jupter.raioOrbita);
	glPopMatrix();

	// JÚPTER
	glPushMatrix();
		glTranslatef(getPosicaoX(jupter), getPosicaoY(jupter), 0.0f);
		glColor3f(0.7f, 0.5f, 0.0f);
		desenharPlaneta(jupter.raio);
	glPopMatrix();

	#pragma endregion

	#pragma region SATURNO

	// ÓRBITA DE SATURNO
	glPushMatrix();
		glColor3f(0.9f, 0.4f, 0.1f);
		desenharOrbita(100, saturno.raioOrbita);
	glPopMatrix();

	// SATURNO
	glPushMatrix();
		glTranslatef(getPosicaoX(saturno), getPosicaoY(saturno), 0.0f);
		glColor3f(0.9f, 0.4f, 0.1f);
		desenharPlaneta(saturno.raio);
	glPopMatrix();

	#pragma endregion

	#pragma region URANO

	// ÓRBITA DE URANO
	glPushMatrix();
		glColor3f(0.1f, 0.8f, 0.7f);
		desenharOrbita(100, urano.raioOrbita);
	glPopMatrix();

	// URANO
	glPushMatrix();
		glTranslatef(getPosicaoX(urano), getPosicaoY(urano), 0.0f);
		glColor3f(0.1f, 0.8f, 0.7f);
		desenharPlaneta(urano.raio);
	glPopMatrix();

	#pragma endregion

	#pragma region NETUNO

	// ÓRBITA DE NETUNO
	glPushMatrix();
		glColor3f(0.1f, 0.6f, 1.0f);
		desenharOrbita(100, netuno.raioOrbita);
	glPopMatrix();

	// NETUNO
	glPushMatrix();
		glTranslatef(getPosicaoX(netuno), getPosicaoY(netuno), 0.0f);
		glColor3f(0.1f, 0.6f, 1.0f);
		desenharPlaneta(netuno.raio);
	glPopMatrix();

	#pragma endregion

	glutSwapBuffers();
}

void animar(int value)
{
	angulo += 0.3;

	iniciarTranslacao(mercurio);
	iniciarTranslacao(venus);
	iniciarTranslacao(terra);
	iniciarTranslacao(marte);
	iniciarTranslacao(jupter);
	iniciarTranslacao(saturno);
	iniciarTranslacao(urano);
	iniciarTranslacao(netuno);

	glutPostRedisplay();
	glutTimerFunc(150, animar, 1);
}

// fun??o para tratar os eventos do teclado
static void key(unsigned char key, int x, int y) {
	if (key == 27)
		exit(0);
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
	glutTimerFunc(150, animar, 1);

	// chama a fun??o respons?vel por fazer as inicializa??es
	setup();

	// inicia o processamento e aguarda intera??es do usu?rio
	glutMainLoop();

	return 0;
}
