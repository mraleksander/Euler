/**

Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.

**/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int predprejsna = 1, prejsna = 2;
    int trenutno = 0;
    int vsota = 2;
    //printf("%d\n%d\n", predprejsna, prejsna);
    while(trenutno <= 4000000){
    	trenutno = prejsna + predprejsna;
        predprejsna = prejsna;
        prejsna = trenutno;
        //printf("%d\n", trenutno);
        if (trenutno % 2 == 0)
        {
            vsota += trenutno;
        }
        
    }
    printf("%d\n",vsota);

    return 0;
}