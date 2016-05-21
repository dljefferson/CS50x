#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define UPPERCASE 65 // ASCII value for letter 'A'
#define LOWERCASE 97 // ASCII value for letter 'a'

void caesar(int key, char letter, int caseType); //function prototype for caesar..takes key number, letter, and 
                                                //case type of letter(UPPERCASE or LOWERCASE) as arguments


int main(int argc, string argv[])

{
    if(argc != 2)             // Validate command line argument
    {
    printf("Error: Program requires one argument.\n");
    
    return 1;    
    }

int key = atoi(argv[1]);
string inText = GetString();    // Gets input text from user
     
    
  for(int i = 0, n = strlen(inText); i < n; i++) 
     { 
         if(isupper(inText[i]))       // if letter is uppercase print rotated uppercase letter
         {
            char letter = inText[i];
            caesar(key, letter, UPPERCASE);  
         }
       
         else if(islower(inText[i])) // if letter is lowercase print rotated lowercase letter
         {
            char letter = inText[i];
            caesar(key, letter, LOWERCASE);
         }
         
         else if(inText[i] == ' ')
         {
             printf(" ");
         }
         
         else
          
         printf("%c", inText[i]);  
          
     }

    printf("\n");
}    

//***************************************************caesar() implementation***********************************************************

void caesar(int key, char letter, int caseType)  // Caesar function

{
    int outText, frstAscii;  
    
    frstAscii = ((int)letter - caseType + key) % 26; //converts input letter into ASCII value and determines ciphertext
    outText = frstAscii + caseType;
    printf("%c", (char)outText);
       
}    