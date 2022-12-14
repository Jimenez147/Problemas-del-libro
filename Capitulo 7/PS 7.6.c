/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 7.6                                      */
/*  Fecha:     12/04/2022                                  */
/***********************************************************/

#include <stdio.h>
#include <string.h>
/*El programa recibe una cantidad determinada de cadenas e imprime la cadena mas larga*/
char cadena[100][20];
void compara(char cadena[][20], int n);

void main(void)
{
    char control = 's';
    int i = 1;
    while (control == 's')
    //Recoge la cantidad de cadenas que el usuario desee
    {
        printf("Ingrese la cadena numero %d: ", i);
        fflush(stdin);
        gets(cadena[i - 1]);
        printf("Desea ingresar otra cadena? (s/n): ");
        scanf("%c", &control);
        i++;
    }
    compara(cadena, i - 1);
}

void compara(char cad[][20], int n)
{
    int RESS = 0;
    for (size_t i = 0; i < n; i++)
    {
        if (strcmp(cad[i], cad[RESS]) > 0)
        // Compara las cadenas en busqueda de la mas larga
        {
            RESS = i;
        }
    }
    printf("\nLa cadena mas larga es la cadena %d: %s\n", RESS + 1, cad[RESS]);
}