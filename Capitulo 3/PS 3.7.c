#include <stdio.h>
#include <math.h>

int n;

void main()
{
    int x = 0;
    long sum = 0;
    printf("Ingrese el numero mayor: ");
    scanf("%d", &n);
    for (size_t i = 1; i <= n; i++)
    {
        if (x == 0)
        {
            sum += pow (i,i);
            x = 1;
        }
        else
        {
            sum -= pow (i,i);
            x = 0;
        }        
    }
    printf("El total de la operacion es: %ld", sum);
}