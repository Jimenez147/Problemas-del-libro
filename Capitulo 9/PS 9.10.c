/*Escribe un programa en C que obtenga lo siguiente:
a) El porcentaje tanto de hombres como de mujeres registrados en el hospital.
b) El número de pacientes de cada una de las categorías de condición.
c) El número de pacientes que hay en cada categoría de edad: 0-9, 10-19, 20-29,30-39, 40-49, 50-59,
60-69, 70-79, 80-89, 90-99, >=100. */
#include <stdio.h>

typedef struct
{
    char calle[100];
    int num;
    char col[100];
    char cp[10];
    char ciudad[100];
    char tel[12];
} ubicacion;

typedef struct
{
    int clave;
    char nom[100];
    int edad;
    char sexo;
    int condicion;
    ubicacion dom;
} paciente;

paciente arc[500];

void man_woman(paciente VEC[], int);
void cat(paciente VEC[], int);
void edad(paciente VEC[], int);

void main(FILE *data)
{
    int i = 1, cont;
    if ((data = fopen("lis.dat", "r")) != NULL)
    {
        fread(&arc[0], sizeof(paciente), 1, data);
        while (!feof(data))
        {
            fread(&arc[i++], sizeof(paciente), 1, data);
        }
        fclose(data);
    }
    else
    {
        printf("error");
    }
    printf("Que desea hacer?\n1- Conocer el porcentaje de hombres y mujeres en el hospital\n2- Conocer la cantidad de pasientes segun su gravedad\n3- Conocer la cantidad de pasientes segun su edad\nRespuesta: ");
    scanf("%i", &cont);
    switch (cont)
    {
    case 1:
        man_woman(arc, i - 1);
        break;

    case 2:
        cat(arc, i - 1);
        break;
    case 3:
        edad(arc, i - 1);
    }
}

void man_woman(paciente VEC[], int x)
{
    float h = 0, m = 0;
    for (size_t i = 0; i < x; i++)
    {
        if (VEC[i].sexo == 'M')
        {
            h++;
        }
        else
        {
            m++;
        }
    }
    printf("El porcentaje de hombres en el hospital es %.2f%C\nEl porcentaje de mujeres en el hospital es %.2f%C", h / x *100, 37, m / x * 100, 37);
}

void edad(paciente VEC[], int x)
{
    int e[10] = {0}, k = 0;
    for (size_t i = 0; i < x; i++)
    {
        for (size_t j = 0; j < 100; j += 10)
        {
            if (VEC[i].edad >= j && VEC[i].edad < j+10)
            {
                e[k]++;
            }
            k++;
        }
        k = 0;
        
    }
    printf("Clasificacion de pasientes segun su edad:");
    for (size_t i = 0; i < 10; i++)
    {
        printf("\n%d0-%d9: %d", i, i, e[i]);
    }
    
}

void cat(paciente VEC[], int x)
{
    int lev = 0, med = 0, grab = 0;
    for (size_t i = 0; i < x; i++)
    {
        if (VEC[i].condicion == 1)
        {
            lev++;
        }
        else if (VEC[i].condicion == 2)
        {
            med++;
        }
        else
        {
            grab++;
        }
    }
    printf("Cantidad de pasientes segun la gravedad:\nLeve: %d\nMedia: %d\nGrave: %d", lev, med, grab);
}