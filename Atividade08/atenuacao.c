#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void lighting() {
    //define a posição e parâmetros da luz 0
    GLfloat position [] = { 0.0, 0.0, 6.0} ;
    GLfloat direction[] = { 0.0, 0.0, -1.0};

    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightf ( GL_LIGHT0, GL_SPOT_EXPONENT , 1.0);
    glLightf ( GL_LIGHT0, GL_SPOT_CUTOFF, 70.0);

    //ativa a iluminação
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); //define a cor de fundo
    glEnable(GL_DEPTH_TEST); //habilita o teste de profundidade

    glMatrixMode(GL_MODELVIEW); //define que a matrix é a model view
    glLoadIdentity(); //carrega a matrix de identidade
    gluLookAt(0.0, 0.0, 1.0, //posição da câmera
              0.0, 0.0, 0.0, //para onde a câmera aponta
              0.0, 1.0, 0.0); //vetor view-up

    glMatrixMode(GL_PROJECTION); //define que a matrix é a de projeção
    glLoadIdentity(); //carrega a matrix de identidade
    glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0);

    lighting(); //defininido os parâmetros de iluminação
}

void displayFunc() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //define que a matrix é a a model view
    glMatrixMode(GL_MODELVIEW);
    
    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(-1.5, 0.0, 0.0);
        glutSolidSphere(0.2, 40, 40);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.0, 1.0, 0.0);   
        glTranslatef(1.5, 0.0, 0.0);
        glutSolidSphere(0.2, 40, 40);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.0, 0.0, 1.0);
        glTranslatef(0.0, -1.5, 0.0);
        glutSolidSphere(0.2, 40, 40);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0, 1.0, 0.0);
        glTranslatef(0.0, 1.5, 0.0);
        glutSolidSphere(0.2, 40, 40);
    glPopMatrix();
    

    //força o desenho das primitivas
    glFlush();
}

int main(int argc, char *argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(500,500);
	glutCreateWindow("Viewing 3D - Projecao Perspectiva");
	glutDisplayFunc(displayFunc);
	init();
	glutMainLoop();
	return 0;
}