/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 5.9                                      */
/*  Fecha:     15/03/2022                                  */
/***********************************************************/

#include <stdio.h>
/*Recibe dos arreglos ordenados en forma ascendente y devuelve la suma de estos*/
int MAX;
int asciende(int VEC[]);
void imprime(int VEC[]);

void main(void)
{
    int X[100], Y[100], Z[100];

    printf("Cantidad de casillas de los arreglos: ");
    scanf("%d", &MAX);
    do
    {
        printf("Ingrese los valores del primer arreglo: \n"); 
        for (size_t i = 0; i < MAX; i++)
        {
            scanf("%d", &X[i]);
        }

    } while (asciende(X));
    do
    {
        printf("Ingrese los valores del segundo arreglo: \n"); 
        for (size_t i = 0; i < MAX; i++)
        {
            scanf("%d", &Y[i]);
        }
    } while (asciende(Y));
    for (size_t i = 0; i < MAX; i++)
    {
        Z[i] = X[i] + Y[i];
    }
    printf("Resultado de la suma:");
    imprime(Z);
}

int asciende(int VEC[])
//Se asegura de que los arreglos estan en forma ascendente
{
    int ret = 0;
    for (size_t i = 1; i < MAX; i++)
    {
        if (VEC[i] <= VEC[i-1])
        {
            ret = 1;
        }
        
    }
    if (ret)
    {
        printf("Error: los valores no estan ordenados de forma ascendente o estan repetidos, intente una vez mas.\n");
    }
    return ret;
}

void imprime(int VEC[])
//Imprime todos los valores contenidos en un arreglo
//Usa la constante global que contiene la cantidad de valores del arreglo (MAX)
{
    int i;
    printf("\n");
    for (i = 0; i < MAX; i++)
    {
        printf("%d\n", VEC[i]);
    }
    printf("\n");
}
