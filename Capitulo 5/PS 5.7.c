/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 5.7                                      */
/*  Fecha:     15/03/2022                                  */
/***********************************************************/

#include <stdio.h>
/*El programa registra las cosechas recogidas a lo largo de un año y devuelve el promedio de
la cosecha, los meses superiores al promedio y el mes con mayor cosecha*/

//Funciones
void datos(int VEC[]);
void promedio(int VEC[]);
void msp(int VEC[]);
void mejormes(int VEC[]);
//Variables glovales 
const int M=12;
float PRO;

void main(void)
//Estructura principal
{
    int COS[12];
    datos(COS);
    promedio(COS);
    msp(COS);
    mejormes(COS);
}

void datos(int VEC[])
//Registra las toneladas conseguidas en cada mes
{
    int i;
    for (i = 0; i < M; i++) 
    //Es una instruccion que permite crear un ciclo con un numero finito de repeticiones
    {
        printf("\nIngrese las toneladas cosechadas en el mes %d: ", i+1);
        scanf("%d", &VEC[i]);
    }
    
}

void promedio(int VEC[])
//Imprime en pantalla el promedo de toneladas conseguidas en el año
{
    int i, RESS=0;
    for (i = 0; i < M; i++)
    {
        RESS += VEC[i];
    }
    PRO = (float)RESS/M;
    printf("El promedio anual de toneladas cosechadas es %.2f\n", PRO);
}

void msp(int VEC[])
//Analiza e imprime los mejes cuya cantidad cosechada es superior al promedio
{
int i;
printf("\nLos meses con cosechas superiores al promedio fueron:\n");
for (i = 0; i < M; i++)
{
    if (VEC[i] > PRO)
    //Es la instruccion encargada de verificar los meses para saber si su valor es superior al promedio
    {
        printf("El %d\n", i+1);
    }
}
}

void mejormes(int VEC[])
//Compara los meses e imprime el que haya obtenido la mayor cantidad de cosecha
{
    int i, B, RESS=VEC[0];
    for (i = 0; i < M; i++)
    {
        if (VEC[i] > RESS)
        {
            RESS = VEC[i];
            B = i+1;
        }
        
    }
    printf("\nEl mes con mayor numero de toneladas fue %d con %d toneladas\n", B, RESS);
}