#include <stdio.h>

double factorial(int);

void main()
{
    int num;
    printf("De que numero quiere conocer el factorial?  ");
    scanf("%d", &num);
    printf("El factorial de tu numero es: %.0lf", factorial(num));
}

double factorial(int X)
{
    double ultra = X;
    for (size_t i = X - 1; i > 0; i--)
    {
        ultra *= i;
    }
    return ultra;
}