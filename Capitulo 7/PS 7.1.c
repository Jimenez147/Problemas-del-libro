/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 7.1                                      */
/*  Fecha:     14/04/2022                                  */
/***********************************************************/

#include <stdio.h>
/*El programa recibe una cadena e imprime solo los caracteres impares*/
char cad[50] = {'\0'};

void main (void)
{
    printf("Ingrese una cadena de caracteres: ");
    gets(cad);
    printf("\n");
    for (size_t i = 0; i < 25; i++)
    {
        printf("%c", cad[i*2+1]);
    }
    printf("\n");
}