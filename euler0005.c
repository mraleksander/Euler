/**
 * 

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

 *
**/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    long stevilo = 1;
    int delitelj = 0;
    while (1)
    {
        for (int i = 1; i <= 20; i++)
        {
            if (stevilo % i == 0)
            {
                delitelj++;
            }
            
        }
        if (delitelj == 20)
        {
            printf("%ld", stevilo);
            break;
        }else{
            delitelj = 0;
        }
        
        stevilo++;

    }
    
    

    return 0;
}
