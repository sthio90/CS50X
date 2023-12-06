#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
 // Define bytes and types
 typedef uint8_t BYTE;
 // open files
 FILE *file = fopen(argv[1], "r");

 // fread file
    // if header of jpeg
        // fwrite into new output in 512 byte chunks
    // else (already in jpeg)
        // keep writing

}
