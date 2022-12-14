/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 5.8                                      */
/*  Fecha:     17/03/2022                                  */
/***********************************************************/

#include <stdio.h>
/*Recibe dos arreglos desordenados y devuelve la suma de ambos ordenada en forma decreciente*/

int ARR1[100] = {0}, ARR2[100] = {0};
int N, M, MAX;
void suma(int VE1[], int VE2[]);
void ordena(int VEC[]);
void imprime(int VEC[]);

void main(void)
{
    printf("Ingrese la cantidad de numeros del arreglo 1: ");
    scanf("%d", &N);
    for (size_t i = 0; i < N; i++)
    // Captura los numeros del primer arreglo
    {
        printf("Ingrese el numero %d del arreglo 1: ", i + 1);
        scanf("%d", &ARR1[i]);
    }
    printf("\nIngrese la cantidad de numeros del arreglo 2: ");
    scanf("%d", &M);
    for (size_t i = 0; i < M; i++)
    // Captura los numeros del segundo arreglo
    {
        printf("Ingrese el numero %d del arreglo 2: ", i + 1);
        scanf("%d", &ARR2[i]);
    }
    if (N > M)
    {
        MAX = N;
    }
    else
    {
        MAX = M;
    }
    suma(ARR1, ARR2);
}

void suma(int VE1[], int VE2[])
// Guarda la suma de ambos arreglos en un tercero
{
    int RESS[100];
    for (size_t i = 0; i < MAX; i++)
    {
        RESS[i] = VE1[i] + VE2[i];
    }
    ordena(RESS);
    imprime(RESS);
}

void ordena(int VEC[])
// Ordena una matriz de mayor a menor y agrega una matriz que contiene las posiciones iniciales
// Utiliza la constante gloval "MAX" que define el total de casillas
{
    int i, j, r;

    for (i = 1; i < MAX; i++)
    {
        r = i;
        j = VEC[i];
        while (r > 0 && j > VEC[r - 1])
        {
            VEC[r] = VEC[r - 1];
            r = r - 1;
        }
        VEC[r] = j;
    }
}

void imprime(int VEC[])
// Imprime todos los valores contenidos en un arreglo
// Usa la constante global que contiene la cantidad de valores del arreglo (MAX)
{
    printf("\nSuma de los arreglos:\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("%d\n", VEC[i]);
    }
    printf("\n");
}
