/*Escribe un programa en C que, al recibir como dato un archivo de texto compuesto por cadenas de
caracteres, forme un nuevo archivo en el cual las cadenas aparezcan intercambiadas: la última con
la primera, la penúltima con la segunda, y así sucesivamente. */
#include <stdio.h>
#include <string.h>

void invierte(char VEC[][100], int);

void main()
{
    char cad[10][100];
    int i = 1;
    FILE *arc;
    if ((arc = fopen("cadenas.txt", "r")) != NULL)
    {
        fgets(cad[0], 100, arc);
        while (!feof(arc))
        {
            fgets(cad[i++], 100, arc);
        }
        invierte(cad, i);
        fclose(arc);
        arc = fopen("cadenas.txt", "w");
        for (size_t j = 0; j < i; j++)
        {
            fputs(cad[j], arc);
            if (j == 0)
            {
                fputs("\n", arc);
            }
        }
        fclose(arc);
        printf("Trabajo realizado");
    }
    else
    {
        printf("Error");
    }
}

void invierte(char VEC[][100], int n)
{
    char trans[n][100];
    for (size_t i = 0; i < n; i++)
    {
        strcpy(trans[i], VEC[n - i - 1]);
    }
    for (size_t i = 0; i < n; i++)
    {
        strcpy(VEC[i], trans[i]);
    }
}