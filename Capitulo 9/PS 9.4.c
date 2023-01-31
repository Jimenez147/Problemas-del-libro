/*Escribe un programa en C que, al recibir como datos una cadena de caracteres y el archivo de
texto arc2.txt, compuesto también por cadenas de caracteres, determine cuántas veces se encuentra
la primera cadena de caracteres en el archivo*/
#include <stdio.h>

int ress = 0;

void busca(char VEC1[], int, char VEC2[], int);

void main()
{
    int cant;
    char gold[] = "sa", cad[100];
    int n = sizeof gold / sizeof gold[0];
    FILE *arc;
    if ((arc = fopen("cadenas.txt", "r")) != NULL)
    {
        fgets(cad, 100, arc);
        cant = sizeof cad / sizeof cad[0];
        busca(gold, n, cad, cant);
        while (!feof(arc))
        {
            fgets(cad, 100, arc);
            cant = sizeof cad / sizeof cad[0];
            busca(gold, n, cad, cant);
        }
        fclose(arc);
    }
    else
    {
        printf("Error");
    }
    printf("la cantidad de veces que aparece '%s' en el archivo es %d", gold, ress);
}

void busca(char VEC1[], int x, char VEC2[], int max)
{
    int check = 0;
    for (size_t i = 0; i < max; i++)
    {
        for (size_t j = 0; j < x - 1; j++)
        {
            if (VEC1[j] == VEC2[i+j])
            {
                check++;
            }
            if (VEC1[0] != VEC2[i])
            {
                break;
            }
            
        }
        if (check == x - 1)
        {
            ress++;
        }
        check = 0;
    }
}