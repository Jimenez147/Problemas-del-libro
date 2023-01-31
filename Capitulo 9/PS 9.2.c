/*Escribe un programa en C que, al recibir como dato el archivo arc.txt compuesto or cadenas
de caracteres, calcule el número de cada una de las vocales que se encuentra en el archivo.*/
#include <stdio.h>
#include <string.h>

int a = 0, e = 0, I = 0, o = 0, u = 0;

void vocales(char VEC[]);

void main()
{
    char cadena[100];
    FILE *arc;
    if ((arc = fopen("cadenas.txt", "r")) != NULL)
    {
        fgets(cadena, 100, arc);
        vocales(cadena);
        while (!feof(arc))
        {
            fgets(cadena, 100, arc);
            vocales(cadena);
        }
        fclose(arc);
    }
    printf("La cantidad de vocales son:\na: %d\ne: %d\ni: %d\no: %d\nu: %d", a, e, I, o, u);
}

void vocales(char VEC[])
{
    int cant;
    cant = strlen(VEC);
    for (size_t i = 0; i < cant; i++)
    {
        switch (VEC[i])
        {
        case 65:
        case 97:
            a++;
            break;

        case 69:
        case 101:
            e++;
            break;

        case 73:
        case 105:
            I++;
            break;

        case 79:
        case 111:
            o++;
            break;

        case 85:
        case 117:
            u++;
            break;
        }
    }
}