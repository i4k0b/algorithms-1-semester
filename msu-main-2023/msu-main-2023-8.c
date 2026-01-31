#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

const int FIXED_SIZE = 10000;

/*---------------------------------------------------------------------------*/

int main(void)
{
    FILE *input = fopen("input.bin", "rb");
    unsigned int *message = malloc(sizeof(unsigned int) * FIXED_SIZE);

    while (fread(message, 4, 1, input) != 0)
    {
        printf("%u", (unsigned int)message[0] << 24 | 0 << 16 |
                     (unsigned int)message[2] << 8 | (unsigned int)message[3]);
    }
    free(message); fclose(input);
    return 0;
}
