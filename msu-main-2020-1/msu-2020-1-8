#include <stdio.h>
#include <string.h>
#include <stdlib.h>

enum {FIXED_SIZE = 10000};

char *expand(char *s)
{
    char *result = malloc(sizeof(char) * FIXED_SIZE); int i, j; i = j = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '%' && s[i + 1] == 'c')
        {
            strcat(result, "2"); j++; i += 2;
        }
        else if (s[i] == '%' && s[i + 1] == 'd')
        {
            strcat(result, "117"); j += 3; i += 2;
        }
        else
        {
            result[j] = s[i]; j++; i++;
        }
    }
    result[FIXED_SIZE - 1] = '\0';
    return result;
}

int main(void)
{
    char *res = (char *)malloc(100);
    scanf("%s", res); printf("%s\n", expand(res)); free(res);
    return 0;
}
