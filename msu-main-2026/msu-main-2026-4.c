#include <stdio.h>
#include <stdlib.h>

const size_t W = 400;
const size_t H = 300;

void rotate_picture(const unsigned char buffer_1[W][H],
                    const unsigned char buffer_2[H][W);

/*---------------------------------------------------------------------------*/

int main(void)
{
    unsigned char *buffer_1 = (unsigned char*)calloc(W*H, sizeof(unsigned char));
    unsigned char *buffer_2 = (unsigned char*)calloc(H*W, sizeof(unsigned char));

    FILE         *picture = fopen("input.raw", "rb");
    FILE *rotated_picture = fopen("output.raw", "wb");

    fread(buffer_1, sizeof(unsigned char), W * H, picture);
    rotate_picture(buffer_1, buffer_2);
    fwrite(buffer_2, sizeof(unsigned char), W * H, rotated_picture);
    free(buffer_1); free(buffer_2); fclose(picture); fclose(rotated_picture);
    return 0;
}

/*---------------------------------------------------------------------------*/

void rotate_picture(const unsigned char buffer_1[W][H],
                    const unsigned char buffer_2[H][W)
{
    for (size_t i = 0; i < W; ++i)
    {
        for (size_t j = 0; j < H; ++j)
        {
            buffer_2[j][H - i - 1] = buffer_1[j][i];
        }
    }
}
