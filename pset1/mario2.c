#include<stdio.h>
#include<cs50.h>

int main(void)

{
    int height, hash;
    
    do
    
    {
     
     printf("Height: ");     //get valid input from user
     height = GetInt();
     hash = height + 2;     // initialize "hash" 
    
    } 
    
    while(height < 0 || height > 23);
    
    do                                  //perform staircase loop 
    
    {
    
     for(int i = height; i > 1; i--)    //print spaces
        
        {
         
         printf(" ");
        
        }
     
      if(height != 0)                    //only runs if staircase height is not equal to zero
        
        {
          for(int i = hash - height ; i > 0; i--)  //print hashes
          
          {
          
             printf("#");
          
          }  
        
          printf("\n");                       //create new line
        
        }
      
      height = height - 1;       //decrement "height by 1"
    
    }
      while(height > 0); 
  
}
