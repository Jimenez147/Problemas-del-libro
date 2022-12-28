#include <stdio.h>

void digit(int, int VEC[]);

void main()
{
    int a, i = 0, num[10] = {0};
    printf("Que numero desea procesar? ");
    scanf("%d", &a);
    digit(a, num);
    while (num[i] != 0)
    {
        printf("%d", num[i]);
        i++;
    }
}

void digit(int cant, int VEC[])
{
    int i = 0;
    while (cant > 0)
    {
        VEC[i] = cant % 10;
        cant /= 10;
        i++;
    }
}