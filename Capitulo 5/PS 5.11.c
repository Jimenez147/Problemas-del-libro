/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 5.11                                     */
/*  Fecha:     15/03/2022                                  */
/***********************************************************/

#include <stdio.h>
/*El programa es capaz de ayar numeros perfectos (con restricciones)*/

int NUM[30];
int perft(int X);

void main(void)
{
    int i = 1;
    int p = 0;
    do
    {
        if (perft(i))
        //Va preguntando con cada numero si es o no perfecto
        {
            NUM[p] = i;
            p++;
        }
        i++;
        
    } while (p < 30);    
}

int perft(int X)
//Averigua si un numero es perfecto
{
    int div[50000], RESS = 0, w, v = 0;
    for (int i = 1; i <= X/2; i++)
    //Recolecta los divisores de un numero
    {
        w = X % i;
        if (w == 0)
        {
            div[v] = i;
            v++;
        }
        
    }
    for (int i = 0; i < v; i++)
    //Suma los divisores
    {
        RESS += div[i];
    }
    if (RESS == X)
    //Si la suma de divisores es igual al numero retorna un positivo, de lo contrario un negativo
    {
        return 1;
    }
    else
    {
        return 0;
    }
}