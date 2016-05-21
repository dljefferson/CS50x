#include<stdio.h>
#include<cs50.h>

int main(void)

{   
    printf("minutes: ");    // prompts user for input   
    int time  = GetInt();  //  gets input from user and puts in a variable called "time"
    
    int bottles = (192 * time) / 16;  //calculates number of bottles of water in ounces 
    printf("bottles:%i\n ", bottles); // outputs # of bottles to screen
    
}