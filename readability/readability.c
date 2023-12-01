#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //TODO take user text input and print
    string text = get_string("Text: ");
    printf("Text: %s\n", text);

    //TODO run count_letters function and print
    int count = count_letters(text);
    printf("%i letters\n", count);

    //TODO count words and print
    int words = count_words(text);
    printf("%i words\n", words);
}

int count_letters(string text)
{
    int sum = 0;
    // TODO for loop to count only letters
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            sum++;
        }
    }
    return sum;
}

int count_words(string text)
{
    // We can assume there will be 1 word, single spaces and the string does not start or end in a space
    int sumWords = 1;
    //TODO for loop to count words
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            sumWords++;
        }
    }
    return sumWords;
}
