/**
 
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

How many such routes are there through a 20×20 grid?

**/
#include <stdio.h>
#include <stdlib.h>

#define N 20

int grid[N+1][N+1];
long stevilopoti[N+1][N+1];
//unsigned long stevecDesno = 0, stevecDol = 0;

unsigned long navigacija(int vrstica, int stolpec){
    unsigned long stevecDesno = 0, stevecDol = 0;
    if (grid[vrstica][stolpec] == 99) return 1;
    if (vrstica > N ||stolpec > N) return 0;
    if (stolpec == N || vrstica == N) return 1;
    if (stevilopoti[vrstica][stolpec] != 0) return stevilopoti[vrstica][stolpec];
    
    stevecDesno += navigacija(vrstica, stolpec+1);
    stevecDol += navigacija(vrstica+1, stolpec);
    stevilopoti[vrstica][stolpec] = stevecDesno + stevecDol;
    return stevecDesno + stevecDol;

    /*    if (stolpec == N-1)
        {
            stevecDol += navigacija(vrstica+1, stolpec);
            return stevecDesno+stevecDol;
        }
        if (vrstica == N-1)
        {
            stevecDesno += navigacija(vrstica, stolpec+1);
            return stevecDesno+stevecDol;
        }
        
        if (stevilopoti[vrstica][stolpec] != 0) return stevilopoti[vrstica][stolpec];
        
        stevecDesno += navigacija(vrstica, stolpec+1);
        stevecDol += navigacija(vrstica+1, stolpec);
        
        stevilopoti[vrstica][stolpec] = stevecDesno+stevecDol;
        return stevecDesno+stevecDol;*/
}


void Dynamic() {

    const int gridSize = N;
            
    long gridy[gridSize+1][gridSize+1];

    for (int i = 0; i < gridSize; i++) {
        gridy[i][gridSize] = 1;
        gridy[gridSize][i] = 1;
    }

    for (int i = gridSize - 1; i >= 0; i--) {
        for (int j = gridSize - 1; j >= 0; j--) {
            gridy[i][j] = gridy[i+1][j] + gridy[i][j+1];
        }
    }
    
    printf("Dynamic: In a {%d}x{%d} grid there are {%ld} possible paths.\n", gridSize, gridSize, *gridy[0,0]);
            
}
      
void Combinatorics() {

    const int gridSize = N;

    long paths = 1;

    for (int i = 0; i < gridSize; i++) {
         paths *= (2 * gridSize) - i;
        paths /= i + 1;
    }


    printf("Combinatorics: In a {%d}x{%d} grid there are {%ld} possible paths.\n", gridSize, gridSize, paths);
}


int main()
{
    // Kombinatorika
    /* 
        const int gridSize = N;
        long paths = 1;
        
        for (int i = 0; i < gridSize; i++) {
            paths *= (2 * gridSize) - i;
            paths /= i + 1;
        }
        printf("%ld\n", paths);*/
    Combinatorics();
    Dynamic();


    // Sprehajanje
    grid [N][N] = 99;
    printf("MOJA RESITEV KI KONCNO DELA: V {%d}x{%d} sahovnici obstaja {%ld} povezav\n",N, N, navigacija(0, 0));
    

    return 0;
}
