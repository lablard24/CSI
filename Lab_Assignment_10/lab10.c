#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Trie node structure
struct TrieNode
{
    struct TrieNode* children[26];
    int count;
};

// Trie structure
struct Trie
{
    struct TrieNode* root;
};

// Create a Trie node
struct TrieNode* createTrieNode()
{
    struct TrieNode* newNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    newNode->count = 0;
    for (int i = 0; i < 26; ++i)
    {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Inserts the word to the trie structure
void insert(struct Trie* pTrie, char* word)
{
    struct TrieNode* curr = pTrie->root;
    for (int i = 0; word[i] != '\0'; ++i)
    {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL)
        {
            curr->children[index] = createTrieNode();
        }
        curr = curr->children[index];
    }
    curr->count++;
}

// computes the number of occurrences of the word
int numberOfOccurrences(struct Trie* pTrie, char* word)
{
    struct TrieNode* curr = pTrie->root;
    for (int i = 0; word[i] != '\0'; ++i)
    {
        int index = word[i] - 'a';
        if (curr->children[index] == NULL)
        {
            return 0;
        }
        curr = curr->children[index];
    }
    return curr->count;
}

// Deallocate the trie structure
void deallocateTrie(struct Trie* trie)
{
    if (trie == NULL)
        return;

    deallocateTrie(trie->root);
    free(trie);
}

// Initializes a trie structure
struct Trie* createTrie()
{
    struct Trie* trie = (struct Trie*)malloc(sizeof(struct Trie));
    trie->root = createTrieNode();
    return trie;
}

// This function will return the number of words in the dictionary,
// and read all the words in the dictionary to the structure words
int readDictionary(char* filename, char** pInWords)
{
    int numWords = 0;
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening the file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char buffer[256];
    int a;
    fscanf(file, "%d\n", &a);
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        pInWords[numWords] = strdup(buffer);
        numWords++;
    }

    fclose(file);
    return numWords;
}

int main(void)
{
    char* inWords[256];

    // Read the number of words in the dictionary
    int numWords = readDictionary("dictionary.txt", inWords);
    for (int i = 0; i < numWords; ++i)
    {
        printf("%s\n", inWords[i]);
    }

    struct Trie* pTrie = createTrie();
    for (int i = 0; i < numWords; i++)
    {
        insert(pTrie, inWords[i]);
    }

    // Parse line by line, and insert each word to the trie data structure
    char* pWords[] = {"notaword", "ucf", "no", "note", "corg"};
    for (int i = 0; i < 5; i++)
    {
        printf("\t%s : %d\n", pWords[i], numberOfOccurrences(pTrie, pWords[i]));
    }

    deallocateTrie(pTrie);
    pTrie = NULL; // Set to NULL after deallocation

    return 0;
}
