/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
//implements binary search algorithm
int min = 0;
int max = n - 1;
int mid = (max + min) / 2;

   while(min <= max)
   {

      if(values[mid] < value)
      {
         min = mid + 1;
         mid = (max + min) / 2;
      }
      else if(values[mid] == value)
      {
          return true;
      }
      else if(values[mid] > value)
      {
          max = mid - 1;
          mid = (max + min) / 2; 
      }
   }

if(min > max)  
{
  return false;
    
}
 
 return false;


}  

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // implements selection sort algorithm
   
   
   for( int i = 0; i < n - 1; i++)
   {
       int swap;
       int min = i;
       
       for(int j = i + 1; j < n; j++)
       {       
           if(values[j] < values[min])
           {
              min = j;
           }
       }
       
       if(min != i)
       {  
         swap = values[i];
         values[i] = values[min];
         values[min] = swap;
       }   
           
    }
   
    return;
}