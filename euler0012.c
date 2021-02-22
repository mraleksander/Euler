#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define bool int
#define true 1
#define false 0

int IsPrime(long long number) 
    {
       int root = sqrt(number) ;
       for(int i=2; i<=root; i++) 
       {
          if(number%i == 0)
              return 0; //ni prastevilo
       } 
       return 1; //je prastevilo
} 

int SteviloDeliteljev(long long number) {
    int stevec = 0;
    for(int i=1; i<=number; i++) 
       {
          if(number%i == 0)
              stevec++;
       } 
       return stevec;
}


/**
 * 
 * Core Dumped at
 * 2046 Stevilo, 2094081 Vsota, 32 Stevilo Deliteljev
 * 
 **/
int divCount(long long n) 
{ 
    // sieve method for prime calculation 
    bool hash[n + 1]; 
    memset(hash, true, sizeof(hash)); 
    for (int p = 2; p * p < n; p++) 
        if (hash[p] == true) 
            for (int i = p * 2; i < n; i += p) 
                hash[i] = false; 
  
    // Traversing through all prime numbers 
    int total = 1; 
    for (int p = 2; p <= n; p++) { 
        if (hash[p]) { 
  
            // calculate number of divisor 
            // with formula total div =  
            // (p1+1) * (p2+1) *.....* (pn+1) 
            // where n = (a1^p1)*(a2^p2)....  
            // *(an^pn) ai being prime divisor 
            // for n and pi are their respective  
            // power in factorization 
            int count = 0; 
            if (n % p == 0) { 
                while (n % p == 0) { 
                    n = n / p; 
                    count++; 
                } 
                total = total * (count + 1); 
            } 
        } 
    } 
    return total; 
} 

/**
 * real    0m0.343s
 * user    0m0.188s
 * sys     0m0.109s
 *  
**/

int delitelji(int x) { 
    int limita = x;
    int steviloDeliteljev = 0;

    if (x == 1) return 1;

    for (int i = 1; i < limita; ++i) {
        if (x % i == 0) {
            limita = x / i;
            if (limita != i) {
                steviloDeliteljev++;
            }
            steviloDeliteljev++;
        }
    }

    return steviloDeliteljev;
}

unsigned divisor_count(unsigned long n){
    unsigned ret = 1;
    unsigned long i;

    for (int i = 0; i <= n; i++)
    {
        unsigned c = 0;
        while (n % i == 0)
        {
            c++;
            n /= i;
        }
        ret *= c+1;
    }
    return ret;
}

/**
 * Baje je hitrejse od divisors(int x)
 *  pretvori iz python v c
 * 
    import operator
    # A slightly efficient superset of primes.
    def PrimesPlus():
    yield 2
    yield 3
    i = 5
    while True:
        yield i
        if i % 6 == 1:
        i += 2
        i += 2
    # Returns a dict d with n = product p ^ d[p]
    def GetPrimeDecomp(n):
    d = {}
    primes = PrimesPlus()
    for p in primes:
        while n % p == 0:
        n /= p
        d[p] = d.setdefault(p, 0) + 1
        if n == 1:
        return d
    def NumberOfDivisors(n):
    d = GetPrimeDecomp(n)
    powers_plus = map(lambda x: x+1, d.values())
    return reduce(operator.mul, powers_plus, 1)
  **/

int main()
{
    int stevilodelit = 0;
    unsigned long vsota = 0;
    unsigned long stevec = 0;
    while (1)
    {
        vsota += stevec;
        //printf("%ld:  %ld\n",stevec, vsota);
        
        stevilodelit = divisors(vsota);

        printf("%ld Stevilo, %ld Vsota, %d Stevilo Deliteljev\n", stevec, vsota, stevilodelit);
        if (stevilodelit > 500)
        {
            break;
        }
        
        
        stevec++;

    }
    
    
    

    return 0;
}