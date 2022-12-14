#include <stdio.h>
#include <math.h>

int T, P, R;
int count = 100;
void main()
{
    int ope;
    printf("T\t\tP\t\tR\n");
    for (size_t i = 1; i < count; i++)
    {
        for (size_t j = 1; j < count; j++)
        {
            for (size_t k = 1; k < count; k++)
            {
                ope = 7 * pow(i, 4) - 6 * pow(j, 3) + 12 * pow(k, 5);
                if (ope < 100 && ope > 0)
                {
                    printf("%d\t\t%d\t\t%d\n", i, j, k);
                }
            }
        }
    }
}