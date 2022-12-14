/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 6.4                                      */
/*  Fecha:     03/03/2022                                  */
/***********************************************************/

#include <stdio.h>
/*El programa analiza un array y determina si es un cuadrado magico o no*/
const int Y = 3;
void cuadrado_magico(int VEC[][Y]);

void main(void)
{
    int CUA[Y][Y] = {{28, 21, 26}, {23, 25, 27}, {24, 29, 22}};
    //Matriz de ejemplo para probar el funcionamiento
    cuadrado_magico(CUA);
}

void cuadrado_magico(int VEC[][Y])
//Analiza un array para averiguar si es cuadrado magico
{
    int i, j, S = Y - 1, RESS = 1, X[Y] = {0}, R[Y] = {0}, B = 0, L = 0;
    for (i = 0; i < Y; i++)
    //Reuna la suma de cada fila
    {
        for (j = 0; j < Y; j++)
        {
            X[i] += VEC[i][j];
        }
    }
    for (i = 0; i < Y - 1; i++)
    //Analiza si las sumas de cada fila coinciden
    {
        if (X[i] != X[i + 1])
        {
            RESS = 0;
        }
    }
    for (i = 0; i < Y; i++)
    //Reuna la suma de cada columna
    {
        for (j = 0; j < Y; j++)
        {
            R[i] += VEC[j][i];
        }
    }
    for (i = 0; i < Y - 1; i++)
    //Analiza si las sumas de cada columna coinciden
    {
        if (R[i] != R[i + 1])
        {
            RESS = 0;
        }
    }
    for (i = 0; i < Y; i++)
    //Suma los valores de la diagonal principal (izquierda a derecha)
    {
        for (j = 0; j < Y; j++)
        {
            if (i == j)
            {
                B += VEC[j][i];
            }
        }
    }
    if (B != R[0])
    //Analiza la suma de la diagonal
    {
        RESS = 0;
    }
    for (i = 0; i < Y; i++)
    //Suma los valores de la otra diagonal principal
    {
        L += VEC[i][Y-1];
        S--;
    }
    if (L != R[0])
    //Analiza la suma de la diagonal
    {
        RESS = 0;
    }
    if (RESS)
    {
        printf("La matriz es un cuadrado magico\n");
    }
    else
    {
        printf("La matriz no es un cuadrado magico\n");
    }
}