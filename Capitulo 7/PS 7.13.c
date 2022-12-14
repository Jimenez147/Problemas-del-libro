/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 7.13                                     */
/*  Fecha:     14/04/2022                                  */
/***********************************************************/

#include <stdio.h>
#include <ctype.h>
/*Recibe un arreglo de cadenas de caracteres y dice cuantas palabras tiene cada una*/
char ARC[10][50];

void main(void)
{
    int count = 0, total[10];
    for (size_t i = 0; i < 10; i++)
    {
        printf("Ingrese la cadena de caracteres numero %d: ", i + 1);
        gets(ARC[i]);
        fflush(stdin);
    }
    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = 0; j < 50; j++)
        {
            if (isalpha(ARC[i][j]) && (ARC[i][j + 1] == ' ' || ARC[i][j + 1] == '\0'))
            {
                count++;
            }
        }
        total[i] = count;
        count = 0;
    }
    printf("\n");
    for (size_t i = 0; i < 10; i++)
    {
        printf("La cadena numero %d tiene %d palabras\n", i + 1, total[i]);
    }
}