/**
 * 
 
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?

 * 
**/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int IsPrime(long number) 
    {
       int root = sqrt(number) ;
       for(int i=2; i<=root; i++) 
       {
          if(number%i == 0)
              return 0;
       } 
       return 1;
} 

int main()
{
    int stevec = 0;
    long stevilo = 2;
    while (1)
    {
        if (IsPrime(stevilo) == 1)
        {

            stevec++;
            if (stevilo == 104743)
            {
                printf("%d st = %ld\n", stevec, stevilo);
                break;
            }
            
        }
        stevilo++;
           
    }
    
    return 0;
}


