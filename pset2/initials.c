#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)

{
    string name = GetString();  //gets a string from user
    
    int nameLength = strlen(name); //determine string length of string obtained from user
    
    
    for(int i = 0; i < nameLength; i++) 
    {
        if(i == 0)                  //Prints first character of string and capitalize it if needed
        {
            printf("%c", toupper(name[0]));
        }
        
        if(name[i] == ' ')            //captializes and prints first character after any null character        
        {
            printf("%c", toupper(name[i + 1]));
        }
    }

    printf("\n");

    
}    
