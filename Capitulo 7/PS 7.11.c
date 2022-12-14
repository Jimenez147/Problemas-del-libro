/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 7.11                                     */
/*  Fecha:     14/04/2022                                  */
/***********************************************************/

#include <stdio.h>
/*Analiza un grupo de cadena de caracteres y determina cual tiene mas vocales*/
char ARC[10][50];

void main(void)
{
    int count = 0, total = 0, best;
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
            if (ARC[i][j] == 'a' || ARC[i][j] == 'e' || ARC[i][j] == 'i' || ARC[i][j] == 'o' || ARC[i][j] == 'u' || ARC[i][j] == 'A' || ARC[i][j] == 'E' || ARC[i][j] == 'I' || ARC[i][j] == 'O' || ARC[i][j] == 'U')
            {
                count++;
            }
        }
        if (count > total)
        {
            total = count;
            best = i;
        }
        count = 0;
    }
    printf("\nLa cadena de caracteres con mas vocales es: %s\n", ARC[best]);
}