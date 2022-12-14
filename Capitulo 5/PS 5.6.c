/***********************************************************/
/*           Programación para mecatrónicos                */
/*  Nombre:    Bryan Jimenez                               */
/*  Matricula: 2021-1108                                   */
/*  Seccion:   Sabados                                     */
/*  Practica:  PS 5.6                                      */
/*  Fecha:     17/03/2022                                  */
/***********************************************************/

#include <stdio.h>
/*Almacena las calificaciones de un grupo de alumnos que presentaron un examen de admisión
a una universidad. Devuelve el promedio de calificaciones, los estudiantes aprovados y
la cantidad de estudiantes con mejores calificaciones*/

int ALU[100], MAX;
void promedio(int VEC[]);
void aprobados(int VEC[]);
void mejores(int VEC[]);

void main(void)
{
    printf("Ingrese la cantidad de alumnos: ");
    scanf("%d", &MAX);
    for (size_t i = 0; i < MAX; i++)
    // Captura las calificaciones de cada estudiante
    {
        printf("Ingrese la cantidad de puntos del alumno %d: ", i + 1);
        scanf("%d", &ALU[i]);
    }
    promedio(ALU);
    aprobados(ALU);
    mejores(ALU);
}

void promedio(int VEC[])
// Imprime el promedio de calificaciones de los estudiantes
{
    int total = 0;
    for (size_t i = 0; i < MAX; i++)
    {
        total += VEC[i];
    }
    printf("\nPromedio de calificaciones: %.2f", (float)total / MAX);
}

void aprobados(int VEC[])
/*Suma la cantidad de estudiantes con una calificacion mayor a 1300 e imprime el promedio de
estas respecto a la cantidad total de estudiantes*/
{
    int total = 0;
    for (size_t i = 0; i < MAX; i++)
    {
        if (VEC[i] > 1300)
        {
            total++;
        }
    }
    printf("\nPromedio de aprobados: %.2f", (float)total / MAX);
}

void mejores(int VEC[])
// Cuenta la cantidad de estudiantes con calificaciones mayores a 1500 e imprime la suma
{
    int total = 0;
    for (size_t i = 0; i < MAX; i++)
    {
        if (VEC[i] >= 1500)
        {
            total++;
        }
    }
    printf("\nHay %d alumnos con una calificacion igual o mayor a 1500\n", total);
}