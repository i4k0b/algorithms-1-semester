#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum
{
    ALPHABET_NUM = 26,
    FIXED_LEN = 100
};
#define ALPHABET "abcdefghijklmnopqrstuvwxyz"
char *generative(int seed);

/*---------------------------------------------------------------------------*/

int main(void)
{
    int n; scanf("%d", &n);
    printf("%s\n", generative(n));
    return 0;
}

/*---------------------------------------------------------------------------*/

char *generative(int seed)
{
    char *first_var = malloc(FIXED_LEN),
         *second_var = malloc(FIXED_LEN);
    int index = 15;

    int pos1 = 0, pos2 = 0;

    while (pos1 < FIXED_LEN)
    {
        index = (index + seed) % ALPHABET_NUM;
        first_var[pos1] = ALPHABET[index];
        if (first_var[pos1] == 'i')
        {
            first_var[pos1] = '\0';
            break;
        }
        ++pos1;
    }
    index = 8;
    while (pos2 < FIXED_LEN - 1)
    {
        index = (index + seed) % ALPHABET_NUM;
        second_var[pos2] = ALPHABET[index];
        if (second_var[pos2] == 'b')
        {
            second_var[pos2] = '\0';
            break;
        }
        ++pos2;
    }
    strcat(strcat(first_var, " "), second_var); free(second_var);
    return first_var;
}
