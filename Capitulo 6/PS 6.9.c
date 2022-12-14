/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 6.9                                      */
/*  Fecha:     01/03/2022                                  */
/***********************************************************/

#include <stdio.h>
#include <stdlib.h>
/*El programa resuelve el famoso problema de las 8 reinas en ajedrez. Interpreta las 
reinas como 1 y las casillas vacias como 0*/

int TAB[8][8] = {0}; //Un arreglo que representa el tablero de ajedrez vacio
int k;
void imprime2(int VEC[][8]);
void comprueba(int VEC[][8]);

void main(void)
{
    int i, b, j, d, l, r, x, y;
    /*Coloca cada una de las reinas en la fila superior y las desplazando hacia abajo una
    por una de derecha a izquierda*/
    for (i = 0; i < 8; i++)
    {
        TAB[i][1] = 1;
        for (b = 0; b < 8; b++)
        {
            TAB[b][2] = 1;
            for (j = 0; j < 8; j++)
            {
                TAB[j][3] = 1;
                for (d = 0; d < 8; d++)
                {
                    TAB[d][4] = 1;
                    for (l = 0; l < 8; l++)
                    {
                        TAB[l][5] = 1;
                        for (r = 0; r < 8; r++)
                        {
                            TAB[r][6] = 1;
                            for (x = 0; x < 8; x++)
                            {
                                TAB[x][7] = 1;
                                for (y = 0; y < 8; y++)
                                {
                                    TAB[y][8] = 1;
                                    /*Llama a la funcion "comprueba" para averiguar si la posicion
                                    actual de las reinas cumple con los requisitos de no atacarse*/
                                    comprueba(TAB);                                    
                                    TAB[y][8] = 0;
                                }
                                TAB[x][7] = 0;
                            }
                            TAB[r][6] = 0;
                        }
                        TAB[l][5] = 0;
                    }
                    TAB[d][4] = 0;
                }
                TAB[j][3] = 0;
            }
            TAB[b][2] = 0;
        }    
        TAB[i][1] = 0;
    }          
}

void comprueba(int VEC[][8])
//La funcion se encarga de averiguar si la posicion entregada cumple con la regla
{
    int i, l, B=0, R=0, j, X=0, Y=8, RESS = 1;
    for (i = 0; i < 8; i++)
    //Primero averigua si las reinas no se atacan entre si de forma horizontal
    {
        for (j = 0; j < 8; j++)
        {
            X += VEC[i][j];
        }
        if (X != 1)
        {
            RESS = 0;
        }
        X = 0;
    }
    for (i = 0; i < 15; i++)
    //Este ciclo se encarga de revisar todas las diagonales que van de de izquierda a derecha
    {
        for (j = 0; j < 8; j++)
        //Este ciclo comprende las diagonales desde la central hacia abajo
        {
            for (l = 0; l < Y; l++)
            {
                X += VEC[B][R];
                B++;
                R++;
            }
            if (X > 1)
            {
            RESS = 0;
            }
            R = 0;
            B = j+1;
            X = 0;
            Y--;
        }
        R = 1;
        B = 0;
        Y = 7;
        X = 0;
        for (j = 1; j < 8; j++)
        //Este se encarga de las diagonales de la central a la derecha
        {
            for (l = 0; l < Y; l++)
            {
                X += VEC[B][R];
                B++;
                R++;
            }
            if (X > 1)
            {
            RESS = 0;
            }
            R = j+1;
            B = 0;
            Y--;
            X = 0;
        }
    }
    Y = 8;
    B = 0;
    R = 7;
    X = 0;
    for (i = 0; i < 15; i++)
    //Este ciclo es similar al anterior, pero se encarga de las diagonales de derecha a izquierda
    {
        for (j = 0; j < 8; j++)
        {
            for (l = 0; l < Y; l++)
            {
                X += VEC[B][R];
                B++;
                R--;
            }
            if (X > 1)
            {
            RESS = 0;
            }
            R = 7;
            B = j+1;
            X = 0;
            Y--;
        }
        Y = 7;
        X = 0;
        B = 0;
        R = 6;
        for (j = 1; j < 8; j++)
        {
            for (l = 0; l < Y; l++)
            {
                X += VEC[B][R];
                B++;
                R--;
            }
            if (X > 1)
            {
            RESS = 0;
            }
            R = 7-j;
            B = 0;
            X = 0;
            Y--;
        }
    }
    if (RESS)
    {
        imprime2(VEC);
    }
    
}

void imprime2(int VEC[][8])
//La funcion se encarga de plasmar los valores del arreglo en forma de cuadricula 
{
    int i, j;
    for (i = 0; i < 8; i++)
    {
       for (j = 0; j < 8; j++)
       {
           printf("%d  ", VEC[i][j]);
       }
       printf("\n");
    }
    if (k == 3)
    {
        exit (-1); //Permite detener el programa luego de encontrar la primera solucion
    }
    printf("\n");
    k++;
}