// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dictionary.h"

// Declare global word count
unsigned int word_count = 0;
// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 150001;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // create temp word in lower case
    char temp_word[LENGTH + 1];
    int len = strlen(word);
    for (int i = 0; i < len; i++)
    {
        temp_word[i] = tolower(word[i]);
    }
    temp_word[len] = '\0';

    // get hash index
    unsigned int index = hash(temp_word);
    // strcomp temp word and dict word
    node *cursor = table[index];
    while (cursor != NULL)
    {
        if (strcmp(temp_word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next; // Advance cursor to the next node
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long hash = 4201;
    int c;

    while ((c = *word++))
    {
        hash = ((hash << 3) + hash) + tolower(c);
    }

    return hash % N;

}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // fopen file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    char word[LENGTH +1];
    while (fscanf(file, "%s", word) !=EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, word);
        unsigned int index = hash(word);

        // Insert node into the hash table at the calculated index
        n->next = table[index];
        table[index] = n;
        word_count++; // Increment word count
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate over each bucket in the hash table
    for (int i = 0; i < N; i++)
    {
        // Set cursor to point to the head of the linked list at the current bucket
        node *cursor = table[i];

        // Traverse the linked list and free nodes
        while (cursor != NULL)
        {
            // Create temp variable pointing to cursor
            node *temp = cursor;

            // Move cursor to the next node
            cursor = cursor->next;

            // Free the node pointed to by temp
            free(temp);
        }
    }
    return true;
}
