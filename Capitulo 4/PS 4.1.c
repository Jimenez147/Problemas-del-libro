#include <stdio.h>

int N, num[500];

void par_impar(int VEC[]);

void main()
{
    printf("Cuantos digiros desea ingresar? ");
    scanf("%i", &N);
    for (size_t i = 0; i < N; i++)
    {
        printf("Ingrese el digito %d: ", i + 1);
        scanf("%d", &num[i]);
        fflush(stdin);
    }
    par_impar(num);
}

void par_impar(int VEC[])
{
    int pcant = 0, icant = 0;
    float par = 0, impar = 0;
    for (size_t i = 0; i < N; i++)
    {
        if (VEC[i] % 2 == 0)
        {
            par += VEC[i];
            pcant++;
        }
        else
        {
            impar += VEC[i];
            icant++;
        }
    }
    par /= pcant;
    impar /= icant;
    printf("\nEl promedio de numeros pares es: %.2f\nEl promedio de numeros impares es: %.2f", par, impar);
}