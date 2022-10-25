/*
 * myFunctionsLib.c
 *
 *    A library of functions.
 *
 *    Author: Isaiah Keating
 *    csc250DT2
 *    Last Modified: 04/20/2020   v0.5  version number indicates how many functions
 */
#include <stdio.h>
#include <math.h>
#include "gfx2.h"
#include "myFunctionsLib.h"
#include <stdlib.h>
#include <time.h>
//const double PI = 3.14159265358979323846264338327950288419716939937510;

void printTableOfInts(int table[MAXROWS][MAXCOLS], int nRows, int nCols)
{
   int i, j;
   for (i=0; i<nRows; i++) // loop over the rows of the table
   {
      for (j=0; j < nCols; j++)  // loop over the columns of the table
      {
         printf("%5d", table[i][j]); // print one number from the table
                                                         // notice: no \n (no return)
      }
      printf("\n");  // after the loop that prints each item from a row (above)
                     // we print a \n to drop to the next line in the output
   }
}

void printGameOfLife(int table[MAXROWS][MAXCOLS], int nRows, int nCols)
{
   int i, j;
   for (i=0; i<nRows; i++) // loop over the rows of the table
   {
      for (j=0; j < nCols; j++)  // loop over the columns of the table
      {
         if ( table[i][j] == 1 )
         {
            printf("*");
         }
         else
         {
            printf(" ");
         }
      }
      printf("\n");  // after the loop that prints each item from a row (above)
                     // we print a \n to drop to the next line in the output
   }
}

   // CHALLENGE...
   // write a function that take 2 2D arrays of ints...
   // the first will a game of life grid of 1's & 0's...
   // the function will count the neighbors of each cell in the grid

void countNeighbors(int sourceGrid[MAXROWS][MAXCOLS], int countGrid[MAXROWS][MAXCOLS], int nRows, int nCols)
{
   for (int i=0; i<nRows; i++) // loop for each row...
   {
      for (int j=0; j<nCols; j++) // loop for each col...
      {
         countGrid[i][j] = 0; // make sure we start counting at zero...
         for ( int deltaRow = -1; deltaRow <= 1; deltaRow++) // loop for each neighbor row...
         {
            for ( int deltaCol = -1; deltaCol <= 1; deltaCol++ )   // loop for each neighbor col...
            {
               // if sourceGrid[i+deltaRow][j+deltaCol] is 1 then add 1 to the count for that location
               // that means increment countGrid[i][j]
               if ( i+deltaRow >= 0 && j+deltaCol >= 0
                    && i+deltaRow < nRows && j+deltaCol < nCols )  // not out of bound
               {
                  if ( ! ( ( deltaRow == 0 ) && ( deltaCol == 0 ) ) ) // "and" is &&
                  // SAME if ( ( deltaRow!=0 ) || ( deltCol !=0 ) ) // "or" is ||
                  {
                     countGrid[i][j] = countGrid[i][j] + sourceGrid[i+deltaRow][j+deltaCol];
                     /* SAME if ( sourceGrid[i+deltaRow][j+deltaCol] == 1)
                     {
                        countGrid[i][j]++    
                     }*/
                  }
               }
            }
         }
      }
   }
}

//given a game of life grid, update the values in the grid according to the rules
void updateGameOfLife (int golGrid[MAXROWS][MAXCOLS], int nRows, int nCols)
{
   int countGrid[MAXROWS][MAXCOLS];
   countNeighbors(golGrid, countGrid, nRows, nCols);
   // look at each cell of the golGrid... and the corresponding count... and decide
   // whether it should be updated to a 1 or 0... according to the rules...
   for (int i = 0; i < nRows; i++)
   {
      for (int j = 0; j < nCols; j++)
      {
         if ( golGrid[i][j] == 1 )  // if the cell is currently alive...
         {
            if ( countGrid[i][j] < 2 || countGrid[i][j] >= 4)  // if lonely or overcrowded...
            {
               golGrid[i][j] = 0;
            }
         }
         else  // the cell is currently empty...
         {
            if ( countGrid[i][j] == 3 ) // if we have exactly 3 neighbors
            {
               golGrid[i][j] = 1;   // a cell is born
            }
         }
      }
   }
}

//Print a 2D array of char

void printTableOfChar(char table[MAXROWS][MAXCOLS], int nRows, int nCols)
{
   int i, j;
   for (i=0; i<nRows; i++) // loop over the rows of the table
   {
      for (j=0; j < nCols; j++)  // loop over the columns of the table
      {
         printf("%2c", table[i][j]); // print one number from the table
                                                         // notice: no \n (no return)
      }
      printf("\n");  // after the loop that prints each item from a row (above)
                     // we print a \n to drop to the next line in the output
   }
}


