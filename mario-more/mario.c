#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //TODO prompt user for for height between 1 to 8
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height <1 || height >8);
    //TODO for loop
    for (int k = 0; k < height; k++)
    {
        //TODO printf spaces (height - row - 1)
        for (int i = 0; i < height - k - 1; i++)
        {
            printf(" ");
        }
        //TODO printf left hashes
        for (int i = 0; i < k + 1; i++)
        {
            printf("#");
        }
        //TODO printf gap

            printf("  ");

        //TODO printf right hashes
        for (int i = 0; i < k + 1; i++)
        {
            printf("#");
        }
        printf("\n");
    }

}

