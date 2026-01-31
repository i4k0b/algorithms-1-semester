#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *collapse(char *s);
const int LEN = 100;

/*-----------------------------------------------------------------*/

/*
"0123123 hello 23424" strtok(*str, char *delim) -> "%d %s %d"
*/

int main(void)
{
    char *str = (char *)malloc(sizeof(char) * LEN);
    fgets(str, LEN, stdin);
    str[99] = '\0';
    printf("%s\n", collapse(str));
    return 0;
}

/*-----------------------------------------------------------------*/

char *collapse(char *s)
{
    int len = strlen(s), i = 0, cnt = 0, flag = -1;
    char *token = strtok(s, " "),
         **strings = (char **)malloc(sizeof(char *) * len * 2),
         *result = (char *)malloc(sizeof(char) * len * 3);
    while (token != NULL) {
        strings[i++] = token;
        token = strtok(NULL, " ");
    }
    cnt = i; i = 0; result[0] = '\0';
    for (i = 0; i < cnt; ++i)
    {
        for (int j = 0; strings[i][j] != '\0'; ++j)
        {
            flag = (isalpha(strings[i][j])) ? 1 : 0; break;
        }
        strcat(strcat(result, (flag) ? "%s" : "%d"), " ");
    }
    free(strings);
    return result;
}
