#include <stdio.h>
#include <stdlib.h>

// 6 - P_0 = (10,20), P_end = (15,25)

void bresenham(int x1, int x2, int y1, int y2)
{
    int m, dx, dy, incSup, incInf, p, x, y;
    int valor;
    dx = x2 - x1;
    dy = y2 - y1;
    p = 2 * dy - dx;

    incInf = 2 * dy;
    incSup = 2 * (dy - dx);
    x = x1;
    y = y1;

    //     m = 3 / 8  => 0 < m < 1 ->incrementos unitários em x
    // dx = 8
    // dy = 3
    // 2dy = 6

    printf("dx = %d\n", dx);
    printf("dy = %d\n",dy);
    printf("2dy = %d\n",incInf);
    printf("2dy-2dx %d\n",incSup);

    int tam;
    if (x2 - x1 > 0){
        tam = x2 - x1;
    }else{
        tam = -(x2 - x1);
    }

        int vecX[tam];
    int vecY[tam];
    int vecPk[tam];

    int i = 0;
    while (x < x2)
    {
        if (p < 0)
        {
            p = p + incInf;
        }
        else
        {
            p = p + incSup;
            y++;
        }
        x++;

        vecPk[i] = p;
        vecX[i] = x;
        vecY[i] = y;
        i++;
    }

    printf("X  | ");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vecX[i]);
    }
    printf("\n");

    printf("Y  | ");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vecY[i]);
    }
    printf("\n");

    printf("Pk | ");
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", vecPk[i]);
    }
    printf("\n");
}

void imprime(int *vec, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d", vec[i]);
    }
}

int main(void)
{
    bresenham(15,10,25,20);
    return 0;
}