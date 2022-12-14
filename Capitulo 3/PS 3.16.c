#include <stdio.h>

int n;

void main()
{
    int lin, x = 1, y;
    printf("Ingrese su numero n: ");
    scanf("%d", &n);
    lin = n * 2 - 1;
    for (size_t i = 1; i <= lin; i++)
    {
        if (i <= n)
        {
            while (x <= i)
            {
                printf("%d ", x);
                x++;
            }
            x = 1;
        }
        else
        {
            x = 1;
            y = n - (i - n);
            while (x <= y)
            {
                printf("%d ", x);
                x++;
            }            
        }
        printf("\n");
    }
}