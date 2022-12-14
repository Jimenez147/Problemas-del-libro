/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 6.5                                      */
/*  Fecha:     01/03/2022                                  */
/***********************************************************/

#include <stdio.h>
/*Multiplica los valores de dos arrelos (a y b) y el resultado se almacena en el arreglo c*/

/*Se definen las constantes que contienen el tamaño de los arreglos, el arreglo del resultado
y la funcion de multiplicacion*/
 const int M=3, N=3, P=3;
 int c[M][P];
void multi(int VE1[][N], int VE2[][P]);
void imprime2(int VEC[][P]);

void main(void)
{
    //Se definen a y b con sus valorse
    int a[M][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, b[N][P] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};
    multi(a, b);
    imprime2(c);
}

void multi(int VE1[][N], int VE2[][P])
/*Asigna en cada casilla de c los valores de las multiplicaciones entre las casillas 
correspondientes de a y b*/
{
    int i, j;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < P; j++)
        {
            c[i][j] = VE1[i][j] * VE2[i][j];
        }
        
    }
    
}

void imprime2(int VEC[][P])
//La funcion se encarga de plasmar los valores del arreglo en forma de cuadricula 
//Toma dos variables glovales (X y Y) que representan las cantidades de casillas del arreglo
{
    int i, j;
    for (i = 0; i < M; i++)
    {
       for (j = 0; j < P; j++)
       {
           printf("%d  ", VEC[i][j]);
       }
       printf("\n");
    }
}