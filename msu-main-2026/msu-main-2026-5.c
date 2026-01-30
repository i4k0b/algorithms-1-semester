#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *from_hex_to_bin(char *str);

/*---------------------------------------------------------------------------*/

int main(void)
{
    char *res = (char *)malloc(100);
    scanf("%s", res); printf("%s\n", from_hex_to_bin(res)); free(res);
    return 0;
}

/*---------------------------------------------------------------------------*/

char *from_hex_to_bin(char *str)
{
    int len = strlen(str);
    char *result = (char *)malloc(5 * len);

    int i, j; i = j = 0;

    for (i = 0; i < len; ++i)
    {
        switch(str[i])
        {
            case '0': strcat(&result[j], "0000"); break;
            case '1': strcat(&result[j], "0001"); break;
            case '2': strcat(&result[j], "0010"); break;
            case '3': strcat(&result[j], "0011"); break;
            case '4': strcat(&result[j], "0100"); break;
            case '5': strcat(&result[j], "0101"); break;
            case '6': strcat(&result[j], "0110"); break;
            case '7': strcat(&result[j], "0111"); break;
            case '8': strcat(&result[j], "1000"); break;
            case '9': strcat(&result[j], "1001"); break;
            case 'A': strcat(&result[j], "1010"); break;
            case 'B': strcat(&result[j], "1011"); break;
            case 'C': strcat(&result[j], "1100"); break;
            case 'D': strcat(&result[j], "1101"); break;
            case 'E': strcat(&result[j], "1110"); break;
            case 'F': strcat(&result[j], "1111"); break;
            default: break;
        }
        j += 4;
    }
    result[len * 5 - 1] = '\0';
    return result;
}
