/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 7.2                                      */
/*  Fecha:     12/04/2022                                  */
/***********************************************************/

#include <stdio.h>
#include <string.h>
/*El programa recibe una cadena de caracteres e imprime los caracteres que se encuentran
en las posiciones pares de la cadena*/
void main(void)
{
    int cant;
    char cad[50] = {'\0'};
    printf("Ingrese una cadena de caracteres: ");
    gets(cad);
    cant = strlen(cad);
    printf("Resultado:\n");
    for (size_t i = 0; i < cant; i++)
    // Toma las posiciones pares de la cadena y las imprime
    {
        if (i % 2 != 0)
        {
            printf("%c", cad[i]);
        }
    }
    printf("\n");
}