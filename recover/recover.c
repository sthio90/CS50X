#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Define bytes and types
typedef uint8_t BYTE;
const int BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Improper usage.\n");
        return 1;
    }

    // open files
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Unable to open file.\n");
        return 2;
    }

    BYTE buffer[BLOCK_SIZE]; // buffer file with 512 bytes of memory
    char filename[8];
    FILE *img = NULL;
    int fileCount = 0;

    while (fread(buffer, 1, BLOCK_SIZE, file) == BLOCK_SIZE) // repeat until end of card:
    {
        // if header of new jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (img != NULL)
            {
                // close the current file
                fclose(img);
            }

            // write new jpeg file
            sprintf(filename, "%03i.jpg", fileCount++);
            img = fopen(filename, "w");
            if (img == NULL)
            {
                printf("Could not create file.\n");
                return 3;
            }
        }
        // else (already in jpeg)
        if (img != NULL)
        {
            // keep writing
            fwrite(buffer, 1, BLOCK_SIZE, img);
        }
    }
    // close any remaining files
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(file);
    return 0;
}
