/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 7.7                                      */
/*  Fecha:     14/04/2022                                  */
/***********************************************************/

#include <stdio.h>
#include <string.h>
/*El programa recibe un numero de telefónico y lo imprime en el formato del pais*/
char cad[30];

void main(void)
{
    int x = 1; 
    char aux[30];
    printf("Ingrese un numero de telefono: ");
    gets(cad);
    strcpy(aux, cad);
    for(size_t i = 0; i < 15; i++)
    {
        if(i == 3)
        {
            x = 2;
        }
                    if(i == 6)
            {
                x = 3;
            }

        cad[i + x] = aux[i];

    }
    cad[0] = '(';
    cad[4] = ')';
    cad[8] = '-';
    printf("%s\n",cad);
}