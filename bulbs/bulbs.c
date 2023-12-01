#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // TODO ask user for message
    string message = get_string("Message: ");

    // TODO convert message into series of 8bit binary numbers one for each character
    for (int i = 0; i < strlen(message); i++) {
        char c = message[i];
        int mask = 128; // Binary 10000000

        for (int j = 0; j < BITS_IN_BYTE; j++) {
            int bit = (c & mask) ? 1 : 0;
            printf("%d", bit);
            mask >>= 1;
        }
     printf("\n");
    }


    // TODO print series of emojis with print_bulb function
    
}

void print_bulb(int bit)
{
    if (bit == 0) {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1) {
        // Light emoji
        printf("\U0001F7E1");
    }
}
