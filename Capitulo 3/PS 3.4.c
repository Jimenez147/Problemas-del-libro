#include <stdio.h>

int pos =0, neg=0, null=0, n, xx;

void main(void)
{
    printf("Numero de datos: ");
    scanf("%d", &n);
    for (size_t i = 0; i < n; i++)
    {
        printf("\nDato numero %d:", i+1);
        scanf("%d", &xx);
        if (xx > 0)
        {
            pos++;
        }
        else if (xx == 0)
        {
            null++;
        }  
        else
        {
            neg++;
        }
    }
    printf("Los totales son:\nPositivos %d\nNegativos %d\nNulos %d", pos, neg, null);
}