/*Escribe un programa en C que, al recibir como dato un archivo de texto compuesto por cadenas 
de caracteres, determine cuántas palabras hay en el archivo. Cadapalabra se separa por medio de 
un espacio en blanco.*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int pal = 0;

void palabras(char VEC[]);

void main()
{
    char cad[100];
    FILE *arc;
    if ((arc = fopen("cadenas.txt", "r")) != NULL)
    {
        fgets(cad, 100, arc);
        palabras(cad);
        while (!feof(arc))
        {
            fgets(cad, 100, arc);
            palabras(cad);
        }
        fclose(arc);
    }
    else
    {
        printf("Error");
    }
    printf("En el texto hay %d palabras", pal);
}

void palabras(char VEC[])
{
    int count = strlen(VEC);
    pal++;
    for (size_t i = 0; i < count; i++)
    {
        if (isblank(VEC[i]))
        {
            pal++;
        }
        
    }
    
}