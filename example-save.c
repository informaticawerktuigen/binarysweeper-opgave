#include <stdio.h>
#include <stdint.h>

int main(void)
{

    uint64_t example_game[] = {0x1ull, 0x0ull, 0x0ull, 0x1ull, 0x0ull, 0x1ull};

    FILE *file = fopen("example_game", "wb");
    if (file == NULL)
    {
        return -1;
    }

    if (fwrite(example_game, sizeof(example_game), 1, file) != 1)
    {
        return -1;
    }
    fclose(file);
    return 0;
}