#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void)

{
   int i, j, k, l, total;
   
   float change;
  
  do            // prompt user until valid input is entered
  {
      
   printf("O hai! How much change is owed?\n");
   
   change = GetFloat();                           

  }
  while(change < 0);   
     
   float cents = change * 100.0;
    cents = round(cents); // round of input and typecast into integer
    cents = (int) cents;
   
   
 for(i = 0 ; cents >= 25; i++) // determine # of quarters
   
    { 
     cents = cents - 25;
    }    

 for(j = 0; cents >= 10; j++) // determine # of dimes
    
    {
      cents = cents- 10;
    }
   
 for(k = 0; cents >= 5; k++) // determine # of nickels
     
    {
       cents = cents - 5;
    }
  
 for(l = 0; cents>= 1; l++) //determine # of pennies
     
    {
       cents = cents - 1;
    }

  total = i + j + k + l;  // compute total # of coins
    
  printf("%i\n", total );
    
}    
