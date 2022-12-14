/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 6.6                                      */
/*  Fecha:     03/03/2022                                  */
/***********************************************************/

#include <stdio.h>
/*Suma el transpuesto de B mas A*/
const int M=3, N=4;
void suma(int VE1[][N], int VE2[][N]);

void main(void)
{
    int A[M][N] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int B[N][M] = {{4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}};
    //Matrices de ejemplo
    int i, j, Bt[M][N];
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        //Coloca el transpuesto de B en Bt
        {
            Bt[j][i] = B[i][j];
        }        
    }
    suma(A, Bt);
}

void suma(int VE1[][N], int VE2[][N])
//Suma dos vectores
{
    int i, j;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d  ", VE1[i][j] + VE2[i][j]);
        }
        printf("\n");
    }
    
}