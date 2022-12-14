/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 7.9                                      */
/*  Fecha:     12/04/2022                                  */
/***********************************************************/

#include <stdio.h>
/*El programa recibe una frace y la imprime de atras hacia alante*/
char cad[50], cad2[50][20];
int MAX = 50;
int palabra(char VEC[], char palabra[][20]);

void main(void)
{
    int cant, i = 0, j = 0;
    printf("Ingrese una cadena de caracteres: ");
    gets(cad);
    cant = palabra(cad, cad2);
    while(cant >= 0)
    {
        cad[j] = cad2[cant][i]; 
        i++;
        j++;
        if(cad2[cant][i] == '\0')
        {
            i = 0;
            cant--;
            cad[j] = ' ';
            j++;
        }
    }
    printf("%s", cad);
}

int palabra(char VEC[], char palabra[][20])
// Recibe un arreglo con una frace y divide sus palabras en otro arreglo
// Utiliza la variable groval "MAX"
{
    int j = 0, r = 0;
    for(size_t i = 0; i < MAX; i++)
    {
        palabra[j][r] = VEC[i];
        r++;
        if(VEC[i + 1] == ' ')
        {
            j++;
            i++;
            r = 0;
        }
    }
    return j;
}