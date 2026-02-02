#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void prefix_func (char *pat,
                  int *pi, int m);

int kmp(char *text, char *pat);

int main(void)
{
    char *s = (char *)malloc(sizeof(char) * 100);
    scanf("%s", s); int len = strlen(s);

    printf("%d\n", kmp(s, "2012"));
    free(s);
    return 0;
}

void prefix_func (char *pat,
                  int *pi, int m)
{
    int k, q;
    pi[0] = 0; k = 0;
    for (q = 1; q < m; q++)
    {
        while (k > 0 && pat[k] != pat[q])
            k = pi[k - 1];
        if (pat[k] == pat[q])
            k++;
        pi[q] = k;
    }
}

int kmp (char *text, char *pat)
{
    int m, n; m = strlen(text); n = strlen(pat);
    int q;
    int cnt = 0;
    int pi[n];
    prefix_func (pat, pi, n);
    q = 0;
    for (int i = 0; i < m; i++)
    {
        while (q > 0 && pat[q] != text[i])
        {
            q = pi[q - 1];
        }
        if (pat[q] == text[i])
        {
            q++;
        }
        if (q == n)
        {
            cnt++;
            q = pi[q - 1];
        }
    }
    return cnt;
}
