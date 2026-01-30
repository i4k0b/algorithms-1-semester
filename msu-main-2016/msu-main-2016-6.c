#include <stdio.h>
#include <stdlib.h>

int is_perfect(unsigned int num);
void zbits(unsigned int *a, int n);

int main(void)
{
    return 0;
}

int is_perfect(unsigned int num)
{
    unsigned int sum = 1;
    if (num <= 1) return 0;
    for (int d = 2, d * d <= num; ++d)
    {
        if (num % d == 0) sum++;
        if (d != num / d) sum += num / d;
    }
    return (sum == num) ? 1 : 0;
}

void zbits(unsigned int *a, int n)
{
    const unsigned int MASK = ~2016;
    for (unsigned int i = 0; i < (unsigned int)n; ++i)
    {
        if (is_perfect(i)) a[i] &= MASK;
    }
}
