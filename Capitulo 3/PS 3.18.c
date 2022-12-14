#include <stdio.h>

int n;

void main()
{
    int x, y;
    printf("Ingrese su numero n: ");
    scanf("%d", &n);
    x = n;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 1; j <= x; j++)
        {
            printf("%d ", j);
        }
        for (size_t j = 0; j < n - x; j++)
        {
            printf("    ");
        }
        if (x > 9 && x < n)
        {
            for (size_t j = 0; j < n - x; j++)
            {
                printf("  ");
            }
        }
        else if (n > 9  && x < n)
        {
            y = n - 9;
            for (size_t j = 0; j < y; j++)
            {
                printf("  ");
            }
        }
        printf("   ");
        for (size_t j = x; j > 0; j--)
        {
            printf("%d ", j);
        }
        x--;
        printf("\n");
    }
}