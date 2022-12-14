/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 5.2                                      */
/*  Fecha:     17/03/2022                                  */
/***********************************************************/

#include <stdio.h>
/*recibe como entrada un arreglo unidimensional ordenado de N enteros y obtiene 
como salida ese mismo arreglo pero sin los elementos repetidos*/
int base[100], MAX, sobra = 0;
int asciende(int VEC[]);
int elimina(int VEC[]);
void ordena(int VEC[]);
void imprime(int VEC[]);

void main(void)
{
    printf("Ingrese la cantidad de casillas del arreglo: ");
    scanf("%d", &MAX);
    printf("Ingrese los valores del arreglo:\n");

    do
    {
        for (size_t i = 0; i < MAX; i++)
        {
            scanf("%d", &base[i]);
        }
    } while (asciende(base));

    elimina(base);
    ordena(base);
    imprime(base);
}

int asciende(int VEC[])
// Se asegura de que los arreglos estan en forma ascendente
{
    int ret = 0;
    for (size_t i = 1; i < MAX; i++)
    {
        if (VEC[i] < VEC[i - 1])
        {
            ret = 1;
        }
    }
    if (ret)
    {
        printf("Error: los valores no estan ordenados en forma ascendente, intente una vez mas.\n");
    }
    return ret;
}

int elimina(int VEC[])
//Busca los numeros que estan repetidos y cambia sus valores
{
    int j;
    for (size_t i = 1; i < MAX; i++)
    {
        if (base[i] != -50)
        {
            if (base[i] == base[i - 1])
            {
                sobra++;
                base[i] = -50;
                j = i + 1;
                while (base[i - 1] == base[j])
                {
                    sobra++;
                    base[j] = -50;
                    j++;
                }
            }
        }
    }
}

void ordena(int VEC[])
// Ordena una matriz de mayor a menor
// Utiliza la constante gloval "MAX" que define el total de casillas
{
    int i, j, r;
    for (i = 1; i < MAX; i++)
    {
        r = i;
        j = VEC[i];
        while (r > 0 && j < VEC[r - 1])
        {
            VEC[r] = VEC[r - 1];
            r = r - 1;
        }
        VEC[r] = j;
    }
}

void imprime(int VEC[])
//Imprime todos los valores contenidos en un arreglo
//Usa la constante global que contiene la cantidad de valores del arreglo (MAX)
{
    int i;
    printf("Arreglo procesado:\n");
    for (i = sobra; i < MAX ; i++)
    {
        printf("%d\n", VEC[i]);
    }
    printf("\n");
}