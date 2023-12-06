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

 // fread file
    // if header of jpeg
        // fwrite into new output in 512 byte chunks
    // else (already in jpeg)
        // keep writing

}
