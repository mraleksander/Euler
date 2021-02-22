/**
 * 
 
    A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
    a2 + b2 = c2

    For example, 32 + 42 = 9 + 16 = 25 = 52.

    There exists exactly one Pythagorean triplet for which a + b + c = 1000.
    Find the product abc.

 * 
**/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    long a = 1, b , c;
    for (a = 1; a < 1001; a++)
    {
        for (b = a+1; b < 1001; b++)
        {
            for (c = b+1; c < 1001; c++)
            {
                if ((a*a + b*b) == c*c)
                {
                    if (a + b + c == 1000)
                    {
                        printf("%ld = %ld * %ld * %ld", a*b*c, a, b, c);
                        return 1;
                    }
                }
            }
            
        }
        
    }
    
    

    return 0;
}