/**


    The following iterative sequence is defined for the set of positive integers:

    n → n/2 (n is even)
    n → 3n + 1 (n is odd)

    Using the rule above and starting with 13, we generate the following sequence:
    13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

    It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

    Which starting number, under one million, produces the longest chain?

    NOTE: Once the chain starts the terms are allowed to go above one million.


**/
#include <stdio.h>
#include <stdlib.h>

long MEMO[1000000];

long collatz(long input){
    long saveinput = input;
    long stevec = 1;
    if (MEMO[saveinput] != 0 ) return MEMO[saveinput];
    
    
    while (input != 1)
    {
        //printf("%ld\n", input);
        if ((input % 2) == 0)
        {
            input = input / 2;
        }else{
            input = 3*input + 1;
        }
        stevec++;
    }
    MEMO[saveinput]= stevec;
    return stevec;
}

int main()
{
    long stevec = 0, maxstevec = 0;
    long maxstevilo;
    //printf("%ld", collatz(13));
    for (long i = 1; i < 1000000; i++)
    {
        stevec = collatz(i);
        if (stevec > maxstevec)
        {
            maxstevec = stevec;
            maxstevilo = i;
            printf("i = %ld | maxstevec= %ld\n", i, maxstevec);
        }
        
    }
    
    printf("Stevilo %ld ima collatz %ld\n", maxstevilo, maxstevec);
    return 0;
}
