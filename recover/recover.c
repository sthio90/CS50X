#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

 // Define bytes and types
typedef uint8_t BYTE;
const BYTE BLOCK_SIZE = 512;

int main(int argc, char *argv[])
{

 // open files
 FILE *file = fopen(argv[1], "r");
 if (file == NULL)
 {
    fprint("Unable to open file.");
    return 1;
 }
    while (fread(buffer, 1, BLOCK_SIZE, argv[1]) == BLOCK_SIZE) //repeat until end of card:
    {
        // if header of new jpeg
            // if new jpeg
            // else if fread returns < 512 then end of file and return
        // else (already in jpeg)
            // keep writing

    //close any remaining files
    }
}
