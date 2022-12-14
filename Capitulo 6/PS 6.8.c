/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 6.8                                      */
/*  Fecha:     03/03/2022                                  */
/***********************************************************/

#include <stdio.h>
/*El programa recorre una matriz columna a columna de arriba hacia abajo y de abajo hacia arriba*/

const int X = 5, Y = 4;
void lectura2(int VEC[][Y]);

void main(void)
{
    int MAT[X][Y], i, j = 1, r;
    lectura2(MAT);
    for (r = 0; r < Y; r++)
    {
        if (j)
        {
            for (i = 0; i < X; i++)
            {
                printf("%d\t", MAT[i][r]);
            }
            j = 0;
        }
        else
        {
            for (i = X - 1; i >= 0; i--)
            {
                printf("%d\t", MAT[i][r]);
            }
            j = 1;
        }
    }
    printf("\n");
}

void lectura2(int VEC[][Y])
// Llena las casillas de un arreglo bidimencional usando una secuencia
// Toma dos variables glovales (X y Y) que representan las cantidades de casillas del arreglo
{
    int i, j, R = 100;
    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Y; j++)
        {
            VEC[i][j] = R;
            R++;
        }
    }
}