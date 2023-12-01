#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int clInd(int count, int words, int sent);

int main(void)
{
    // TODO take user text input and print
    string text = get_string("Text: ");

    // TODO run count_letters function and print
    int count = count_letters(text);
    printf("%i\n", count);
    // TODO count words and print
    int words = count_words(text);
    printf("%i\n", words);
    // TODO count sentences and print
    int sent = count_sentences(text);
    printf("%i\n", sent);
    // TODO use clInd to get grading and print
    int grade = clInd(count, words, sent);
    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    int sum = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
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
    int sumWords = 0;
    int length = strlen(text);
    bool inWord = false; // Flag to indicate if we are inside a word

    for (int i = 0; i < length; i++)
    {
        if (isspace(text[i]))
        {
            if (inWord)
            {
                sumWords++;
                inWord = false; // Reset the flag as we're now outside a word
            }
        }
        else
        {
            inWord = true; // We are inside a word
        }
    }

    // If the last character is not a space, then we need to count the final word
    if (inWord)
    {
        sumWords++;
    }

    return sumWords;
}

int count_sentences(string text)
{
    int sumSent = 0;
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sumSent++;
        }
    }
    return sumSent;
}

int clInd(int count, int words, int sent)
{
    // Coleman-Liau index = 0.0588 * L - 0.296 * S - 15.8; L is ave letters/100 words and S is ave sentences /100 words
    float clGrade = 0.0588 * (count * 100.0 / words) - 0.296 * (sent * 100.0 / words) - 15.8;
    return round(clGrade);
}
