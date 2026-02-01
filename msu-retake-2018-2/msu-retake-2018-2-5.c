#include <stdio.h>
#include <stdlib.h>

int f(int a, int b);

static int m[] = {2, 0, 1, 8};
static int *p = &m[3], *q = &m[1];

/*
Returned is 8.
*/

int main(void)
{
    printf("%d\n", f(1, f(f(0, 1), 2)));
    return 0;
}

int f(int a, int b)
{
    static int x = 1; int y = x;
    x = p[0]; q[0] += b;
    if (a) { p--; q++; }
    return y;
}
