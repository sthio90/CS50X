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

    // TODO count words and print
    int words = count_words(text);

    // TODO count sentences and print
    int sent = count_sentences(text);

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
    // TODO for loop to count words
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            sumWords++;
        }
    }
    return sumWords;
}

int count_sentences(string text)
{
    int sumSent = 0;

    // TODO for loop to count sentences separated by . ! ?
    for (int i = 0; i < strlen(text); i++)
    {
        if (ispunct(text[i]))
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
