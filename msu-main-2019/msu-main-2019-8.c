#include <stdio.h>
#include <stdlib.h>

int f(const char *s, int n);

/*
5 7 0
5 5 1
5 3 1
5 1 1
*/

int main(void)
{
    return (f("9376598347983245", 1));
    return 0;
}

int f(const char *s, int n)
{
    int x; register int k = 0;
    static char h = '9';
    if (*s == 0) return 0;
  
    while (*s && *s != h) ++s; k++;
    h--;
    x = f(s, ((n % 2) || (n++ & 4)) ? (n + 1) : (n + 2));
    printf("%c %d %d\n", h, n, x);
    return k;
}
