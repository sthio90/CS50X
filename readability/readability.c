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
    printf("%i\n", count);
}

int count_letters(string text)
{
    int sum = 0;
    // TODO for loop to count only letters
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            sum++
        }
    }
    return sum
}
