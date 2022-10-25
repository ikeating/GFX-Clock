/*
 * myFunctionsLib.h
 *
 *    A library of functions.
 *
 *    Author: Isaiah Keating
 *    csc250DT2
 *    Last Modified: 04/20/2020   v0.5
 */

// header files normally contain constants, global variables, #define, as well
// as function headers

//mostly function headers (prototypes, signatures) are listed in the header
//file

#define MAXROWS 200
#define MAXCOLS 200

void printTableOfInts(int table[MAXROWS][MAXCOLS], int nRows, int nCols);

void printGameOfLife(int table[MAXROWS][MAXCOLS], int nRows, int nCols);

void countNeighbors(int sourceGrid[MAXROWS][MAXCOLS], int countGrid[MAXROWS][MAXCOLS], int nRows, int nCols);

void updateGameOfLife (int golGrid[MAXROWS][MAXCOLS], int nRows, int nCols);

void printTableOfChar(char table[MAXROWS][MAXCOLS], int nRows, int nCols);


