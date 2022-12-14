/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 6.2                                      */
/*  Fecha:     03/03/2022                                  */
/***********************************************************/ 

#include <stdio.h>
/*Recibe los montos de venta mensuales de 5 departamentos a lo largo de un año y devuelve 
Las ventas mensuales de la fábrica, incluido el monto anual.
El departamento que tuvo la mayor venta en el mes de julio, incluyendo el monto de la venta.
El mes en el que se obtuvieron las mayores y menores ventas del departamento 3.*/
void ventas(int VEC[][12]);
void julio(int VEC[][12]);
void dep3(int VEC[][12]);

void main(void)
{
    int VEN[5][12], i, j;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 12; j++)
        {
            printf("Ingrese las ventas del departamento %d en el mes %d: ", i+1, j+1);
            scanf("%d", &VEN[i][j]);
            /*Permite al usuario asignar las ventas por departamento en cada mes usando dos
            ciclos for*/
        }
        
    }
    ventas(VEN);
    julio(VEN);
    dep3(VEN);
}

void ventas(int VEC[][12])
/*Imprime los totales vendidos en cada mes y el total anual*/
{
    int MES[12] = {0}, i, j, X=0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 12; j++)
        {
            MES[j] += VEC[i][j];
            X += VEC[i][j];
        }
        
    }
    for (i = 0; i < 12; i++)
    {
        printf("Las ventas del mes %d fueron %d\n", i+1, MES[i]);
    }
    printf("Las ventas anuales fueron %d\n", X);
}

void julio(int VEC[][12])
//Busca el departamento que obtuvo mas ventas en julio
{
    int i, DEP, RESS=0;
    for (i = 0; i < 5; i++)
    {
        if (VEC[i][6] > RESS)
        {
            RESS = VEC[i][6];
            DEP = i;
        }
        
    }
    printf("El departamento con mayor ventas en julio es el departamento %d con %d ventas\n", DEP+1, RESS);
}

void dep3(int VEC[][12])
//Imprime el mejor y el peor mes del departamento 3
{
    int i, R, S, MAX=0, MIN=100000;
    for (i = 0; i < 12; i++)
    {
        if (VEC[2][i] > MAX)
        {
            MAX = VEC[2][i];
            S = i;
        }
         if (VEC[2][i] < MIN)
        {
            MIN = VEC[2][i];
            R = i;
        }
    }
    printf("El mes con mayor numero de ventas en el departamento 3 fue %d\n", S+1);
    printf("El mes con menor numero de ventas en el departamento 3 fue %d\n", R+1);
}