/*Escribe un programa en C que, al recibir como dato un archivo de texto formado por cadenas
de caracteres, determine la longitud de la cadena más grande sin utilizar la función strlen.*/
#include <stdio.h>
#include <string.h>

void main()
{
    char cad[100], max[100];
    FILE *tex;
    if ((tex = fopen("cadenas.txt", "r")) != NULL)
    {
        fgets(cad, 100, tex);
        strcpy(max, cad);
        while (!feof(tex))
        {
            fgets(cad, 100, tex);
            if (sizeof(cad) > sizeof(max))
            {
                strcpy(max, cad);
            }
        }
        fclose(tex);
    }
    else
    {
        printf("No se pudo abrir el archivo");
    }
    printf("La cadena mas larga es:\n");
    puts(max);
}