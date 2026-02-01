#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *collapse(char *s);

int main(void)
{
    char *string = (char *)malloc(sizeof(char) * 100);
    scanf("%s", string);
    printf("%s\n", collapse(string));
    return 0;
}

char *collapse(char *s)
{
    int len = strlen(s);
    char *result = (char *)malloc(sizeof(char) * (len + 1));
    int i, pos; i = 0; pos = 1;
    result[0] = s[0];

    while (s[i + 1] != '\0')
    {
        if (s[i] != s[i + 1])
        {
            result[pos++] = s[i + 1];
        }
        i++;
    }
    result[pos] = '\0';
    return result;
}
