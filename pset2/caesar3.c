#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

char caesar(int key, char letter); //function prototype for caesar..takes key number and letter as auguments
                                                

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
         if(isalpha(inText[i]))       
         {
            char inLetter = inText[i];
            char outLetter = caesar(key, inLetter);  //use of caesar function
            printf("%c", outLetter);
         }
         
         else if(inText[i] == ' ')  //if character is a space, print space
         {
             printf(" ");
         }
         
         else
         printf("%c", inText[i]);  //if thing other that a letter or a space print character as is
          
     }

    printf("\n");
}    



char caesar(int key, char letter)  // Caesar function

{
    int outAscii, inAscii;  
    int upper = 65;    //ASCII value for letter 'A'
    int lower = 97;    //ASCII value for letter 'a' 
    char cipherLetter;
    
    if(isupper(letter)); 
    {
        inAscii = ((int)letter - upper + key) % 26; //converts input letter into ASCII value and determines ciphertext for
        outAscii = inAscii + upper;                 // upppercase letters
        cipherLetter = (char) outAscii;
    }

     if(islower(letter)) 
    {
        inAscii = ((int)letter - lower + key) % 26; //converts input letter into ASCII value and determines ciphertext
        outAscii = inAscii + lower;                  //lowercase letter
        cipherLetter = (char) outAscii;
    }

    return cipherLetter;
}   