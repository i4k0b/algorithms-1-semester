#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

unsigned rright(unsigned x);

int main(void)
{
    return 0;
}

unsigned rright(unsigned x)
{
    unsigned copy_x = x; int k = 0;
    while (copy_x != 0)
    {
        if (copy_x & 1) k++;
        copy_x <<= 1;
    }
    return (x >> k) | (x << (32 - k));
}
