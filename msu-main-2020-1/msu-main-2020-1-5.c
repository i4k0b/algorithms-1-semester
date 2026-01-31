#include <stdio.h>
#include <stdlib.h>

int allrem(int *a, int n);

/*-----------------------------------------------------------------*/

int main(void)
{
    /*
    int a[6] = {6, 5, 4, 3, 2, 1}, n = 3;
    printf("%d\n", allrem(a, n));
    */
    return 0;
}

/*-----------------------------------------------------------------*/

int allrem(int *a, int n)
{
    int len = 2 * n; int sum = 0;
    for (int i = 0; i < len - 1; ++i)
    {
        sum += (i % 2 == 0) ? (a[i] % a[i + 1]) : 0;
    }
    return sum;
}
