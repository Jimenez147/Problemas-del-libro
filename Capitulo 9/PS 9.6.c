/*Escribe un programa en C que, al recibir como dato el archivo doc.dat compuesto
por cadenas de caracteres, revise la ortografía del mismo y verifique si se cumplen
las siguientes reglas ortográficas: antes de b va m, no n; antes de p va m, no n, y
finalmente, antes de v va n, no m.*/
#include <stdio.h>
#include <string.h>

void ortografia(char VEC[], int);

void main()
{
    char cad[100];
    int n;
    FILE *arc;
    if ((arc = fopen("cadenas.txt", "r")) != NULL)
    {
        fgets(cad, 100, arc);
        n = strlen(cad);
        ortografia(cad, n);
        while (!feof(arc))
        {
            fgets(cad, 100, arc);
            n = strlen(cad);
            ortografia(cad, n);
        }
        fclose(arc);
    }
    else
    {
        printf("Error");
    }
}

void ortografia(char VEC[], int x)
{
    int j = 0, control = 0, errores[100] = {0}, pos;
    for (size_t i = 0; i < x; i++)
    {
        if (VEC[i] == 'p' || VEC[i] == 'b' || VEC[i] == 'v')
        {
            if (VEC[i - 1] == 'n')
            {
                control = 1;
                errores[j++] = i;
            }
        }
    }
    if (control)
    {
        int i = 0;
        printf("%s", VEC);
        j = sizeof(errores) / sizeof(errores[0]);
        pos = errores[0] - 1;
        while (errores[i] != 0)
        {
            for (size_t l = 0; l < pos; l++)
            {
                printf(" ");
            }
            printf("~~");
            pos = errores[i + 1] - errores[i] - 2;
            i++;
        }
        printf("\nHay errores ortograficos\n\n");
    }
}