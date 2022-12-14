/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 7.5                                      */
/*  Fecha:     14/04/2022                                  */
/***********************************************************/

#include <stdio.h>
#include <ctype.h>
/*El programa recibe una frace y la imprime con mayusculas*/
char cad[50];

void main(void)
{
    printf("Ingrese una cadena de caracteres: ");
    gets(cad);
    cad[0] = toupper(cad[0]);
    for(size_t i = 1; i < 50; i++)
    {
        if(cad[i - 1] == ' ')
        {
            cad[i] = toupper(cad[i]);
        }
    }
    printf("\n%s\n", cad);
}