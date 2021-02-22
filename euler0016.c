/**
 *  
    2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

    What is the sum of the digits of the number 2^1000?
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int tabela[1000];
long unsigned sum(){
    int b = sizeof(tabela) / sizeof(tabela[0]);
    long unsigned vsota = 0;
    for (int i = 0; i < b; i++)
    {
        vsota += tabela[i];
    }
    return vsota;
}

void potenca(int do_Kam){
    int b = sizeof(tabela) / sizeof(tabela[0]);
    int zmozek = 0, naprejprenese = 0, zapise = 0;
    for (int i = 0; i < do_Kam; i++)
    {
        for (int j = b-1; j >= 0; j--)
        {
            zmozek = (tabela[j] * 2) + naprejprenese;
            zapise = zmozek % 10;
            if (zmozek > 9)
            {
                naprejprenese = zmozek;
                while(naprejprenese >= 10)
                {
                    naprejprenese = naprejprenese / 10;
                }
            }else
            {
                naprejprenese = 0;
            }
            
            
            
            tabela[j] = zapise;
        }
        
    }
}

int main()
{
    /** SIZE OF TABELA
        int a = sizeof(tabela);
        int b = sizeof(tabela) / sizeof(tabela[0]); //vrstice
        int c = sizeof(tabela) / sizeof(tabela[0]);
        int column = sizeof(tabela[0])/sizeof(tabela[0]); //stolpci

        printf("%d %d %d %d\n", a, b, c, column);*/
    tabela[999] = 1;
    potenca(1000);
    printf("%ld", sum());
    

    return 0;
}