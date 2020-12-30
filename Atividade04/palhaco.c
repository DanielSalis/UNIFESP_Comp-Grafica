#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float angX = 0.0;
float angY = 0.0;
int opcao = 0;

void init(){
     glClearColor(0.0,0.0,0.0,0.0);
     glEnable(GL_DEPTH_TEST); //habilita o teste de profundidade
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     glOrtho(-7.0,7.0,-7.0,7.0,-7.0,7.0);
     glPushMatrix();
}


void desenhaCabeca(){
    glColor3f(0.0,0.0,1.0);
    glutWireSphere(2.0, 20, 20);
}

void desenhaChapeu(){
    glColor3f(0.0,1.0,0.0);
    glRotatef(30.0, 0.0, 0.0, 1.0);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glTranslatef(0.0, 0.0, 2.0);
    glutWireCone(2.0,4.0,20,20);
    glutWireTorus(0.2, 2.2, 10, 25);
}

void desenhaNariz(){
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(0.0, 0.0, 4.0);
    glutWireSphere(0.5, 20, 20);
}

void desenhaCabeloEsquerda(){
    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(-2.5, 0.0, 0.0);
        glutWireSphere(0.5, 10, 10);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(-2.2, 0.7 , 0.0);
        glutWireSphere(0.5, 10, 10);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(-2.2, -0.7, 0.0);
        glutWireSphere(0.5, 10, 10);
    glPopMatrix();
}

void desenhaCabeloDireita(){
    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(2.5, 0.0, 0.0);
        glutWireSphere(0.5, 10, 10);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(2.2, 0.7 , 0.0);
        glutWireSphere(0.5, 10, 10);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0, 0.0, 0.0);
        glTranslatef(2.2, -0.7, 0.0);
        glutWireSphere(0.5, 10, 10);
    glPopMatrix();
}

void display()
{
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -9.0);

    glPopMatrix();
    glPushMatrix();

    desenhaCabeca();

    glPushMatrix();
        desenhaChapeu();
    glPopMatrix();

    glPushMatrix();
        desenhaNariz();
    glPopMatrix();
    

    desenhaCabeloEsquerda();
    desenhaCabeloDireita();

    glutSwapBuffers();
}

void anima()
{
    switch (opcao) {
        case 1:
            angX+=5;
            break;
        case 2:
            angX-=5;
            break;
        case 3:
            angY+=5;
            break;
        case 4:
            angY-=5;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void rotacoes(int key, int x, int y){
     glutIdleFunc(anima);
     switch (key){
        case GLUT_KEY_UP :
           opcao = 1;
           break ;
        case GLUT_KEY_DOWN :
           opcao = 2;
           break ;
        case GLUT_KEY_LEFT :
           opcao = 3;
           break ;
        case GLUT_KEY_RIGHT :
           glutIdleFunc(NULL);
           opcao = 4;
           break ;
        default:
           break;
     }
}

int main(int argc, char *argv[])
{
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
     glutInitWindowPosition(50,50);
     glutInitWindowSize(600,600);
     glutCreateWindow("Palhaco Animado - OpenGL");
     glutDisplayFunc(display);
     glutSpecialFunc(rotacoes);
     glutIdleFunc(anima);
     init();
     glutMainLoop();
}