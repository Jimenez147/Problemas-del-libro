/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 7.12                                     */
/*  Fecha:     12/04/2022                                  */
/***********************************************************/

#include <stdio.h>
#include <ctype.h>
/*Recibe un arreglo de cadenas de caracteres y elige la que contiene mas letras mayusculas*/
char ARC[10][50];
void llenado(char VEC[][50]);

void main(void)
{
    int mayus1 = 0, mayus2 = 0, cad;
    llenado(ARC);
    for (size_t j = 0; j < 10; j++)
    {
        for (size_t i = 0; i < 50; i++)
        {
            if (isupper(ARC[j][i]))
            {
                mayus1++;
            }
        }
        if (mayus1 > mayus2)
        {
            mayus2 = mayus1;
            cad = j;
        }
        mayus1 = 0;
    }
    printf("La cadena con mas mayusculas es: %s\n", ARC[cad]);
}

void llenado(char VEC[][50])
// Asignacion de valores de la cadena
{
    for (size_t i = 0; i < 10; i++)
    {
        printf("Ingrese la cadena %d: ", i + 1);
        gets(VEC[i]);
        fflush(stdin);
    }
}