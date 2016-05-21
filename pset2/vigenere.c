#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define UPPERCASE 65 // ASCII value for letter 'A'
#define LOWERCASE 97 // ASCII value for letter 'a'

void vigenere(int key, char letter, int caseType); //function prototype for vigenere..takes key number, letter, and 
                                                //case type of letter(UPPERCASE or LOWERCASE) as arguments
int validInput(string keyCipher);

int main(int argc, string argv[])

{
    if(argc != 2)             // Validate command line argument
    {
    printf("Error: Program requires one argument.\n");
    
    return 1;    
    }

    if(validInput(argv[1]) == true)
    {
        printf("Keyword must only contain letters A-Z and a-z\n");
    
        return 1;      
    } 
  
  string keyStr = argv[1];
  string inText = GetString();    // Gets input text from user
  int j = 0;   
  int keyLength = strlen(keyStr);

  
  for(int i = 0, n = strlen(inText); i < n; i++) 
     { 
         if(isupper(inText[i]))       // if letter is uppercase print rotated uppercase letter
         {
            
            char letter = inText[i];
            char keyLetter = toupper(keyStr[j]);
            int vKey = ((int) keyLetter - UPPERCASE) % 26;
            vigenere(vKey, letter, UPPERCASE);  
            j = (j + 1) % keyLength;
         }
       
         else if(islower(inText[i])) // if letter is lowercase print rotated lowercase letter
         {
            char letter = inText[i];
            char keyLetter = tolower(keyStr[j]);
            int vKey = ((int) keyLetter - LOWERCASE) % 26;
            vigenere(vKey, letter, LOWERCASE);
            j = (j + 1) % keyLength;
             
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

//***************************************************vigenere() implementation***********************************************************

void vigenere(int key, char letter, int caseType)  // vigenere function

{
    int outText, frstAscii;  
    
    frstAscii = ((int)letter - caseType + key) % 26; //converts input letter into ASCII value and determines ciphertext
    outText = frstAscii + caseType;
    printf("%c", (char)outText);
       
}    

//*****************************************************validInput() Implementation***************************************************

int validInput(string keyCipher)  
       
{     
       
    for(int i = 0, n = strlen(keyCipher); i < n; i++)  // iterates through each character in key pharse
    {
        if(isalpha(keyCipher[i]) == false)            // checks to see if character is a letter
            {
                return 1;
            }  
    
    }
       
    return 0; 
}    