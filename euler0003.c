/**
 * 
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 600851475143 ?
 * 
 **/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int max = 0;
    long stevilo;
    int prime_flag = 0;
    //scanf("%d", &stevilo);
    
    stevilo = 600851475143;
    int delitelj = 2;
    while (stevilo > 1)
    {
        if (stevilo % delitelj == 0)
        {
            max = delitelj;
            stevilo = stevilo / delitelj;
        }else
        {
            delitelj++;
        }
        
    }
    printf("%d", max);
    
    
    
    
    
    
    
    return 0;
}