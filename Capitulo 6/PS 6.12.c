/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 6.12                                     */
/*  Fecha:     03/03/2022                                  */
/***********************************************************/

#include <stdio.h>
/*Recoge informacion sobre la cantidad de visitantes en cada mes de los ultimos 5 años en los
10 principales estadios de Mexico y devuelve lo siguiente:
-El número de asistentes del último año en cada estadio, ordenados de mayor a menor
-Los estadios que tuvieron la mayor y menor afluencia de público en los últimos cinco años,
junto con el número de asistentes.
-El mes del último año en que cada estadio tuvo la mayor afluencia de público, junto con el
número de asistentes*/

char estadio[10][25] = {{"BBVA"}, {"Azteca"}, {"Akron"}, {"Olimpico Universitario"}, {"Hidalgo"}, {"Victoria"}, {"Corregidora"}, {"Corona"}, {"Universitario (UANL)"}, {"Cuauhtemoc"}};
// Un arreglo que contiene los nombre de los estadios principales de Mexico
void ultimo(int VEC[][5][12]);
void mes(int VEC[][5][12]);
void masmenos(int VEC[][5][12]);

void main(void)
{
    int i, j, r, X, SEC[10][5][12];
    for (r = 0; r < 10; r++)
        // Va preguntando sobre las cantidades de visitantes
    {
        for (i = 0; i < 5; i++)
        {
            switch (i)
            // Relaciona las casillas del arreglo con sus años correspondientes
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
            {
                printf("Ingrese la cantidad de visitantes del estadio %s en el mes %d de %d: ", estadio[r], j + 1, X);
                scanf("%d", &SEC[r][i][j]);
            }
        }
    }
    ultimo(SEC);
    masmenos(SEC);
    mes(SEC);
}

void ultimo(int VEC[][5][12])
//Imprime las cantidades de asistencias en cada estadio del ultimo año de mayor a menor
{
    int i, j, r, f, RESS[10] = {0}, ARR[10];
    printf("\nNumero de asistentes del 2022:\n");
    for (r = 0; r < 10; r++)
    //Suma las visitas de los meses
    {

        for (i = 0; i < 12; i++)
        {
            RESS[r] += VEC[r][0][i];
        }
        ARR[r] = r;
    }
    for (i = 1; i < 10; i++)
    //Organiza los estadios de mayor a menor
    {
        r = i;
        j = RESS[i];
        f = ARR[i];
        while (r > 0 && j > RESS[r - 1])
        {
            RESS[r] = RESS[r - 1];
            ARR[r] = ARR[r - 1];
            r = r - 1;
        }
        RESS[r] = j;
        ARR[r] = f;
    }
    for (i = 0; i < 10; i++)
    //Imprime los resultados
    {
        printf("-%s con %d\n", estadio[ARR[i]], RESS[i]);
    }
}

void masmenos(int VEC[][5][12])
//Imprime los estadios con mayor y menor afluencia de personas
{
    int i, j, r, Y, AA, BB, RESS = 0, MAX = 0, MIN = 1000000000;
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
    printf("\n%s fue el estadio con mayor afluencia de visitas con %d personas\n", estadio[AA], MAX);
    printf("%s fue el estadio con menor afluencia de visitas con %d personas\n", estadio[BB], MIN);
}

void mes(int VEC[][5][12])
//Ofrece el mejor mes en cada estadio
{
    int i, j, est[10], MAX = 0, meses[10];
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 12; j++)
        {
            if (VEC[i][0][j] > MAX)
            {
                MAX = VEC[i][0][j];
                meses[i] = j;
            }
        }
        est[i] = MAX;
    }
    for (i = 0; i < 10; i++)
    {
        printf("\nEl mes de 2022 con mayor afluencia de publico en el estadio %s fue el mes %d con %d personas\n", estadio[i], meses[i] + 1, est[i]);
    }
}