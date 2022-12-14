/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 5.3                                      */
/*  Fecha:     15/03/2022                                  */
/***********************************************************/

#include <stdio.h>
/*El programa imprime los 100 primeros numeros de la sucesion de fibonacci*/
void imprime(double VEC[]);

void main(void)
{
    double aureo[100] = {0, 1};
    for (size_t i = 2; i < 100; i++)
    //Va asignando los valores al arreglo siguiendo la regla de la sucesion
    {
        aureo[i] = aureo[i-1] + aureo[i-2];
    }
    imprime(aureo);
}

void imprime(double VEC[])
//Imprime todos los valores contenidos en un arreglo
//Usa la constante global que contiene la cantidad de valores del arreglo (MAX)
{
    int i;
    printf("\n");
    for (i = 0; i < 100; i++)
    {
        printf("%.0lf\t", VEC[i]);
    }
    printf("\n");
}
