/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 7.4                                      */
/*  Fecha:     12/04/2022                                  */
/***********************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*El programa recibe una fecha en un formato y la imprime en uno diferente*/
void main(void)
{
    char cad[30] = {'\0'}, cad2[30] = {'\0'}, aux[3] = {'\0'}; 
    char meses[12][30] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};
    int mes;
    printf("Ingrese la fecha: ");
    gets(cad);
    strncat(cad2, cad, 2); // Toma los dias de la primera fecha y los guarda en la segunda
    strcat(cad2, " de ");
    for (size_t i = 0; i < 2; i++)
    // Guarda el mes en aux
    {
        aux[i] = cad[i + 3];
    }
    mes = atoi(aux);
    strcat(cad2, meses[mes - 1]);// Agrega el mes a la fecha
    strcat(cad2, " de ");
    if (cad[6] > 3)
    //hace distincion entre los siglos
    {
        strcat(cad2, "20");
    }
    else
    {
        strcat(cad2, "19");
    }
    strncat(cad2, cad + 6, 2);
    puts(cad2);
}