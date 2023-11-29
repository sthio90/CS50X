#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("End Size: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    // for loop that adds a year and number of llamas
    int years = 0;
    for (int i = 0; start < end; i++)
    {
        start += start / 12;
        years++;
    }
    // TODO: Print number of years
    printf("Years: %i\n", years);
}
