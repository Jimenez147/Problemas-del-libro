/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 6.10                                     */
/*  Fecha:     03/03/2022                                  */
/***********************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
/*El programa resuelve el problema de ajedrez "La Marcha del Caballo". Empesando desde cualquier
casilla da los pasos a seguir por el caballo*/
char tablero[8][8][3] = {{"A8", "B8", "C8", "D8", "E8", "F8", "G8", "H8"}, {"A7", "B7", "C7", "D7", "E7", "F7", "G7", "H7"}, {"A6", "B6", "C6", "D6", "E6", "F6", "G6", "H6"}, {"A5", "B5", "C5", "D5", "E5", "F5", "G5", "H5"}, {"A4", "B4", "C4", "D4", "E4", "F4", "G4", "H4"}, {"A3", "B3", "C3", "D3", "E3", "F3", "G3", "H3"}, {"A2", "B2", "C2", "D2", "E2", "F2", "G2", "H2"}, {"A1", "B1", "C1", "D1", "E1", "F1", "G1", "H1"}};
// Un arreglo que contiene las casillas del tablero
int F, C;
void nombra(int VEC[]);
void clasifica(int, int);
void paso(int, int, int);
void arreglo(int, int);

void main(void)
{
    int i;
    char INI[3];
    printf("Ingrese la posicion inicial: ");
    scanf("%s", &INI);
    printf("\nPasos:\n");
    nombra(INI);
    for (i = 0; i < 63; i++)
    {
        clasifica(F, C);
    }
    printf("FIN\n");
}

void nombra(int VEC[])
// La funcion se encarga de identificar la casilla inicial que fue escrita
{
    int i, j;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (strcmp(VEC, tablero[i][j]) == 0)
            {
                F = i;
                C = j;
                clasifica(i, j);
            }
        }
    }
}

void clasifica(int A, int B)
{
    double RESS, CLASS[4][4][4] = {{{64, 216, 3125, 2401}, {36, 625, 16807, 512}, {343, 25, 1296, 32768}, {49, 125, 7776, 4096}}, {{262144, 279936, 1953125, 5764801}, {46656, 390625, 40353607, 2097152}, {823543, 15625, 1679616, 134217728}, {117649, 78125, 10077696, 16777216}}, {{144, 1000, 59049, 14641}, {100, 6561, 161051, 1728}, {1331, 81, 10000, 248832}, {121, 729, 100000, 20736}}, {{2985984, 10000000, 387420489, 214358881}, {1000000, 43046721, 2357947691, 35831808}, {19487171, 531441, 100000000, 5159780352}, {1771561, 4782969, 1000000000, 429981696}}};
    /*El arreglo asigna un identificador especifico a cada casilla del tablero usando una ecuacion 
    y los clasifica usando 3 parametros necesarios para el algoritmo*/
    int i, j, r, C = 0;
    printf("%s,  ", tablero[A][B]);
    RESS = pow((A + 5), (B + 2));
    //Es la ecuacion utilizada para determinar los identificadores
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            for (r = 0; r < 4; r++)
            {
                if (CLASS[i][j][r] == RESS)
                /*luego de encontrar la casilla usando el identificador captura los valores que 
                representan los parametros y se los ofrece a la funcion "paso"*/
                {
                    paso(i, j, r);
                    C = 1;
                    break;
                }
            }
            if (C)
            {
                break;
            }
        }
        if (C)
        {
            break;
        }
    }
    C = 0;
}

void paso(int S, int G, int L)
//Usando los parametros determina los pasos a dar hacia la siguiente casilla
{
    int i;
    switch (S)
    {
    case 0:
        switch (G)
        {
        case 0:
            switch (L)
            {
            case 0:
                F -= 2;
                C++;
                break;
            case 1:
                F--;
                C += 2;
                break;
            case 2:
                F += 2;
                C--;
                break;
            case 3:
                F--;
                C += 2;
                break;
            }
            break;
        case 1:
            switch (L)
            {
            case 0:
                F--;
                C += 2;
                break;
            case 1:
                F += 2;
                C--;
                break;
            case 2:
                F++;
                C -= 2;
                break;
            case 3:
                F -= 2;
                C--;
                break;
            }
            break;
        case 2:
            switch (L)
            {
            case 0:
                F -= 2;
                C--;
                break;
            case 1:
                F++;
                C = +2;
                break;
            case 2:
                F += 2;
                C++;
                break;
            case 3:
                F--;
                C += 2;
                break;
            }
            break;
        case 3:
            switch (L)
            {
            case 0:
                F -= 2;
                C++;
                break;
            case 1:
                F++;
                C += 2;
                break;
            case 2:
                F--;
                C += 2;
                break;
            case 3:
                F--;
                C -= 2;
                break;
            }
            break;
        }
        break;
    case 1:
        switch (G)
        {
        case 0:
            switch (L)
            {
            case 0:
                F -= 2;
                C++;
                break;
            case 1:
                F--;
                C += 2;
                break;
            case 2:
                F += 2;
                C--;
                break;
            case 3:
                F += 2;
                C++;
                break;
            }
            break;
        case 1:
            switch (L)
            {
            case 0:
                F--;
                C += 2;
                break;
            case 1:
                F += 2;
                C++;
                break;
            case 2:
                F++;
                C -= 2;
                break;
            case 3:
                F += 2;
                C--;
                break;
            }
            break;
        case 2:
            switch (L)
            {
            case 0:
                F -= 2;
                C--;
                break;
            case 1:
                F++;
                C += 2;
                break;
            case 2:
                F += 2;
                C++;
                break;
            case 3:
                F += 2;
                C--;
                break;
            }
            break;
        case 3:
            switch (L)
            {
            case 0:
                F += 2;
                C++;
                break;
            case 1:
                F++;
                C += 2;
                break;
            case 2:
                F += 2;
                C--;
                break;
            case 3:
                F--;
                C -= 2;
                break;
            }
            break;
        }
        break;
    case 2:
        switch (G)
        {
        case 0:
            switch (L)
            {
            case 0:
                F -= 2;
                C++;
                break;
            case 1:
                F -= 2;
                C--;
                break;
            case 2:
                F += 2;
                C--;
                break;
            case 3:
                F++;
                C -= 2;
                break;
            }
            break;
        case 1:
            switch (L)
            {
            case 0:
                F--;
                C += 2;
                break;
            case 1:
                F -= 2;
                C++;
                break;
            case 2:
                F++;
                C -= 2;
                break;
            case 3:
                F -= 2;
                C--;
                break;
            }
            break;
        case 2:
            switch (L)
            {
            case 0:
                F -= 2;
                C--;
                break;
            case 1:
                F--;
                C += 2;
                break;
            case 2:
                F += 2;
                C++;
                break;
            case 3:
                F--;
                C -= 2;
                break;
            }
            break;
        case 3:
            switch (L)
            {
            case 0:
                F -= 2;
                C++;
                break;
            case 1:
                F++;
                C += 2;
                break;
            case 2:
                F -= 2;
                C++;
                break;
            case 3:
                F--;
                C -= 2;
                break;
            }
            break;
        }
        break;
    case 3:
        switch (G)
        {
        case 0:
            switch (L)
            {
            case 0:
                F -= 2;
                C++;
                break;
            case 1:
                F--;
                C -= 2;
                break;
            case 2:
                F += 2;
                C--;
                break;
            case 3:
                F++;
                C -= 2;
                break;
            }
            break;
        case 1:
            switch (L)
            {
            case 0:
                F--;
                C += 2;
                break;
            case 1:
                F += 2;
                C++;
                break;
            case 2:
                F++;
                C -= 2;
                break;
            case 3:
                F--;
                C -= 2;
                break;
            }
            break;
        case 2:
            switch (L)
            {
            case 0:
                F -= 2;
                C--;
                break;
            case 1:
                F++;
                C -= 2;
                break;
            case 2:
                F += 2;
                C++;
                break;
            case 3:
                F--;
                C -= 2;
                break;
            }
            break;
        case 3:
            switch (L)
            {
            case 0:
                F++;
                C -= 2;
                break;
            case 1:
                F++;
                C += 2;
                break;
            case 2:
                F += 2;
                C--;
                break;
            case 3:
                F--;
                C -= 2;
                break;
            }
            break;
        }
        break;
    }
}