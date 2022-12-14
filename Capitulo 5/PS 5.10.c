/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 5.10                                     */
/*  Fecha:     17/03/2022                                  */
/***********************************************************/

#include <stdio.h>
/*Recibe dos arreglos, uno ordenado de forma ascendente y el otro descendente y devuelve
la suma de ambos ordenada en forma decreciente*/

int ARR1[100] = {0}, ARR2[100] = {0};
int N, M, MAX, marca;
void suma(int VE1[], int VE2[]);
void ordena(int VEC[]);
void imprime(int VEC[]);
int comprueba(int VEC[]);

void main(void)
{
    printf("Ingrese la cantidad de numeros del arreglo 1: ");
    scanf("%d", &N);
    do
    {
        marca = 1;
        for (size_t i = 0; i < N; i++)
        // Captura los numeros del primer arreglo
        {
            printf("Ingrese el numero %d del arreglo 1: ", i + 1);
            scanf("%d", &ARR1[i]);
        }
    } while (comprueba(ARR1));
    printf("\nIngrese la cantidad de numeros del arreglo 2: ");
    scanf("%d", &M);
    do
    {
        marca = 0;
        for (size_t i = 0; i < M; i++)
        // Captura los numeros del segundo arreglo
        {
            printf("Ingrese el numero %d del arreglo 2: ", i + 1);
            scanf("%d", &ARR2[i]);
        }
    } while (comprueba(ARR2));

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

int comprueba(int VEC[])
// Se asegura de que los arreglos estan en forma ascendente o descendente segun corresponda
{
    int ret = 0, w;
    if (marca)
    {
        for (size_t i = 1; i < N; i++)
        {
            if (VEC[i] < VEC[i - 1])
            {
                ret = 1;
            }
        }
    }
    else
    {
        for (size_t i = 1; i < M; i++)
        {
            if (VEC[i] > VEC[i - 1])
            {
                ret = 1;
            }
        }
    }
    if (ret)
    {
        printf("Error: los valores no estan ordenados debidamente, intente una vez mas.\n");
    }
    return ret;
}