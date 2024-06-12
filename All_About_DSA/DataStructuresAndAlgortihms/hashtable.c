#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_TABLE_SIZE 100

// Define a structure for a dictionary word node
struct WordNode {
    char word[50];
    struct WordNode* next;
};

// Define a hash table as an array of linked lists
struct WordNode* hashTable[HASH_TABLE_SIZE];

// Function to calculate the hash value for a given word
unsigned int hash(char* word) {
    unsigned int hashValue = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        hashValue = (hashValue * 31 + word[i]) % HASH_TABLE_SIZE;
    }
    return hashValue;
}

// Function to insert a word into the hash table
void insertWord(char* word) {
    unsigned int index = hash(word);
    struct WordNode* newNode = (struct WordNode*)malloc(sizeof(struct WordNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    strncpy(newNode->word, word, sizeof(newNode->word));
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Function to check if a word is in the dictionary
int isWordInDictionary(char* word) {
    unsigned int index = hash(word);
    struct WordNode* currentNode = hashTable[index];
    while (currentNode != NULL) {
        if (strcmp(currentNode->word, word) == 0) {
            return 1; // Word found in the dictionary
        }
        currentNode = currentNode->next;
    }
    return 0; // Word not found in the dictionary
}

int main() {
    // Populate the dictionary with some sample words
    char* dictionary[] = {"apple", "banana", "cherry", "date", "grape", "kiwi", "lemon", "orange", "pear", "pineapple"};
    int numWords = sizeof(dictionary) / sizeof(dictionary[0]);
    
    // Initialize the hash table
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
    
    // Insert words from the dictionary into the hash table
    for (int i = 0; i < numWords; i++) {
        insertWord(dictionary[i]);
    }
    
    // Check if a word is in the dictionary
    char inputWord[50];
    printf("Enter a word: ");
    scanf("%s", inputWord);
    
    if (isWordInDictionary(inputWord)) {
        printf("%s is in the dictionary.\n", inputWord);
    } else {
        printf("%s is not in the dictionary.\n", inputWord);
    }
    
    return 0;
}
