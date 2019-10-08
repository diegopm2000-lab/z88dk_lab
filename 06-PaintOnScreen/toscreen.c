// toscreen.c

#include <stdio.h>
#include <stdlib.h>

int main() {

    int numPixels = 256 * 192; // 256 horizontal x 192 vertical = 49152

    int videoMemPixelInit = 16384;
    int videoMemPixelLastFirstColumn = videoMemPixelInit + (32 * 2) - 1;

    int videoMemPixelEnd = 16384 + (49152 / 8) - 99;

    int pattern = 25; // 25 in binary is 11001 --> ..  . Paints a pattern

    printf("\x0C"); // clear screen (12)

    for (int i = videoMemPixelInit; i <= videoMemPixelLastFirstColumn; i++) {
        /* printf("%d\n", i); */
        bpoke(i, 25);
    }
}
