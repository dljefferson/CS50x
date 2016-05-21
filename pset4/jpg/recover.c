/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

           
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

#define BLOCK_SIZE 512

int main(void)
{
    
    //open raw card file
    FILE* fp = fopen("card.raw", "r");
    //declare image output pointer
    FILE* img;
    
    if(fp == NULL)
    {
        fclose(fp);
        printf("File connot be opened.\n");
        return 1;
    }
    
    //buffer for 512 byte size block
    BYTE buffer[BLOCK_SIZE];
   
    //jpeg signatures
    BYTE sigBytes1[4] = {0xff, 0xd8, 0xff, 0xe0};
    BYTE sigBytes2[4] = {0xff, 0xd8, 0xff, 0xe1};
    
    //keeps track of jpeg count
    int jpgCount = 0;
    
    //keeps track of when new file has been reached
    bool newFile = false;
    
    while(fread(&buffer, BLOCK_SIZE, 1, fp) == 1)
    {
        //keeps track of each signature byte found
        int sigCount = 0;
        
       
        //checks first 4 bytes are signature bytes
        for(int i = 0; i < 4; i++)
        { 
            if((buffer[i] == sigBytes1[i]) || (buffer[i] == sigBytes2[i]))
            {
                sigCount++;
            }
        }
         
         //if first 4 bytes are signature bytes, construct image file  
         if(sigCount == 4)
         {
            //makes new jpg file
            char title[7];
            sprintf(title, "%03d.jpg", jpgCount);
            //if img not able to open, return 1
            if(img == NULL)
            {
                fclose(img);
                printf("File cannot be opened.\n");
                return 1;
            }
            
            if(newFile == false)
			{  
			   img = fopen("title", "w");
			   fwrite(buffer, BLOCK_SIZE, 1, img);
			   newFile = true;
			}
            
            if(newFile == true)
            {
                fclose(img);
                img = fopen(title, "w");
                fwrite(&buffer, BLOCK_SIZE , 1, img);
                jpgCount++;
            }
            
           
         } 
         
         else if(newFile == true)
         {
             fwrite(&buffer, BLOCK_SIZE , 1, img);
             
         }
    
        
    }
    
    //close remaining image
    fclose(img);
    //close card file
    fclose(fp);
    

   
}    