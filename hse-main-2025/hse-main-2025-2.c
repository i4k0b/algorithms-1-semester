#include <stdio.h>

/*
1. 1 0
2. 0 2
3. 0 4
*/

int main(void)
{
    int pref[] = {0, 0, 1, 0, 1, 2, 1, 2, 3, 4};
    int n = sizeof(pref) / sizeof(int);
    int k = n;
    while (k > 0)
    {
        if (n - pref[k - 1] < n) printf("%d\n", n - pref[k - 1]);
        k = pref[k - 1];
    }
    return 0;
}
