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
    while (height >0 && height <9);

    //TODO printf hashes at prompted height

}
