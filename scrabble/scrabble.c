#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int sum = 0;
    int wordLength = strlen(word);
    // check if letter in string is lower case if so change it to upper case
    for (int i = 0; i < wordLength; i++)
    {
        if (islower(word[i]))
        {
            word[i] = toupper(word[i]);
            printf("%c\n", word[i]);
        }

    // assign points to chars in string and 0 to non-letters and sum
        //if (char is uppercase)
        if (isupper(word[i]))
        {
            sum += 1;
        }
       // {
           // sum += assigned points in array;
       // }

    }
    printf("%i\n", sum);
    return sum;

}