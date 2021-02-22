/**
 * 
 
    The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

    Find the sum of all the primes below two million.

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
    long long vsota = 0;
    for (long i = 2; i <= 2000000; i++)
    {
        if (IsPrime(i) == 1)
        {
            vsota += i;
        }
        
    }
    printf("Vsota = %lld\n", vsota);
    
    return 0;
}