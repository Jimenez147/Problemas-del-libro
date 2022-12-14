/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 7.10                                     */
/*  Fecha:     12/04/2022                                  */
/***********************************************************/

#include <stdio.h>
#include <time.h>
#include <string.h>
/*El programa recibe cadenas con fechas al inicio e imprime solo las cadenas que contienen
la fecha actual*/
void fecha(char *fecha);

void main(void)
{
    char control = 's', hoy[11], cad[100][50];
    int i = 1;
    while (control == 's')
    // Recoge la cantidad de cadenas que el usuario desee
    {
        printf("Ingrese la cadena numero %d: ", i);
        fflush(stdin);
        gets(cad[i - 1]);
        printf("Desea ingresar otra cadena? (s/n): ");
        scanf("%c", &control);
        i++;
    }
    fecha(hoy);
    for (size_t j = 0; j < i - 1; j++)
    // Compara cada fecha en las cadenas con la fecha actual
    {
        if (strncmp(cad[j], hoy, 10) == 0)
        {
            printf("%s\n", cad[j]);
        }
    }
}

void fecha(char *fecha)
// Funcion que recoge la fecha actual
{
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    strftime(fecha, 128, "%d/%m/%Y", tlocal);
}