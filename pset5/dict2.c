/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"



typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
    
} node;

node* hashtable[65536];


int hash(const char* str)
{
	int h=5381;
	unsigned int c;
	while (((c = *str++)))
	    h = ((h << 5) + h) + c;  // hash * 33 + c 
	
	return (unsigned int) h % 65536;
}



// counter for size implementation
int wordCount = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    int wordLength = strlen(word);
    char checkWord[wordLength + 1];
    
    for(int i = 0; i < wordLength; i++)
    {
        checkWord[i] = tolower(word[i]);
    
    }   
        
    checkWord[wordLength] = '\0';
    
    //printf("%s\n", checkWord);
    int hashNum = hash(checkWord);
    printf("%i\n", hashNum);
    
   // node* cursor = hashtable[hashNum];
    //printf("%s\n", cursor->word);
    printf("%s\n", checkWord);
   
    if (hashtable[hashNum] == NULL)
    {
        return false;
    }
    
    else
    {
        node* cursor = hashtable[hashNum];
        while(cursor != NULL);
        {
            if(strcmp(checkWord, cursor->word) == 0)
            {
                return true;
            }
        
            printf("%s\n", checkWord);
            cursor = cursor->next;
        }
    }
    
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    //open dictionary file
    FILE* fp = fopen(dictionary, "r");
    
    if(fp == NULL) 
    {
        printf("The file could not be opened.");
        return false;
    }
    
    while(!feof(fp))
    {
        node *newNode = malloc(sizeof(node));
    
        fscanf(fp, "%s", newNode->word);
    
        int wordHash = hash(newNode->word);
    
        wordCount++;
     
        if(hashtable[wordHash] == NULL)
	   	{
	   		newNode->next = NULL;
	   		hashtable[wordHash] = newNode;
	   		//newNode->next = NULL;
	   	}
	   	else
	   	{
	   		newNode->next = hashtable[wordHash];
	   		hashtable[wordHash] = newNode;
	   	}   
  
        //free(newNode);
     }
    
    
     //printf("%i\n", wordCount);
    
    //free allocated memory
    //free(newNode);
    //free(head);
    //close dictionary file
    fclose(fp);
    
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    
    return false;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO   
   for(int i = 0; i < 65536; i++ )
   {
       node* cursor = hashtable[i];
       while (cursor != NULL)
       {
           node* temp = cursor;
           cursor = cursor->next;
           free(temp);
       }
    
   }
    
    return true;  
}
