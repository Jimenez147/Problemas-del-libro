/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 6.1                                      */
/*  Fecha:     01/03/2022                                  */
/***********************************************************/

#include <stdio.h>
/*En una matrix cuadrada coloca un 1 en cada posicion de las dos diagonales principales*/

const int X=8, Y=8;
//introduccion de la funcion
void DP(int VEC[][Y]);
void imprime2(int VEC[][Y]);

void main(void)
//Estructura principal
{
    int MATRIX[X][Y];
    DP(MATRIX);
    imprime2(MATRIX);
}

void DP(int VEC[][Y])
{
    int i, s;
    for (i = 0; i < X; i++)
    {
        for (s = 0; s < Y; s++)
        {
            /*Evalua cada posicion del arreglo y si el valor de las filas es igual al de las 
            columnas se coloca un 1, de lo contrario un 0*/
            if (i == s)
            {
                VEC[i][s] = 1;
            }
            else
            {
                VEC[i][s] = 0;
            }
        }
        
    }
    s=Y-1;
    for (i = 0; i < X; i++)
    /*Empieza en la primera fila y en la ultima columna y se va moviendo de forma diagonal 
    colocando un 1 en cada casilla*/
    {
        VEC[i][s] = 1;
        s--;
    }
}

void imprime2(int VEC[][Y])
//La funcion se encarga de plasmar los valores del arreglo en forma de cuadricula 
//Toma dos variables glovales (X y Y) que representan las cantidades de casillas del arreglo
{
    int i, j;
    for (i = 0; i < X; i++)
    {
       for (j = 0; j < Y; j++)
       {
           printf("%d  ", VEC[i][j]);
       }
       printf("\n");
    }
}