/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 7.14                                     */
/*  Fecha:     12/04/2022                                  */
/***********************************************************/

#include <stdio.h>
#include <string.h>
#include <conio.h>
/*El programa recibe un texto pequeño y cuenta la cantidad de palabras con la misma cantidad de 
letras*/
char ARC[20][80];
void cuentaletras(char VEC[][80]);

void main(void)
{
    char uno;
    printf("Ingrese la cadena de caracteres: ");
    for (size_t i = 0; i < 20; i++)
    // Captura el texto
    {
        for (size_t j = 0; j < 80; j++)
        {
            uno = getche();
            if (uno == ' ')
            {
                break;
            }
            else
            {
                ARC[i][j] = uno;
            }
        }
        
    }
    cuentaletras(ARC);
}

void cuentaletras(char VEC [][80])
// Cuenta cuantas palabras hay con la misma cantidad de letras e imprime esa informacion
{
    int letras[80] = {0}, cantidad;
    for (size_t i = 0; i < 20; i++)
    {
        cantidad = strlen(VEC[i]);
        letras[cantidad - 1]++;
    }
    printf("\nLongitud de las palabras:\t\tFrecuencia:\n");
    for (size_t i = 0; i < 80; i++)
    {
        if (letras[i] != 0)
        {
            printf("%d\t\t\t\t\t%d\n", i + 1, letras[i]);
        }
    }
}