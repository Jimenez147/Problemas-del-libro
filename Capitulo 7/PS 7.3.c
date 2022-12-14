/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 7.3                                      */
/*  Fecha:     14/04/2022                                  */
/***********************************************************/

#include <stdio.h>
/*Usa una cadena con una maximo de caracteres, te permite ingresar valores en la cadena y completa
la cadena con espacios en barras hasta que se llene la cadena*/
char cad[30];

void main(void)
{
    int control;
    printf("Ingrese una cadena de caracteres: ");
    gets(cad);
    for (size_t i = 0; i < 30; i++)
    {
        if (cad[i] == '\0')
        {
            control = i;
            break;
        }
    }
    for (size_t i = control; i < 30; i++)
    {
        cad[i] = '-';
    }
    puts(cad);
}