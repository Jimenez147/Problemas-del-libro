/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 5.10                                     */
/*  Fecha:     17/03/2022                                  */
/***********************************************************/

#include <stdio.h>
/*El programa recibe un arreglo y averigua si es o no un palindrome*/
int ARR[100], MAX;
void palindrome(int VEC[]);
void main(void)
{
    printf("Ingrese la cantidad de casillas del arreglo: ");
    scanf("%d", &MAX);
    for (size_t i = 0; i < MAX; i++)
    // Captura los numeros del arreglo
    {
        printf("Valor %d del arreglo: ", i + 1);
        scanf("%d", &ARR[i]);
    }
    palindrome(ARR);
}

void palindrome(int VEC[])
// Opera en el arreglo para saber si es palindrome
{
    int i, RESS = 1, j = MAX / 2 - 1;
    if (MAX % 2 == 0)
    // Distingue entre arreglos pares e impares
    {
        i = MAX / 2;
    }
    else
    {
        i = MAX / 2 + 1;
    }
    for (i; i < MAX; i++)
    // Compara las casillas del arreglo
    {
        if (ARR[i] != ARR[j])
        {
            RESS = 0;
        }
        j--;
    }
    if (RESS)
    {
        printf("\nEl areglo es un palindrome\n");
    }
    else
    {
        printf("\nEl areglo no es un palindrome\n");
    }
}