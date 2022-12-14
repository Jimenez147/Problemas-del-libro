/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 6.3                                      */
/*  Fecha:     01/03/2022                                  */
/***********************************************************/
#include <stdio.h>
/*El programa te permite introducir los valores de un arreglo y luego intercambia las filas.
Los elementos de la primera fila se intercambian con los de la última fila, los del segundo con 
los de la penúltima, y así sucesivamente.*/

//constantes glovales que identifican la cantidad de filas y culumnas del arreglo
const int X=3, Y=3;
//funciones
void datos(int VEC[][Y]);
void interc(int VEC[][Y]);
void imprime2(int VEC[][Y]);

void main(void)
{
    int ARR[X][Y];
    datos(ARR);
    interc(ARR);
    imprime2(ARR);
}

void datos(int VEC[][Y])
//Funcion que permite ingresar los valores de cada casilla del arreglo
{
    int i, j;
    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Y; j++)
        {
            printf("Ingrese el valor de la fila %d y columna %d: ", i+1, j+1);
            scanf("%d", &VEC[i][j]);
        }
        
    }
    
}

void interc(int VEC[][Y])
{
    int i, j, R, MIRR[X][Y];
    R = X-1;
    //Primero crea un arreglo al que se le asignan los valores con las filas intercambiadas
    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Y; j++)
        {
            MIRR[R][j] = VEC[i][j];
        }
        R--;
    }
    //Luego se le asignan los valores del arreglo creado al arreglo original
    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Y; j++)
        {
            VEC[i][j] = MIRR[i][j];
        }
        
    }
    
}

void imprime2(int VEC[][Y])
//La funcion se encarga de plasmar los valores del arreglo en forma de cuadricula 
//Toma dos variables glovales (X y Y) que representan las cantidades de casillas del arreglo
{
    int i, j;
    for (i = 0; i < X; i++)
    {
       for (j = 0; j < Y; j++)
       {
           printf("%d  ", VEC[i][j]);
       }
       printf("\n");
    }
}