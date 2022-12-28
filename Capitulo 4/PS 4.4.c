#include <stdio.h>
#include <math.h>

float interes_simple(int, float, float);

void main()
{
    int mes;
    float cap, tasa, ress;
    printf("Ingrese su capital inicial: ");
    scanf("%f", &cap);
    printf("Cuantos meses de interes desea? ");
    scanf("%i", &mes);
    printf("A que tasa porcentual desea calcular el interes? ");
    scanf("%f", &tasa);
    ress = interes_simple(mes, cap, tasa);
    printf("\nSu cantidad final es: %.2f", ress);
}

float interes_simple(int m, float c, float t)
{
    return c * m * (t/100);
}