/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 8.2                                      */
/*  Fecha:     21/04/2022                                  */
/***********************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Una base de datos de partidos de futbol en mexico, con la posibilidad de agregar partidos*/
typedef struct
// Estructura con los datos de cada equipo
{
    char nombre[30];
    int part_jugados;
    int part_ganados;
    int part_empatados;
    int part_perdidos;
    int goles_favor;
    int goles_contra;
    int diferencia_goles;
    int puntos;
} EQUIPO;

EQUIPO FUTBOL[20];
void posiciones(EQUIPO RTS[]);
void agregar(EQUIPO RTS[]);
void update(char equipo1[], char equipo2[], int puntos1, int puntos2);

void main(void)
{
    char control;
    for (size_t i = 0; i < 20; i++)
    // Lectura de datos de cada equipo
    {
        printf("Datos del equipo %d\n", i + 1);
        printf("Nombre: ");
        fflush(stdin);
        gets(FUTBOL[i].nombre);
        printf("Partidos jugados: ");
        scanf("%d", &FUTBOL[i].part_jugados);
        printf("Partidos ganados: ");
        scanf("%d", &FUTBOL[i].part_ganados);
        printf("Partidos empatados: ");
        scanf("%d", &FUTBOL[i].part_empatados);
        FUTBOL[i].part_perdidos = FUTBOL[i].part_jugados - FUTBOL[i].part_ganados - FUTBOL[i].part_empatados;
        printf("Goles a favor: ");
        scanf("%d", &FUTBOL[i].goles_favor);
        printf("Goles en contra: ");
        scanf("%d", &FUTBOL[i].goles_contra);
        FUTBOL[i].diferencia_goles = FUTBOL[i].goles_favor - FUTBOL[i].goles_contra;
        FUTBOL[i].puntos = FUTBOL[i].part_ganados * 3 + FUTBOL[i].part_empatados;
        printf("\n");
    }
    while (1)
    // Menu para agregar partidos
    {
        posiciones(FUTBOL);
        printf("\nDesea agregar un partido? (s/n): ");
        fflush(stdin);
        scanf("%c", &control);
        if (control == 's')
        {
            agregar(FUTBOL);
        }
        else
        {
            break;
        }
    }
}

void posiciones(EQUIPO RTS[])
// Imprime una tabla con el ranking de los equipos
{
    int point[20], control = 0, best;
    for (size_t i = 0; i < 20; i++)
    {
        point[i] = RTS[i].puntos;
    }
    for (size_t i = 0; i < 20; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            if (point[j] > control)
            {
                control = point[j];
                best = j;
            }
        }
        printf("Posicion no %d: %s\n", i + 1, RTS[best].nombre);
        point[best] = 0;
        control = 0;
    }
}

void agregar(EQUIPO RTS[])
// Lee los datos en el formato ingresado y se encarda de identificar sus valores y de separarlos
{
    int pt1, pt2, X;
    char partido[50], eq1[30] = {'\0'}, eq2[30] = {'\0'}, point[5], point2[5];
    printf("Ingrese los resultado del partido: ");
    fflush(stdin);
    gets(partido);
    for (size_t i = 0; i < 25; i++)
    {
        eq1[i] = partido[i];
        if (partido[i + 2] >= '0' && partido[i + 2] <= '9')
        {
            sscanf(&partido[i + 2], "%s", point);
            X = strlen(point);
            for (size_t j = i + 5 + X; j < 50; j++)
            {
                eq2[j - i - 5 - X] = partido[j];
                if (partido[j + 2] >= '0' && partido[j + 2] <= '9')
                {
                    sscanf(&partido[j + 2], "%s", point2);
                    break;
                }
            }
            break;
        }
    }
    pt1 = atoi(point);
    pt2 = atoi(point2);
    update(eq1, eq2, pt1, pt2);
}

void update(char equipo1[], char equipo2[], int puntos1, int puntos2)
// Recive los valores ya separados en variables y actualiza la informacion de la base de datos
{
    for (size_t j = 0; j < 20; j++)
    {
        if (strcmp(equipo1, FUTBOL[j].nombre) == 0)
        {
            FUTBOL[j].part_jugados++;
            if (puntos1 > puntos2)
            {
                FUTBOL[j].part_ganados++;
                FUTBOL[j].puntos += 3;
            }
            else if (puntos1 == puntos2)
            {
                FUTBOL[j].part_empatados++;
                FUTBOL[j].puntos += 1;
            }
            else
            {
                FUTBOL[j].part_perdidos++;
            }
            FUTBOL[j].goles_favor += puntos1;
            FUTBOL[j].goles_contra += puntos2;
            FUTBOL[j].diferencia_goles = FUTBOL[j].goles_favor - FUTBOL[j].goles_contra;
        }
        if (strcmp(equipo2, FUTBOL[j].nombre) == 0)
        {
            FUTBOL[j].part_jugados++;
            if (puntos2 > puntos1)
            {
                FUTBOL[j].part_ganados++;
                FUTBOL[j].puntos += 3;
            }
            else if (puntos2 == puntos1)
            {
                FUTBOL[j].part_empatados++;
                FUTBOL[j].puntos += 1;
            }
            else
            {
                FUTBOL[j].part_perdidos++;
            }
            FUTBOL[j].goles_favor += puntos2;
            FUTBOL[j].goles_contra += puntos1;
            FUTBOL[j].diferencia_goles = FUTBOL[j].goles_favor - FUTBOL[j].goles_contra;
        }
    }
}