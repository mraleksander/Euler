/**
 * 

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

 * 
 * **/
#include <stdio.h>
#include <stdlib.h>
int obrni(int stevilo){
    int rev = 0, ostanek;
    while(stevilo != 0) {
        ostanek = stevilo % 10;
        rev = rev * 10 + ostanek;
        stevilo /= 10;
    }
    return rev;
}

int main()
{
    long long max = 9009;
    long long peledrom;
    for (int i = 100; i < 1000; i++)
    {
        for (int j = 100; j < 1000; j++)
        {
            peledrom = i * j;
            if (peledrom == obrni(peledrom))
            {
                if (peledrom > max)
                {
                    max = peledrom;
                }
                
            }
            
        }
        
    }
    printf("%ld",max);
    

    return 0;
}
