#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum {len_input = 100};
char *unroll(char *s);

int main(void)
{
    char *string = (char *)malloc(sizeof(char) * len_input);
    scanf("%s", string);
    printf("%s\n", unroll(string)); free(string);
    return 0;
}

char *unroll(char *s)
{
    int len = strlen(s);
    int n = s[len - 1] - '0';
    char *result = (char *)malloc(sizeof(char) * n + 1);
    result[0] = '\0';
    for (int i = 0; i < n; ++i)
    {
        strncat(result, s, len - 1);
    }
    return result;
}
