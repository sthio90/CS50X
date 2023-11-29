#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //TODO prompt for input
    long card;
    do
    {
        card = get_long("Number: ");
    }
    while (card < 0);

    //TODO calculate checksum
    //

    //TODO check for card length and starting digits
}
