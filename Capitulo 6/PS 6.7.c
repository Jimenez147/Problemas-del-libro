/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 6.7                                      */
/*  Fecha:     01/03/2022                                  */
/***********************************************************/

#include <stdio.h>
/*Recibe un arreglo bidimencional e imprime sus valores siguiendo una espiral*/
const int M=10, N=10;
int MAT[10][10];
void lectura2(int VEC[][N]);

void main(void)
{
    int i, b, j, r, s; 
    int X=N-1, Y=M-1, Z=0, W;
    lectura2(MAT);//Primero llama a la funcion lectura para asignar valores a las casillas del arreglo
    if (M % 2 == 0)
    //Averigua si la cantidad de filas es par o no
    {
        W=M/2;
    }
    else
    {
        W=(M/2)+1;
    }
    for (i = 0; i < W; i++)
        {
            for (j = Z; j <= X; j++)
            //Imprime una fila de izquierda a derecha
            {
                printf("%d\t", MAT[i][j]);
            }
            if (i != Y)
            //Cada uno de estos se encarga de asegurarse de si el siguiente paso puede hacerse
            {
                for (r = i+1; r <= Y; r++)
                //Imprime una columna de arriba hacia abajo
                {
                    printf("%d\t", MAT[r][X]);
                }
                if (X != Z)
                {
                    for (b = X-1; b >= Z; b--)
                    //Imprime una fila de derecha a izquierda
                    {
                    printf("%d\t", MAT[Y][b]);
                    }
                    if (i != Y-1)
                    {
                        for (s = Y-1; s > i; s--)
                        //Imprime una columna de abajo hacia arriba
                        {
                            printf("%d\t", MAT[s][Z]);
                        }
                        X--;
                        Y--;
                        Z++;
                    }
                }
            }
        }
}

void lectura2(int VEC[][N])
//Llena las casillas de un arreglo bidimencional usando una secuencia
//Toma dos variables glovales (M y N) que representan las cantidades de casillas del arreglo
{
    int i, j, R=1;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            VEC[i][j] = R;
            R++;
        }
        
    }
    
}