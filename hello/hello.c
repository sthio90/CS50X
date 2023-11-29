#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //TODO ask user for name
    string name = get_string("What is your name? ");
    printf("hello, %s\n", name);
}
