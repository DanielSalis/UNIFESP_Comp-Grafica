#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

char tool;

float coordX[100];
float coordY[100];

float colors[3] = {1.0, 1.0, 1.0};
int clicks = 0;


void resetCoordsVector(){
    int i = 0;
    for (i = 0; i < 100;i++){
        coordX[i]=0;
        coordY[i]=0;
    }
}

void line()
{
    if (clicks > 0)
    {
        glColor3f(colors[0], colors[1], colors[2]); //point color
        glPointSize(5.0f);                          //point size
        glBegin(GL_LINES);
        int i;
        for (i = 0; i < clicks; i++)
        {
            glVertex2f(coordX[i], coordY[i]);
        }
        glEnd();
    }
    glFlush();
}

void triangle(){
    if (clicks > 1)
    {
        glColor3f(colors[0], colors[1], colors[2]); //point color
        glPointSize(5.0f);                          //point size
        glBegin(GL_TRIANGLES);
        int i;
        for (i = 0; i < clicks; i++)
        {
            glVertex2f(coordX[i], coordY[i]);
        }
        glEnd();
    }
    glFlush();
}

void desenha()
{
    glClearColor(0, 0, 0, 0); //Backgroung
    glClear(GL_COLOR_BUFFER_BIT);
    if(tool=='r'){
        line();
    }
    else if( tool=='t'){
        triangle();
    }
    glFlush();
}

void toolsController(int estado, float ox, float oy){
    if (tool == 'r')
    {
        if (estado == GLUT_DOWN)
        {
            if (clicks % 2 == 0)
            {
                printf("CLicou\n");
                line();
            }

            if (clicks > 0)
            {
                coordX[clicks] = ox;
                coordY[clicks] = oy;
                printf("%f %f\n", coordX[clicks], coordY[clicks]);
            }
            clicks++;
        }
    }

    else if (tool == 't')
    {
        if (estado == GLUT_DOWN)
        {
            if (clicks % 3 == 0 && clicks !=0)
            {
                printf("Clicou trinagulo\n");
                triangle();
            }

            if (clicks > 0)
            {
                coordX[clicks] = ox;
                coordY[clicks] = oy;
                printf("%f %f\n", coordX[clicks], coordY[clicks]);
            }
            clicks++;
        }
    }
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
        toolsController(estado, ox, oy);
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
    case 'r':
        tool = 'r';
        clicks = 0;
        resetCoordsVector();
        glClearColor(0.0, 0.0, 0.0, 0.0);
        glClearDepth(1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        break;
    case 't':
        tool = 't';
        clicks = 0;
        resetCoordsVector();
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        break;
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

    glutKeyboardFunc(teclado);
    glutMouseFunc(mouse);

    glutMainLoop();
    return 0;
}