/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 8.3                                      */
/*  Fecha:     18/04/2022                                  */
/***********************************************************/

#include <stdio.h>
#include <string.h>
/*Base de detos de profesores de una universidad con la capacidad de devolver el profesor con 
mayor sueldo, la cantidad de sueldos destinados al extranjero y el departamento al que ingreso
el mayor sueldo*/

char departamentos[4][15] = {"Economia", "Derecho", "Computacion", "Administracion"};

typedef struct
{
    int numero;
    char nombre[30];
    int departamento;
    char puesto[30];
    char grado[30];
    char nacionalidad[30];
    float sueldo[12];
} profesor;

profesor EMPLE[200];
int N;

void mejor(profesor RTS[]);
void extranjero(profesor RTS[]);
void departamento(profesor RTS[]);
float porciento(float X, float Y, int MODO);

void main(void)
{
    printf("Ingrese la cantidad de profesores: ");
    scanf("%d", &N);
    for (size_t i = 0; i < N; i++)
    //Lectura de datos
    {
        printf("\n\nIngrese los datos del profesor %d: ", i + 1);
        printf("\nN%cmero de empleado: ", 163);
        scanf("%d", &EMPLE[i].numero);
        printf("Nombre y apellido: ");
        fflush(stdin);
        gets(EMPLE[i].nombre);
        printf("Departamento al que pertenece: 1-Economia, 2-Derecho, 3-Computacion, 4-Administracion: ");
        scanf("%d", &EMPLE[i].departamento);
        printf("Puesto que ocupa: ");
        fflush(stdin);
        gets(EMPLE[i].puesto);
        printf("Grado acad%cmico: ", 130);
        fflush(stdin);
        gets(EMPLE[i].grado);
        printf("Pais de origen: ");
        fflush(stdin);
        gets(EMPLE[i].nacionalidad);
        for (size_t j = 0; j < 12; j++)
        {
            printf("Ingrese el sueldo del mes %d: ", j + 1);
            scanf("%f", &EMPLE[i].sueldo[j]);
        }
    }
    mejor(EMPLE);
    extranjero(EMPLE);
    departamento(EMPLE);
}

void mejor(profesor RTS[])
//Devuelve el profesor con mayor sueldo
{
    float suma = 0, mayor = 0;
    int best;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < 12; j++)
        {
            suma += RTS[i].sueldo[j];
        }
        if (suma > mayor)
        {
            mayor = suma;
            best = i;
        }
        suma = 0;
    }
    printf("\n\nProfesor con mayor sueldo: ");
    printf("\nNombre: %s", RTS[best].nombre);
    printf("\nDepartamento: %s", departamentos[RTS[best].departamento - 1]);
    printf("\nPais de origen: %s", RTS[best].nacionalidad);
    printf("\nSueldo total: %.2f", mayor);
}

void extranjero(profesor RTS[])
//Suma los sueldos del extranjero y tambien el total de sueldos para luego hacer comparacion
{
    float suma = 0, total = 0, porcentaje = 0;
    char pais[10] = "Colombia";
    for (size_t i = 0; i < N; i++)
    {
        if (strcmp(RTS[i].nacionalidad, pais) != 0)
        {
            for (size_t j = 0; j < 12; j++)
            {
                suma += RTS[i].sueldo[j];
            }
        }
        else
        {
            for (size_t j = 0; j < 12; j++)
            {
                total += RTS[i].sueldo[j];
            }
        }
    }
    total += suma;
    porcentaje = porciento(suma, total, 2);
    printf("\n\nMonto total pagado a los profesores extranjeros: %.2f", suma);
    printf("\nPorcentaje de los profesores extranjeros respecto al total: %.2f%c", porcentaje, 37);
}

float porciento(float X, float Y, int MODO)
/*Trabaja con el porcentaje Ej: 50% de 200 = 100
Elejir un modo:
1- X = 50% Y = 200
2- X = 100 Y = 200
3- x = 100 y = 50%
(Ingresar el porcentaje sin hacer la divicion entre 100)*/
{
    switch (MODO)
    {
    case 1:
        return ((X / 100) * Y);
        break;
    case 2:
        return ((X / Y) * 100);
        break;
    case 3:
        return (X / (Y / 100));
        break;
    }
}

void departamento(profesor RTS[])
//Suma totales de sueldos en funcion a los departamentos
{
    float dep[4] = {0}, total = 0;
    int best;
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < 12; j++)
        {
            switch (RTS[i].departamento)
            {
            case 1:
                dep[0] += RTS[i].sueldo[j];
                break;
            case 2:
                dep[1] += RTS[i].sueldo[j];
                break;
            case 3:
                dep[2] += RTS[i].sueldo[j];
                break;
            case 4:
                dep[3] += RTS[i].sueldo[j];
                break;
            }
        }
    }
    for (size_t i = 0; i < 4; i++)
    //Busca el departamento con mayor entrada
    {
        if (dep[i] > total)
        {
            total = dep[i];
            best = i;
        }
    }
    printf("\n\nDepartamento con mayor sueldo: %s", departamentos[best]);
}