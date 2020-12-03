#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

float up = 0.0;
float right = 0.0;
float colors[3] = {1.0, 1.0, 1.0};

void line()
{
    glColor3f(colors[0], colors[1], colors[2]); //point color
    glPointSize(5.0f);                          //point size
    glBegin(GL_LINES);
        glVertex2f(0.0, 0.0);
        glVertex2f(up, right);
    glEnd();
}

void desenha()
{
    glClearColor(0, 0, 0, 0); //Backgroung
    glClear(GL_COLOR_BUFFER_BIT);
    line();
    glFlush();
}

void mouse(int botao, int estado, int x, int y)
{
    float mx = x;
    float my = y;
    float ox = (mx / 200 - 1.0);
    float oy = -(my / 200 - 1.0);

    switch (botao)
    {
    case GLUT_LEFT_BUTTON:
        if (estado == GLUT_DOWN)
        {
            printf("x = %f, y = %f\n", ox, oy);
            up = ox;
            right = oy;
            line();
        }
        break;

    default:
        break;
    }
    glutPostRedisplay();
}

void teclado(unsigned char tecla, int x, int y)
{
    switch (tecla)
    {
    case '0':
        colors[0] = 0.0;
        colors[1] = 0.0;
        colors[2] = 0.0;
        break;
    case '1':
        colors[0] = 1.0;
        colors[1] = 1.0;
        colors[2] = 1.0;
        break;
    case '2':
        colors[0] = 0.0;
        colors[1] = 1.0;
        colors[2] = 1.0;
        break;
    case '3':
        colors[0] = 1.0;
        colors[1] = 0.0;
        colors[2] = 1.0;
        break;
    case '4':
        colors[0] = 1.0;
        colors[1] = 1.0;
        colors[2] = 0.0;
        break;
    case '5':
        colors[0] = 1.0;
        colors[1] = 1.0;
        colors[2] = 0.5;
        break;
    case '6':
        colors[0] = 0.5;
        colors[1] = 1.0;
        colors[2] = 0.0;
        break;
    case '7':
        colors[0] = 1.0;
        colors[1] = 0.5;
        colors[2] = 0.0;
        break;
    case '8':
        colors[0] = 0.5;
        colors[1] = 0.0;
        colors[2] = 0.0;
        break;
    case '9':
        colors[0] = 0.5;
        colors[1] = 0.5;
        colors[2] = 0.5;
        break;

    default:
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(400, 400);

    glutCreateWindow("Exercicio 01");
    glutDisplayFunc(desenha);

    glutMouseFunc(mouse);
    glutKeyboardFunc(teclado);

    glutMainLoop();
    return 0;
}