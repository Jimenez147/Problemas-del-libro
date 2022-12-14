/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 5.4                                      */
/*  Fecha:     17/03/2022                                  */
/***********************************************************/

#include <stdio.h>
/*Agrega o elimina un numero al arreglo*/

int ARR[100] = {0}, MAX, g = 0;
int busca(int);
void imprime(int VEC[]);

void main(void)
{
    int ELE;

    printf("Ingrese la cantidad de casillas del arreglo: ");
    scanf("%d", &MAX);
    printf("Ingrese el numero que desea agregar o eliminar: ");
    scanf("%d", &ELE);

    while (ELE != -1)
    // Continua el programa hasta que se dé la señal de cierre
    {
        if (busca(ELE))
        // Averigua si el numero suminstrado se va a agregar o eliminar del arreglo
        {
            if (ARR[MAX - 1] == 0)
            // Agrega el numero al arreglo, y si el arreglo ya esta lleno lo notifica
            {
                ARR[g] = ELE;
                g++;
                printf("\nEl numero fue agregado");
            }
            else
            {
                printf("\nEl arreglo ya esta lleno, no pueden agregarse mas numeros");
            }
        }
        else
        {
            printf("\nEl numero fue eliminado");
        }
        printf("\n\n(-1 para terminar)\nIngrese el siguiente numero a agregar o eliminar: ");
        scanf("%d", &ELE);
    }
    imprime(ARR);
}

int busca(int X)
// busca si el numero esta en el arreglo, y en caso de estarlo lo elimina.
{
    int RESS = 1;
    for (size_t i = 0; i < MAX; i++)
    {
        if (ARR[i] == X)
        {
            RESS = 0;
            ARR[i] = 0;
            for (size_t j = i; j < MAX; j++)
            {
                ARR[j] = ARR[j + 1];
            }
            g--;
        }
    }
    return RESS;
}

void imprime(int VEC[])
// Imprime todos los valores contenidos en un arreglo
// Usa la constante global que contiene la cantidad de valores del arreglo (MAX)
{
    int i;
    printf("\nValores del arreglo: ");
    for (i = 0; i < MAX; i++)
    {
        printf("%d\t", VEC[i]);
    }
    printf("\n");
}
