#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

 // Define bytes and types
typedef uint8_t BYTE;
const BYTE BLOCK_SIZE = 512;

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
        fprint("Unable to open file.\n");
        return 2;
    }

    while (fread(buffer, 1, BLOCK_SIZE, argv[1]) == BLOCK_SIZE) //repeat until end of card:
    {
        // if header of new jpeg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // if first jpeg
            if (check its first jpeg)
                // start writing new jpeg
                {

                    sprintf(filename, "%03i.jpg", 0);
                    FILE *img = fopen(filename, "w");
                    if (img == NULL)
                    {
                        printf("No such file.\n");
                        return 3;
                    }
                }
            // else if not first jpeg
                // close file
                // write new jpeg file
        }
        // else (already in jpeg)
            // keep writing
    }
    //close any remaining files
}
