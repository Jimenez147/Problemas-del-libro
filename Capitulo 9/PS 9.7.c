/*Escribe un programa en C que, al recibir como dato el archivo de acceso directo est.dat que
contiene los registros de los alumnos de una escuela —algunos están repetidos— ordenados de mayor
a menor en función de su matrícula, genere uno nuevo archivo pero sin registros repetidos.*/
#include <stdio.h>

typedef struct
{
    int mat;
    char nom[100];
    int carr;
    float prom;
} alumno;

void main()
{
    int i = 1, j = 0;
    alumno listado[500] = {0};
    FILE *base;
    if ((base = fopen("est.dat", "r")) != NULL)
    {
        fread(&listado[0], sizeof(alumno), 1, base);
        while (!feof(base))
        {
            fread(&listado[i++], sizeof(alumno), 1, base);
        }
        fclose(base);
        i = 0;
        j = 0;
        while (listado[i].mat != 0)
        {
            while (listado[j].mat != 0)
            {
                if (listado[i].mat == listado[j].mat)
                {
                    while (listado[i].mat != 0)
                    {
                        listado[i] = listado[i + 1];
                    }
                }
                j++;
            }
            i++;
        }
        base = fopen("est.dat", "w");
        i = 0;
        while (listado[i].mat != 0)
        {
            fwrite(&listado[i], sizeof(alumno), 1, base);
            i++;
        }
        fclose(base);
        printf("Finalizado");
    }
    else
    {
        printf("error");
    }
}

