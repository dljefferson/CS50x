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


//define node data type
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
    
} node;

//define hastable size
#define tableSize 65536

//define hashtable array
node* hashtable[tableSize];

//hash function (from http://www.cse.yorku.ca/~oz/hash.html)
int hash(const char* str)
{
	int h=5381;
	unsigned int c;
	while (((c = *str++)))
	    h = ((h << 5) + h) + c;  // hash * 33 + c 
	
	return (unsigned int) h % tableSize;
}



// word counter for size implementation
int wordCount = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    int wordLength = strlen(word);
    
    //temp array of lowercase word
    char checkWord[wordLength + 1];
    
    //convert each letter to lowercase
    //and place into checkWord array
    for(int i = 0; i < wordLength; i++)
    {
        checkWord[i] = tolower(word[i]);
    }   
        
    //terminate word with null charactor
    checkWord[wordLength] = '\0';
    
    int hashNum = hash(checkWord);
    
    //check hashtable for word at index hashNum
    node* cursor = hashtable[hashNum];
    
    //checks if there is a linked list at hashtable index
    if(cursor == NULL)
    {
       return false;
    }
    else 
    {  
        //loop through linked list to find word
        while(cursor != NULL)
        {
            if(strcmp(checkWord, cursor->word) == 0)
            {
                return true;
            }
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
    
    //check to see if file cannot be opened
    if(fp == NULL) 
    {
        printf("Unable to open file.");
        return false;
    }
    
    //load dictionary into memory as a hashtable
    while(feof(fp) == false)
    {
        //create new node for dictionary word
        node *newNode = malloc(sizeof(node));
        
        //read word from dictionary file
        fscanf(fp, "%s\n", newNode->word);
        
        //hash value for dictionary word
        int wordHash = hash(newNode->word);
        
        //place word at index of hashtable
        if(hashtable[wordHash] == NULL)
	   	{
	   		hashtable[wordHash] = newNode;
	   		newNode->next = NULL;
	   	}
	   	else if(hashtable[wordHash] != NULL)
	   	{
	   	   newNode->next = hashtable[wordHash];
	   	   hashtable[wordHash] = newNode;
	   	   
	   	}   
        
        //keeps track of number of words loaded into memory 
        wordCount++;
       
     }
      
    //close file
    fclose(fp);
    
     return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    //return number of words in dictionary
    return wordCount;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
     //loop through each element in hastable array
     for(int i = 0; i < tableSize; i++)
     {
         node* cursor = hashtable[i];
         //free each item in linked list
         while (cursor != NULL)
         {
             node* temp = cursor;
             cursor = cursor->next;
             free(temp);
         }
    
      }

    return true;
}

