/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 6.11                                     */
/*  Fecha:     01/03/2022                                  */
/***********************************************************/

#include <stdio.h>
/*Programa que almacena informacion para la cecretaría de Turismo de México sobre la cantidad
de visitantes de los 10 principales centros turisticos del pais en cada mes de los ultimos 5 años*/
void total(int VEC[][5][12]);
void mes(int VEC[][5][12]);
void centros(int VEC[][5][12]);

void main(void)
{
    int i, j, r, X, SEC[10][5][12];
    char plaza[10][25] = {{"Cancun"}, {"Xochimilco"}, {"Oaxaca"}, {"Guadalajara"}, {"Los Cabos"}, {"Parque Dos Ojos"}, {"Guanajuato"}, {"Acapulco"}, {"Parque Fundidora"}, {"Santuario de Mariposas"}};
    //Un arreglo que almacena los nombres de los 10 principales centros turisticos
    for (r = 0; r < 10; r++)
    {        
        for (i = 0; i < 5; i++)
        {
            switch (i)
            //Relaciona cada valor concerniente a los años con un año en especifico
            {
            case 0:
                X = 2022;
                break;           
            case 1:
                X = 2021;
                break;
            case 2:
                X = 2020;
                break;
            case 3:
                X = 2019;
                break;
            case 4:
                X = 2018;
                break;
            }
            for (j = 0; j < 12; j++)
            //Usando los tres ciclos se encarga de asignar la cantidad de visitantes
            {
                printf("Ingrese la cantidad de visitantes de %s en el mes %d de %d: ", plaza[r], j+1, X);
                scanf("%d", &SEC[r][i][j]);
            }
            
        }
        
    }    
    total(SEC); 
    centros(SEC);
    mes(SEC);   
}

void total(int VEC[][5][12])
//Plasma las cantidades de visitantes en cada lugar
{
    int i, j, r, RESS=0;
    char plaza[10][25] = {{"Cancun           "}, {"Xochimilco       "}, {"Oaxaca           "}, {"Guadalajara       "}, {"Los Cabos       "}, {"Parque Dos Ojos    "}, {"Guanajuato       "}, {"Acapulco          "}, {"Parque Fundidora"}, {"Santuario de Mariposas"}};
    printf("\nTotal de visitantes:\n");
    for (r = 0; r < 10; r++)
    {      
        for (j = 0; j < 5; j++)
        {
            for (i = 0; i < 12; i++)
            {
                RESS += VEC[r][j][i];
            }
            
        }
        printf("%s\t\t%d\n", plaza[r], RESS);
        RESS = 0;
    }
    
}

void centros(int VEC[][5][12])
//Se encarga de averiguar cual fue el centro que tuvo mas visitantes y el que tuvo menos
{
    int i, j, r, Y, AA, BB, RESS=0, MAX=0, MIN=1000000000;
    char plaza[10][25] = {{"Cancun"}, {"Xochimilco"}, {"Oaxaca"}, {"Guadalajara"}, {"Los Cabos"}, {"Parque Dos Ojos"}, {"Guanajuato"}, {"Acapulco"}, {"Parque Fundidora"}, {"Santuario de Mariposas"}};
    for (r = 0; r < 10; r++)
    {
        for (j = 0; j < 5; j++)
        {
            for (i = 0; i < 12; i++)
            {
                RESS += VEC[r][j][i];
            }
            
        }
        if (RESS > MAX)
        {
            MAX = RESS;
            AA = r;
        }
        if (RESS < MIN)
        {
            MIN = RESS;
            BB = r;
        }        
        RESS = 0;
    }
    printf("%s fue el lugar con mayor numero de visitas con %d visitantes\n", plaza[AA], MAX);
    printf("%s fue el lugar con menor numero de visitas con %d visitantes\n", plaza[BB], MIN);
}

void mes(int VEC[][5][12])
//Se encarga de averiguar cual fue el mes que tuvo mas visitantes y el que tuvo menos
{
    int j, r, AA, BB, MAX=0, MIN=1000000000, MES[12] = {0};
    for (r = 0; r < 10; r++)
    {
        for (j = 0; j < 12; j++)
        {
            MES[j] += VEC[r][0][j];
        }
       
    }
    for (j = 0; j < 12; j++)
    {
        if (MES[j] > MAX)
        {
            MAX = MES[j];
            AA = j;
        }
        if (MES[j] < MIN)
        {
            MIN = MES[j];
            BB = j;
        }    
    }
    printf("\nEl mes con mayor afluencia turistica fue el mes %d con %d turistas\n", AA+1, MAX);
    printf("El mes con menor afluencia turistica fue el mes %d con %d turistas\n", BB+1, MIN);
}