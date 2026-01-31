#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_LEN = 1000;
char *cat_foo(const char **strings, int n);

/*------------------------------------------------------------------*/

int main(void)
{
    /*
    const char *strings[5] = { "a", "ab", "qwertyA", "ABCa", "abcd" };
    printf("%s\n", cat_foo(strings, 5));
    */
    return 0;
}

/*------------------------------------------------------------------*/

char *cat_foo(const char **strings, int n)
{
    int max_even_len, max_odd_len; max_even_len = max_odd_len = 0;
    int even_index, odd_index; odd_index = even_index = -1;
    for (int j = 0; j < n; ++j)
    {
        int len = strlen(strings[j]);
        if (len > max_even_len && len % 2 == 0)
        {
            max_even_len = len; even_index = j;
        }
    }
    char *result = (char *)malloc(sizeof(char) * (max_even_len + 1));
    result[0] = '\0';
    strcat(result, strings[even_index]);
    for (int i = 0; i < n; ++i)
    {
        int len = strlen(strings[i]);
        if ((len < max_even_len) && (len % 2) && (len > max_odd_len)) {max_odd_len = len; odd_index = i;}
    }
    char *new_result = realloc(result, sizeof(char) * (max_even_len + max_odd_len + 1));
    strcat(new_result, strings[odd_index]);
    return new_result;
}
