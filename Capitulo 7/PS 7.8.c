/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 7.8                                      */
/*  Fecha:     12/04/2022                                  */
/***********************************************************/

#include <stdio.h>
/* El programa recibe dos cadenas de caracteres y crea una tercera cadena con las palabras
de ambas cadenas mescladas*/
char cad1[50], cad2[50], cad3[100];
void construye(char cadena1[], char cadena2[]);

void main(void)
{
    printf("Ingrese la primera cadena: ");
    gets(cad1);
    fflush(stdin);
    printf("Ingrese la segunda cadena: ");
    gets(cad2);
    construye(cad1, cad2);
}

void construye(char cadena1[], char cadena2[])
// Se encarga de asignar los valores a la tercera cadena como corresponde
{
    int i, x = 1, j = 0, c1 = 0, c2 = 0;
    char control, last;
    while (control != '\0')
    {
        if (x)
        {
            for (i = c1; (cadena1[i] != ' ') && (cadena1[i] != '\0'); i++)
            {
                cad3[j] = cadena1[i];
                j++;
            }
            c1 = i + 1;
            x = 0;
            control = cadena2[c2];
        }
        else
        {
            for (i = c2; (cadena2[i] != ' ') && (cadena2[i] != '\0'); i++)
            {
                cad3[j] = cadena2[i];
                j++;
            }
            c2 = i + 1;
            x = 1;
            control = cadena1[c1];
        }
        cad3[j] = ' ';
        j++;
        if (control == '\0')
        // En caso de que una cadena sea mayor a la otra
        {
            while (last != '\0')
            {
                if (x == 0)
                {
                    cad3[j] = cadena1[c1];
                    c1++;
                    last = cadena1[c1];
                }
                else
                {
                    cad3[j] = cadena2[c2];
                    c2++;
                    last = cadena2[c2];
                }
                j++;
            }
        }
    }
    printf("\nLa cadena resultante es: %s\n", cad3);
}