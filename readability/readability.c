#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);

int main(void)
{
    //TODO take user text input and print
    string text = get_string("Text: ");
    printf("Text: %s\n", text);

    //TODO run count_letters function and print
    int count = count_letters(text);
}

int count_letters(string text)
{
    strlen(text);
}
