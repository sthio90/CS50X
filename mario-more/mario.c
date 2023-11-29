#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO prompt user for for height between 1 to 8
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    // TODO nested for loop
    for (int i = 0; i < height; i++)
    {
        // TODO printf spaces (height - row - 1)
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }
        // TODO printf left hashes
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        // TODO printf gap

        printf("  ");

        // TODO printf right hashes
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
