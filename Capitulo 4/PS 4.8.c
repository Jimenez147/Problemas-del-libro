#include <stdio.h>

int perfecto(int);

void main()
{
    int N;
    printf("Cuantos numeros desea analizar? ");
    scanf("%i", &N);
    printf("\nLos numeros perfectos son: ");
    for (size_t i = 1; i <= N; i++)
    {
        if (perfecto(i))
        {
            printf("%d\t", i);
        }
    }
}

int perfecto(int x)
{
    int count = 0;
    for (size_t i = 1; i < x; i++)
    {
        if (x % i == 0)
        {
            count += i;
        }
    }
    if (count == x)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}