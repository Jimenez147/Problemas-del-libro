/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 8.4                                      */
/*  Fecha:     21/04/2022                                  */
/***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*Base de datos de estudiantes con sus respectivos datos, da la oportunidad de presentar el 
promedio general de un estudiante especifico, un listado de los estudiantes de un nivel especifico
y el mejor estudiante del nivel elegido*/
typedef struct 
{
    char calle[50];
    char colonia[50];
    char ciudad[50];
    int cp;
    char telefono[50];
} direccion;

typedef struct 
{
    char materia[50];
    float promedio;
} calificacion;


typedef struct
{
    char nivel[50];
    int grado;
    char salon[50];
    calificacion calificaciones[7];
} estudios;

typedef struct
{
    int matricula;
    char nombre[50];
    direccion domicilio;
    estudios nivel;
} alumnos;

int N;
alumnos escuala[1000];

float promedio(alumnos RTS[], int matricula);
void nivel(alumnos RTS[]);
void mejor(alumnos RTS[]);

void main(void)
{
    int control, matric;
    printf("Ingrese el numero de alumnos: ");
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    //Captura de datos
    {
        printf("\nAlumno %d\n", i+1);
        printf("Matricula: ");
        scanf("%d", &escuala[i].matricula);
        printf("Nombre: ");
        fflush(stdin);
        gets(escuala[i].nombre);
        printf("Calle: ");
        fflush(stdin);
        gets(escuala[i].domicilio.calle);
        printf("Colonia: ");
        fflush(stdin);
        gets(escuala[i].domicilio.colonia);
        printf("Ciudad: ");
        fflush(stdin);
        gets(escuala[i].domicilio.ciudad);
        printf("Codigo Postal: ");
        scanf("%d", &escuala[i].domicilio.cp);
        printf("Telefono: ");
        fflush(stdin);
        gets(escuala[i].domicilio.telefono);
        printf("Nivel: ");
        fflush(stdin);
        gets(escuala[i].nivel.nivel);
        printf("Grado: ");
        scanf("%d", &escuala[i].nivel.grado);
        printf("Salon: ");
        fflush(stdin);
        gets(escuala[i].nivel.salon);
        for(int j = 0; j < 7; j++)
        {
            printf("\nMateria %d\n", j+1);
            printf("Materia: ");
            fflush(stdin);
            gets(escuala[i].nivel.calificaciones[j].materia);
            printf("Promedio: ");
            scanf("%f", &escuala[i].nivel.calificaciones[j].promedio);
        }
    }
    while (1)
    // Menu de opciones
    {
        printf("\n\n1. Promedio General\n2. Listado segun el Nivel\n3. Alumno con el promedio mas alto\n4. Salir\n\nQue desea hacer? ");
        scanf("%d", &control);
        switch(control)
        {
            case 1:
                printf("Ingrese la matricula del alumno: ");
                scanf("%d", &matric);
                printf("El promedio general es: %.2f\n", promedio(escuala, matric));
                break;
            case 2:
                nivel(escuala);
                break;
            case 3:
                mejor(escuala);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Opcion invalida\n");
        }
    }
}

float promedio(alumnos RTS[], int matri)
// Calcula el promedio de un alumno segun su matricula
{
    int control = 0;
    float promedio = 0;
    for(int i = 0; i < N; i++)
    {
        if(RTS[i].matricula == matri)
        {
            for(int j = 0; j < 7; j++)
            {
                promedio += RTS[i].nivel.calificaciones[j].promedio;
            }
            promedio /= 7;
            return promedio;
            control = 1;
        }
    }
    if(control == 0)
    {
        printf("No se encontro al alumno\n");
    }
}

void nivel(alumnos RTS[])
// Recibe el nivel, el grado y el salon e imprime todos su estudiantes
{
    int control = 0, grado;
    char nivel[50], salon[50];
    printf("Ingrese el nivel: ");
    fflush(stdin);
    gets(nivel);
    printf("Ingrese el grado: ");
    scanf("%d", &grado);
    printf("Ingrese el salon: ");
    fflush(stdin);
    gets(salon);
    for(int i = 0; i < N; i++)
    {
        if(strcmp(RTS[i].nivel.nivel, nivel) == 0 && RTS[i].nivel.grado == grado && strcmp(RTS[i].nivel.salon, salon) == 0)
        {
            printf("\nAlumno %d\n", i+1);
            printf("Matricula: %d\n", RTS[i].matricula);
            printf("Nombre: %s\n", RTS[i].nombre);
            printf("Promedio: %.2f\n", promedio(RTS, RTS[i].matricula));
            control = 1;
        }
    }
    if(control == 0)
    {
        printf("No se encontraron alumnos\n");
    }
}

void mejor(alumnos RTS[])
//Recibe el nivel, el grado y el salon e imprime el alumno con el mejor promedio
{
    int control = 0, grado;
    char nivel[50], salon[50];
    float mejor = 0, prom;
    printf("Ingrese el nivel: ");
    fflush(stdin);
    gets(nivel);
    printf("Ingrese el grado: ");
    scanf("%d", &grado);
    printf("Ingrese el salon: ");
    fflush(stdin);
    gets(salon);
    for(int i = 0; i < N; i++)
    {
        if(strcmp(RTS[i].nivel.nivel, nivel) == 0 && RTS[i].nivel.grado == grado && strcmp(RTS[i].nivel.salon, salon) == 0)
        {
            prom = promedio(RTS, RTS[i].matricula);
            if(prom > mejor)
            {
                mejor = prom;
                control = 1;
            }
        }
    }
    if(control == 0)
    {
        printf("No se encontraron alumnos\n");
    }
    else
    {
        for(int i = 0; i < N; i++)
        {
            if(strcmp(RTS[i].nivel.nivel, nivel) == 0 && RTS[i].nivel.grado == grado && strcmp(RTS[i].nivel.salon, salon) == 0 && promedio(RTS, RTS[i].matricula) == mejor)
            {
                printf("\nAlumno no %d\n", i+1);
                printf("Matricula: %d\n", RTS[i].matricula);
                printf("Nombre: %s\n", RTS[i].nombre);
                printf("Promedio: %.2f\n", promedio(RTS, RTS[i].matricula));
            }
        }
    }
}