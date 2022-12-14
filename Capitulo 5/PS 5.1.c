/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 5.1                                      */
/*  Fecha:     15/03/2022                                  */
/***********************************************************/

#include <stdio.h>
/*El programa recibe un arreglo y determina cuanto de sus valores son positivos, cuantos negativos y
cuantos nulos*/
int N, NUM[100];
void cuenta(int VEC[]);

void main(void)
{
    printf("Ingrese la dimencion del arreglo: ");
    scanf("%d", &N);
    printf("\nIngrese los valores del arreglo:\n");
    for (size_t i = 0; i < N; i++)
    //Va asignando cada valor entregado a una casilla del arreglo
    {
        scanf("%d", &NUM[i]);
    }
    cuenta(NUM);
}

void cuenta(int VEC[])
//Averigua si el numero es posivo, negativo o nulo 
{
    int pos=0, neg=0, nul=0;
    for (size_t i = 0; i < N; i++)
    {
        if (VEC[i] > 0)
        {
            pos++;
        }
        else if (VEC[i] < 0)
        {
            neg++;
        }
        else
        {
            nul++;
        }
    }
    printf("Cantidad de numeros:\nPositivos: %d\nNegativos: %d\nNulos: %d\n", pos, neg, nul);
}