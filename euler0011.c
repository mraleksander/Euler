/*
    
    In the 20×20 grid below, four numbers along a diagonal line have been marked in red.

    08 02 22 97 38 15 00 40 00 75 04 05 07 78 52 12 50 77 91 08
    49 49 99 40 17 81 18 57 60 87 17 40 98 43 69 48 04 56 62 00
    81 49 31 73 55 79 14 29 93 71 40 67 53 88 30 03 49 13 36 65
    52 70 95 23 04 60 11 42 69 24 68 56 01 32 56 71 37 02 36 91
    22 31 16 71 51 67 63 89 41 92 36 54 22 40 40 28 66 33 13 80
    24 47 32 60 99 03 45 02 44 75 33 53 78 36 84 20 35 17 12 50
    32 98 81 28 64 23 67 10 26 38 40 67 59 54 70 66 18 38 64 70
    67 26 20 68 02 62 12 20 95 63 94 39 63 08 40 91 66 49 94 21
    24 55 58 05 66 73 99 26 97 17 78 78 96 83 14 88 34 89 63 72
    21 36 23 09 75 00 76 44 20 45 35 14 00 61 33 97 34 31 33 95
    78 17 53 28 22 75 31 67 15 94 03 80 04 62 16 14 09 53 56 92
    16 39 05 42 96 35 31 47 55 58 88 24 00 17 54 24 36 29 85 57
    86 56 00 48 35 71 89 07 05 44 44 37 44 60 21 58 51 54 17 58
    19 80 81 68 05 94 47 69 28 73 92 13 86 52 17 77 04 89 55 40
    04 52 08 83 97 35 99 16 07 97 57 32 16 26 26 79 33 27 98 66
    88 36 68 87 57 62 20 72 03 46 33 67 46 55 12 32 63 93 53 69
    04 42 16 73 38 25 39 11 24 94 72 18 08 46 29 32 40 62 76 36
    20 69 36 41 72 30 23 88 34 62 99 69 82 67 59 85 74 04 36 16
    20 73 35 29 78 31 90 01 74 31 49 71 48 86 81 16 23 57 05 54
    01 70 54 71 83 51 54 69 16 92 33 48 61 43 52 01 89 19 67 48

    The product of these numbers is 26 × 63 × 78 × 14 = 1788696.

    What is the greatest product of four adjacent numbers in the same direction (up, down, left, right, or diagonally) in the 20×20 grid?

*/


#include <stdio.h>

#define N 20

static __inline unsigned max(unsigned a, unsigned b);

int main(void)
{
  unsigned grid[20][20] = {
    {8,2,22,97,38,15,0,40,0,75,4,5,7,78,52,12,50,77,91,8},
    {49,49,99,40,17,81,18,57,60,87,17,40,98,43,69,48,4,56,62,0},
    {81,49,31,73,55,79,14,29,93,71,40,67,53,88,30,3,49,13,36,65},
    {52,70,95,23,4,60,11,42,69,24,68,56,1,32,56,71,37,2,36,91},
    {22,31,16,71,51,67,63,89,41,92,36,54,22,40,40,28,66,33,13,80},
    {24,47,32,60,99,3,45,2,44,75,33,53,78,36,84,20,35,17,12,50},
    {32,98,81,28,64,23,67,10,26,38,40,67,59,54,70,66,18,38,64,70},
    {67,26,20,68,2,62,12,20,95,63,94,39,63,8,40,91,66,49,94,21},
    {24,55,58,5,66,73,99,26,97,17,78,78,96,83,14,88,34,89,63,72},
    {21,36,23,9,75,0,76,44,20,45,35,14,0,61,33,97,34,31,33,95},
    {78,17,53,28,22,75,31,67,15,94,3,80,4,62,16,14,9,53,56,92},
    {16,39,5,42,96,35,31,47,55,58,88,24,0,17,54,24,36,29,85,57},
    {86,56,0,48,35,71,89,7,5,44,44,37,44,60,21,58,51,54,17,58},
    {19,80,81,68,5,94,47,69,28,73,92,13,86,52,17,77,4,89,55,40},
    {4,52,8,83,97,35,99,16,7,97,57,32,16,26,26,79,33,27,98,66},
    {88,36,68,87,57,62,20,72,3,46,33,67,46,55,12,32,63,93,53,69},
    {4,42,16,73,38,25,39,11,24,94,72,18,8,46,29,32,40,62,76,36},
    {20,69,36,41,72,30,23,88,34,62,99,69,82,67,59,85,74,4,36,16},
    {20,73,35,29,78,31,90,1,74,31,49,71,48,86,81,16,23,57,5,54},
    {1,70,54,71,83,51,54,69,16,92,33,48,61,43,52,1,89,19,67,48},
  };
  unsigned m = 0;
  unsigned i, j;

  for (i = 0; i < N-3; i++) {
    for (j = 0; j < N-3; j++) {
      unsigned h = grid[i][j] * grid[i][j+1] * grid[i][j+2] * grid[i][j+3];
      unsigned v = grid[j][i] * grid[j+1][i] * grid[j+2][i] * grid[j+3][i];
      unsigned d1 = grid[i][j] * grid[i+1][j+1] * grid[i+2][j+2] * grid[i+3][j+3];
      unsigned d2 = grid[i][N-j-1] * grid[i+1][N-j-2] * grid[i+2][N-j-3] * grid[i+3][N-j-4];
      m = max(m, max(h, max(v, max(d1, d2))));

      //test
      if(h == 70600674 || v == 70600674 || d1 == 70600674 || d2 == 70600674){
          printf("%d %d | h=%u v=%u d1=%u d2=%u\n", i, j, h, v, d1, d2);
          printf("%u * %u * %u * %u\n", grid[i][N-j-1], grid[i+1][N-j-2], grid[i+1][N-j-3], grid[i+1][N-j-4]);
      }
    }
  }
  printf("%u\n", m);

  return 0;
}

unsigned max(unsigned a, unsigned b)
{
  return a > b ? a : b;
}


/* one solution
    #include 

    int main()
    {

        int array[20][20]=
        {
    { 8,  2, 22, 97, 38, 15,  0, 40,  0, 75,  4,  5,  7, 78, 52, 12, 50, 77, 91,  8},
    {49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48,  4, 56, 62,  0},
    {81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30,  3, 49, 13, 36, 65},
    {52, 70, 95, 23,  4, 60, 11, 42, 69, 24, 68, 56,  1, 32, 56, 71, 37,  2, 36, 91},
    {22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80},
    {24, 47, 32, 60, 99,  3, 45,  2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
    {32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
    {67, 26, 20, 68,  2, 62, 12, 20, 95, 63, 94, 39, 63,  8, 40, 91, 66, 49, 94, 21},
    {24, 55, 58,  5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
    {21, 36, 23,  9, 75,  0, 76, 44, 20, 45, 35, 14,  0, 61, 33, 97, 34, 31, 33, 95},
    {78, 17, 53, 28, 22, 75, 31, 67, 15, 94,  3, 80,  4, 62, 16, 14,  9, 53, 56, 92},
    {16, 39,  5, 42, 96, 35, 31, 47, 55, 58, 88, 24,  0, 17, 54, 24, 36, 29, 85, 57},
    {86, 56,  0, 48, 35, 71, 89,  7,  5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
    {19, 80, 81, 68,  5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77,  4, 89, 55, 40},
    { 4, 52,  8, 83, 97, 35, 99, 16,  7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
    {88, 36, 68, 87, 57, 62, 20, 72,  3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69},
    { 4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18,  8, 46, 29, 32, 40, 62, 76, 36},
    {20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74,  4, 36, 16},
    {20, 73, 35, 29, 78, 31, 90,  1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57,  5, 54},
    { 1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52,  1, 89, 19, 67, 48},
        };

        unsigned long long highest=0;
        unsigned long long test=0;

        int one=0;
        int two=0;
        int three=0;
        int four=0;

        int i=0;
        int j=0;

        //check for horizontal highest//
        for(i=0; i<20; i++)
        {

            for(j=0; j<17; j++)
            {
                test=(array[i][j]*array[i][j+1]*array[i][j+2]*array[i][j+3]);

                if(test>highest)
                {
                    highest=test;

                    one=array[i][j];
                    two=array[i][j+1];
                    three=array[i][j+2];
                    four=array[i][j+3];
                }

            }//end of j for loop

        }//end of i for loop


        //test for vertical highest//
        for(i=0; i<17; i++)
        {

            for(j=0; j<20; j++)
        {

                test=(array[i][j]*array[i+1][j]*array[i+2][j]*array[i+3][j]);

                if(test>highest)
                {
                    highest=test;
                    one=array[i][j];
                    two=array[i+1][j];
                    three=array[i+2][j];
                    four=array[i+3][j];
                }

        }//end of j for loop

        }//end of i for loop


        //check for diagonal-right highest//
        for(i=3; i<20; i++)
        {

            for(j=0; j<17; j++)
            {

            test=(array[i][j]*array[i-1][j-1]*array[i-2][j-2]*array[i-3][i-3]);

                if(test>highest)
                {
                    highest=test;
                    one=array[i][j];
                    two=array[i-1][j-1];
                    three=array[i-2][j-2];
                    four=array[i-3][j-3];
                }

            }//end j for loop

        }//end i for loop


        //check for diagonal-left highest//
        for(i=0; i<17; i++)
        {

            for(j=0; j<17; j++)
            {

            test=(array[i][j]*array[i+1][j-1]*array[i+2][j-2]*array[i+3][j-3]);

                if(test>highest)
                {
                    highest=test;
                    one=array[i][j];
                    two=array[i+1][j-1];
                    three=array[i+2][j-2];
                    four=array[i+3][j-3];
                }

            }//end j for loop

        }//end i for loop


        printf("%d\n", highest);

        return 0;
    }
*/

/* My Solution that dosent work pozabil sem šteti da gre diagonala v levo
    #include <stdio.h>
    #include <stdlib.h>
    int grid [20][21]={
    {8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8},
    {49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 4, 56, 62, 0},
    {81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65},
    {52, 70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 1, 32, 56, 71, 37, 2, 36, 91},
    {22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80},
    {24, 47, 32, 60, 99, 3, 45, 2, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50},
    {32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70},
    {67, 26, 20, 68, 2, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21},
    {24, 55, 58, 5, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72},
    {21, 36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95},
    {78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 3, 80, 4, 62, 16, 14, 9, 53, 56, 92},
    {16, 39, 5, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57},
    {86, 56, 0, 48, 35, 71, 89, 7, 5, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58},
    {19, 80, 81, 68, 5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 4, 89, 55, 40},
    {4, 52, 8, 83, 97, 35, 99, 16, 7, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66},
    {88, 36, 68, 87, 57, 62, 20, 72, 3, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69},
    {4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36},
    {20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16},
    {20, 73, 35, 29, 78, 31, 90, 1, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54},
    {1, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 1, 89, 19, 67, 48},
    };
    long long up (int x, int y) {
        long long vsota = 1;
        for (int i = 0; i < 4; i++)
        {
            vsota *= grid[x-i][y];
        }
        return vsota;
        
    }
    long long down (int x, int y) {
        long long vsota = 1;
        for (int i = 0; i < 4; i++)
        {
            vsota *= grid[x+i][y];
        }
        return vsota;
    }
    unsigned long long left (int x, int y) {
        unsigned long long vsota = 1;
        for (int i = 0; i < 4; i++)
        {
            vsota *= grid[x][y-i];
        }
        return vsota;

    }
    unsigned long long right (int x, int y) {
        unsigned long long vsota = 1;
        for (int i = 0; i < 4; i++)
        {
            vsota *= grid[x][y+i];
        }
        return vsota;

    }
    unsigned long long updiagonally (int x, int y){
        unsigned long long vsota = 1;
        for (int i = 0; i < 4; i++)
        {
            vsota *= grid[x-i][y-i];
        }
        return vsota;

    }
    unsigned long long downdiagonally (int x, int y){
        unsigned long long vsota = 1;
        for (int i = 0; i < 4; i++)
        {
            vsota *= grid[x+i][y+i];
        }
        return vsota;
    }

    int main()
    {
        unsigned long long vsotaup = 0;
        unsigned long long vsotadown = 0;
        unsigned long long vsotaleft = 0;
        unsigned long long vsotaright = 0;
        unsigned long long vsotaupdig = 0;
        unsigned long long vsotadowndig = 0;
        unsigned long long max = 0;
        unsigned long long maxmax = 0;
        for (int x = 0; x <= 20; x++)
        {
            for (int y = 0; y <= 20; y++)
            {
                if (x >= 3)
                {
                vsotaup = up(x, y);
                if (vsotaup == 70600674)
                {
                    printf("70600674");
                }
                
                }
                if (x <= 16)
                {
                    vsotadown = down(x, y);
                    if (vsotadown == 70600674)
                {
                    printf("70600674");
                }
                }
                if (y >= 3)
                {
                    vsotaleft = left(x, y);
                    if (vsotaleft == 70600674)
                {
                    printf("70600674");
                }
                }
                if (y <= 16)
                {
                    vsotaright = right(x, y);
                    if (vsotaright == 70600674)
                {
                    printf("70600674");
                }
                }
                if (x >= 3 && y >= 3)
                {
                    vsotaupdig = updiagonally(x, y);
                    if (vsotaupdig == 70600674)
                {
                    printf("70600674");
                }
                }
                if (x <= 16 && y <= 16)
                {
                    vsotadowndig = downdiagonally(x, y);
                    if (vsotadowndig == 70600674)
                {
                    printf("70600674");
                }
                }
                
                
                if (max < vsotaup)
                {
                    max = vsotaup;
                }
                if (max < vsotadown)
                {
                    max = vsotadown;
                }
                if (max < vsotaleft)
                {
                    max = vsotaleft;
                }
                if (max < vsotaright)
                {
                    max = vsotaright;
                }
                if (max < vsotaupdig)
                {
                    max = vsotaupdig;
                }
                if (max < vsotadowndig)
                {
                    max = vsotadowndig;
                }
                if (max > maxmax)
                {
                    maxmax = max;
                }
                max = 0;
            }
            
            
        } 
        printf("%llu\n", maxmax);
        
    return 0;
    }

*/

/* C++
    using System;
    using System.IO;


    namespace euler1 {
        class Problem11 {

            public static void Main(string[] args) {
                new Problem11().Solve();            
            }     


            public void Solve() {

                string filename = Environment.GetFolderPath(Environment.SpecialFolder.DesktopDirectory) + "\\input.txt";
                const int numbersInProduct = 4;

                DateTime startTime = DateTime.Now;
                decimal product = 0;

                int[,] inputSquare = readInput(filename);
                for (int col = 0; col < inputSquare.GetLength(0); col++) {
                    for (int row = 0; row < inputSquare.GetLength(1); row++) {                    
                        decimal tempProd;

                        // Check Vertically
                        if (row < inputSquare.GetLength(0) - numbersInProduct) {
                            tempProd = inputSquare[col, row];
                            for (int i = 1; i < numbersInProduct; i++) {
                                tempProd *= inputSquare[col, row + i];
                            }
                            product = Math.Max(product, tempProd);
                        }

                        // Check Horisontally
                        if (col < inputSquare.GetLength(1) - numbersInProduct) {
                            tempProd = inputSquare[col, row];
                            for (int i = 1; i < numbersInProduct; i++) {
                                tempProd *= inputSquare[col + i, row];
                            }
                            product = Math.Max(product, tempProd);
                        }

                        // Check diagonally upwards / forwards           
                        if ((col < inputSquare.GetLength(0) - numbersInProduct) && (row >= numbersInProduct)) {
                            tempProd = inputSquare[col, row];
                            for (int i = 1; i < numbersInProduct; i++) {
                                tempProd *= inputSquare[col + i, row - i];
                            }
                            product = Math.Max(product, tempProd);
                        }

                        // Check diagonally Downwards / forwards      
                        if ((row < inputSquare.GetLength(0) - numbersInProduct) && (col < inputSquare.GetLength(1) - numbersInProduct)) {
                            tempProd = inputSquare[col, row];
                            for (int i = 1; i < numbersInProduct; i++) {
                                tempProd *= inputSquare[col + i, row + i];
                            }
                            product = Math.Max(product, tempProd);
                        }                                                           
                    }
                }

                DateTime stopTime = DateTime.Now;
                TimeSpan duration = stopTime - startTime;            
                Console.WriteLine("The greatest product of {0} entries, is {1}",numbersInProduct, product);            
                Console.WriteLine("Solution took {0} ms", duration.TotalMilliseconds);
            }


            private int[,] readInput(string filename) {
                int lines = 0;
                string line;
                string[] linePieces;
                                    
                StreamReader r = new StreamReader(filename);
                while(r.ReadLine() != null){
                    lines++;
                }            

                int[,] inputSquare = new int[lines, lines];
                r.BaseStream.Seek(0, SeekOrigin.Begin);            
                
                int j =0;
                while ((line = r.ReadLine()) != null) {
                    linePieces = line.Split(' ');
                    for (int i = 0; i < linePieces.Length; i++) {                    
                        inputSquare[j, i] = int.Parse(linePieces[i]);
                    }
                    j++;
                }         
                            
                r.Close();
                
                return inputSquare;
            }
        }
    }
*/

/* Sizeof TABEL
            int a = sizeof(grid);
            int b = sizeof(grid) / sizeof(grid[0]); //vrstice
            int c = sizeof(grid) / sizeof(grid[0][0]);
            int column = sizeof(grid[0])/sizeof(grid[0][0]); //stolpci

            printf("%d %d %d %d\n", a, b, c, column);*/